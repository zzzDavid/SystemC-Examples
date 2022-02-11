#ifdef ioConfig_TLM
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_fsdb );
		}
	}
#endif

#ifdef ioConfig_PIN
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_fsdb );
		}
	}
#endif

