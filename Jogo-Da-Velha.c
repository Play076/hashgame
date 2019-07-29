//PT-BR: Criado por Valdemir Valença
//EN-USA: Create by Valdemir Valença
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
//PT-BR: bibliotecas utilizadas
//EN-USA: libarys used

#define max 3
//PT-BR: tamanho da matrix do jogo
//EN-USA: size of game matriz

char PLAY1, PLAY2, aux;
//PT-BR: Valores do símbolo do Jogador 1 e do Jogador 2 no jogo
//EN-USA: Values of symbol of Player 1 and Player 2 on game

void verificationpos(char game[max][max], int awe, char PLAY);
//PT-BR: Verificações de posição do jogo para adicionar X ou O
//EN-USA: Game position check for add X or O
void gamebuild(char game[max][max], int prints[max][max]);
//PT-BR: Constuir a matriz of game
//EN-USA: Build the game matriz
void gameprint(char game[max][max], int prints[max][max], bool veri);
//PT-BR: Imprimir a matriz para o jogador
//EN-USA: Print the matriz to the player
int verification(char game[max][max]);
//PT-BR: Verificação para ver a vitória sé deu velha
//EN-USA: Check to see the victory se gave old
int main()
{
	char copy=184;
	//PT-BR: Copyright
	//EN-USA: Copyright
	char game[max][max];
	//PT-BR: Matriz do game
	//EN-USA: Game Matriz
	int prints[max][max];
	//PT-BR: Imprimir matriz de posição
	//EN-USA: Print position matriz
	int answame;
	//PT-BR: Repostas do player
	//EN-USA: Answame of player
	bool verificationendgame=false;
	//PT-BR: Verificar fim de jogo
	//EN-USA: Check End Game
	system("TITLE HASH - © Copyright");
	//PT-BR: Título do jogo
	//EN-USA: Game title
	system("CLS");
	//PT-BR: Limpar a tela
	//EN-USA: Claer screen
	printf("Welcome to hash.\n");
	//PT-BR: Mensage de boas vindas a o jogo
	//EN-USA: Welcome to game message
	printf("PLAY1 select [X] ou [O]: \n");
	//PT-BR: Limpar a tela
	//EN-USA: Claer screen
	do
	{
		scanf(" %c", &PLAY1);
	}while(PLAY1 != 120);
	//PT-BR: Verifica sé o jogador escolhe o X ou o O
	//EN-USA: Check if the player chooses X or O
	printf("\n");
	printf("PLAY2 select [O]: \n");
	do
	{
		scanf(" %c", &PLAY2);
	}while(PLAY2 != 111);
	//PT-BR: Verifica sé o jogador escolhe O
	//EN-USA: Check if the player chooses O
	system("CLS");

	gamebuild(game, prints);
	//PT-BR: Constuir o game
	//EN-USA: Game build

	//PT-BR: Verificar quando o jogo acabar
	//EN-USA: Check whan the end game
	while(verificationendgame != true)
	{
		//PT-BR: Corpo do jogo
		//EN-USA: Body Game
		printf("| START GAME |-------------------| PLAY1: %c  VS PLAY2: %c - %c Copyright|\n", PLAY1, PLAY2, copy);
		if(aux == PLAY1)
		{
			gameprint(game, prints, false);
			printf("PLAY2: ");
			do
			{
				scanf(" %d", &answame);
			}while(answame < 14 || answame > 22);
			verificationpos(game, answame, PLAY2);
			if(verification(game) == true)
			{
				system("CLS");
				printf("PLAY2: %c WINS!!\n", PLAY2);
				printf("  ==============  \n");
				printf("==================\n");
				printf(" =  ==========  = \n");
				printf("  =  ========  =  \n");
				printf("    ==========    \n");
				printf("       ====       \n");
				printf("       ====       \n");
				printf("     ========     \n");
				printf("  ==============  \n");
				gameprint(game, prints, true);
				verificationendgame = true;
				system("PAUSE");
				system("CLS");
			}else if(verification(game) == false)
			{
				system("CLS");
				printf("GAME OVER\n");
				gameprint(game, prints, true);
				verificationendgame = true;
				system("PAUSE");
				system("CLS");
			}else
			{
				verificationendgame = false;
				aux = PLAY2;
				system("CLS");
			}
		}else if(aux == PLAY2)
		{
			gameprint(game, prints, false);
			printf("PLAY1: ");
			do
			{
				scanf(" %d", &answame);
			}while(answame < 14 || answame > 22);
			verificationpos(game, answame, PLAY1);
			if(verification(game) == true)
			{
				system("CLS");
				printf("PLAY1: %c WINS!!\n", PLAY1);
				printf("  ==============  \n");
				printf("==================\n");
				printf(" =  ==========  = \n");
				printf("  =  ========  =  \n");
				printf("    ==========    \n");
				printf("       ====       \n");
				printf("       ====       \n");
				printf("     ========     \n");
				printf("  ==============  \n");
				gameprint(game, prints, true);
				verificationendgame = true;
				system("PAUSE");
				system("CLS");
			}else if(verification(game) == false)
			{
				system("CLS");
				printf("GAME OVER\n");
				gameprint(game, prints, true);
				verificationendgame = true;
				system("PAUSE");
				system("CLS");
			}else
			{
				verificationendgame = false;
				aux = PLAY1;
				system("CLS");
			}
		}else
		{
			gameprint(game, prints, false);
			printf("PLAY1: ");
			do
			{
				scanf(" %d", &answame);
			}while(answame < 14 || answame > 22);
			verificationpos(game, answame, PLAY1);
			aux = PLAY1;
			system("CLS");
		}
	}

	return 0;
}
void verificationpos(char game[max][max], int awe, char PLAY)
{
	//PT-BR: Sé o play for igual a o jogador X
	//EN-USA: If the play is equal to the player X
	if(PLAY == PLAY1)
	{
		for(int i = 0; i < max; i++)
		{
			for(int j = 0; j < max; j++)
			{
				//PT-BR: Sé a posição não exisite, vai colocar X ou O na posição
				//EN-USA: If the position does not exist, will put X or O in position
				if(game[i][j] == awe)
				{
					game[i][j] = PLAY;
				}
			}
		}
	}
	//PT-BR: Sé o play for igual a o jogador O
	//EN-USA: If the play is equal to the player O
	if(PLAY == PLAY2)
	{
		for(int i = 0; i < max; i++)
		{
			for(int j = 0; j < max; j++)
			{
				//PT-BR: Sé a posição não exisite, vai colocar X ou O na posição
				//EN-USA: If the position does not exist, will put X or O in position
				if(game[i][j] == awe)
				{
					game[i][j] = PLAY;
				}
			}
		}
	}
}
void gamebuild(char game[max][max], int prints[max][max])
{
	//PT-BR: Constuir a matriz
	//EN-USA: Build the matriz
	int n=13;
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			n++;
			//PT-BR: Adiciona as posição
			//EN-USA: Add position
			game[i][j] = n;
			//PT-BR: Matriz
			//EN-USA: Matriz
			prints[i][j] = n;
			//PT-BR: Posição
			//EN-USA: Position
		}
	}

}
void gameprint(char game[max][max], int prints[max][max], bool veri)
{
	//PT-BR: Mostrar a matriz
	//EN-USA: Show the matriz
	printf("GAME: \n");
	printf("+---++---++---+\n");
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			printf("| %c |", game[i][j]);
		}
		printf("\n");
	}
	printf("+---++---++---+\n");
	//PT-BR: Mostrar a posição
	//EN-USA: Show the position
	if(veri == false)
	{
		printf("Playing Position: \n");
		printf("+----++----++----+\n");
		for(int i = 0; i < max; i++)
		{
			for(int j = 0; j < max; j++)
			{
				printf("| %i |", prints[i][j]);
			}
			printf("\n");
		}
		printf("+----++----++----+\n");
	}else
	{
		printf("END GAME.\n");
	}
}
int verification(char game[max][max])
{
	if(game[0][0] == game[1][1] && game[1][1] == game[2][2])
	//PT-BR: Verificar Diagonal do pequeno para o grande
	//EN-USA: Diagonal check of the small for the big
	{
		return true;
	}
	if(game[2][0] == game[1][1] && game[1][1] == game[0][2])
	//PT-BR: Verificar Diagonal do grande para o pequeno
	//EN-USA: Diagonal check of the big for the small
	{
		return true;
	}
	if(game[0][0] == game[0][1] && game[0][1] == game[0][2])
	//PT-BR: Verificar linha 1
	//EN-USA: Check line 1
	{
		return true;
	}
	if(game[1][0] == game[1][1] && game[1][1] == game[1][2])
	//PT-BR: Verificar linha 2
	//EN-USA: Check line 2
	{
		return true;
	}
	if(game[2][0] == game[2][1] && game[2][1] == game[2][2])
	//PT-BR: Verificar linha 3
	//EN-USA: Check line 3
	{
		return true;
	}
	if(game[0][0] == game[1][0] && game[1][0] == game[2][0])
	//PT-BR: Verificar coluna 1
	//EN-USA: Check column 1
	{
		return true;
	}
	if(game[0][1] == game[1][1] && game[1][1] == game[2][1])
	//PT-BR: Verificar coluna 2
	//EN-USA: Check column 2
	{
		return true;
	}
	if(game[0][2] == game[1][2] && game[1][2] == game[2][2])
	//PT-BR: Verificar coluna 3
	//EN-USA: Verification column 3
	{
		return true;
	}
	if((game[0][0] == PLAY1 || game[0][0] == PLAY2) && (game[0][1] == PLAY1 || game[0][1] == PLAY2) && (game[0][2] == PLAY1 || game[0][2] == PLAY2))
	{
		if((game[1][0] == PLAY1 || game[1][0] == PLAY2) && (game[1][1] == PLAY1 || game[1][1] == PLAY2) && (game[1][2] == PLAY1 || game[1][2] == PLAY2))
		{
			if((game[2][0] == PLAY1 || game[2][0] == PLAY2) && (game[2][1] == PLAY1 || game[2][1] == PLAY2) && (game[2][2] == PLAY1 || game[2][2] == PLAY2))
			{
				return false;
				//PT-BR: Verificar velha
				//EN-USA: Check old
			}
		}
	}
}