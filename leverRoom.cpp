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
#include "leverRoom.hpp"

LeverRoom::LeverRoom(){
	// Initalize values
	name = "Library Room";

	menuOptions.push_back("Arrange the books: E. Hemingway, W. Shakespeare, V. Woolf");
	menuOptions.push_back("Arrange the books: V. Woolf, W. Shakespeare, E. Hemingway");
	menuOptions.push_back("Arrange the books: W. Shakespeare, V. Woolf, E. Hemingway");

	choice.setDisplayMenu(menuOptions);
}

LeverRoom::~LeverRoom(){
}

bool LeverRoom::roomInteraction(){
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

void LeverRoom::roomDescription(){
	cout << "*********" << this->getName() << " Description:" << endl;
	cout << "You walk into the next room. Polar opposite of the previous room,\n" \
			"this room is unbelievably clean...and full of books. It appears that\n" \
			"everything in this room has the hint of being in a very specific place.\n" \
			"As if everything is very carefully planned.\n"\
			"- You notice the door across the room. Above it is a sign that reads:\n" \
			"\"Good order is the foundation of all great things.\"" << endl;
}
