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
#ifndef TWITHERS_SPACE_HPP
#define TWITHERS_SPACE_HPP

#include <vector>
#include <string>
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include "menu.hpp"
#include "inputValid.hpp"

class Space
{
	protected:
		Space* up;
		Space* down;
		Space* left;
		Space* right;	

		std::string name;

		// Menu stuff
		Menu choice;
		std::vector<std::string> menuOptions;
		int menuChoice;
		std::string userInput;
					
	public:
		// Constructor(s)
		Space();
	
		// Getters
		Space* getUp(){ return this->up; }
		Space* getDown(){ return this->down; }
		Space* getLeft(){ return this->left; }
		Space* getRight(){ return this->right; }

		std::string getName(){ return this->name; };

		// Setters
		void setUp(Space* up){ this->up = up; }
		void setDown(Space* down){ this->down = down; }
		void setLeft(Space* left){ this->left = left; }
		void setRight(Space* right){ this->right = right; }
		void setName(std::string name){ this->name = name; }

		// Public Functions
		virtual void roomDescription();
		virtual bool roomInteraction() = 0;		// This will return true if player passed through to the next room. If false, player dies.

};

#endif
