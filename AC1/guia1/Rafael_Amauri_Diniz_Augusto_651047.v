/*
	Nome: Rafael Amauri Diniz Augusto 
	Matrícula: 651047
	Guia 01 - Respostas em verilog
 */

module Guia_0101;
	integer entrada = 13;	//Decimal
	//Actions:
	initial
		begin: dec2bin
			
			$display("Guia_0101 - testes");
			$display("Decimal = %d" , entrada);
			$display("Binario = %8b" , entrada);
		end //dec2bin
	
endmodule //Guia_0101

/*
   Guia_0102
 */

module Guia_0102;
   reg [7:0] binario = 8'b0001101;
   //Actions
   initial
      begin: bin2dec
         $display("Guia_0102 - testes");
         $display("Binario = %8b" , binario);
         $display("Decimal = %d" , binario);
      end //bin2dec

endmodule //Guia_0102

/*
   Guia_0103
 */
module Guia_0103;
	integer decimal = 13; //Decimal
	reg [7:0] array = 0; //Para trasnformar em quartenário
	//Actions
	initial
		begin: dec2base;
			$display("Guia_0103 - testes");
			$display("Binario = %8b" , decimal);
			$display("Decimal = %d" , decimal);
			$display("Octal = %o" , decimal);
			$display("Hexadecimal = %h", decimal);
		end //dec2base
	
endmodule //Guia_0103

/*
   Guia_0104
 */

module Guia_0104;
   integer dec = 13;
   reg [7:0] bin = 0;

   initial
      begin: bin2base
         $display("Guia 0104-testes");
         $display("Decimal = %d" , dec);
         $display("Binary = %8b" , bin);
         bin = dec;
         $display("Quartenario = [%2b][%2b][%2b][%2b] = %x %x %x %x" , 
                  bin[7:6] , bin[5:4] , bin[3:2] , bin[1:0] , bin[7:6] , bin[5:4] , bin[3:2] , bin[1:0]);
         $display("Octal = [%2b][%3b][%3b] = %x %x %x" , 
                  bin[7:6] , bin[5:3] , bin[2:0] , bin[7:6] , bin[5:3] , bin[2:0]);
         $display("Hexadecimal = [%4b][%4b] = %x %x" , 
                  bin[7:4] , bin[3:0] , bin[7:4] , bin[3:0]);
      end //bin2base
endmodule //Guia_0104

/*
   Guia 0105
 */

module Guia_0105;
   integer binario = 0;
   reg [0:2][7:0] string = "PUC";

   initial
      begin: asc2base
         $display("Guia_0105 - Testes");
         $display("Palavra = %s" , string);
         $display("Binario = %b %b %b", string[0][7:0],string[1][7:0],string[2][7:0]);
         $display("Decimal = %d %d %d", string[0][7:0],string[1][7:0],string[2][7:0]);
         $display("Octal = %o %o %o", string[0][7:0],string[1][7:0],string[2][7:0]);
         $display("Hexadecimal = %h %h %h", string[0][7:0],string[1][7:0],string[2][7:0]);
   end //asc2base
endmodule //Guia_0105
