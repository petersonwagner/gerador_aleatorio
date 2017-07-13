//NOME: PETERSON WAGNER KAVA DE CARVALHO - GRR: 20163053

#include <stdlib.h>
#include <stdio.h>
#include "lcrandom.h"

short* aloca_vetor (long size)
{
	short *ptr;
	ptr = ((short*) malloc (sizeof(short) * size)); //alocando um vetor de inteiros para contagem dos valores gerados

	if (ptr == NULL) //caso a alocação não tenha ocorrido
	{
		printf("ALOCACAO NAO OCORREU\n");
		abort ();
	}

	for (long i = 0; i < size; ++i) //inicializando vetor alocado
		ptr[i] = 0;

	return ptr;
}

long periodo (short *vetor)
{
	long i, periodo = 0;

	//calcula o periodo, fazendo periodo += 1 ate que
	//algum valor seja gerado mais de uma vez, verificando pelo vetor de contagem
	do
	{
		i = lcrandom();
		vetor[i] ++;
		periodo ++;
	} while (vetor[i] < 2);

    //retorna periodo-1 para nao contabilizar o numero repetido duas vezes
	return periodo-1;
}

int main(int argc, char const *argv[])
{
	long a, c, m;
	short *contagem = NULL;
	
	//periodo para valores padrao
	m = lcrandom_max() + 1;  //descobrindo o valor de m
	contagem = aloca_vetor (m-1);  //aloca vetor de tamanho m-1 no endereço de contagem[0]
	printf("\nPeriodo para valores padrao: %ld\n", periodo(contagem));  //imprime o periodo calculado

	//libera a memoria alocada
	free (contagem);
	contagem = NULL;

	//novos valores para os parametros
    a = 1103515245;
	c = 12345;
	m = 2147483648; //2^31

	//periodo para os outros valores
	printf("\nO calculo do periodo para os proximos parametros deve demorar 1-2 minutos\n");
	lcrandom_parms (a, c, m);  //redefine os parametros de lcrandom
	contagem = aloca_vetor (m-1);  //aloca vetor de tamanho m-1 no endereço de contagem[0]
	printf("Periodo para a = %ld, c = %ld, m = %ld: %ld\n", a, c, m, periodo(contagem));  //imprime o periodo calculado

	return 0;
}