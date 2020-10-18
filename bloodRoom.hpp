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

#ifndef TWITHERS_BLOODROOM_HPP
#define TWITHERS_BLOODROOM_HPP

#include "space.hpp"

class BloodRoom : public Space
{
	private:
							
	public:
		// Constructor(s)
		BloodRoom();

		// Destructor
		~BloodRoom();

		// Getters
		
		// Setters
	
		// Public Functions
		void roomDescription();
		bool roomInteraction();

};

#endif
