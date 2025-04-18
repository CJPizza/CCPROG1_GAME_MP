/******************************************************************************
	This is to certify that this project is my own work, based on my personal
	efforts in studying and applying the concepts learned. I have constructed
	the functions and their respective algorithms and corresponding code by
	myself. The program was run, tested, and debugged by my own efforts. I
	further certify that I have not copied in part or whole or otherwise
		plagiarized the work of other students and/or persons.
			<Carl Justine S. Alamay> - <12274100> - <S12>
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

/***********************************************************************************

Description: This function creates the code as a single integer and checks if any
			 of the generated colors are the same. If so, it will replace that specific
			 color with a new one that is dissimilar from the other 3 colors.
@param: int iColor1, iColor2, iColor3, iColor4
@return: int; 4-digit value for the code.

************************************************************************************/
	int codemaker(int iColor1, int iColor2, int iColor3, int iColor4)
{
		do{iColor1 = rand() % 6 + 1;
		 }while (iColor1 == iColor2 || iColor1 == iColor3 || iColor1 == iColor4);
		 
		do{iColor2 = rand() % 6 + 1;
		 }while (iColor2 == iColor3 || iColor2 == iColor4 || iColor2 == iColor1);
		 
		do{iColor3 = rand() % 6 + 1;
		 }while (iColor3 == iColor4 || iColor3 == iColor1 || iColor3 == iColor2);
		 
	return (iColor1 * 1000) + (iColor2 * 100) + (iColor3 * 10) + iColor4;
}
/**********************************************************************************

Description: This function just generates a random number out of a maximum of 6.
@return: int; a randomized digit.

**********************************************************************************/
	int randomize()
{
	return rand() % 6 + 1;
}
/**********************************************************************************

Description: This function combines the A.I.'s guess into a single integer for easier
			checking, and comparison.
@param: int iGuess1, iGuess2, iGuess3, iGuess4
@return: int; a 4-digit integer.

**********************************************************************************/
	int combineAIguess(int iGuess1, int iGuess2, int iGuess3, int iGuess4)
{
	return (iGuess1 * 1000) + (iGuess2 * 100) + (iGuess3 * 10) + iGuess4;	
}
/**********************************************************************************

Description: This function combines the player input for the A.I. to guess into a single
			 integer for easier checking, and comparison.
@param: int iColor1, iColor2, iColor3, iColor4
@return: int; a 4-digit integer.

**********************************************************************************/
	int combineHumaninput(int iColor1, int iColor2, int iColor3, int iColor4)
{
	return (iColor1 * 1000) + (iColor2 * 100) + (iColor3 * 10) + iColor4;	
}
/***********************************************************************************

Description: This function is responsible for determining whether or not the guesses,
			generated colors, and peg positions are equal.  
@param: int iColor1, iColor2, iColor3, iColor4, iGuess1, iGuess2, iGuess3, iGuess4

************************************************************************************/
	void pegchecker(int iGuess1, int iGuess2, int iGuess3, int iGuess4, int iColor1, int iColor2, int iColor3, int iColor4)
{	
	switch (iGuess1 == iColor1)
	{
		case 1: printf("B "); break;
		default:
			switch (iGuess2 == iColor1)
			{
				case 1: printf("W "); break;
				default:
					switch (iGuess3 == iColor1)
					{
						case 1: printf("W "); break;
						default:
							switch (iGuess4 == iColor1)
							case 1: printf("W "); break;
					}
					
			}
	}
	switch (iGuess2 == iColor2)
	{
		case 1: printf("B "); break;
		default:
			switch (iGuess1 == iColor2)
			{
				case 1: printf("W "); break;
				default:
					switch (iGuess3 == iColor2)
					{
						case 1: printf("W "); break;
						default:
							switch (iGuess4 == iColor2)
							case 1: printf("W "); break;
					}
					
			}
	}
	switch (iGuess3 == iColor3)
	{
		case 1: printf("B "); break;
		default:
			switch (iGuess1 == iColor3)
			{
				case 1: printf("W "); break;
				default:
					switch (iGuess2 == iColor3)
					{
						case 1: printf("W "); break;
						default:
							switch (iGuess4 == iColor3)
							case 1: printf("W "); break;
					}
					
			}
	}
	switch (iGuess4 == iColor4)
	{
		case 1: printf("B "); break;
		default:
			switch (iGuess1 == iColor4)
			{
				case 1: printf("W "); break;
				default:
					switch (iGuess2 == iColor4)
					{
						case 1: printf("W "); break;
						default:
							switch (iGuess3 == iColor4)
							case 1: printf("W "); break;
					}
					
			}
	}
}

