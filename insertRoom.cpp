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
#include "insertRoom.hpp"

InsertRoom::InsertRoom(){
	// Initalize values
	name = "Insertion Room";

	menuOptions.push_back("Put Bird - Diamond into door slot");
	menuOptions.push_back("Put Bird - Circle into door slot");
	menuOptions.push_back("Put Bird - Square into door slot");

	choice.setDisplayMenu(menuOptions);
}

InsertRoom::~InsertRoom(){
}

bool InsertRoom::roomInteraction(){
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
			return true;
			break;
		case 3:
			return false;
			break;
		default:
			break;
	}
}

void InsertRoom::roomDescription(){
	cout << "*********" << this->getName() << " Description:" << endl;
	cout << "You slowly walk into the room. Immediately you spot the DOOR on the opposite wall.\n " \
		"You also notice the room is full of garbage.\n" \
		"There's random undescript items all over the place.\n" \
		"As you start walking towards the door, you notice three remarkably\n" \
		"clean, small, objects on the ground.\n" \
		"You pick them up and inspect them:\n" \
		"- They are all the same bird shape. The only difference are the eyes.\n" \
		"- One has a diamond shaped eye.\n" \
		"- One has a circular shaped eye.\n" \
		"- One has a square shaped eye.\n" \
		"You put them in your backpack and continue to the door.\n";

}
