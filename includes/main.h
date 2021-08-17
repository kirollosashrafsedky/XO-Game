#ifndef INCLUDES_MAIN_H_
#define INCLUDES_MAIN_H_

#define XO_SIZE 3					// size of the XO_Matrix
#define PLAYERS_NO 2				// number of players
#define MIN_NAME_LEN 2				// name validation, min allowed chars
#define MAX_NAME_LEN 25				// name validation, max allowed chars

// struct for each player
typedef struct Player{
	char symbol;
	int map[XO_SIZE][XO_SIZE];
	char name[MAX_NAME_LEN + 1];
} Player;

/**
 * Prints the initial data and instructions
 */
void printInstructions(void);

#endif /* INCLUDES_MAIN_H_ */
