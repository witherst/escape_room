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

#include "building.hpp"

Building::Building(){
	// Any room variable (up, left, down, right) not set below is already nullptr
	// room1
	room1->setRight(room2);

	// room2
	room2->setLeft(room1);
	room2->setRight(room3);

	// room3
	room3->setLeft(room2);
	room3->setRight(room4);
	
	// room4
	room4->setLeft(room3);
	room4->setRight(room5);

	// room5
	room5->setLeft(room4);
	room5->setRight(room6);

	// room6
	room6->setLeft(room5);	
		
}

Building::~Building(){
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	delete room6;
}
