/*
 *		Nome: André Lucas Ribeiro Costa
 *		Matrícula: 666400
 * 	Arquivo verilog referente ao Guia 08 de Circuitos Sequenciais.
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
//--------------------Teste de Clock 02-------------------------------
//--------------------------------------------------------------------
module exemplo_0902;
	wire clock0;
	clock CLOCK1(clock0);
	reg p;
	wire p1,t1;
	pulse PULSE1(p1,clock0);
	trigger TRIGGER1(t1,p,clock0);
	initial begin
		p = 1'b0;
	end
	
	initial begin
		$dumpfile("Exemplo_0802.vcd");
		$dumpvars(1,clock0,p1,p,t1);
		
		#060	p = 1'b1;
		#120	p = 1'b0;
		#180	p = 1'b1;
		#240	p = 1'b0;
		#300	p = 1'b1;
		#360	p = 1'b0;
		#376 	$finish;
	end
endmodule //exemplo_0902 */
