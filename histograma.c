//NOME: PETERSON WAGNER KAVA DE CARVALHO - GRR: 20163053

#include <stdlib.h>
#include <stdio.h>
#include "lcrandom.h"

#define SIZE 100

void inicializa_vetor (int *vetor, int size)
{
	//inicializando o vetor de contagem
	for (int i = 0; i < size; ++i)
        vetor[i] = 0;
}

void preenche_vetor (int *vetor, long max)
{
	for (int i = 0; i < max; ++i)
		vetor[ lcrandom() % 100 ] ++; //contando quantas vezes cada valor aleatorio [0..99] foi gerado
}

int busca_maior_valor (int *vetor, int size)
{
	int maior = 0;

	//buscando o valor que foi gerado mais vezes dentro do vetor
    //para usar na regra de 3
	for (int i = 0; i < size; ++i)
		if (vetor[i] > maior)
			maior = vetor[i];

	return maior;
}

void imprimir_histograma (int *vetor, int size, int maior)
{
	//imprimindo histograma simples similar ao do exemplo
	printf ("   0   10   20   30   40   50   60   70   80   90   100\n");
    printf ("   +----+----+----+----+----+----+----+----+----+----+\n");

    for (int i = 0; i < size; ++i)
    {
        if (i<10)
            printf(" ");

        printf ("%d |", i);

        //imprimindo asteriscos para representar cada contagem fazendo regra de 3
        for (int j = 0; j < (size * vetor[i]/maior)/2; ++j)
            printf ("*");

        printf ("\n");
    }
}

int main()
{
    int contagem[SIZE];
    int maior = 0;
    long a, c, m;

    //histograma para valores padrao
    inicializa_vetor (contagem, SIZE);
    preenche_vetor (contagem, 1000000);
    maior = busca_maior_valor (contagem, SIZE);
    printf("Imprimindo histograma para os valores padrao\n");
    imprimir_histograma (contagem, SIZE, maior);

    printf ("\n\n");

    a = 1103515245;
	c = 12345;
	m = 2147483648; //2^31

    //histograma para os outros valores
    lcrandom_parms (a, c, m);
    inicializa_vetor (contagem, SIZE);
    preenche_vetor (contagem, 1000000);
    maior = busca_maior_valor (contagem, SIZE);
    printf("Imprimindo histograma para a = %ld, c = %ld, m = %ld\n", a, c, m);
    imprimir_histograma (contagem, SIZE, maior);

    return 0;
}