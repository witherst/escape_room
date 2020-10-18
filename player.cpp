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
#include "player.hpp"

Player::Player(){
	// Initalize values	
}

Player::~Player(){
}

void Player::printBPitems(){
	backpack.printItems();
}

void Player::addBPitem(Item itemToAdd){
	backpack.addItem(itemToAdd);
}

void Player::emptyBP(){
	backpack.clearItems();
}

bool Player::isBPfull(){
	return backpack.isFull();
}
