#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#include<stdbool.h>

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int acabou();
void move(char direcao);
bool direcaovalida(char direcao);
void fantasmas();
int paraondeofantamavai(int xatual, int yatual, int* xdestino, int* ydestino);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);

#endif