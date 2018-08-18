# gerador_aleatorio - Trabalho de Oficina de Computação (Prof. Carlos Maziero)
# Especificação

Números aleatórios são muito importantes em várias áreas da informática, como jogos, simulações e na geração de chaves criptográficas. Um gerador de números pseudoaleatórios (PRNG - Pseudo Random Number Generator) é um algoritmo que gera uma sequência de valores aparentemente aleatórios. A sequência de números gerada por um PRNG não é realmente aleatória, porque pode ser reproduzida caso seja usado o mesmo valor inicial, usualmente chamado de “semente” (seed).1)

Uma das abordagens mais simples para a geração de números pseudoaleatórios são os geradores congruentes lineares (LCG), que são definidos através da seguinte fórmula:
> xi+1 = (A · xi + C) mod M

onde “x0” é o valor inicial (semente), A e C são parâmetros inteiros, M é o tamanho do espaço de valores aleatórios possíveis e “mod” é o resto da divisão inteira.


Por exemplo, escolhendo-se A=40692, C=127, M=10000000 e x0=0, será gerada a seguinte sequência de números pseudoaleatórios:

```
x0 = 0
x1 = 127
x2 = 5168011
x3 = 6703739
x4 = 8547515
x5 = 5480507
x6 = 2790971
x7 = 192059
x8 = 5264955
x9 = 1548987
...
```

## a) Implementação da biblioteca
Construa uma biblioteca LC-Random para gerar números inteiros pseudoaleatórios usando o algoritmo de congruência linear; a interface dessa biblioteca é definida pelo seguinte arquivo de cabeçalho (que não deve ser alterado):

### lcrandom.h 
```
#ifndef __LCRANDOM__
#define __LCRANDOM__
 
// calcula e devolve um valor pseudoaleatório
unsigned long lcrandom () ;
 
// define o valor inicial (semente) da sequência de aleatórios
// (inicialmente zero (0) por default
void lcrandom_seed (unsigned long s) ;
 
// informa o valor máximo que pode ser gerado (o mínimo é sempre zero)
unsigned long lcrandom_max () ;
 
// modifica os parâmetros da equação do gerador; por default
// devem ser usados: A=40692, C=127 e M=10000000
void lcrandom_parms (unsigned long A, unsigned long C, unsigned long M) ;
 
#endif
```

## b) Geração de histograma
A distribuição dos valores produzidos por um gerador de números aleatórios pode ser avaliada visualmente através de um histograma2).

Escreva um programa C para gerar um histograma dos valores aleatórios produzidos por sua biblioteca.

Para isso:

1. gere 106 valores aleatórios no intervalo [0...99] (use lcrandom() % 100);
2. conte quantas vezes cada número foi gerado;
3. normalize (i.e. ajuste) as contagens para intervalo [0..100], aplicando uma regra de três às contagens obtidas, na qual a maior contagem equivale a 100;
4. plote o histograma resultante em um gráfico em modo texto; no eixo vertical estão os valores possível (0 a 99, neste exemplo); no eixo horizontal estão as frequências de ocorrência normalizadas.


Exemplo simplificado de histograma em modo texto (cada * vale 2 unidades):
```
   0   10   20   30   40   50   60   70   80   90   100
   +----+----+----+----+----+----+----+----+----+----+
 0 |*****************************
 1 |********************************
 2 |**************************
 3 |******************************
 4 |****************************
 5 |******************************
 6 |****************************
 7 |******************************
...| (linhas omitidas)
98 |***********************
99 |*********************
   +----+----+----+----+----+----+----+----+----+----+
```

## c) Cálculo de período
O período de um PRNG corresponde à quantidade de valores gerados por ele antes de começar a repeti-los, para uma dada semente. Por exemplo, para uma semente x0=0, um PRNG gera a seguinte sequência, cujo período é 16 (pois são gerados 16 valores distintos antes de repetir o 78):

0 2233 491 11 7219 **7801** 31 446 9876 831 6159 43259 63 38321 1126 43674 **7801** 31 446 9876 831 ...
Escreva um programa C para calcular o período do gerador implementado em sua biblioteca, a partir de x0=0.

Para os valores default de (A=40692, C=127 e M=10000000), o período do gerador vale 62503.
