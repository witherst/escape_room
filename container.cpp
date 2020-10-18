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

#include "container.hpp"

Container::Container(){
	// Initalize values
	items.clear();
	itemCount = 0;
	itemLimit = 4;
	
}

Container::~Container(){
}

// Getters
Item Container::getItemX(int itemNum){
	return items[itemNum];
}

// Setters
void Container::addItem(Item userItem){
	if(!isFull()){
		items.push_back(userItem);
	}
	else{
		cout << "--BACKPACK IS FULL. EMPTY THE CONTENTS TO STORE MORE STUFF--" << endl;
	}	
}

// Public Functions
void Container::printItems(){
	cout << "------------Backpack Contents: " << endl;
	if(items.empty()){
		cout << "--BACKPACK IS EMPTY." << endl;
	}
	else if(isFull()){
		for(int i = 0; i < items.size(); i++){
			cout << i+1 << ": " << items[i].getName() << endl;
		}
		cout << "--BACKPACK IS FULL. EMPTY THE CONTENTS TO STORE MORE STUFF--" << endl;
	}
	else{
		for(int i = 0; i < items.size(); i++){
			cout << i+1 << ": " << items[i].getName() << endl;
		}
	}
}

void Container::clearItems(){
	items.clear();
	itemCount = 0;
}

bool Container::isFull(){
	return (items.size() >= itemLimit);
}
