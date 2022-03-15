#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "amazons_functions.h"
typedef struct boardSize{
	int x;
	int y;	
} boardSize;

typedef struct board{
	int table [100][100][3];
} board;

typedef struct player{
char userName[15];
int ID;
int collectedTreasure;
} player;

typedef struct move{
	int x;
	int y;
} move;

int playerCounter = 0;
int number_of_players;
int horse=0;
int number_of_amazons;

player players[8];
boardSize sizeOfBoard;
board ar;
move place;
move from;

int checkIfTheMoveIsLegal(int positionOnX, int positionOnY, int positionXOfAmazon, int positionYOfAmazon){
//This function check if coordinates provided by a player ale correct to make a move/shoot an arrow
int war;
war=0;
	
	if (positionOnY == positionYOfAmazon)
	{	
		war = 1;

		if (positionOnX > positionXOfAmazon)
		{
			for (int i = positionXOfAmazon; i <= positionOnX; i++)
			{
				if (ar.table[positionYOfAmazon][i][2] != 0)
					war = 0;
			}

		}
			
		if (positionOnX < positionXOfAmazon)
		{
			for (int i = positionXOfAmazon; i >= positionOnY; i--)
			{
				if (ar.table[positionYOfAmazon][i][2] != 0)
					war = 0;
			}

		}
		
		if (war == 1)
			return 1;
		else
			return 0;
	}
	if (positionOnX == positionXOfAmazon)
	{

		if (positionOnY > positionYOfAmazon)
		{
			for (int i = positionYOfAmazon; i <= positionOnY; i++)
			{
				if (ar.table[i][positionXOfAmazon][2] != 0)
					war = 0;
			}

		}

		if (positionOnY < positionYOfAmazon)
		{
			for (int i = positionYOfAmazon; i >= positionOnY; i--)
			{
				if (ar.table[i][positionXOfAmazon][2] != 0)
					war = 0;
			}

		}

		if (war == 1)
			return 1;
		else
			return 0;


		
	}
	if ((positionXOfAmazon - positionOnX) == (positionYOfAmazon - positionOnY))
	{
		war = 1;
		if ((positionOnX > positionXOfAmazon) && (positionOnY > positionYOfAmazon))
		{
			for (int i = positionYOfAmazon; i <= positionOnY; i++)
			{
				if (ar.table[i][positionXOfAmazon+i- positionYOfAmazon][2] != 0)
					war = 0;
			}
		}

		if ((positionOnX < positionXOfAmazon) && (positionOnY < positionYOfAmazon))
		{
			for (int i = positionYOfAmazon; i >= positionOnY; i--)
			{
				if (ar.table[i][positionXOfAmazon - i + positionYOfAmazon][2] != 0)
					war = 0;
			}
		}

		if ((positionOnX <  positionXOfAmazon) && (positionOnY > positionYOfAmazon))
		{
			for (int i = positionYOfAmazon; i <= positionOnY; i++)
			{
				if (ar.table[i][positionXOfAmazon - i + positionYOfAmazon][2] != 0)
					war = 0;
			}
		}

		if ((positionOnX > positionXOfAmazon) && (positionOnY < positionYOfAmazon))
		{
			for (int i = positionYOfAmazon; i >= positionOnY; i--)
			{
				if (ar.table[i][positionXOfAmazon + i - positionYOfAmazon][2] != 0)
					war = 0;
			}
		}

		if (war == 1)
			return 1;
		else
			return 0;
	}

}

int checkifspearislegal(int positionOnX, int positionOnY, int positionXOfAmazon, int positionYOfAmazon){
//This function check if coordinates provided by a player are correct to shoot a spear
int war;
war=0;
	
	if (positionOnY == positionYOfAmazon)
	{	
		war = 1;

	
		if (ar.table[positionYOfAmazon][positionOnX][2] != 0)
			war = 0;

	}
	if (positionOnX == positionXOfAmazon)
	{
		war = 1;	
		if (ar.table[positionOnY][positionXOfAmazon][2] != 0)
			war = 0;
			
		
	}
	if ((positionXOfAmazon - positionOnX) == (positionYOfAmazon - positionOnY))
	{
		war = 1;
		if (ar.table[positionOnY][positionOnX][2] != 0)
			war = 0;
	
		
	}
    if (war == 1)
			return 1;
		else
			return 0;
}

void askforsizeofboard(){
//This function ask for the size of board
    printf("Please provide number of rows and columns");
    scanf("%d %d",&sizeOfBoard.y,&sizeOfBoard.x);
    
    
}

void afterhorse(){
//This function is connected with horse artifact which skip the part of asking which amazon player wants to move    
    
    printf("choose where to move your amazon");
    scanf("%d %d",&place.x,&place.y);
    
    while(checkIfTheMoveIsLegal(place.x, place.y, from.x, from.x)!=0)
    {
        printf("choose a proper place to move your amazon");
        scanf("%d %d",&place.x,&place.y);
    }
    
    horse=0; 
    
}


