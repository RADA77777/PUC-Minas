//Matrícula: 651047
//Nome: Rafael Amauri Diniz Augusto

module mux2x1(output s,input a,input b,input select);
	wire notSelect,sa,sb;
	not NOT(notSelect,select);
	and AND0(sa,a,notSelect);
	and AND1(sb,b,select);
	or OR(s,sa,sb);
endmodule //mux2x1

module mux4x1(output s,input a,input b,
				  input c,input d,input select1,
				  input select2);
	wire mux1,mux2;
	mux2x1 MUX1(mux1,a,b,select1);
	mux2x1 MUX2(mux2,c,d,select1);
	mux2x1 MUX3(s,mux1,mux2,select2);
endmodule //mux4x1

module mex8x1(output s,input a,input b, input c,
				  input d,input e,input f, input g,
				  input h,input select1,input select2,
				  input selecet3);
	wire mux1,mux2;
	mux4x1 MUX1(mux1,a,b,c,d,select1,select2);
	mux4x1 MUX2(mux2,e,f,g,h,select1,select2);
	mux2x1 MUX3(s,mux1,mux2,select3);
endmodule //mux8x1
//========================================
//And e Nand Paralelos
//========================================
//Exemplo_0701
//========================================
module e701(output s1, output s2,
				input a,input b);
	and AND(s1,a,b);
    nand NAND(s2,a,b);
endmodule //e701

//=========================================
//Nor e Or com Mux
//=========================================
//Exemplo_0702
//=========================================
module e702(output s,input a,input b, input selector);
	wire norS,orS,mux;
	nor NOR(andS,a,b);
	or OR(orS,a,b);
	mux2x1 MUX(s,norS,orS,selector);
endmodule //e702

//======================================================
//And/Nand/Or/Nor com MUX
//======================================================
//Exemplo_0703
//======================================================
module e703(output s,input a,input b,input selector1,input selector2);
	wire ands, nands, ors, nors;
	and AND(ands,a,b);
	nand NAND(nands,a,b);
	or OR(ors,a,b);
	nor NOR(nors,a,b);
	mux4x1(s,ands,nands,ors,nors,selector1,selector2);
endmodule //e703

//=========================================================================
//Xor,Xnor,Or,Nor com MUX
//=========================================================================
//Exemplo_0704
//=========================================================================
module e704(output s,input a,input b,input select1,input selecet2);
	wire xors,xnors,ors,nors;
	xor XOR(xors,a,b);
	xnor XNOR(xnors,a,b);
	or OR(ors,a,b);
	nor NOR(nors,a,b);
	mux4x1(s,xors,xnors,ors,nors,select1,select2);
endmodule //e704

//==========================================================================
//FULL LU
//==========================================================================
//Exemplo_0705
//==========================================================================
module e705(output s,input a,input b,input select1,
				input select2,input select3);
	wire nota,notb,ands,ors,nands,nors,xors,xnors;
	not NOTA(nota,a);
	not NOTB(notb,b);
	and ANDS(ands,a,b);
	or OR(ors,a,b);
	nand NAND(nands,a,b);
	nor NORS(nors,a,b);
	xor XORS(xors,a,b);
	xnor XNORS(xnors,a,b);
	mux8x1 MUX8X1(s,nota,notb,ands,ors,nands,nors,xors,xnors,select1,select2,select3);
endmodule //e705
