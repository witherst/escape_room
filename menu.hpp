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
#ifndef TWITHERS_MENU_HPP
#define TWITHERS_MENU_HPP

#include <string>
#include <vector>

class Menu
{
	private:
		//Board playerBoard;
		std::string choice;
		std::vector<std::string> menu;
		int userInput;
		int minChoice;		// Min num of menu choice, most likely will be 1. Sometimes 0 perhaps?
		int maxChoice;		// Depending on the number of menu choices, this can be a wide variety of nums.

	public:	
		// Constructor
		Menu();

		// Getters and setters
		int getUserInput();
		int getMinChoice();
		int getMaxChoice();
		int setMinChoice(int);
		int setMaxChoice(int);
		void setDisplayMenu(std::vector<std::string>);

		// Functions
		void displayMenu();		
		void promptUserInput();
		bool isValidInt(std::string);

};

#endif
