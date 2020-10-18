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
#include "depressRoom.hpp"

DepressRoom::DepressRoom(){
	// Initalize values
	name = "Depress Room";

	menuOptions.push_back("Place the Small, Shiny Circle Bird on the \"tongue\"");
	menuOptions.push_back("Place the Large, Shiny Diamond Bird on the \"tongue\"");
	menuOptions.push_back("Place the Medium, Shiny Square Bird on the \"tongue\"");
	
	choice.setDisplayMenu(menuOptions);
}

DepressRoom::~DepressRoom(){
}

bool DepressRoom::roomInteraction(){
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

void DepressRoom::roomDescription(){
	cout << "*********" << this->getName() << " Description:" << endl;
	cout << "You walk into the room. Immediately you notice every square inch\n" \
			"of every wall is full of different types of Cuckoo clocks. What is it\n" \
			"with this place and birds? The sounds of the tick-tocks are overwhelming.\n" \
			"There's a table to your right with, you guessed it, three items on it.\n" \
			"These items look familiar. They're all differently shaped birds. The only\n" \
			"distinguishing features are, once again, the eyes:\n"\
			"- One bird is small and has two shiny circles for eyes.\n"\
			"- One bird is large and has two shiny diamonds for eyes.\n"\
			"- One bird is medium size and has two shiny squares for eyes.\n" << endl;
}
