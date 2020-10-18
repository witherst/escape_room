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

#ifndef TWITHERS_BUILDING_HPP
#define TWITHERS_BUILDING_HPP

#include <string>
#include "bloodRoom.hpp"
#include "insertRoom.hpp"
#include "leverRoom.hpp"
#include "depressRoom.hpp"
#include "lightRoom.hpp"
#include "mathRoom.hpp"

class Building
{
	private:
		BloodRoom* room1 = new BloodRoom();
		InsertRoom* room2 = new InsertRoom();
		LeverRoom* room3 = new LeverRoom();
		DepressRoom* room4 = new DepressRoom();
		LightRoom* room5 = new LightRoom();
		MathRoom* room6 = new MathRoom();
							
	public:
		// Constructor(s)
		Building();

		// Destructor
		~Building();

		// Getters
		Space* getRoom1(){ return this->room1; }
		Space* getRoom2(){ return this->room2; }
		Space* getRoom3(){ return this->room3; }
		Space* getRoom4(){ return this->room4; }
		Space* getRoom5(){ return this->room5; }
		Space* getRoom6(){ return this->room6; }





};
#endif
