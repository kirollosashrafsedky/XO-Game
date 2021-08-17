#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/main.h"
#include "../includes/user_input.h"

/**
 * takes the input from the user and sets the player's name
 *
 * @param index => index of the player to set his name
 */
void setPlayerName(int index){
	printf("\nPlease enter player %d \"%c\" name: ", index + 1, players[index].symbol);
	gets(players[index].name);
	// only get out of the loop when validation is true, the name is greater than min value and smaller than max value
	// else show error msg
	while(strlen(players[index].name) < MIN_NAME_LEN || strlen(players[index].name) > MAX_NAME_LEN)
	{
		printf("\nName must be greater than %d and smaller than %d.\nPlease enter player %d \"%c\" name again: ",MIN_NAME_LEN - 1, MAX_NAME_LEN + 1, index + 1, players[index].symbol);
		gets(players[index].name);
	}
}

/**
 * solve the scanf issue when entering successive inputs
 */
void ignoreRestOfLine(FILE* fp)
{
	int c;
	while ( (c = fgetc(fp)) != EOF && c != '\n');
}

/**
 * check if the user wants to exit or play again
 *
 * @return char => 1 if user wants to play again, 0 if user wants to exit
 */
char playAgainDecision(void){
	int decision = -1;
	printf("\nEnter \t 1: to play again\n\t 0: to exit: ");
	int firstTime = 1;
	do
	{
		// don't show the error msg for the first time
		if(!firstTime)
		{
			printf("\nCommand not recognized\nEnter 1: to play again\n\t 0: to exit: ");
		}
		firstTime = 0;
		if(scanf("%d", &decision) <= 0) {
			// Ignore rest of the line and continue with the loop.
			ignoreRestOfLine(stdin);
		}

	}while(decision != 0 && decision != 1);				// make sure decision is only 0 or 1
	// clear stdin so as not to affect other scanfs
	fflush(stdin);
	return decision;
}


/**
 * get the player input to place an 'X' or an 'O' in this position, with validating entered value
 *
 * @return int => value entered by the user from 1 to 9
 */
int getPlayerInput(void){
	int input = 0;
	printf("Player %d - %s - \"%c\" turn, Choose number: ", currentPlayerIndex + 1, players[currentPlayerIndex].name, players[currentPlayerIndex].symbol);
	int firstTime = 1;
	do
	{
		// don't show the error msg for the first time
		if(!firstTime)
		{
			printf("Invalid input, Try again: ");
		}

		firstTime = 0;
		if(scanf("%d", &input) <= 0) {
			// Ignore rest of the line and continue with the loop.
			ignoreRestOfLine(stdin);
		}
	}while(input < 1 || input > XO_SIZE * XO_SIZE);		// make sure input is from 1 to 9
	fflush(stdin);
	return input;
}
