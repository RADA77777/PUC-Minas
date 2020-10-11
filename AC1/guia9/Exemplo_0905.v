`include "clock.v"

module tercoPulse(clock,sinal);
	input clock;
	output sinal;
	reg sinal;
	
	always @ (posedge clock) begin
		sinal = 1'b1;
		#4 sinal = 1'b0;
		#4 sinal = 1'b1;
		#4 sinal = 1'b0;
        #4 sinal = 1'b1;
		#4 sinal = 1'b0;
		#4 sinal = 1'b1;
        #4 sinal = 1'b0;
	end
endmodule //quartoPulse

module main;
	wire clock;
	clock CLOCK(clock);
	wire qp;
	tercoPulse UMTERCODOCLOCK(clock,qp);
	initial begin
		$dumpfile("Exemplo_0805.vcd");
		$dumpvars(1,qp,clock);
		#120 $finish;
	end
endmodule //main