int main()
{
	srand(time(NULL));
	int iSelectScreen, iSelect, iChoicea, iChoiceb, iChoicec;		// Variables that control the choices that player makes.
	int iAttempts, iRounds;											// Variables that control the pace of the game through the rounds and attempts.
	int i, j;														// Control variables for the loops, conditional statements, and the current attempts number.
	int iGuess, iCode;												// Variables for the player input as either the Code Maker or Code Guesser.
	int iGuess1, iGuess2, iGuess3, iGuess4;							// The player or A.I.'s guess separated into 4 separate integers.
	int iColor1, iColor2, iColor3, iColor4;							// The generated code split into for the player or A.I. to guess.
	int iScore = 0, iAIscore = 0;									// Variables that store the player and the A.I.'s score during the game.
	
	printf("Welcome to Mega Mastermind!");		// The start menu screen that displays the different options.
	printf("\nPlease select an option.");
	printf("\n[0] Start!"); 					// Goes to line 178, which starts the game.
	printf("\n[1] How to play");				// Goes to line 462, which displays the instructions and rules of the game.
	printf("\n[2] Exit");
	printf("\n[3] Creator info.\n");			// Goes to line 485, which displays the creator's infomation.
	
	scanf("%d", &iSelectScreen);
	system("cls");
	
	if (iSelectScreen == 0)
	{
		printf("Choose difficulty:\n");				// Just a simple addition to the game where the player
		printf("[0] Easy - 10 attempts.\n");		// can choose the ammount of attempts for each round.
		printf("[1] Average - 12 attempts.\n");
		printf("[2] Difficult - 16 attempts.\n");
		printf("[3] Extreme - 20 attempts.\n");
		scanf("%d", &iChoicea);
													
		while (iChoicea != 0 && iChoicea != 1 && iChoicea != 2 && iChoicea != 3) // Corrects the user input if it isn't valid.
		{
			printf("Invalid Input\n");
			scanf("%d", &iChoicea);
		}
			
		if (iChoicea == 0)
		iAttempts = 10;
		if (iChoicea == 1)			// The amount of attempts per round depends on the user input for iChoicea.
		iAttempts = 12;
		if (iChoicea == 2)
		iAttempts = 16;
		if (iChoicea == 3)
		iAttempts = 20;
			
		printf("\nHow many rounds do you want to play? [2] [4] [6] [8] [10]\n"); // Player selection for the amount of rounds in each playthrough.
		scanf("%d", &iChoiceb);
		
			while (iChoiceb != 2 && iChoiceb != 4 && iChoiceb != 6 && iChoiceb != 8 && iChoiceb != 10)
			{
				printf("Invalid input.\n");											// Corrects the user input if it isn't valid.
				scanf("%d", &iChoiceb);
			}

			iRounds = iChoiceb - (iChoiceb - 1); 		// Equation to turn rounds into the value "1" for the beginning of the game.
			
			system("cls");
			printf("Would you like to play as the code guesser or code maker first?\n[0] Code Guesser\n[1] Code Maker\n");
			scanf("%d", &iSelect);
		
				while (iSelect != 0 && iSelect != 1)
				{
					printf("Invalid input.\n");
					scanf("%d", &iSelect);
				}
		
			for (j = 1; j != iChoiceb; j++)		// for loop that allows Code Guesser to be the Code Maker, and vice versa.
			{
				
			while (iSelect == 0)
			{		
				system("cls");
				printf("\tYou are now the Code Guesser.\n");
				printf("Input four different colours between 1 to 6 following the code:\n");
				printf("\t1  2  3  4  5  6\n\tR  O  Y  G  B  I\n");
				iColor1 = randomize();
				iColor2 = randomize();		// Code to randomly generate numbers from 1 to 6.
				iColor3 = randomize(); 
				iColor4 = randomize();
	
				iCode = codemaker(iColor1, iColor2, iColor3, iColor4);
			
				printf("Round %d out of %d", iRounds, iChoiceb); // Displays which round is currently being played.
			
			do
			{
				printf("\nAttempt %d\n", i + 1);		// Displays the attempt no. based on the difficulty.
				scanf("%d", &iGuess);
				
				iGuess1 = iGuess / 1000;
				iGuess2 = iGuess % 1000 / 100;
				iGuess3 = iGuess % 100 / 10;
				iGuess4 = iGuess % 10;
													// Lines of code to separate the 4-digit user input into separate intergers.
				iColor1 = iCode / 1000;
				iColor2 = iCode % 1000 / 100;
				iColor3 = iCode % 100 / 10;
				iColor4 = iCode % 10;
				
					if (iGuess1 > 6 || iGuess1 < 1 || iGuess2 > 6 || iGuess2 < 1 || iGuess3 > 6 || iGuess3 < 1 || iGuess4 > 6 || iGuess4 < 1)
				{
					printf("Invalid Input. Enter another set of digits.\n");		// Corrects the user input if it doesn't satisfy the required digits.
					scanf("%d", &iGuess);
				} 
					else if (iGuess1 == iGuess2 || iGuess1 == iGuess3 || iGuess1 == iGuess4 || iGuess2 == iGuess3 || iGuess2 == iGuess4 || iGuess3 == iGuess4)
				{
					printf("Invalid Input. Enter another set of digits.\n");
					scanf("%d", &iGuess);
				}
					else if (iGuess1 != 1 && iGuess1 != 2 && iGuess1 != 3 && iGuess1 != 4 && iGuess1 != 5 && iGuess1 != 6 &&
							iGuess2 != 1 && iGuess2 != 2 && iGuess2 != 3 && iGuess2 != 4 && iGuess2 != 5 && iGuess2 != 6 &&
							iGuess3 != 1 && iGuess3 != 2 && iGuess3 != 3 && iGuess3 != 4 && iGuess3 != 5 && iGuess3 != 6 &&
							iGuess4 != 1 && iGuess4 != 2 && iGuess4 != 3 && iGuess4 != 4 && iGuess4 != 5 && iGuess4 != 6)
				{
					printf("Invalid Input. Enter another set of digits.\n");		// Corrects the user input if it doesn't satisfy the required digits.
					scanf("%d", &iGuess);
				} 
					else
					pegchecker(iGuess1, iGuess2, iGuess3, iGuess4, iColor1, iColor2, iColor3, iColor4);	
				
					if (iGuess == iCode)		// Executes if the user correctly guesses the generated code from the A.I.
				{
					printf("\nCongratulations! You won in %d attempt(s).\n", i + 1);
					printf("A.I scored %d points.", i + 1);
					iAIscore = iAIscore + i + 1;			// Stores the score of the A.I. for the score board.
					i = iAttempts;
				}
				i++;
			} while (i < iAttempts);
		
		if (i == iAttempts) 		// Executes if the user no longer has any attempts.
		{
			printf("\n\nUnfortunately, you're out of attempts.\n");
			printf("A.I scored %d points.", i + 1);
			iAIscore = iAIscore + i + 1; 
		}
		
			if (iRounds == iChoiceb) // Executes in the event that the game end after the player is the Code Guesser.
			{
				sleep(2);
				system("cls");
				printf("That's the end of the game. Thanks for playing!\n");
				printf("You scored %d points total, and the AI scored %d points total.\n", iScore, iAIscore);	// Displays the score for the player and the A.I.
					if (iScore > iAIscore)
					printf("\nCongratulations! You Won!");				// Displays if the player wins the game.
					else if (iScore < iAIscore)
					printf("\nUnfortunately, you weren't able to beat the machine. Better luck next time.");	// Displays if the player wasn't able to beat the A.I.
					else if(iScore == iAIscore)
					printf("\nThis game has no victor. It's a tie.");		// Diplays if the game has no victor, and the game ends in a tie.
				abort();
			}
			
			else if (iRounds != iChoiceb)			// Executes if there are no more attempts, or the player has correctly guessed the code.
			{
				printf("\n\nDo you want to move onto the next round?");
				printf("\n[1]Yes[0]No\n");
				scanf("%d", &iChoicec);
			}
			
				i = i - i;		// Resets the score and the attempts for the next round
				iRounds++;		// Increment for the round number.
			
				switch (iChoicec)		// Connected to the code in line 262, which either ends the game or sends the player to the next round.
				{
					case 1: iSelect = 1; break;		// Switch case that sends the user to being the Code Maker.
					case 0: system("cls");
							printf("Thanks for playing!");
							abort(); break;					// Switch case that ends the game abruptly.
					default: printf("Invalid input.\n");
							scanf("%d", &iChoicec); break;		// Corrects the user input if it isn't valid.
				}
	 	}
	
	for (j = 1; j != iChoiceb; j++)		// for loop that allows Code Maker to be the Code Guesser, and vice versa.
		while (iSelect == 1)
		{
			system("cls");
			printf("\tYou are now the Code Maker.\n");
			printf("Input four different colours between 1 to 6 following the code:\n");
			printf("\t  1  2  3  4  5  6\n\t  R  O  Y  G  B  I\n");
			printf("Round %d out of %d\n", iRounds, iChoiceb);
			scanf("%d", &iCode);
		
				if (iCode > 6666 || iCode < 1111)		// Corrects the user input if it doesn't fit the criteria.
				{
					printf("Invalid Input. Enter another set of digits.\n");
					scanf("%d", &iCode);
				} 	
					iColor1 = iCode / 1000;
					iColor2 = iCode % 1000 / 100;		// Splits the user input into 4 different integers.
					iColor3 = iCode % 100 / 10;
					iColor4 = iCode % 10;
				
				if (iColor1 > 6 || iColor1 < 1 || iColor2 > 6 || iColor2 < 1 || iColor3 > 6 || iColor3 < 1 || iColor4 > 6 || iColor4 < 1)
				{
					printf("Invalid Input. Enter another set of digits.\n");		// Corrects the user input if it isn't valid.
					scanf("%d", &iCode);
				} 
				
				else if (iColor1 == iColor2 || iColor1 == iColor3 || iColor1 == iColor4 || iColor2 == iColor3 || iColor2 == iColor4 || iColor3 == iColor4)
				{
					printf("Invalid Input. Enter another set of digits.\n");
					scanf("%d", &iCode);
				}
				
				while (iColor1 != 1 && iColor1 != 2 && iColor1 != 3 && iColor1 != 4 && iColor1 != 5 && iColor1 != 6 &&
							iColor2 != 1 && iColor2 != 2 && iColor2 != 3 && iColor2 != 4 && iColor2 != 5 && iColor2 != 6 &&
							iColor3 != 1 && iColor3 != 2 && iColor3 != 3 && iColor3 != 4 && iColor3 != 5 && iColor3 != 6 &&
							iColor4 != 1 && iColor4 != 2 && iColor4 != 3 && iColor4 != 4 && iColor4 != 5 && iColor4 != 6)
				{
					printf("Invalid Input. Enter another set of digits.\n");		// Corrects the user input if it doesn't satisfy the required digits.
					scanf("%d", &iCode);
				} 
			
		do
		{
			printf("\nA.I attempt %d", i + 1);		// Displays which attempts is currently being played.
			sleep(1);
			iColor1 = randomize();
			iColor2 = randomize();
			iColor3 = randomize(); 		// Generates 4 different integers.
			iColor4 = randomize();
			
			do{iColor1 = rand() % 6 + 1;
			}while (iColor1 == iColor2 || iColor1 == iColor3 || iColor1 == iColor4);
		 
			do{iColor2 = rand() % 6 + 1;
			}while (iColor2 == iColor3 || iColor2 == iColor4 || iColor2 == iColor1);	// Corrects the integers if a duplicate is generated.
		 
			do{iColor3 = rand() % 6 + 1;
			}while (iColor3 == iColor4 || iColor3 == iColor1 || iColor3 == iColor2);
			
			iGuess1 = iCode / 1000;
			iGuess2 = iCode % 1000 / 100;		// Splits the user input into 4 different intergers for the A.I. to guess.
			iGuess3 = iCode % 100 / 10;
			iGuess4 = iCode % 10;
			
			printf("\n   %d %d %d %d", iColor1, iColor2, iColor3, iColor4);		// Displays the A.I.'s guess.
			printf("\n   ");
			
			pegchecker(iGuess1, iGuess2, iGuess3, iGuess4, iColor1, iColor2, iColor3, iColor4);
			
			iGuess = combineAIguess(iGuess1, iGuess2, iGuess3, iGuess4); // Turns the user input and the A.I.'s guess into 4-digit integers.
			iCode = combineHumaninput(iColor1, iColor2, iColor3, iColor4);
			
			if (iCode == iGuess)		// Executes if the A.I. correctly guesses the user's code.
			{
				printf("\nUnfortunately the AI has won on attempt %d.", i+1);
				printf(" You scored %d points.", i);
				iScore = iScore + i;
				i = iAttempts;
			}
			i++;
		}	while (i < iAttempts);		// Condition for the do-while loop where the control integer is less than the attempts.
	
		 if (i == iAttempts)	 // Executes if the amounts of attempts has been used by the A.I.
		{
		printf("\nThe AI has failed to guess your code.\nCongratulations! You scored %d points!", i + 1);
		iScore = iScore + i + 1;
		}
		
		else if (i < iAttempts) 	// Executes if the A.I. has correctly guessed the user's code.
		{
		printf("\nUnfortunately the AI has won on attempt %d.", i+1);
		printf(" You scored %d points.", i);
		}
		
		if (iRounds  == iChoiceb)		// Executes in the event that the game end after the player is the Code Maker.
		{
		sleep(2);
		system("cls");
		printf("That's the end of the game. Thanks for playing!\n");
		printf("You scored %d points total, and the AI scored %d points total.", iScore, iAIscore);		// Displays the total scores for the player and the A.I.
				if (iScore > iAIscore)
				printf("\nCongratulations! You Won!");
				else if (iScore < iAIscore)
				printf("\nUnfortunately, you weren't able to beat the machine. Better luck next time."); 	// Displays in the event that the player wasn't able to beat the A.I.
				else if(iScore == iAIscore)
				printf("\nThis game has no victor. It's a tie.'"); 				// Diplays in the event that the game has no victor, and ends in a tie.
		abort();
	}
	
	else if (iRounds != iChoiceb)		
	{
	printf("\n\nDo you want to move onto the next round?");		// Asks the player if they want to continue or end the game abruptly.
	printf("\n[1]Yes\n[0]No\n");
	scanf("%d", &iChoicec);
	
		iRounds++;		// Increments the round number.
		i = i - i;		// Resets the amount of attempts back to 1.
		
		switch (iChoicec)
		{
			case 1:	iSelect = 0; break;					// Switch statement that sends the user back to being the Code Guesser.
			case 0: system("cls");
					printf("Thanks for playing!");		// Switch case that ends the game abruptly.
					abort(); break;
			default: printf("Invalid input.\n");
					scanf("%d", &iChoicec); break;		// Corrects the user input if it isn't valid.
		}
	}
	}
	}
	}
	
 	else if (iSelectScreen == 1)
	{
	printf("In this game, you are fighting a against a machine where both of your goals are to outscore each other in the game of Mastermind.\n");
	printf("You have the option of either becoming the code maker or the code guesser in the first round, and the machine assumes the other role.\n");
	printf("\nCODE GUESSER");
	printf("\nYou need to correctly guess the color code that the machine has created for you. For each wrong guess, the machine");
	printf("\ngets awarded 1 point. But, don't worry as black and white pegs will serve as clues to help you. A white peg means that you guessed a");
	printf("\ncorrect color but it's in the wrong position, while a black peg means that you have correctly guessed a color and it's in the right");
	printf("\nposition.\n");
	printf("\nCODE MAKER");
	printf("\nYou are to input a code for the machine to guess. For every wrong guess that the machine makes, you will be awarded");
	printf("\n1 point. Just like your role in being the code guesser, the machine will also get black and white pegs to help it correctly your code.\n");
	printf("\nRULES");
	printf("\n1. Duplicate pegs are not allowed, otherwise an error will occur and you will have to enter another code.");
	printf("\n2. Only 1 player per role at a time. Two players cannot become the code guesser, or code maker, at once");
	printf("\n3. Only 4 colors can be played at once. You can't place down 6 different colors and expect the machine to guess.");
	printf("\n4. You can only play to the amount of attempts and rounds agreed upon before the game began.");
	printf("\n5. The player with the most point at the end of the game, wins.");
	printf("\n\nHave Fun!");
	}
	else if (iSelectScreen == 2)
	system("cls");
	
	else if (iSelectScreen == 3)
	{
	printf("Program created by\nCarl Justine Sicat Alamay of\nBS CS-CSE during the first term of SY 2022-2023.");
	printf("\n\nCourse Professor: Sir Gary Soriano.");
	}
	
	else
	printf("Invalid option.");
	
return 0;
}
