	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->finish, ( std::string(name()) + std::string( ".dut.finish" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->find_max_x_out.busy, ( std::string(name()) + std::string( ".dut.find_max_x_out.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->find_max_x_out.vld, ( std::string(name()) + std::string( ".dut.find_max_x_out.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->find_max_x_out.data, ( std::string(name()) + std::string( ".dut.find_max_x_out.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->find_max_return_in.busy, ( std::string(name()) + std::string( ".dut.find_max_return_in.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->find_max_return_in.vld, ( std::string(name()) + std::string( ".dut.find_max_return_in.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->find_max_return_in.data, ( std::string(name()) + std::string( ".dut.find_max_return_in.data" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->finish, ( std::string(name()) + std::string( ".dut.finish" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->find_max_x_out.busy, ( std::string(name()) + std::string( ".dut.find_max_x_out.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->find_max_x_out.vld, ( std::string(name()) + std::string( ".dut.find_max_x_out.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->find_max_x_out.data, ( std::string(name()) + std::string( ".dut.find_max_x_out.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->find_max_return_in.busy, ( std::string(name()) + std::string( ".dut.find_max_return_in.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->find_max_return_in.vld, ( std::string(name()) + std::string( ".dut.find_max_return_in.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->find_max_return_in.data, ( std::string(name()) + std::string( ".dut.find_max_return_in.data" ) ).c_str(), esc_trace_fsdb );
		}
	}
