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
#ifndef TWITHERS_SIM_HPP
#define TWITHERS_SIM_HPP
#include <vector>
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include "menu.hpp"
#include "inputValid.hpp"
#include "player.hpp"
#include "building.hpp"
#include "bloodRoom.hpp"

class Sim
{
	private:
		Menu choice;
		std::vector<std::string> menuOptions;

		// For input validation
		std::string userInput;
		int menuChoice;

		// Private Functions
		void getMenuChoice(std::vector<std::string>);

		// Room functions
		void room1();
		void room2();
		void room3();
		void room4();
		void room5();
		void room6();
		void escapeRoom();
	
		// Game variables
		bool gameWon = false;
		bool escaped = false;		// To be used to trigger whether or not the player escaped a room
		bool playerDied = false;
		Player p1;
		Item pItem;			// Player item
		Building myBldg;
		int playerRoom = 0;
		Space* playerSpace = nullptr;

		// Game won, I guess
		void lameWin();
			
	public:
		// Constructor(s)
		Sim();

		// Destructor
		~Sim();

		// Public Functions
		void simGame();
		void greeting();
		void intro();
		void printBP();
		void resetGame();

		// Pause for user to read
		void pause();
};

#endif
