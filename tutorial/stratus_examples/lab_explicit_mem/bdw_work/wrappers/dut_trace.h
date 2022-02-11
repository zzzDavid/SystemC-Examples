	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->din.busy, ( std::string(name()) + std::string( ".dut.din.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->din.vld, ( std::string(name()) + std::string( ".dut.din.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->din.data, ( std::string(name()) + std::string( ".dut.din.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->dout.busy, ( std::string(name()) + std::string( ".dut.dout.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->dout.vld, ( std::string(name()) + std::string( ".dut.dout.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->dout.data, ( std::string(name()) + std::string( ".dut.dout.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->mem.WE0, ( std::string(name()) + std::string( ".dut.mem.WE0" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->mem.DIN0, ( std::string(name()) + std::string( ".dut.mem.DIN0" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->mem.DOUT0, ( std::string(name()) + std::string( ".dut.mem.DOUT0" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->mem.A0, ( std::string(name()) + std::string( ".dut.mem.A0" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &dut0->mem.REQ0, ( std::string(name()) + std::string( ".dut.mem.REQ0" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( dut0 != NULL ) {
			esc_trace_signal( &dut0->clk, ( std::string(name()) + std::string( ".dut.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->rst, ( std::string(name()) + std::string( ".dut.rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->din.busy, ( std::string(name()) + std::string( ".dut.din.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->din.vld, ( std::string(name()) + std::string( ".dut.din.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->din.data, ( std::string(name()) + std::string( ".dut.din.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->dout.busy, ( std::string(name()) + std::string( ".dut.dout.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->dout.vld, ( std::string(name()) + std::string( ".dut.dout.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->dout.data, ( std::string(name()) + std::string( ".dut.dout.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->mem.WE0, ( std::string(name()) + std::string( ".dut.mem.WE0" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->mem.DIN0, ( std::string(name()) + std::string( ".dut.mem.DIN0" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->mem.DOUT0, ( std::string(name()) + std::string( ".dut.mem.DOUT0" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->mem.A0, ( std::string(name()) + std::string( ".dut.mem.A0" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &dut0->mem.REQ0, ( std::string(name()) + std::string( ".dut.mem.REQ0" ) ).c_str(), esc_trace_fsdb );
		}
	}
