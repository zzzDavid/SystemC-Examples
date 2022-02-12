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
* block called "find_max". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/

#if defined(STRATUS_VLG)



#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#include	"find_max_rtl.cc"

#else 

#if defined(BDW_HUB)

#define SC_INCLUDE_DYNAMIC_PROCESSES 1
#include "esc.h"

#if defined(BDW_RTL) || defined(COWARE_RTL_find_max)

#define BDW_AUTO_KNOWN 1 


#undef add_one
#define add_one add_one_wrapper_r

#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#undef find_max
#define find_max find_max_rtl
#	include	"find_max_rtl.cc"
#undef find_max


#undef add_one

#ifdef BDW_PORTS_ONLY
#undef BDW_PORTS_ONLY
#endif



#elif defined(BDW_HOIST) 
#else

#endif
#ifdef BDW_COWARE
#include	"find_max_coware.h"
#else
#include	"find_max_cosim.h"
#endif




// Include the source for the behavioral model so it will be compiled.
#include	"/work/shared/users/phd/nz264/systemc-examples/hierarchy/project/find_max.cc"


#define		find_max_INTERNAL


#include	"find_max_wrap.h"


#define MAX_SIMCONFIG_LENGTH 128

#if BDW_WRITEFSDB == 1

#if (defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
#include "fsdb_nc_mix.h"
#else
#if SYSTEMC_VERSION >= 20120701
#include "fsdb_osci.h"
#else
#include "fsdb_trace_file.h"
#endif
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

const char * find_max_wrapper::simConfigName()
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

enum find_max_wrapper::Representation find_max_wrapper::lookupRepresentation( const char* instName )
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
	err = qbhGetRepresentation(hProj, "find_max", simConfig, instName, &iresult );
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
								 "find_max", simConfig, instName, leaf,  "find_max" );
		}
		return BDWRep_Behavioral;
	}

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
    {
        exit(1);
    }

	return BDWRep_None;
}

