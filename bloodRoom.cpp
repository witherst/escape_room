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

#include "bloodRoom.hpp"

BloodRoom::BloodRoom(){
	// Initalize values
	name = "Blood Room";

	menuOptions.push_back("Enter code 0951 into the number pad.");
	menuOptions.push_back("Enter code 0159 into the number pad.");
	menuOptions.push_back("Enter code 0591 into the number pad.");

	choice.setDisplayMenu(menuOptions);
}

BloodRoom::~BloodRoom(){
}

/****************************************************************
 * If the user enters 1 or 2, this is the wrong number and the	*
 * player will die for their INABILITY TO PAY ATTENTION.		*
 ****************************************************************/
bool BloodRoom::roomInteraction(){
	do{
		cout << "Actions: " << endl;
		choice.displayMenu();
		cout << "Choice: ";
		cin >> userInput;
	}while(!InputValid::isValidInt(userInput, menuChoice, 1, menuOptions.size()));	

	switch(menuChoice){
		case 1:
			return false;
			break;
		case 2:
			return false;
			break;
		case 3:
			return true;
			break;
		default:
			break;

	}

}

void BloodRoom::roomDescription(){
	cout << "*********" << this->getName() << " Description:" << endl;
	cout << "The room has a wet iron smell." << endl;
	cout << "Next to the door you were just looking at is a\n" \
		"large number 0 written on the wall. It appears there are\n" \
		"more numbers to the right of it, but covered with, what\n" \
		"now is clearly, blood." << endl;
}
