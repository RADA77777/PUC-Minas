/*
 *		Nome: André Lucas Ribeiro Costa
 *		Matrícula: 666400
 * 	Arquivo verilog referente ao Guia 09 de Circuitos Sequenciais.
 */

module clock(output clk);
	reg clk;
	
	initial
	begin
		clk = 1'b0;
	end
	
	always
	begin
		#12 clk = ~clk;
	end

endmodule //clock;

module pulse(signal, clock);
	input clock;
	output signal;
	reg signal;
	
	always @ (clock) begin
			signal = 1'b1;
		#3 signal = 1'b0;
		#3 signal = 1'b1;
		#3 signal = 1'b0;	
	end
endmodule //pulse

module trigger(signal,on,clock);
	input on,clock;
	output signal;
	reg signal;
	
	always @(posedge clock & on) begin
		#60	signal = 1'b1;
		#60	signal = 1'b0;
	end
endmodule //trigger

//--------------------------------------------------------------------
//--------------------Teste de Clock 01-------------------------------
//--------------------------------------------------------------------
module exemplo_0901;
	wire clk;
	clock CLK1(clk);
	
	initial begin
		$dumpfile("Exemplo_0801.vcd");
		$dumpvars;
		#120 $finish;
	end
endmodule //exemplo_0901
