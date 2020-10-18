/***********************************************************
 ** Program name: 	escapeRoom
 ** Author: 		Tim Withers
 ** Date:			3/16/2019
 **	Description:	This program simulates an escape room text game.
 *					There are 6 rooms total. The user always starts in
 *					room 1 and goes until room 6. Each room has a different
 *					puzzle for the user to solve. If the user picks the 
 *					wrong answer for any puzzle, they will die and the game
 *					is over. After successfully solving room 6's puzzle, the user
 *					escapes the building and wins the game.
 ************************************************************/
#include "mathRoom.hpp"

MathRoom::MathRoom(){
	// Initalize values
	name = "Math Room";

	menuOptions.push_back("You press the button: 14");
	menuOptions.push_back("You press the button: 49");
	menuOptions.push_back("You press the button: 50");


	choice.setDisplayMenu(menuOptions);
}

MathRoom::~MathRoom(){
}

bool MathRoom::roomInteraction(){
	do{
		cout << "Actions: " << endl;
		choice.displayMenu();
		cout << "Choice: ";
		cin >> userInput;
	}while(!InputValid::isValidInt(userInput, menuChoice, 1, menuOptions.size()));	

	switch(menuChoice){
		case 1:
			return true;
			break;
		case 2:
			return false;
			break;
		case 3:
			return false;
			break;
		default:
			break;
	}
}

void MathRoom::roomDescription(){
	cout << "*********" << this->getName() << " Description:" << endl;
	cout << "This room is...completely white. Harsh lighting from flourescent lights\n" \
			"make this room feel like a doctor's office. You have a very bad feeling about\n" \
			"this room for some reason. You immediately rush to the door, which is on the opposite\n" \
			"side of the room." << endl; 
}
