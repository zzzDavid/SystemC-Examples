/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file is used to wrap the three different versions of the DUT
* block called "dut". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/

#if defined(CYNTHVLG)


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#include	"dut_rtl.cc"

#else 

#if defined(BDW_HUB)

#include "esc.h"

#if defined(BDW_RTL) || defined(COWARE_RTL_dut)

#define BDW_AUTO_KNOWN 1 


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#undef dut
#define dut dut_rtl
#	include	"dut_rtl.cc"
#undef dut


#ifdef BDW_PORTS_ONLY
#undef BDW_PORTS_ONLY
#endif



#elif defined(BDW_HOIST) 
#else

#endif
#ifdef BDW_COWARE
#include	"dut_coware.h"
#else
#include	"dut_cosim.h"
#endif

// include for cycle-accurate verilator simulation
#include    "dut_cycsim.h"



// Include the source for the behavioral model so it will be compiled.
#include	"dut.cc"


#define		dut_INTERNAL


#include	"dut_wrap.h"

// this global pointer indicates whether or not the Verilator cycsim wrapper is present
dut_cycsim* (*dut_cycsim_factory_p)() = 0;

#define MAX_SIMCONFIG_LENGTH 128

#if BDW_WRITEFSDB == 1

#if defined(NC_SYSTEMC) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
#include "fsdb_nc_mix.h"
#else
#include "fsdb_trace_file.h"
#endif 
#if BDW_USE_SCV
#include "scv.h"
#include "scv_tr_fsdb.h"
#endif

#endif /* BDW_WRITEFSDB */

inline void esc_open_fsdb_trace( const char *file_name = "systemc" );
inline void esc_close_fsdb_trace();
inline void esc_close_fsdb_scv_trace();

// The following threads are used to connect structured ports to the actual
// RTL ports

const char * dut_wrapper::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum dut_wrapper::Representation dut_wrapper::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "dut", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound ) {
		return BDWRep_Behavioral;
	} else if ( err == qbhErrorBadInstName ) {
		if (instName && *instName) {
			const char* leaf = strrchr( instName, '.' ) + 1;
			esc_report_error( esc_warning, "Instance names were specified for module '%s' in simConfig '%s', but they did not "
			                    "match the actal instance names in the RTL.  Try '%s' or '%s'. Simulating '%s' as BEH.\n",
								 "dut", simConfig, instName, leaf,  "dut" );
		}
		return BDWRep_Behavioral;
	}

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
        exit(1);

	return BDWRep_None;
}

