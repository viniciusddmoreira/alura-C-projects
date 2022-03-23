#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

	// imprime o cabeçalho do nosso jogo
	printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

	// declarando variaveis que serao usadas mais a frente
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;
    int tentativas = 0;

    // definindo a quantidade de pontos inicial
    double pontos = 1000;

    // gerando um numero secreto aleatorio
    srand(time(0));
    int numerosecreto = rand() % 100;

    // escolhendo o nivel de dificuldade
	printf("Qual o nível de dificuldade?\n");
	printf("(1)Fácil (2)Médio (3)Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	switch(nivel) {
		case 1:
			totaldetentativas = 15;
			break;

		case 2:
			totaldetentativas = 10;
			break;

		default:
			totaldetentativas = 5;
			break;
	}

	// loop principal do jogo
	for (int i=0; i < totaldetentativas; i++){

		printf("Qual é o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi de %d\n", chute);
		
		if (chute < 0){
			printf("Você não pode chutar números negativos!\n");

			continue;
		}

		acertou = (numerosecreto == chute);
		int maior = (chute > numerosecreto);

		if(acertou){
			break;
		} 

		else if (maior){
			printf("Seu chute foi maior que o número secreto.\n");
		} 

		else {
			printf("Seu chute foi menor que o número secreto.\n");
		}

		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;

		tentativas++;
	}

	printf("Fim de jogo!\n");

	if(acertou){

		printf("\n             OOOOOOOOOOO              \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

		printf("Parabéns! Você ganhou!\n");
		printf("Você acertou em %d tentativas!\n", tentativas);
		printf("Total de pontos: %.2f\n", pontos);
	} else {
		printf("\nVocê perdeu! Tente de novo!\n\n");

		printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");

	}	
}