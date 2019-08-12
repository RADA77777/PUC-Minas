module main();

reg [71:0]x = "PUC-Minas"; //Trocar esse valor para obter o que deseja. Trocar a string por outra de ate 8 caracteres
integer i;
initial
  begin
	$display("%s em hex vale %h %h %h %h %h %h %h %h %h",x, x[71:64], x[63:56], x[55:48], x[47:40], x[39:32], x[31:24] , x[23:16],  x[15:8], x[7:0]);
    	$finish ;
   end

endmodule