void find_max_wrapper::InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10] )
{
    enum find_max_wrapper::Representation rep =
		find_max_wrapper::lookupRepresentation( name() );

	esc_log_wrapper_inst( "find_max" );
	esc_log_representation( "find_max", name(), rep );

	

	switch ( rep )
	{
		case BDWRep_Gates:
		    find_max_cosim0 = new find_max_cosim( "find_max" );

		    find_max_cosim0->clk(clk);
		    find_max_cosim0->rst(rst);
		    find_max_cosim0->find_max_x_busy(find_max_x.busy);
		    find_max_cosim0->find_max_x_vld(find_max_x.vld);
		    find_max_cosim0->find_max_x_data(find_max_x.data);
		    find_max_cosim0->find_max_return_busy(find_max_return.busy);
		    find_max_cosim0->find_max_return_vld(find_max_return.vld);
		    find_max_cosim0->find_max_return_data(find_max_return.data);
		    find_max_cosim0->add_one_x_out_busy(add_one_x_out.busy);
		    find_max_cosim0->add_one_x_out_vld(add_one_x_out.vld);
		    find_max_cosim0->add_one_x_out_data(add_one_x_out.data);
		    find_max_cosim0->add_one_return_in_busy(add_one_return_in.busy);
		    find_max_cosim0->add_one_return_in_vld(add_one_return_in.vld);
		    find_max_cosim0->add_one_return_in_data(add_one_return_in.data);

			break;
		case BDWRep_RTL_HDL:
		    find_max_cosim0 = new find_max_cosim( "find_max" );

		    find_max_cosim0->clk(clk);
		    find_max_cosim0->rst(rst);
		    find_max_cosim0->find_max_x_busy(find_max_x.busy);
		    find_max_cosim0->find_max_x_vld(find_max_x.vld);
		    find_max_cosim0->find_max_x_data(find_max_x.data);
		    find_max_cosim0->find_max_return_busy(find_max_return.busy);
		    find_max_cosim0->find_max_return_vld(find_max_return.vld);
		    find_max_cosim0->find_max_return_data(find_max_return.data);
		    find_max_cosim0->add_one_x_out_busy(add_one_x_out.busy);
		    find_max_cosim0->add_one_x_out_vld(add_one_x_out.vld);
		    find_max_cosim0->add_one_x_out_data(add_one_x_out.data);
		    find_max_cosim0->add_one_return_in_busy(add_one_return_in.busy);
		    find_max_cosim0->add_one_return_in_vld(add_one_return_in.vld);
		    find_max_cosim0->add_one_return_in_data(add_one_return_in.data);

			break;
#if defined(BDW_RTL) || defined(COWARE_RTL_find_max)
		case BDWRep_RTL_C:
		    find_max_rtl0 = new find_max_rtl( "find_max" );

		    find_max_rtl0->clk(clk);
		    find_max_rtl0->rst(rst);
		    find_max_rtl0->find_max_x_busy(find_max_x.busy);
		    find_max_rtl0->find_max_x_vld(find_max_x.vld);
		    find_max_rtl0->find_max_x_data(find_max_x.data);
		    find_max_rtl0->find_max_return_busy(find_max_return.busy);
		    find_max_rtl0->find_max_return_vld(find_max_return.vld);
		    find_max_rtl0->find_max_return_data(find_max_return.data);
		    find_max_rtl0->add_one_x_out_busy(add_one_x_out.busy);
		    find_max_rtl0->add_one_x_out_vld(add_one_x_out.vld);
		    find_max_rtl0->add_one_x_out_data(add_one_x_out.data);
		    find_max_rtl0->add_one_return_in_busy(add_one_return_in.busy);
		    find_max_rtl0->add_one_return_in_vld(add_one_return_in.vld);
		    find_max_rtl0->add_one_return_in_data(add_one_return_in.data);


			{
			const char *simConfig = find_max_wrapper::simConfigName();
			
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
		    find_max0 = new find_max( "find_max", _A, _B );

		    find_max0->clk(clk);
		    find_max0->rst(rst);
		    find_max0->find_max_x.busy(find_max_x.busy);
		    find_max0->find_max_x.vld(find_max_x.vld);
		    find_max0->find_max_x.data(find_max_x.data);
		    find_max0->find_max_return.busy(find_max_return.busy);
		    find_max0->find_max_return.vld(find_max_return.vld);
		    find_max0->find_max_return.data(find_max_return.data);
		    find_max0->add_one_x_out.busy(add_one_x_out.busy);
		    find_max0->add_one_x_out.vld(add_one_x_out.vld);
		    find_max0->add_one_x_out.data(add_one_x_out.data);
		    find_max0->add_one_return_in.busy(add_one_return_in.busy);
		    find_max0->add_one_return_in.vld(add_one_return_in.vld);
		    find_max0->add_one_return_in.data(add_one_return_in.data);


			{
			const char *simConfig = find_max_wrapper::simConfigName();
			
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

void find_max_wrapper::InitThreads()
{
	if ( !isBEH() )
	{
		
	}
}

void find_max_wrapper::start_of_simulation()
{

#include <find_max_trace.h>

    esc_multiple_writers_warning();
}

void find_max_wrapper::CloseTrace()
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

void find_max_wrapper::end_of_simulation()
{
	CloseTrace();
}



void find_max_wrapper::DeleteInstances()
{
    if (find_max0)
    {
        delete find_max0;
        find_max0 = 0;
    }
    if (find_max_cosim0)
    {
        delete find_max_cosim0;
        find_max_cosim0 = 0;
    }
  #if defined(BDW_RTL) || defined(COWARE_RTL_find_max)
    if (find_max_rtl0)
    {
        delete find_max_rtl0;
        find_max_rtl0 = 0;
    }
#endif
}

// The following threads are used to connect RTL ports to the actual
// structured ports

const char * find_max_wrapper_r::simConfigName()
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

enum find_max_wrapper_r::Representation find_max_wrapper_r::lookupRepresentation( const char* instName )
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
	err = qbhGetRepresentation(hProj, "find_max", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound )
		return BDWRep_Behavioral;

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
    {
        exit(1);
    }

	return BDWRep_None;
}

void find_max_wrapper_r::InitInstances()
{
    enum find_max_wrapper_r::Representation rep =
		find_max_wrapper_r::lookupRepresentation( name() );

	esc_log_wrapper_inst( "find_max" );
	esc_log_representation( "find_max", name(), rep );

	switch ( rep )
	{
		case BDWRep_Gates:
		    find_max_cosim0 = new find_max_cosim( "find_max" );

		    find_max_cosim0->clk(clk);
		    find_max_cosim0->rst(rst);
		    find_max_cosim0->find_max_x_busy(find_max_x_busy);
		    find_max_cosim0->find_max_x_vld(find_max_x_vld);
		    find_max_cosim0->find_max_x_data(find_max_x_data);
		    find_max_cosim0->find_max_return_busy(find_max_return_busy);
		    find_max_cosim0->find_max_return_vld(find_max_return_vld);
		    find_max_cosim0->find_max_return_data(find_max_return_data);
		    find_max_cosim0->add_one_x_out_busy(add_one_x_out_busy);
		    find_max_cosim0->add_one_x_out_vld(add_one_x_out_vld);
		    find_max_cosim0->add_one_x_out_data(add_one_x_out_data);
		    find_max_cosim0->add_one_return_in_busy(add_one_return_in_busy);
		    find_max_cosim0->add_one_return_in_vld(add_one_return_in_vld);
		    find_max_cosim0->add_one_return_in_data(add_one_return_in_data);

			break;
		case BDWRep_RTL_HDL:
		    find_max_cosim0 = new find_max_cosim( "find_max" );

		    find_max_cosim0->clk(clk);
		    find_max_cosim0->rst(rst);
		    find_max_cosim0->find_max_x_busy(find_max_x_busy);
		    find_max_cosim0->find_max_x_vld(find_max_x_vld);
		    find_max_cosim0->find_max_x_data(find_max_x_data);
		    find_max_cosim0->find_max_return_busy(find_max_return_busy);
		    find_max_cosim0->find_max_return_vld(find_max_return_vld);
		    find_max_cosim0->find_max_return_data(find_max_return_data);
		    find_max_cosim0->add_one_x_out_busy(add_one_x_out_busy);
		    find_max_cosim0->add_one_x_out_vld(add_one_x_out_vld);
		    find_max_cosim0->add_one_x_out_data(add_one_x_out_data);
		    find_max_cosim0->add_one_return_in_busy(add_one_return_in_busy);
		    find_max_cosim0->add_one_return_in_vld(add_one_return_in_vld);
		    find_max_cosim0->add_one_return_in_data(add_one_return_in_data);

			break;
#if defined(BDW_RTL) || defined(COWARE_RTL_find_max)
		case BDWRep_RTL_C:
		    find_max_rtl0 = new find_max_rtl( "find_max" );

		    find_max_rtl0->clk(clk);
		    find_max_rtl0->rst(rst);
		    find_max_rtl0->find_max_x_busy(find_max_x_busy);
		    find_max_rtl0->find_max_x_vld(find_max_x_vld);
		    find_max_rtl0->find_max_x_data(find_max_x_data);
		    find_max_rtl0->find_max_return_busy(find_max_return_busy);
		    find_max_rtl0->find_max_return_vld(find_max_return_vld);
		    find_max_rtl0->find_max_return_data(find_max_return_data);
		    find_max_rtl0->add_one_x_out_busy(add_one_x_out_busy);
		    find_max_rtl0->add_one_x_out_vld(add_one_x_out_vld);
		    find_max_rtl0->add_one_x_out_data(add_one_x_out_data);
		    find_max_rtl0->add_one_return_in_busy(add_one_return_in_busy);
		    find_max_rtl0->add_one_return_in_vld(add_one_return_in_vld);
		    find_max_rtl0->add_one_return_in_data(add_one_return_in_data);


			{
			const char *simConfig = find_max_wrapper::simConfigName();
			
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
            esc_report_error( esc_fatal, "Cannot simulate module '%s' as BEH inside RTL_C parent because it has extra constructor parameters\n", "find_max");

			{
			const char *simConfig = find_max_wrapper::simConfigName();
			
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

void find_max_wrapper_r::InitThreads()
{
	if ( isBEH() ) 
	{
		
	}
}

void find_max_wrapper_r::start_of_simulation()
{

#include <find_max_trace.h>

    esc_multiple_writers_warning();
}

void find_max_wrapper_r::CloseTrace()
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

void find_max_wrapper_r::end_of_simulation()
{
	CloseTrace();
}



void find_max_wrapper_r::DeleteInstances()
{
    if (find_max0)
    {
        delete find_max0;
        find_max0 = 0;
    }
    if (find_max_cosim0)
    {
        delete find_max_cosim0;
        find_max_cosim0 = 0;
    }
  #if defined(BDW_RTL) || defined(COWARE_RTL_find_max)
    if (find_max_rtl0)
    {
        delete find_max_rtl0;
        find_max_rtl0 = 0;
    }
#endif
}

#if BDW_WRITEFSDB == 1

inline void esc_open_fsdb_trace( const char *file_name  )
{
	sc_trace_file *fsdb_file;
#if ( (defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102 ) || SYSTEMC_VERSION >= 20120701
    fsdbDumpfile(file_name);
    esc_set_trace_file( fsdb_file, esc_trace_fsdb );
# else

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
#if ! (((defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) &&  defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102) || SYSTEMC_VERSION >= 20120701)
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

class find_max_wrapper_fsdb_opener {
public:
	find_max_wrapper_fsdb_opener() {
		esc_set_open_fsdb_trace( esc_open_fsdb_trace );
		esc_set_open_fsdb_scv_trace( esc_open_fsdb_scv_trace );
	}
};

static find_max_wrapper_fsdb_opener
  find_max_wrapper_fsdb_opener_inst;

#else

// Visible to uses of the wrapper outside of the BDW environment.
// Only behavioral SystemC simulation is supported.


// Include the source for the behavioral model so it will be compiled.
#include	"/work/shared/users/phd/nz264/systemc-examples/hierarchy/project/find_max.cc"

#define		find_max_INTERNAL


#include	"find_max_wrap.h"

const char * find_max_wrapper::simConfigName()
{
  return "";
}

enum find_max_wrapper::Representation find_max_wrapper::lookupRepresentation( const char* instName )
{
  return BDWRep_Behavioral;
}

void find_max_wrapper::InitInstances( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10] )
{
	find_max0 = new find_max( "find_max", _A, _B );

	find_max0->clk(clk);
	find_max0->rst(rst);
	find_max0->find_max_x.busy(find_max_x.busy);
	find_max0->find_max_x.vld(find_max_x.vld);
	find_max0->find_max_x.data(find_max_x.data);
	find_max0->find_max_return.busy(find_max_return.busy);
	find_max0->find_max_return.vld(find_max_return.vld);
	find_max0->find_max_return.data(find_max_return.data);
	find_max0->add_one_x_out.busy(add_one_x_out.busy);
	find_max0->add_one_x_out.vld(add_one_x_out.vld);
	find_max0->add_one_x_out.data(add_one_x_out.data);
	find_max0->add_one_return_in.busy(add_one_return_in.busy);
	find_max0->add_one_return_in.vld(add_one_return_in.vld);
	find_max0->add_one_return_in.data(add_one_return_in.data);

}

void find_max_wrapper::InitThreads()
{
}

void find_max_wrapper::CloseTrace()
{
}

void find_max_wrapper::DeleteInstances()
{
    if (find_max0)
    {
        delete find_max0;
        find_max0 = 0;
    }
}

void find_max_wrapper::start_of_simulation()
{
}

void find_max_wrapper::end_of_simulation()
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

class find_max_wrapper_fsdb_opener {
public:
	find_max_wrapper_fsdb_opener() {
	}
};

static find_max_wrapper_fsdb_opener
  find_max_wrapper_fsdb_opener_inst;

#endif

#endif