void dut_wrapper::InitInstances(  )
{
    enum dut_wrapper::Representation rep =
		dut_wrapper::lookupRepresentation( name() );

	esc_log_wrapper_inst( "dut" );
	esc_log_representation( "dut", name(), rep );

	

	switch ( rep )
	{
		case BDWRep_Gates:
		    dut_cosim0 = new dut_cosim( "dut" );

		    dut_cosim0->clk(clk);
		    dut_cosim0->rst(rst);
		    dut_cosim0->din_1_busy(din_1.busy);
		    dut_cosim0->din_1_vld(din_1.vld);
		    dut_cosim0->din_1_data(din_1.data);
		    dut_cosim0->din_2_busy(din_2.busy);
		    dut_cosim0->din_2_vld(din_2.vld);
		    dut_cosim0->din_2_data(din_2.data);
		    dut_cosim0->dout_busy(dout.busy);
		    dut_cosim0->dout_vld(dout.vld);
		    dut_cosim0->dout_data(dout.data);

			break;
		case BDWRep_RTL_HDL:
		    dut_cosim0 = new dut_cosim( "dut" );

		    dut_cosim0->clk(clk);
		    dut_cosim0->rst(rst);
		    dut_cosim0->din_1_busy(din_1.busy);
		    dut_cosim0->din_1_vld(din_1.vld);
		    dut_cosim0->din_1_data(din_1.data);
		    dut_cosim0->din_2_busy(din_2.busy);
		    dut_cosim0->din_2_vld(din_2.vld);
		    dut_cosim0->din_2_data(din_2.data);
		    dut_cosim0->dout_busy(dout.busy);
		    dut_cosim0->dout_vld(dout.vld);
		    dut_cosim0->dout_data(dout.data);

			break;
        case BDWRep_CYC_HDL:
            if ( dut_cycsim_factory_p )
                dut_cycsim0 = dut_cycsim_factory_p();
            else
            {
                esc_report_error( esc_fatal, "verilator_produced files not available for module dut");
                return;
            }

            esc_report_error( esc_note, " using verilator model for module \"dut\"");

		    dut_cycsim0->clk(clk);
		    dut_cycsim0->rst(rst);
		    dut_cycsim0->din_1_busy(din_1.busy);
		    dut_cycsim0->din_1_vld(din_1.vld);
		    dut_cycsim0->din_1_data(din_1.data);
		    dut_cycsim0->din_2_busy(din_2.busy);
		    dut_cycsim0->din_2_vld(din_2.vld);
		    dut_cycsim0->din_2_data(din_2.data);
		    dut_cycsim0->dout_busy(dout.busy);
		    dut_cycsim0->dout_vld(dout.vld);
		    dut_cycsim0->dout_data(dout.data);

			break;
#if defined(BDW_RTL) || defined(COWARE_RTL_dut)
		case BDWRep_RTL_C:
		    dut_rtl0 = new dut_rtl( "dut" );

		    dut_rtl0->clk(clk);
		    dut_rtl0->rst(rst);
		    dut_rtl0->din_1_busy(din_1.busy);
		    dut_rtl0->din_1_vld(din_1.vld);
		    dut_rtl0->din_1_data(din_1.data);
		    dut_rtl0->din_2_busy(din_2.busy);
		    dut_rtl0->din_2_vld(din_2.vld);
		    dut_rtl0->din_2_data(din_2.data);
		    dut_rtl0->dout_busy(dout.busy);
		    dut_rtl0->dout_vld(dout.vld);
		    dut_rtl0->dout_data(dout.data);


			{
			const char *simConfig = dut_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    dut0 = new dut( "dut" );

		    dut0->clk(clk);
		    dut0->rst(rst);
		    dut0->din_1.busy(din_1.busy);
		    dut0->din_1.vld(din_1.vld);
		    dut0->din_1.data(din_1.data);
		    dut0->din_2.busy(din_2.busy);
		    dut0->din_2.vld(din_2.vld);
		    dut0->din_2.data(din_2.data);
		    dut0->dout.busy(dout.busy);
		    dut0->dout.vld(dout.vld);
		    dut0->dout.data(dout.data);


			{
			const char *simConfig = dut_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void dut_wrapper::InitThreads()
{
	if ( !isBEH() )
	{
		
	}
}

void dut_wrapper::start_of_simulation()
{

#include <dut_trace.h>

    esc_multiple_writers_warning();
}

void dut_wrapper::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void dut_wrapper::end_of_simulation()
{
	CloseTrace();
}



void dut_wrapper::DeleteInstances()
{
    if (dut0)
    {
        delete dut0;
        dut0 = 0;
    }
    if (dut_cosim0)
    {
        delete dut_cosim0;
        dut_cosim0 = 0;
    }
    if (dut_cycsim0)
    {
        delete dut_cycsim0;
        dut_cycsim0 = 0;
    }
#if defined(BDW_RTL) || defined(COWARE_RTL_dut)
    if (dut_rtl0)
    {
        delete dut_rtl0;
        dut_rtl0 = 0;
    }
#endif
}

// The following threads are used to connect RTL ports to the actual
// structured ports

const char * dut_wrapper_r::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum dut_wrapper_r::Representation dut_wrapper_r::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "dut", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound )
		return BDWRep_Behavioral;

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
        exit(1);

	return BDWRep_None;
}

void dut_wrapper_r::InitInstances()
{
    enum dut_wrapper_r::Representation rep =
		dut_wrapper_r::lookupRepresentation( name() );

	esc_log_wrapper_inst( "dut" );
	esc_log_representation( "dut", name(), rep );

	switch ( rep )
	{
		case BDWRep_Gates:
		    dut_cosim0 = new dut_cosim( "dut" );

		    dut_cosim0->clk(clk);
		    dut_cosim0->rst(rst);
		    dut_cosim0->din_1_busy(din_1_busy);
		    dut_cosim0->din_1_vld(din_1_vld);
		    dut_cosim0->din_1_data(din_1_data);
		    dut_cosim0->din_2_busy(din_2_busy);
		    dut_cosim0->din_2_vld(din_2_vld);
		    dut_cosim0->din_2_data(din_2_data);
		    dut_cosim0->dout_busy(dout_busy);
		    dut_cosim0->dout_vld(dout_vld);
		    dut_cosim0->dout_data(dout_data);

			break;
		case BDWRep_RTL_HDL:
		    dut_cosim0 = new dut_cosim( "dut" );

		    dut_cosim0->clk(clk);
		    dut_cosim0->rst(rst);
		    dut_cosim0->din_1_busy(din_1_busy);
		    dut_cosim0->din_1_vld(din_1_vld);
		    dut_cosim0->din_1_data(din_1_data);
		    dut_cosim0->din_2_busy(din_2_busy);
		    dut_cosim0->din_2_vld(din_2_vld);
		    dut_cosim0->din_2_data(din_2_data);
		    dut_cosim0->dout_busy(dout_busy);
		    dut_cosim0->dout_vld(dout_vld);
		    dut_cosim0->dout_data(dout_data);

			break;
        case BDWRep_CYC_HDL:
            if ( dut_cycsim_factory_p )
                dut_cycsim0 = dut_cycsim_factory_p();
            else
            {
                esc_report_error( esc_fatal, "verilator_produced files not available for module dut");
                return;
            }

            esc_report_error( esc_note, " using verilator model for module \"dut\"");

		    dut_cycsim0->clk(clk);
		    dut_cycsim0->rst(rst);
		    dut_cycsim0->din_1_busy(din_1_busy);
		    dut_cycsim0->din_1_vld(din_1_vld);
		    dut_cycsim0->din_1_data(din_1_data);
		    dut_cycsim0->din_2_busy(din_2_busy);
		    dut_cycsim0->din_2_vld(din_2_vld);
		    dut_cycsim0->din_2_data(din_2_data);
		    dut_cycsim0->dout_busy(dout_busy);
		    dut_cycsim0->dout_vld(dout_vld);
		    dut_cycsim0->dout_data(dout_data);

			break;
#if defined(BDW_RTL) || defined(COWARE_RTL_dut)
		case BDWRep_RTL_C:
		    dut_rtl0 = new dut_rtl( "dut" );

		    dut_rtl0->clk(clk);
		    dut_rtl0->rst(rst);
		    dut_rtl0->din_1_busy(din_1_busy);
		    dut_rtl0->din_1_vld(din_1_vld);
		    dut_rtl0->din_1_data(din_1_data);
		    dut_rtl0->din_2_busy(din_2_busy);
		    dut_rtl0->din_2_vld(din_2_vld);
		    dut_rtl0->din_2_data(din_2_data);
		    dut_rtl0->dout_busy(dout_busy);
		    dut_rtl0->dout_vld(dout_vld);
		    dut_rtl0->dout_data(dout_data);


			{
			const char *simConfig = dut_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    dut0 = new dut( "dut" );

		    dut0->clk(clk);
		    dut0->rst(rst);
		    dut0->din_1.busy(din_1_busy);
		    dut0->din_1.vld(din_1_vld);
		    dut0->din_1.data(din_1_data);
		    dut0->din_2.busy(din_2_busy);
		    dut0->din_2.vld(din_2_vld);
		    dut0->din_2.data(din_2_data);
		    dut0->dout.busy(dout_busy);
		    dut0->dout.vld(dout_vld);
		    dut0->dout.data(dout_data);


			{
			const char *simConfig = dut_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
											  "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void dut_wrapper_r::InitThreads()
{
	if ( isBEH() ) 
	{
		
	}
}

void dut_wrapper_r::start_of_simulation()
{

#include <dut_trace.h>

    esc_multiple_writers_warning();
}

void dut_wrapper_r::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void dut_wrapper_r::end_of_simulation()
{
	CloseTrace();
}



void dut_wrapper_r::DeleteInstances()
{
    if (dut0)
    {
        delete dut0;
        dut0 = 0;
    }
    if (dut_cosim0)
    {
        delete dut_cosim0;
        dut_cosim0 = 0;
    }
    if (dut_cycsim0)
    {
        delete dut_cycsim0;
        dut_cycsim0 = 0;
    }
#if defined(BDW_RTL) || defined(COWARE_RTL_dut)
    if (dut_rtl0)
    {
        delete dut_rtl0;
        dut_rtl0 = 0;
    }
#endif
}

#if BDW_WRITEFSDB == 1

inline void esc_open_fsdb_trace( const char *file_name  )
{
#if defined(NC_SYSTEMC) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
    fsdbDumpfile(file_name);
# else
	sc_trace_file *fsdb_file;

	// SystemC suffixes .fsdb to filenames automatically. Make sure
	// that doesn't get tacked onto a filename that already has the suffix.
	if ( strrchr( file_name, '.' ) != NULL )
	{
		char *trunc_file_name = new char[strlen(file_name)+1];
		strcpy( trunc_file_name, file_name );

		fsdb_file = new fsdb_trace_file( trunc_file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );

		delete trunc_file_name;
	}
	else
	{
		fsdb_file = new fsdb_trace_file( file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );
	}
#endif

//
// Novas's SystemC wrapper doesn't have a way to set the time unit as of SystemC 2.1v1.
//
//		((fsdb_trace_file*)fsdb_file)->sc_set_fsdb_time_unit( -12 );
}

inline void esc_close_fsdb_trace()
{
#if ! defined(NC_SYSTEMC) | ! defined(BDW_NCSC_VER) | BDW_NCSC_VER <= 102
	fsdb_trace_file * fsdb_file =
		(fsdb_trace_file *)esc_trace_file( esc_trace_fsdb );

	if ( fsdb_file != NULL )
	{
		fsdb_file->CloseFile();
		delete fsdb_file;
		esc_set_trace_file( NULL, esc_trace_fsdb );
	}
#endif
}

#else

inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}

#endif

#if BDW_USE_SCV && BDW_WRITEFSDB == 1
static scv_tr_db* local_fsdb_scv_db = 0;

inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
	// Start SCV logging to FSDB if there is not already a database setup.
    if (!esc_get_scv_tr_db() && esc_trace_is_enabled(esc_trace_scv) )
	{
		scv_startup();
		scv_tr_fsdb_init();

		char* scv_file_name = new char[strlen(file_name) + 1];
		strcpy( scv_file_name, file_name );
		char* fsdb_suffix = strstr( scv_file_name, ".fsdb" );
		if (fsdb_suffix)
			*fsdb_suffix = 0;
		local_fsdb_scv_db = new scv_tr_db(scv_file_name);

		delete [] scv_file_name;
		esc_set_scv_tr_db(local_fsdb_scv_db);
		scv_tr_db::set_default_db(local_fsdb_scv_db);
		local_fsdb_scv_db->set_recording(true);
	}
}

inline void esc_close_fsdb_scv_trace()
{
    if ( local_fsdb_scv_db && (local_fsdb_scv_db == esc_get_scv_tr_db() ) ) 
	{
		delete local_fsdb_scv_db;
		local_fsdb_scv_db = 0;
		esc_set_scv_tr_db(0);
	}
}
#else 
inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

#endif

class dut_wrapper_fsdb_opener {
public:
	dut_wrapper_fsdb_opener() {
		esc_set_open_fsdb_trace( esc_open_fsdb_trace );
		esc_set_open_fsdb_scv_trace( esc_open_fsdb_scv_trace );
	}
};

static dut_wrapper_fsdb_opener
  dut_wrapper_fsdb_opener_inst;

#else

// Visible to uses of the wrapper outside of the BDW environment.
// Only behavioral SystemC simulation is supported.


// Include the source for the behavioral model so it will be compiled.
#include	"dut.cc"

#define		dut_INTERNAL


#include	"dut_wrap.h"

const char * dut_wrapper::simConfigName()
{
  return "";
}

enum dut_wrapper::Representation dut_wrapper::lookupRepresentation( const char* instName )
{
  return BDWRep_Behavioral;
}

void dut_wrapper::InitInstances( sc_core::sc_module_name  )
{
	dut0 = new dut( "dut" );

	dut0->clk(clk);
	dut0->rst(rst);
	dut0->din_1.busy(din_1.busy);
	dut0->din_1.vld(din_1.vld);
	dut0->din_1.data(din_1.data);
	dut0->din_2.busy(din_2.busy);
	dut0->din_2.vld(din_2.vld);
	dut0->din_2.data(din_2.data);
	dut0->dout.busy(dout.busy);
	dut0->dout.vld(dout.vld);
	dut0->dout.data(dout.data);

}

void dut_wrapper::InitThreads()
{
}

void dut_wrapper::CloseTrace()
{
}

void dut_wrapper::DeleteInstances()
{
    if (dut0)
    {
        delete dut0;
        dut0 = 0;
    }
}

void dut_wrapper::start_of_simulation()
{
}

void dut_wrapper::end_of_simulation()
{
}



inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}


inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

class dut_wrapper_fsdb_opener {
public:
	dut_wrapper_fsdb_opener() {
	}
};

static dut_wrapper_fsdb_opener
  dut_wrapper_fsdb_opener_inst;

#endif

#endif
