/** 
 ** Aluno: Rafael Amauri Diniz Augusto 
 ** Matricula: 651047 
 */

module halfsum(a,b,s0,s1);
	input a;
	input b;
	output s0;
	output s1;
	reg s0;
	reg s1;
	wire nota;
	wire notb;
	wire andb1;
	wire andb2;
	not NOT1(nota,a);
	not NOT2(notb,b);
	and AND1(s1,a,b);
	and AND2(andb1,nota,b);
	and AND3(andb2,a,notb);
	or  OR(s1,andb1,andb2);
endmodule //halfsum

module fulladder(a,b,c,s0,s1);
	input a,b,c;
	output s0,s1;
	reg s0,s1;
	wire so1,so2,so3,so4;
	halfsum SOMA1(a,b,so1,so2);	
	halfsum SOMA2(c,so1,s0,so3);
	halfsum SOMA3(so2,so1,so4,s1);
endmodule //fulladder

module fulladder5bits(a,b,s0,s1);
	input[5:0]  a,b;
	output[5:0] s0;
	output s1;
	reg[5:0] s0;
	reg s1;
	wire sum1,sum2,sum3,sum4,sum5;
	
	halfsum   SOMA1(a[0],b[0],s0[0],sum1);
	fulladder SOMA2(a[1],b[1],sum1,s0[1],sum2);
	fulladder SOMA3(a[2],b[2],sum2,so[2],sum3);
	fulladder SOMA4(a[3],b[3],sum3,so[3],sum4);
	fulladder SOMA5(a[4],b[4],sum4,so[4],s1);
endmodule //fuladder5bits

module halfsub(a,b,s0,s1);
	input a,b;
	output s0,s1;
	reg s0,s1;
	wire nota,notb,and1,and2;
	
	not NOT1(nota,a);
	not NOT2(notb,b);
	and AND1(and1,nota,b);
	and AND2(and2,a,notb);
	s1 = and1;
	or OR(s0,and1,and2);
endmodule //halfsub

module fullsub(a,b,c,s0,s1);
	input a,b,c;
	output s0,s1;
	reg s0,s1;
	wire sub1,sub2,sub3;
	
	halfsub SUB1(a,b,sub1,sub2);
	halfsub SUB2(sub1,c,s0,sub3);
	or      OR(s1,sub2,sub1);
endmodule //fullsub

module fullsub5bits(a,b,s0,s1);
	input[5:0] a,b;
	output[5:0] s0;
	output s1;
	reg[5:0] s0;
	reg s1;
	wire sub1,sub2,sub3,sub4;
	halfsub SUB1(a[0],b[0],s0[0],sub1);
	halfsub SUB2(a[1],b[1],sub1,s0[1],sub2);
	halfsub SUB3(a[2],b[2],sub2,s0[2],sub3);
	halfsub SUB4(a[3],b[3],sub3,s0[3],sub4);
	halfsub SUB5(a[4],b[4],sub4,s0[4],s1);
endmodule //fullsub4bits

module complemento1(a,s);
	input[5:0] a;
	output s;
	reg[5:0] s;
	not NOT1(s[0],a[0]);
	not NOT2(s[1],a[1]);
	not NOT3(s[2],a[2]);
	not NOT4(s[3],a[3]);
	not NOT5(s[4],a[4]);
endmodule //complemento1

module complemento2(a,s);
	input[5:0] a;
	output s;
	reg[5:0] s;
	wire[5:0] c1,soma;
	wire vaium;
	soma = 5'b0001;
	complemento1 COMPLEMENTO1(a,c1);
	fulladder5bits SOMA(a,b,s,vaium);
endmodule //complemento2