void askForAMoveFromTheCurrentPlayer(){
//This function asks for coordinates where to move an amazon

    printf("player %d choose amazon to move",players[playerCounter].ID);
    scanf("%d %d",&from.x,&from.y);

    while(players[playerCounter].ID!=ar.table[from.y][from.x][2])
    {
        printf("choose a proper amazon");
        scanf("%d %d",&from.x,&from.y);
    }
    
    printf("choose a place to move ");
    scanf("%d %d",&place.x,&place.y);

    while(checkIfTheMoveIsLegal(place.x, place.y, from.x, from.x)!=0)
    {
        printf("choose a proper place to move your amazon");
        scanf("%d %d",&place.x,&place.y);
    }


}

void showTheUpdatedBoard(){
//This function display the board
    for(int i=0;i<=sizeOfBoard.y-1;i++)
	{
        for(int j=0;j<=sizeOfBoard.x-1;j++)
	    {	
            for (int k = 0; k <= 2;k++)
            {
                printf("%d",ar.table[i][j][k]);  
            }
            printf(" "); 
        }
        printf("\n"); 
    }
    
    
}


void fillWithRandomTreasuresAndArtifacts()
//This function fill the board with random treasure and artifacts

{
	
    for(int i=0;i<=sizeOfBoard.y-1;i++)
	{
        for(int j=0;j<=sizeOfBoard.x-1;j++)
        {	
            if(ar.table[i][j][0]==0)
            {
                ar.table[i][j][0]=rand() % 6;
                ar.table[i][j][1]=rand() % 4;
            }
        }
    }
	
	
	
}





void shootarrow(){
//This function asks for coordinates to shoot an arrow and then place it
    printf("player %d choose where to shoot an arrow",players[playerCounter].ID);
    scanf("%d %d",&place.x,&place.y);
    
    while(checkIfTheMoveIsLegal(place.x, place.y, from.x, from.x)==0)
    {
        printf("choose a proper place to shoot an arrow");
        scanf("%d %d",&place.x,&place.y);
    }
    
    ar.table[place.y][place.x][2]=9;
    

    
}

void shootspear(){
//This function asks for coordinates to shoot a spear and then place it
    printf("player %d choose where to shoot a spear",players[playerCounter].ID);
    scanf("%d %d",&place.x,&place.y);
    
    while(checkifspearislegal(place.x, place.y, from.x, from.x)==0)
    {
        printf("choose a proper place to shoot an spear");
        scanf("%d %d",&place.x,&place.y);
    }
    if(checkifspearislegal(place.x, place.y, from.x, from.x)==0)
    {
        ar.table[place.y][place.x][2]=9;
    }    
    
    
}

int makeMove(){
//This function move a player to other position then checks if there are any artifacts 
//If there is no artifact(0), it first shoots an arrow and then add 1 to a player counter
//If the artifact is horse(1) then it first shoots an arrow that it repeats the whole process.
//If the artifact is broken arrow(2) it adds 1 to a player counter
//If the artifact is spear(3) then it shoots a spear instead of an arrow and then add 1 to a player counter


	    ar.table[place.y][place.x][2]=players[playerCounter].ID;
	    ar.table[from.y][from.x][2]=0;
		players[playerCounter].collectedTreasure += ar.table[place.y][place.x][0];
		ar.table[place.y][place.x][0]=0;
		
		if (ar.table[place.y][place.x][1] = 0)
		{
		    shootarrow();
			playerCounter++;
			return 0;
		}
		if (ar.table[place.y][place.x][1] = 1)
		{
		    shootarrow();
		   
			return 1;
		}
		if (ar.table[place.y][place.x][1] = 2)
		{
		    
		    playerCounter++;
			return 1;
		}
		if (ar.table[place.y][place.x][1] = 3)
		{
		    
		    shootspear();
			playerCounter++;
			return 1;
		}
			return 1;
		
}


int checkIfAnyLegalMovesForPlayer(int playerID){
//It basically checks if the player
//with the id in the variable playerID
//currently has any legal moves to make, 
//if there is any, it returns 1,
//otherwise 0.    
	int war;
	war=0;
	
	for(int i=0;i<=sizeOfBoard.y-1;i++)
	{
        for(int j=0;j<=sizeOfBoard.x-1;j++)
        {
        if(ar.table[i][j][1]==playerID)  
            for(int k=0;k<=sizeOfBoard.y-1;k++)
            {
                for(int l=0;l<=sizeOfBoard.x-1;l++)  
                {
                if(checkIfTheMoveIsLegal(l, k, j, i)==0)
                    {
                        war= 1;
                    }
                }
            }
        }
    }
    
    
    if (war == 1)
			return 1;
		else
			return 0;
	
	
	
	return 1;
	
}


