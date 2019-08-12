module main();

reg [7:0]x = 8'b110011; //Trocar esse valor para obter o que deseja. Inserir numeros de 8 bits no maximo

initial
  begin
    $display("%b na base 10 vale %d", x, x);
    $display("%b na base 4 vale %d%d%d%d", x, x[7:6], x[5:4], x[3:2], x[1:0]);
    $display("%b na base 8 vale %d%d%d", x, x[7:6], x[5:3], x[2:0]);
    $display("%b na base 16 vale %h", x, x);
    $finish ;
   end

endmodule
