#ifndef INCLUDES_XO_H_
#define INCLUDES_XO_H_

extern Player players[PLAYERS_NO];
extern int currentPlayerIndex;


/**
 * initialize the game by filling data for both players (names, symbols, init map to zeros)
 * and sets the current player turn
 */
void initGame(void);

/**
 * simple printf that displays winning player's info
 */
void showWiningInfo(void);

/**
 * draw the matrix with numbers in empty spaces or 'X's and 'O's
 */
void drawMap(void);

/**
 * check if the current player made changes that results in a win, whether horizontally, vertically, or diagonally
 *
 * @return int => 1 if thers's a winner, 0 otherwise
 */
int checkWinner(void);

/**
 * check if the input entered by the user is not repeated before
 *
 * @param input => number from 1 to 9 entered by the user
 * @return int => 1 if available, 0 if it's repeated
 */
int checkAvailability(int input);

/**
 * change map in the current player's struct by adding 1 to the location indicated by the user
 *
 * @param input => number from 1 to 9 entered by the user
 */
void commitChanges(int input);

/**
 * calculates the row and column number ("2d" array) from just numbers from 1 to 9 ("1d" array)
 *
 * @param *row => pointer to row var to change it
 * @param *col => pointer to col var to change it
 * @param input => number from 1 to 9 entered by the user
 */
void getRowColFromInput(int* row, int* col, int input);

#endif /* INCLUDES_XO_H_ */