int checkIfAnyLegalMoves(){
//If at least one of the players has any legal moves to
//make, then it returns 1, if none of them has any moves
//left to make, then it returns 0 .

for(int i=0;i<number_of_players;i++)
{
if(checkIfAnyLegalMovesForPlayer(i)==1)
return 1;
}

return 0;
    
}


void generateRandomIDS(){
//It sets IDs for the players 
//that were named using namePlayers(),
//Random numbers in the range
// of [1, 8] as many times
// as the number of players
//using the stdlib time functions    
int random;


for(int a=0;a<number_of_players;a++)
{
	players[a].ID=0;
}
for(int i=0;i<number_of_players;i++)
{
	random=(rand() % (number_of_players - 1 + 1)) + 1;
	for(int j=0;j<i;j++)
	{
	  if(random==players[j].ID)
	  {
	    random=(rand() % (8 - 1 + 1)) + 1;
	    j=0;
	  }	
	}
	players[i].ID=random;
} 

}
	

void namePlayers()
//This function asks for names of the players
{

for(int i=1;i<=number_of_players;i++)
{
printf("Give a name for player %d ",i);
scanf("%s",players[i-1].userName);
}

}


int numPlayers()
//This function asks for number of players
{
int n;
printf("How many players are playing?[Choose from 1-8]= ");
scanf("%d", &n);
return n; 

}


void initializeTheTresures(){
//This function sets all players treasure score to 0
for(int i=0;i<number_of_players;i++)
{
    players[i].collectedTreasure=0;
}

}


void placeTheAmazonsInteractively(){
//This function asks where amazons should be placed for each player 

for(int i=0;i<number_of_players;i++)
{
    for(int j=0;j<number_of_amazons;j++)
    {
        printf("player %d choose where you want to place an amazon ",players[i].ID);
        scanf("%d %d",&from.x,&from.y);
   
        while(ar.table[from.y][from.x][2]!=0)
        {
            printf("choose a proper place to place an amazon");
            scanf("%d %d",&from.x,&from.y);
        }
   
        ar.table[from.y][from.x][2]=players[i].ID;
        showTheUpdatedBoard();
    }
}


}


void numAmazons(){
//This function asks for number of amazons for each player
    printf("How many amazons for each player? ");
    scanf("%d",&number_of_amazons); 
    
    
}


void final(){
//This function display the final message and then display the winner with the highest number of treasures collected
    int n;
    int winner;
    winner=players[0].ID;
    printf("There are no legal moves left for any player, the game will terminate itself!\a\n");
	printf("Thanks for playing the amazons!");
    n=players[0].collectedTreasure;
    for(int i=1;i<=number_of_players;i++)
    {
        if(n<players[i].collectedTreasure)
        winner=players[i].ID;
        n=players[i].collectedTreasure;
    }
    printf("The winner is %s with a score of %d points",players[winner].userName,players[winner].collectedTreasure);
}




/* Here is not implemented part of handling the files




This part was supposed to read from a text file


FILE* file = fopen("the choosen board.txt","r");

	fscanf(file, "%d %d", &sizeOfBoard.y, &sizeOfBoard.x);
	
	for(int i=0;i<=sizeOfBoard.y-1;i++)
	    for(int j=0;j<=sizeOfBoard.x-1;j++)
		    for (int k = 0; k <= 2)
		    {
			int z;
			z= getchar(file)
				if (z >= 48 && z <= 57)
				{
					if (z == 48)
						ar.table[i][j][k] = 0;

					if (z == 49)
						ar.table[i][j][k] = 1;

					if (z == 50)
						ar.table[i][j][k] = 2;

					if (z == 51)
						ar.table[i][j][k] = 3;

					if (z == 52)
						ar.table[i][j][k] = 4;

					if (z == 53)
						ar.table[i][j][k] = 5;

					if (z == 54)
						ar.table[i][j][k] = 6;

					if (z == 55)
						ar.table[i][j][k] = 7;

					if (z == 56)
						ar.table[i][j][k] = 8;

					if (z == 57)
						ar.table[i][j][k] = 9;

					k++;
				}
		}
	for(int i=0;i<=number_of_players-1;i++)	
	{
	    fscanf(file, "%s %d %d", &players[i].userName,&players[i].ID,&players[i].collectedTreasure);	
	}	
		
	

This part was supposed to save the board in the file

		
FILE* file = fopen("saving place.txt","w");

	fprintf(file, "%d %d", &sizeOfBoard.y, &sizeOfBoard.x);
		
	for(int i=0;i<=sizeOfBoard.y-1;i++)
	    {
	        for(int j=0;j<=sizeOfBoard.x-1;j++)
	        {
		            for (int k = 0; k <= 2,k++)
		            {
		                putw(ar.table[i][j][k], file);
				    }
		    fprintf(file, " ");
	        }
	fprintf(file, "\n");
	}
		
	for(int i=0;i<=number_of_players-1;i++)
	{
        fprintf(file, "%s %d %d\n",players[i].userName,players[i].ID,players[i].collectedTreasure);
	}
		
*/		
		

		
		
		
		





