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
#include "lightRoom.hpp"

LightRoom::LightRoom(){
	// Initalize values
	name = "Light Room";

	menuOptions.push_back("Blow out all the candles in the room. Making it completely dark.");
	menuOptions.push_back("Take a candle and light the door candle.");

	choice.setDisplayMenu(menuOptions);
}

LightRoom::~LightRoom(){
}

bool LightRoom::roomInteraction(){
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
		default:
			break;
	}
}

void LightRoom::roomDescription(){
	cout << "*********" << this->getName() << " Description:" << endl;
	cout << "As you walk into the next room you are greeted with a very soft,\n" \
			"warm glow from, what must be, hundreds of candles scattered throughout\n" \
			"the room.\n" \
			"You notice the door on the opposite side of the room and see a quote:\n" \
			"\"After darkness comes the light.\"" << endl;	
}
