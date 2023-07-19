#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "mapa.h"

bool direcaopermitida(MAPA* m, int x, int y) {
    if(x >= m->linhas) return false;
    if(y >= m->colunas) return false;

    return true;
}

bool direcaoestavazia(MAPA* m, int x, int y) {
    return m->matriz[x][y] == VAZIO;
}

bool ehparede(MAPA*m, int x, int y) {
    return 
        m->matriz[x][y] == PAREDE_VERTICAL
        || m->matriz[x][y] == PAREDE_HORIZONTAL;
}

bool ehpersonagem(MAPA*m, char personagem, int x, int y) {
    return m->matriz[x][y] == personagem;
}

bool podeandar(MAPA* m, char personagem, int x, int y) {
    return 
        direcaopermitida(m, x, y)
        && !ehparede(m, x, y)
        && !ehpersonagem(m, personagem, x, y);
}

void copiamapa(MAPA* origem, MAPA* destino) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocamapa(destino);

    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void andanomapa(MAPA* m, int xorigem, int yorigem,
        int xdestino, int ydestino) {
    
    char personagem = m->matriz[xorigem][yorigem];

    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
}

bool encontramapa(MAPA* m, POSICAO* p, char c) {
    // acha a posição do foge foge
    for(int i = 0; i < m->linhas; i++) {
        for(int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return true;
            }
        }
    }

    return false;
}

// m->matriz é o mesmo que (*m).matriz
void liberamapa(MAPA* m) {
    for(int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }

    free((*m).matriz);
}

void alocamapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for(int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1)); // o +1 é por conta do \0 que tem no final de cada linha
    }
}

void readmap(MAPA* m) {
    FILE* f;
    f = fopen(MAP_FILE, "r");

    if(f == NULL || f == 0) {
        printf("Erro na leitura do arquivo de mapa");
        system("pause");
        exit(1);
    }

    fscanf(f, "%d%d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]); // passando apenas a primeira dimensão da matriz, será considerada a linha toda
    }

    fclose(f);
}

// void imprimemapa(MAPA* m) {
//     for (int i = 0; i < m->linhas; i++) {
//         printf("%s\n", m->matriz[i]);
//     }
// }