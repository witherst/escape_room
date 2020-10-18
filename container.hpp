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

#ifndef TWITHERS_CONTAINER_HPP
#define TWITHERS_CONTAINER_HPP

#include <vector>
#include <iostream>
using std::cout;
using std::endl;

#include "item.hpp"

class Container
{
	private:
		std::vector<Item> items;
		int itemLimit;
		int itemCount;

	public:
		// Constructor(s)
		Container();

		// Destructor
		~Container();

		// Getters
		Item getItemX(int);
		
		// Setters
		void addItem(Item);

		// Public Functions
		void printItems();	
		void clearItems();
		bool isFull();
};

#endif
