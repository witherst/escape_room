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
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "menu.hpp"
#include "sim.hpp"

int main(){
	bool playAgain = true;
	
	// For inputValidation
	std::string userInput;
	int userChoice;
	
	// Menu(s)
	Menu mainMenu;	

	// Set up the mainMenu Options display 
	std::vector<std::string> menuOptions;
	menuOptions.push_back("Play again?");
	menuOptions.push_back("Exit.");
	
	// Set menu
	mainMenu.setDisplayMenu(menuOptions);
	
	

	// Sim
	Sim escapeRoom;

	do{
		// Start sim
		escapeRoom.simGame();

		// Play again?
		do{	
				cout << endl;
				cout << "--------------------------------------------" << endl;	
				mainMenu.displayMenu();	
				cout << "Choice: ";
				cin >> userInput;
		 }while(!InputValid::isValidInt(userInput, userChoice, 1, menuOptions.size()));
	
		switch(userChoice){
			case 1:
				escapeRoom.resetGame();
				playAgain = true;	
				break;
			case 2:
				playAgain = false;
				break;
			default:
				break;
		
		}
	} while(playAgain);	
	
	return 0;
}
