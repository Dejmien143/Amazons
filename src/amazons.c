#include <stdio.h>
#include <stdlib.h>
#include "amazons_functions.h"
#include <time.h>


int main(void){
	
	time_t tt;
	srand(time(&tt));
	number_of_players = numPlayers();
	askforsizeofboard();
	generateRandomIDS();
	numAmazons();
	namePlayers();
	placeTheAmazonsInteractively();
	fillWithRandomTreasuresAndArtifacts();
	initializeTheTresures();
	
	while(checkIfAnyLegalMoves()==1)
	{
	    
	    if(horse==0)    
	    askForAMoveFromTheCurrentPlayer();
	    if(horse==1)
	    {
	        afterhorse();
	        playerCounter++;
	    }
	    makeMove();
	    showTheUpdatedBoard();
	    if(playerCounter==number_of_amazons)
	    {
	        playerCounter=0; 
	    }
	
	}
	
	final();
	






}
