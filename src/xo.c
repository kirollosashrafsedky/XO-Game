#include <stdio.h>
#include <stdlib.h>
#include "../includes/main.h"
#include "../includes/user_input.h"
#include "../includes/xo.h"

const char symbols[2] = {'X', 'O'};	// symbols to use, must be equal to players no

/**
 * initialize the game by filling data for both players (names, symbols, init map to zeros)
 * and sets the current player turn
 */
void initGame(void){
	for(int player = 0; player < PLAYERS_NO; player ++){
		// set player's symbol
		players[player].symbol = symbols[player];
		// set player's name
		setPlayerName(player);
		// initialize player's map to zeros
		for(int mapRow = 0; mapRow < XO_SIZE; mapRow ++){
			for(int mapCol = 0; mapCol < XO_SIZE; mapCol ++){
				players[player].map[mapRow][mapCol] = 0;
			}
		}
	}
	//sets the current player turn
	currentPlayerIndex = 0;
}

/**
 * draw the matrix with numbers in empty spaces or 'X's and 'O's
 */
void drawMap(void){
	printf("\n");
	for(int mapRow = 0; mapRow < XO_SIZE; mapRow ++){				// loop through rows
		if(mapRow == 0)
		{
			printf("-------------------\n");
		}
		for(int mapCol = 0; mapCol < XO_SIZE; mapCol ++){			// loop through cols
			int empty = 1;
			if(mapCol == 0)
			{
				printf("|  ");
			}
			for(int player = 0; player < PLAYERS_NO; player ++){	// loop through players to check if position is empty or not
				if(players[player].map[mapRow][mapCol] == 1)
				{
					printf("%c", players[player].symbol);
					// when 1 is found in the map => position is not empty so break
					empty = 0;
					break;
				}
			}
			if(empty)
			{
				printf("%d", ((mapRow) * XO_SIZE) + (mapCol + 1));
			}
			printf("  |  ");
		}
		printf("\n-------------------\n");
	}
}

/**
 * simple printf that displays winning player's info
 */
void showWiningInfo(void){
	printf("\n--------- Player %d - %s - \"%c\" won ---------\n", currentPlayerIndex + 1, players[currentPlayerIndex].name, players[currentPlayerIndex].symbol);
}

/**
 * check if the current player made changes that results in a win, whether horizontally, vertically, or diagonally
 *
 * @return int => 1 if thers's a winner, 0 otherwise
 */
int checkWinner(void){
	// winning horizontally
	for(int mapRow = 0; mapRow < XO_SIZE; mapRow ++){
		int win = 1;
		for(int mapCol = 0; mapCol < XO_SIZE; mapCol ++){
			if(players[currentPlayerIndex].map[mapRow][mapCol] == 0)
			{
				win = 0;
				break;
			}
		}
		if(win)
		{
			showWiningInfo();
			return 1;
		}
	}
	// winning vertically
	for(int mapCol = 0; mapCol < XO_SIZE; mapCol ++){
		int win = 1;
		for(int mapRow = 0; mapRow < XO_SIZE; mapRow ++){
			if(players[currentPlayerIndex].map[mapRow][mapCol] == 0)
			{
				win = 0;
				break;
			}
		}
		if(win)
		{
			showWiningInfo();
			return 1;
		}
	}
	// winning diagonally
	for(int i = 0; i < 2; i++){			// 2 is the number of diagonals
		int win = 1;
		for(int mapRow = 0; mapRow < XO_SIZE; mapRow ++){
			for(int mapCol = 0; mapCol < XO_SIZE; mapCol ++){
				// check for both diagonals
				if(((mapRow == mapCol && !i) || (mapRow == XO_SIZE - 1 - mapCol && i)) && players[currentPlayerIndex].map[mapRow][mapCol] == 0)
				{
					win = 0;
					break;
				}

			}
			if(!win)
			{
				break;
			}
		}
		if(win)
		{
			showWiningInfo();
			return 1;
		}
	}

	return 0;
}

/**
 * calculates the row and column number ("2d" array) from just numbers from 1 to 9 ("1d" array)
 *
 * @param *row => pointer to row var to change it
 * @param *col => pointer to col var to change it
 * @param input => number from 1 to 9 entered by the user
 */
void getRowColFromInput(int* row, int* col, int input){
	*row = (input - 1) / XO_SIZE;
	*col = input - (*row * XO_SIZE) - 1;
}

/**
 * check if the input entered by the user is not repeated before
 *
 * @param input => number from 1 to 9 entered by the user
 * @return int => 1 if available, 0 if it's repeated
 */
int checkAvailability(int input){
	int mapRow, mapCol;
	getRowColFromInput(&mapRow, &mapCol, input);
	for(int player = 0; player < PLAYERS_NO; player ++){
		if(players[player].map[mapRow][mapCol] == 1)
		{
			printf("\nThe number you entered was already taken\n");
			return 0;
		}
	}
	return 1;
}

/**
 * change map in the current player's struct by adding 1 to the location indicated by the user
 *
 * @param input => number from 1 to 9 entered by the user
 */
void commitChanges(int input){
	int mapRow, mapCol;
	getRowColFromInput(&mapRow, &mapCol, input);
	players[currentPlayerIndex].map[mapRow][mapCol] = 1;
}
