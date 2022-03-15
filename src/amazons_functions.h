#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
extern int horse;
extern int playerCounter;
extern int number_of_players;
extern int number_of_amazons;
//extern struct player players[8];
extern struct boardSize sizeOfBoard;
extern struct board ar;
extern struct move place;
extern struct move from;


void askforsizeofboard();
void afterhorse();
void askForAMoveFromTheCurrentPlayer();
void showTheUpdatedBoard();
void fillWithRandomTreasuresAndArtifacts();
int checkIfTheMoveIsLegal(int positionOnX, int positionOnY, int positionXOfAmazon, int positionYOfAmazon);
int checkifspearislegal(int positionOnX, int positionOnY, int positionXOfAmazon, int positionYOfAmazon);
void shootarrow();
void shootspear();
int makeMove();
int checkIfAnyLegalMovesForPlayer(int playerID);
int checkIfAnyLegalMoves();
void initializeTheTresures();
int numPlayers();
void generateRandomIDS();
void namePlayers();
void placeTheAmazonsInteractively();
void numAmazons();
void final();

#endif





