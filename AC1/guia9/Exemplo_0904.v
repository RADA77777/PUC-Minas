`include "clock.v"

module pulseMeio(clock,signal);
	input clock;
	output signal;
	reg signal;
	always @ (posedge clock) begin
			signal = 1'b1;
		#6 signal = 1'b0;
		#6 signal = 1'b1;
		#6 signal = 1'b0;
	end
endmodule //pulseMeio

module main;
	wire clock;
	clock clk(clock);
	wire p;
	pulseMeio PULSE(clock,p);
	initial begin
		$dumpfile("Exemplo_0804.vcd");
		$dumpvars;
		#120 $finish;
	end
endmodule //main
