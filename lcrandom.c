//NOME: PETERSON WAGNER KAVA DE CARVALHO - GRR: 20163053

long x = 0;
long a = 40692;
long c = 127;
long m = 10000000;
 
long lcrandom ()
{
    x = (a * x + c) % m;
    return x; //retornando o calculo do proximo valor gerado
}
 
void lcrandom_seed (long s)
{
    x = s; //a seed da expressao usada aqui recebe uma nova seed de quem chamou esta funcao
}
 
long lcrandom_max ()
{
    return (m-1); //retorna o valor maximo que a expressao pode gerar
}
 
void lcrandom_parms (long A, long C, long M)
{
	//os parametros sao atualizados com os valores passados por quem chamou esta funcao
    a = A;
    c = C;
    m = M;
}