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
#include <sstream>
#include <iostream>
#include "inputValid.hpp"

/*************************************************************
 * isValidInt(string choice) well use the stringstream object ss and attempt
 * 	to put that object into userInput, which is an int. If it succeeds and is
 * 	within the range of the menu options, return true. Method taken from the 
 * 	youtube channel "Beginners Programming. Data Validation with String Stream"
 *
 * 	Also, a required OUTval is passed through. If the input is valid, then the
 * 	 OUTval will be equal to whatever the correct int is. This is needed because
 * 	 the initial value is passed in a string and should be used as an int.
 *
 * 	The function takes an optional min and max value in case the user wants to
 * 	 check if the int is within a certain range.
*************************************************************/
bool InputValid::isValidInt(std::string userInput, int &OUTval, int min, int max){
	std::stringstream ss(userInput);

	int intCheck;
	bool flag = false;
	std::string errorMessage = "";

	if(ss >> intCheck){
		// Is both min and max set? 
		if(min != -1 && max != -1){
			// If so, check to see if they are within range
			if(intCheck >= min && intCheck <= max){
				flag = true;
			}
			else{
				errorMessage = "Integer not within acceptable input range.";
				flag = false;
			}
			
		}
		else if(min != -1){	
			if(intCheck >= min){
				flag = true;
			}
			else{
				errorMessage = "Integer is below minimum number input.";
				flag = false;
			}
			
		}
		else if(max != -1){
			// Check maximum
			if(intCheck <= max){
				flag = true;
			}
			else{
				errorMessage = "Integer is over max number input.";
				flag = false;
			}
		}
	}
	else{
		errorMessage = "Not an integer.";
		flag = false;
	}

	// If !flag, so if flag is set to false, then there was an error. Print out the message.	
	if(flag){
		OUTval = intCheck;
	}
	else{
		std::cout << errorMessage << std::endl;
	}

	return flag;

}
