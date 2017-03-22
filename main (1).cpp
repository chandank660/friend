//  Rock, Paper, Scissors Interview Question
//
//  Created by Manjith Krishnappa.
//  Adapted by Vidur Murali.
//
//  ---
//
//  Candidate Name: Chandan Kumar
//  Date:           12/03/2017
//
//

//  ---
//  GAME DESIGN SPEC
//  ---
//  Rock, Paper, Scissors is a two-person game typically played using hand gestures.
//  Both players make a fist with one hand and hold the other open, palm upward. Together,
//  they tap their fists in their open palms once, twice, and on the third time form one
//  of three items: a rock (by keeping the hand in a fist), a sheet of paper (by holding
//  the hand flat, palm down), or a pair of scissors (by extending the first two fingers
//  and holding them apart in a “V”).
//
// There are only three possible outcomes other than a tie:
//  1) Rock cuts Scissors
//  2) Paper covers Rock
//  3) Scissors cuts Paper
//
// If both players throw the same shape, the game is tied and is usually replayed to break the tie.
//

// ---
// PROBLEM STATEMENT
// ---
//  1. Write a game of rock paper scissors using the skeleton code that is provided below.
//  2. Set up a loop for the game which prompts the player to input if he/she would like to
//     play another game and restart or exit based on that.
//  3. Bonus:
//      - Set up a prediction mechanism such that the computer chooses its move based on
//        the previous selections of the user. e if the user has selected paper consistently
//        then the computer will predict that the user might select paper in the next round
//        and select scissors based on this. (probabilistic)
//      - Abstract out all the hard-coded variables such that it will be easy to add one more
//        Selection to the game
//

// ---
// EVALUATION CRITERIA
// ---
// 1. Functionality - First and foremost, the submitted code should work and meet the spec.
// 2. Modularity - An ideal solution will be modular and be able to adapt to possible
//    changes in spec
// 3. Formatting - Code should be formatted and readable. i.e.:
//      - Good documentation
//      - Good use of whitespace
//      - Lines are not too long (80 chars is a good rule of thumb)
//      - Variable names are meaningful
//      - There are no hardcoded 'magic' numbers
//      - There should be no 'dead code' - code that is unused
// 4. Attention to detail:
//      - Failure conditions and errors are handled
//      - Memory is handled properly - anything that is allocated is also disposed
//
//


#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

enum Selection {
    NONE,
    ROCK,
    PAPER,
    SCISSORS
};

enum Result {
    DRAW,
    WON,
    LOST,
    ERROR
};

// Figure out what the selection is from the specified integer
Selection GetSelectionForInteger(int inputInteger) {
		Selection R=ROCK;
		Selection S=SCISSORS;
		Selection P=PAPER;
		Selection N=NONE;

	if(inputInteger==1)
		return R;
    else if(inputInteger==2)
		return P;
	else if(inputInteger==3)
		return S;
	 else
		return N;
	
}

// Returns a random number between min and max, inclusive of both
int GetRandomNumber(int min, int max) {
    srand(time(NULL)); 
int random = rand() % max + min;
return random;
}

// Returns the selection for the AI according to a certain strategy
Selection GetAISelection() {
	int min=GetRandomNumber(1,10);
		Selection R=ROCK;
		Selection S=SCISSORS;
		Selection P=PAPER;
		Selection N=NONE;
	if(min>=0&&min<=3){
		return R;
	}
	else if(min>=7&&min<=9){
		return S;	
	}	
			else if(min>=4&&min<=6){
		return P;
	}else {
		return N;
	}

}

// Compares the user's selection to the AI's selection,
// and determines the result of the round. If the user beats
// the AI it is considered a WIN, etc.
Result GetResult(Selection userSelection, Selection aiSelection) {
	Result D=DRAW;
	Result W=WON;
	Result L=LOST;
    if(userSelection==ROCK && aiSelection==1){
		return D;
	}
	 else if(userSelection==PAPER && aiSelection==1){
		return L;
			}
   
 	else if(userSelection==SCISSORS && aiSelection==1){
	return L;
	}
    else if(userSelection==ROCK && aiSelection==2){
	return W;
	}
    else if(userSelection==ROCK && aiSelection==3){
		return W;
	}
    else if(userSelection==PAPER && aiSelection==2){
	return D;
	}
    else if(userSelection==PAPER && aiSelection==3){
	return L;
	}
    else if(userSelection==SCISSORS && aiSelection==3){
	return D;
	}
	 else if(userSelection==SCISSORS && aiSelection==2){
		return W;}
	 else if(userSelection==SCISSORS && aiSelection==1){
	return L;}
   else {
	cout << "Error";
}
}

// Display the instructions of what number corresponds to which selection
void ShowInitalUI(int roundNum) {
    cout << "\nRound #" << roundNum << ":\n";
    cout << "\nEnter the number associated with the option below to select your move:";
    cout << "\n1. Rock";
    cout << "\n2. Paper";
    cout << "\n3. Scissors";
    cout << "\n> ";
}

// Displays the appropriate string for each Selection
void DisplaySelection(Selection a_nSelection) {
     
	  switch(a_nSelection){
  	case 1: 
  	cout<<"Rock";
  	break;
  
    case 2: 
  	cout<<"Paper";
  	break;
  	
     case 3: 
  	cout<<"Scissors";
  	break;
  
     case 4: 
  	exit;
  	break;        
	default: cout << "";
}
}

// Displays an appropriate string for each Result
void DisplayResult(Result result) {
    if(result == WON) {
        cout<<"\n\n YOU have WON this round";
        
    } else if(result == LOST) {
        cout<<"\n\n The COMPUTER has WON this round";
        
    } else if(result == DRAW) {
        cout<<"\n\n This round is a DRAW";
        
    } else {
        cout<<"\n\n Oops! Something has gone wrong!";
    }
}

int main(int argc, const char * argv[]) {
    
    // Init variables
    int roundNum = 1;
    
    Selection playerSelection = NONE;
    Selection aiSelection     = NONE;
    
    // Start game
    cout << "\nWelcome to a game of Rock, Paper, Scissors!\n";
    do
	{
		
    ShowInitalUI(roundNum);
    
    // Gets player input
    
	string input;
    getline(cin, input);
    // TODO: Use input apporpriately
    // Hint: Look up the 'atoi' function to parse the string to int
    int playerInputInt=atoi(input.c_str());
    playerSelection = GetSelectionForInteger(playerInputInt);

    // Show selected option
    cout<<"\nYou have Selected: ";
    DisplaySelection(playerSelection);
    
    // Let the AI make a selection
    aiSelection = GetAISelection();
    
    // Show option selected by AI
    cout<<"\nThe Computer has Selected: ";
    DisplaySelection(aiSelection);
    
    //Display final result
    Result result = GetResult(playerSelection, aiSelection);
    DisplayResult(result);
   
 
    ++roundNum;
    cout<<"\n Do you want to play again press any key or press Q or q to exit \n";
    string x;
    getline(cin, x);
    if(x=="q"||x=="Q")
    {
    	break;
	}
     }while(roundNum!=1);
    cout << "\nThank you for playing!";
    return 0;
}
