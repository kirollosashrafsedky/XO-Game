#ifndef INCLUDES_USER_INPUT_H_
#define INCLUDES_USER_INPUT_H_

extern Player players[PLAYERS_NO];
extern int currentPlayerIndex;


/**
 * takes the input from the user and sets the player's name
 *
 * @param index => index of the player to set his name
 */
void setPlayerName(int index);

/**
 * check if the user wants to exit or play again
 *
 * @return char => 1 if user wants to play again, 0 if user wants to exit
 */
char playAgainDecision(void);

/**
 * get the player input to place an 'X' or an 'O' in this position, with validating entered value
 *
 * @return int => value entered by the user from 1 to 9
 */
int getPlayerInput(void);

/**
 * solve the scanf issue when entering successive inputs
 */
void ignoreRestOfLine(FILE* fp);

#endif /* INCLUDES_USER_INPUT_H_ */
