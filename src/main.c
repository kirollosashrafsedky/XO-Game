/*
 ============================================================================
 Name         : X-O game
 Author       : Kirollos Ashraf Sedky
 Team		  : Conquerors Team
 Organization : Sprints Internship
 Version      : 1.0
 Description  : X-O Game - A simple X-O game that allows two users to play, first the two players enter ther name
 	 	 	 	"each name can be from 2 chars up to 25" then the players exchange turns, each player enters a number
 	 	 	 	corresponding to the place he wants to place an 'X' or an 'O' in it, A player wins when he completes a
 	 	 	 	row, a column or a diagonal. Then the user can enter 1 to play again or 0 to exit. The game is full of
 	 	 	 	validations for different inputs, whether the name of players, the input numbers and the final choice
 	 	 	 	to exit or play again.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/main.h"
#include "../includes/user_input.h"
#include "../includes/xo.h"

Player players[PLAYERS_NO];				// array of players
int currentPlayerIndex;					// var to hold the current turn player's index

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);	// solve eclipse issue in printf and scanf
	printInstructions();
	do{
		initGame();						// fill the two players structs
		printf("\n%s VS %s\n", players[0].name, players[1].name);
		int draw = 1;					// consider there's draw by default from the beginning
		drawMap();						// draw the matrix for the first time
		for(int i = 0; i < XO_SIZE * XO_SIZE; i++)
		{
			int playerInput = getPlayerInput();
			// check if the input is not chosen before, if it's repeated, take the input again
			while(!checkAvailability(playerInput))
			{
				playerInput = getPlayerInput();
			}
			// change the map in both players structs
			commitChanges(playerInput);
			// draw the matrix with numbers in empty spaces or 'X's and 'O's
			drawMap();
			// check if that move results in a winner
			if(checkWinner())
			{
				draw = 0;
				break;
			}
			// toggle players' turns
			currentPlayerIndex = !currentPlayerIndex;
		}
		if(draw)
		{
			printf("\nDraw. No winner nor loser\n");
		}
	}while(playAgainDecision());	// check if user chooses to play again
	printf("\nGood Bye\n");
	return 0;
}

/**
 * Prints the initial data and instructions
 */
void printInstructions(void){
	printf("Welcome to X-O Game\n");
	printf("-------------------\n");
	printf("Developed by\t:\t Kirollos Ashraf\n");
	printf("Team\t\t:\t Conquerors\n");
	printf("Organization\t:\t Sprints Internship\n");
	printf("-------------------\n");
	printf("Description :\n");
	printf("--------------\n");
	printf("X-O Game - A simple X-O game that allows two users to play, first the two players enter ther name\n\"each name can be from 2 chars up to 25\" then the players exchange turns, each player enters a number\ncorresponding to the place he wants to place an 'X' or an 'O' in it, A player wins when he completes a row,\na column or a diagonal. Then the user can enter 1 to play again or 0 to exit\n");
}
