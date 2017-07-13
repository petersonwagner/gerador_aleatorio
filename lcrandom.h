#ifndef __LCRANDOM__
#define __LCRANDOM__

// calcula e devolve um valor pseudoaleatório
unsigned long lcrandom () ;

// define o valor inicial (semente) da sequência de aleatórios
void lcrandom_seed (unsigned long s) ;

// informa o valor máximo que pode ser gerado (mínimo é zero)
unsigned long lcrandom_max () ;

// modifica os parâmetros da equação do gerador; por default
// devem ser usados: A=40692, C=127 e M=10000000
void lcrandom_parms (unsigned long A, unsigned long C, unsigned long M) ;

#endif