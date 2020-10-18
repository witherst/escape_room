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
#include <sstream>		// Stringstream, for input validation
#include <iostream>
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Menu::Menu(){
	choice = "";
	userInput = -1;
	minChoice = 0;
	maxChoice = 0;
}

void Menu::setDisplayMenu(std::vector<std::string> userMenu){
	// Clear anything that could be in the menu, just in case
	menu.clear();

	// Populate menu with prompt for user	
	menu.push_back("Please select an option:");

	for(int i = 0; i < userMenu.size(); i++){
		menu.push_back(userMenu[i]);
	}

	minChoice = 1; // TODO: May want to make this other than 1 for future assignments
	maxChoice = menu.size();
}

void Menu::displayMenu(){
	for(int i = 1;i < menu.size();i++){
		cout << i << ")" <<  menu[i] << endl;
	}
}

void Menu::promptUserInput(){	
	bool validInput = false;

	while(!validInput){
		cout << "Choice: ";
		cin >> choice;
		validInput = isValidInt(choice);	
	}
}

/*************************************************************
 * isValidInt(string choice) well use the stringstream object ss and attempt
 * 	to put that object into userInput, which is an int. If it succeeds and is
 * 	within the range of the menu options, return true. Method taken from the 
 * 	youtube channel "Beginners Programming. Data Validation with String Stream"
*************************************************************/
bool Menu::isValidInt(string choice){
	std::stringstream ss(choice);
	if(ss >> userInput && userInput >= minChoice && userInput <= maxChoice-1){
		return true;
	}
	else{
		cout << "Wrong input. Please enter a value between " << minChoice << " and " << maxChoice-1 << "." << endl;
	}
	return false;

}

// Setters
int Menu::setMinChoice(int val){
	minChoice = val;
}

int Menu::setMaxChoice(int val){
	maxChoice = val;
}

// Getters
int Menu::getUserInput(){
	return userInput;
}

int Menu::getMinChoice(){
	return minChoice;
}

int Menu::getMaxChoice(){
	return maxChoice;
}
