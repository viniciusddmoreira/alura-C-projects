#ifndef _MAPA_H_
#define _MAPA_H_


#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'
#define BOMBA 'b'

struct mapa {
	char** matriz;
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

struct posicao {
	int x;
	int y;
};

typedef struct posicao POSICAO;

void alocamapa(MAPA* m);
void liberamapa(MAPA* m);
void lemapa(MAPA* m);
int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);

#endif