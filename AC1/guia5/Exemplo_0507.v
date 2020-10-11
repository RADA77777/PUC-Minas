//Nome: Rafael Amauri Diniz Augusto
//Matrícula: 651047

module nandModule(input a,input b,output s);
	nand nandA(s,a,b);
endmodule //nandModule

module norModule(input a,input b,output s);
	nor norA(s,a,b);
endmodule //norModule

module orComNand(input a,input b,output s);
	wire not_a;
	wire not_b;
	nandModule moduloNotA1(a,a,not_a);
	nandModule moduloNotA2(b,b,not_b);
	nandModule moduloNand(not_a,not_b,s);
endmodule //orComNand

module andComNand(input a,input b,output s);
	wire nandA;
	nandModule moduloNand(a,b,nandA);
	nandModule moduloNot(nandA,nandA,s);
endmodule //andComNand

module orComNor(input a,input b, output s);
	wire norA;
	norModule moduleNor(a,b,norA);
	norModule moduleNot(norA,norA,s);
endmodule //orComNor	

module andComNor(input a,input b,output s);
	wire not_a;
	wire not_b;
	norModule moduleNot1(a,a,not_a);
	norModule moduleNot2(b,b,not_b);
	norModule moduleResposta(not_a,not_b,s);
endmodule //andComNor

module notComNand(input a,output s);
	nandModule moduleNot(a,a,s);
endmodule //notComNand

module notComNor(input a,output s);
	norModule moduleNot(a,a,s);
endmodule //notComNor

module xnorComNand(input a,input b,output s);
	wire notA,notB,andA,andB, xorNand;
	notComNand not_A1(a,notA);
	notComNand not_A2(b,notB);
	andComNand and_A1(notA,b,andA);
	andComNand and_A2(a,notB,andB);
	orComNand xor_A1(andA,andB,xorNand);
	notComNand xnor_A1(xorNand, s);
endmodule //xorComNand

module xnorComNor(input a,input b,output s);
	wire notA,notB,andA,andB,orA;
	notComNor notA1(a,notA);
	notComNor notA2(b,notB);
	andComNor andA1(notA,b,andA);
	andComNor andA2(a,notB,andB);
	orComNor orA1(andA,andB,orA);
	notComNor notSolution(orA,s);
endmodule //xnorComNor

module testeOrComNand;
//=========================================================================================================================================
//Definição de dados:
	reg x;
	reg y;
	wire xnorNand;

	xnorComNand module5(x,y,xnorNand);

//Fim da definição de dados.
//=========================================================================================================================================
initial
begin : teste_0507
   $display("Exemplo_0507 - x,y,z");
   $display("Teste de modulo");
   $display("x y a");
   $monitor("%b %b %b",x,y,xnorNand);
   x = 1'b0; y = 1'b0;
#1 x = 1'b0; y = 1'b1;
#1 x = 1'b1; y = 1'b0;
#1 x = 1'b1; y = 1'b1;
end
endmodule


