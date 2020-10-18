/***********************************************************
 ** Author: 		Tim Withers
 ** Date:			2/06/2019
 **	Description:	The sim class will handle all steps in carrying
 *					out the fighting aspect of the characters. It will
 *					call functions on the character classes to simulate
 *					a battle.
***********************************************************/
#ifndef TWITHERS_DEPRESSROOM_HPP
#define TWITHERS_DEPRESSROOM_HPP

#include "space.hpp"

class DepressRoom : public Space
{
	private:
							
	public:
		// Constructor(s)
		DepressRoom();

		// Destructor
		~DepressRoom();

		// Getters
		
		// Setters
	
		// Public Functions
		void roomDescription();
		bool roomInteraction();
	
};

#endif
