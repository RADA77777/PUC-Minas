//Biblioteca que contem todos os tipos de memória necessarias para o funcionamento do programa
//solicitado em Verilog do Guia 13.

module dff(q,qnot,d,clk);
	output q,qnot;
	input d,clk;
	reg q,qnot;

	always @(posedge clk) begin
		q <= d; 
		qnot < ~d;
	end

endmodule dff
