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
#include <vector>

#include "sim.hpp"

using std::cout;
using std::cin;
using std::endl;

Sim::Sim(){	
	// Initalize values	
}

Sim::~Sim(){
}

void Sim::simGame(){
	// Greeting
	greeting();

	// Start Game
	// Choice #1	
		menuOptions.clear();
		menuOptions.push_back("Enter door.");
		menuOptions.push_back("Turn around and go home.");
		
		getMenuChoice(menuOptions);	
		switch(menuChoice){
			case 1:
				intro();
				break;
			case 2:
				lameWin();
				break;
			default:
				break;
		}
}

/******************************
 * Display intro text to user
 ******************************/
void Sim::intro(){
	cout << "\n***************************\n"	\
		"A very old man stares at you as you walk in. Something's off about him.\n"	\
		"You greet him happily. He says nothing.\n"	\
		"You notice a sign that reads, \"$10.00 per Adult.\"\n"	\
		"You present the old creeper with a $10 bill. He takes it. He says nothing.\n" \
		"He hands you a backpack and a dirty, red stained rag. He says nothing.\n"	\
		"----You receive: BACKPACK\n" \
		"----You receive: RAG\n"	\
		"You put the rag in the backpack with two fingers...Gross\n" \
		"All of a sudden the old man rears back and throws a punch.\n" \
		"*********BLAMMMMMMMMMMMMMM************\n"		\
		"His old man strength knocks you unconcious.\n"; 	
	pause();
	room1();
	
}

/********************************************************
 * This isn't really an escape room. Just an escape.	*
 ********************************************************/
void Sim::escapeRoom(){
	playerSpace = nullptr;
	cout << "The door opens to the outside of a back alley...presumably behind the abandoned warehouse building.\n" \
			"This, being your first time through, you think, \"That wasn't so hard.\" And go home safely.\n" \
			"Congratulations. You win." << endl;
}

/**********************
 * Room 6
 **********************/
void Sim::room6(){
	// Reset certain vars
	playerDied = false;
	escaped = false;

	// Set room
	playerSpace = playerSpace->getRight();

	// Set player vars
	bool lookAtRoom = false;
	bool canAddOption = true;

	cout << "********************ROOM 6" << endl;
	cout << "********************" << playerSpace->getName() << endl;

	menuOptions.clear();
	menuOptions.push_back("Look at what's in backpack?");
	menuOptions.push_back("Look around the room?");

	do{
		// Add menu options if user did certain actions
		if(lookAtRoom && canAddOption){
			menuOptions.push_back("Inspect door");
			canAddOption = false;
		}

		// Prompt user to do actions
		cout << endl;
		getMenuChoice(menuOptions);
		switch(menuChoice){
			case 1:
				cout << endl;
				printBP();	
				break;
			case 2:
				cout << endl;
				playerSpace->roomDescription();
				lookAtRoom = true;	
				break;
			case 3:
				cout << endl;
				cout << "You inspect the door. It looks like some math equations are written on it:\n" \
				"- 1 + 4 = 5\n" \
				"- 2 + 6 = 13\n" \
				"- 3 + 7 = 24\n" \
				"- 4 + 8 = 36\n" \
				"= 5 + 9 = ?\n" \
				"Below the math equation there are buttons that you can press for the answer. Below\n" \
				"the buttons you see a quote: \n" \
				"Life is really simple, but we insist on making it complicated.\n" << endl;

				if(playerSpace->roomInteraction()){
					// Player picked the correct number, you have escaped
					cout << endl;
					cout << "The door unlocks." << endl;
					escaped = true;
				}
				else{
					// Player picked the wrong number, they dead. Game over.
					cout << endl;
					cout << "SIMPLICITY MAN! What is 9 + 5? THERE IS ONLY ONE ANSWER! Because of this foolery, a combination\n" \
							"of all the rooms' previous traps activate in this final room. You get shot by a shotgun, get sulphuric\n" \
							"filled eggs thrown at you from the white walls, a giant book crushes your legs...all while burning to\n" \
							"death. YOU WERE SO CLOSE. But you're dead." << endl;
					playerDied = true;
					return;
				}	
				break;
			default:
				break;
		}
	}while(!escaped && !playerDied);

	// Move to escape
	escapeRoom();

}

/**********************
 * Room 5
 **********************/
void Sim::room5(){
	// Reset certain vars
	playerDied = false;
	escaped = false;

	// Set room
	playerSpace = playerSpace->getRight();

	// Set player vars
	bool lookAtRoom = false;
	bool canAddOption = true;

	cout << "********************ROOM 5" << endl;
	cout << "********************" << playerSpace->getName() << endl;

	menuOptions.clear();
	menuOptions.push_back("Look at what's in backpack?");
	menuOptions.push_back("Look around the room?");

	do{
		// Add menu options if user did certain actions
		if(lookAtRoom && canAddOption){
			menuOptions.push_back("Walk up to Door");
			canAddOption = false;
		}

		// Prompt user to do actions
		cout << endl;
		getMenuChoice(menuOptions);
		switch(menuChoice){
			case 1:
				cout << endl;
				printBP();	
				break;
			case 2:
				cout << endl;
				playerSpace->roomDescription();
				lookAtRoom = true;	
				break;
			case 3:
				cout << endl;
				cout << "You walk up to the door. In the middle of the door is a single candle that is not lit.\n" \
						"This seems obvious. Light the candle...You think back to the quote, though...darkness.\n" \
						"You go back and fourth thinking which one it could be." << endl;
				if(playerSpace->roomInteraction()){
					// Player picked the correct number, go to room 4
					cout << endl;
					cout << "The door unlocks. You go in and enter room #5." << endl;
					escaped = true;
				}
				else{
					// Player picked the wrong number, they dead. Game over.
					cout << endl;
					cout << "THE QUOTE WAS RIGHT THERE! You light the door candle. It immediately falls to the ground\n" \
							"lighting some flamable, odorless, substance that now appears to be everywhere. The entire room\n" \
							"is engulfed in flames! Including you. You burn to death. Now you're dead. You'll never learn." << endl;
					playerDied = true;
					return;
				}	
				break;
			default:
				break;
		}
	}while(!escaped && !playerDied);

	// Move to room 6 
	room6();

}

/**********************
 * Room 4
 **********************/
void Sim::room4(){
	// Reset certain vars
	playerDied = false;
	escaped = false;

	// Set room
	playerSpace = playerSpace->getRight();


	// Set player vars
	bool lookAtRoom = false;
	bool canAddOption = true;
	bool itemsInBP = false;

	cout << "********************ROOM 4" << endl;
	cout << "********************" << playerSpace->getName() << endl;

	menuOptions.clear();
	menuOptions.push_back("Look at what's in backpack?");
	menuOptions.push_back("Look around the room?");
	menuOptions.push_back("Empty backpack");
	
	do{
		// Add menu options if user did certain actions
		if(lookAtRoom && canAddOption){
			menuOptions.push_back("Put items in backpack");
			menuOptions.push_back("Walk up to Door");
			canAddOption = false;
		}

		// Prompt user to do actions
		cout << endl;
		getMenuChoice(menuOptions);
		switch(menuChoice){
			case 1:
				cout << endl;
				printBP();	
				break;
			case 2:
				cout << endl;
				playerSpace->roomDescription();
				lookAtRoom = true;	
				break;
			case 3:
				cout << "-- Emptying backpack" << endl;
				p1.emptyBP();
				itemsInBP = false;
				break;
			case 4:
				// Add items to backpack
				if(p1.isBPfull()){
					cout << "--Backpack is full. Empty contents first." << endl;
				}
				else{
					// Add room items
					pItem.setName("Small Bird - Shiny Circles");
					p1.addBPitem(pItem);
					pItem.setName("Large Bird - Shiny Diamonds");
					p1.addBPitem(pItem);
					pItem.setName("Medium Bird - Shiny Squares");
					p1.addBPitem(pItem);

					itemsInBP = true;
					cout << "-- You place the three birds into the backpack." << endl;
				}
				break;
			case 5:
				// Walk up to door
				if(!itemsInBP){
					cout << "--You need items to interact with the door. PICK THEM UP!" << endl;
				}
				else{
					cout << endl;
					cout << "As you walk up to the door you notice a birdhouse in the middle\n" \
							"of the door that isn't working. The \"tongue\" (where the bird would go)\n" \
							"of the bird house is extended, without a bird." << endl;
					if(playerSpace->roomInteraction()){
						// Player picked the correct number, go to room 4
						cout << endl;
						cout << "The door unlocks. You go in and enter room #4." << endl;
						escaped = true;
					}
					else{
						// Player picked the wrong number, they dead. Game over.
						cout << endl;
						cout << "REMEMBER ROOM 2! All tick-tocking stops all of a sudden. You hear a click\n" \
								"Suddenly all the wooden \"tongues\" of the bird houses extend at light speed.\n" \
								"My god it's as if each of the \"tongues\" are endlessly long. They won't stop!\n" \
								"You feel multiple sharp pains in your back, sides, front.... The Cuckoo clocks\n" \
								"have speared you, turning you into swiss cheese. Because of your goldfish memory\n" \
								"you are now dead." << endl;
						playerDied = true;
						return;
					}
				}
				break;
			default:
				break;
		}
	}while(!escaped && !playerDied);

	// Move to room 5 
	room5();
}

/**********************
 * Room 3
 **********************/
void Sim::room3(){
	// Reset certain vars
	playerDied = false;
	escaped = false;

	// Set room
	playerSpace = playerSpace->getRight();

	// Set player vars
	bool lookAtRoom = false;
	bool canAddOption = true;

	cout << "********************ROOM 3" << endl;
	cout << "********************" << playerSpace->getName() << endl;

	menuOptions.clear();
	menuOptions.push_back("Look at what's in backpack?");
	menuOptions.push_back("Look around the room?");
	
	do{
		// Add menu options if user did certain actions
		if(lookAtRoom && canAddOption){
			menuOptions.push_back("Walk up to Door");
			canAddOption = false;
		}

		// Prompt user to do actions
		cout << endl;
		getMenuChoice(menuOptions);
		switch(menuChoice){
			case 1:
				cout << endl;
				printBP();	
				break;
			case 2:
				cout << endl;
				playerSpace->roomDescription();
				lookAtRoom = true;	
				break;
			case 3:
				cout << endl;
				cout << "The door has shelves and is full of books. At eye height you notice\n" \
						"three books that look 100 years old. They're not as pristine and new\n" \
						"as every other book in the room. You look closer and notice the authors from\n" \
						"left to right:\n" \
						"- E. Hemingway\n" \
						"- V. Woolf\n" \
						"- W. Shakespeare\n" << endl;
				if(playerSpace->roomInteraction()){
					// Player picked the correct number, go to room 4
					cout << endl;
					cout << "The door unlocks. You go in and enter room #4." << endl;
					escaped = true;
				}
				else{
					// Player picked the wrong number, they dead. Game over.
					cout << endl;
					cout << "REMEMBER THE SIGN! The books are put into a non-sensical order. You hear\n" \
							"a click. The entire wall slams down on you, crushing the lower half of \n" \
							"your body, throwing you to the floor and paralyzing you.\n" \
							"No one comes to save you. You eventually die of thirst. You fool." << endl;
					playerDied = true;
					return;
				}
				break;
			default:
				break;
		}
	}while(!escaped && !playerDied);

	// Move to room 4
	room4();
}

/**********************
 * Room 2
 **********************/
void Sim::room2(){
	// Reset certain vars
	playerDied = false;
	escaped = false;

	// Set room
	playerSpace = playerSpace->getRight();

	// Set player vars
	bool lookAtRoom = false;
	bool canAddOption = true;

	cout << "********************ROOM 2" << endl;
	cout << "********************" << playerSpace->getName() << endl;
	cout << "You slowly walk into the room. Immediately you spot the DOOR on the opposite wall.\n";

	menuOptions.clear();
	menuOptions.push_back("Look at what's in backpack?");
	menuOptions.push_back("Look around the room?");
	
	do{
		// Add menu options if user did certain actions
		if(lookAtRoom && canAddOption){
			menuOptions.push_back("Inspect Door");
			canAddOption = false;
		}

		// Prompt user to do actions
		cout << endl;
		getMenuChoice(menuOptions);
		switch(menuChoice){
			case 1:
				cout << endl;
				printBP();	
				break;
			case 2:
				cout << endl;
				playerSpace->roomDescription();
				lookAtRoom = true;

				// Add room items
				pItem.setName("Bird - Diamond");
				p1.addBPitem(pItem);
				pItem.setName("Bird - Circle");
				p1.addBPitem(pItem);
				pItem.setName("Bird - Square");
				p1.addBPitem(pItem);
				break;
			case 3:
				cout << endl;
				cout << "The door has three pictures of eggs.\n" \
						"One is very diamond shaped. One is very circular shaped.\n" \
						"One is an odd square shape.\n"\
						"Besides the obvious differences in shape, the diamond and square\n" \
						"eggs are black outlines. Whereas the circular one is bright white.\n" 
						"Below the egg images is a slot that appears big enough to insert something into." << endl;
				if(playerSpace->roomInteraction()){
					// Player picked the correct number, go to room 3
					cout << endl;
					cout << "The door unlocks. You go in and enter room #3." << endl;
					escaped = true;
				}
				else{
					// Player picked the wrong number, they dead. Game over.
					cout << endl;
					cout << "WRONG EGG! You hear a click from the ceiling. You see the ceiling\n" \
							"tiles open. You start seeing hundreds of eggs being slowly lowered by\n" \
							"some mechanical device. The eggs start dropping. Oh god they're filled with\n" \
							"sulphuric acid. They don't stop dropping. The eggs keep breaking all over your\n" \
							"body. You melt. You're dead." << endl;
					playerDied = true;
					return;
				}
				break;
			default:
				break;
		}
	}while(!escaped && !playerDied);

	// Move to room 3
	room3();
}

/**********************
 * Room 1
 **********************/
void Sim::room1(){
	playerSpace = myBldg.getRoom1();
	bool lookInBP = false;
	bool lookAtRoom = false;
	bool canAddOption = true;

	cout << "********************ROOM 1" << endl;
	cout << "********************" << playerSpace->getName() << endl;
		 "You wake up next to a door, lying on the floor of a damp, moist room.\n" \
		 "Your face is very sore and your head is throbbing.\n" \
		 "You get up and try to open the door. It's locked. On the door\n" \
		 " is written, \"Turn Around.\"\n" \
		 "You turn around and see another door. \n"	\
		 "On it is written \"Solve the puzzles to win your life.\"\n";	

	pItem.setName("Rag");	
	p1.addBPitem(pItem);	

	menuOptions.clear();
	menuOptions.push_back("Look at what's in backpack?");
	menuOptions.push_back("Look around the room?");
	
	do{
		// Add menu options if user did certain actions
		if(lookInBP && lookAtRoom && canAddOption){
			menuOptions.push_back("Use rag to wipe off blood.");
			canAddOption = false;
		}

		// Prompt user to do actions
		cout << endl;
		getMenuChoice(menuOptions);
		switch(menuChoice){
			case 1:
				cout << endl;
				printBP();	
				lookInBP = true;
				break;
			case 2:
				cout << endl;
				playerSpace->roomDescription();
				lookAtRoom = true;
				break;
			case 3:
				cout << endl;
				cout << "-----Wiping away the blood reveals 4 numbers. 0591\n"
						"You notice the door has a keycode with 4 digits. Well this seems simple.\n";
				if(playerSpace->roomInteraction()){
					// Player picked the correct number, go to room 2
					cout << endl;
					cout << "The door unlocks. You go in and enter room #2." << endl;
					escaped = true;
				}
				else{
					// Player picked the wrong number, they dead. Game over.
					cout << endl;
					cout << "MY god. The number was right there! YOU PICKED THE WRONG ONE!\n" \
							"The keypad digits retract into the door. You hear a click...\n" \
							"Suddenly a loud explosion. The keypad digits shoot out like a shotgun\n" \
							"directly into your upper right leg. Your leg is severed from your body.\n" \
							"You fall down, in shock, bleeding to death. You're dead. You fool.\n";
					playerDied = true;
					return;
				}
				break;
			default:
				break;
		}
	}while(!escaped && !playerDied);

	// Move to room 2
	room2();
}

/********************
 * Print back pack items (container)
 ********************/
void Sim::printBP(){
	p1.printBPitems();
	cout << endl;
}

/***********************
 * User just goes home like a lame ass
 ***********************/
void Sim::lameWin(){
	cout << "Game over I guess. You go home safely. That was uneventful." << endl;
	gameWon = true;
}

void Sim::getMenuChoice(std::vector<std::string> menuOptions){
	cin.clear();
	choice.setDisplayMenu(menuOptions);	

	do{
		cout << "Actions: " << endl;
		choice.displayMenu();
		cout << "Choice: ";
		cin >> userInput;
	}while(!InputValid::isValidInt(userInput, menuChoice, 1, menuOptions.size()));	
	cin.clear();
}

/**************************
 * Function for when the user first starts the program
 **************************/
void Sim::greeting(){
	// Greeting
	cout << "******************Welcome to ESCAPE ROOM!******************" << endl;
	cout << "Your goal is to try and escape without dying. There will be 6 rooms total. Each room has at least\n" 	\
				"one door that leads to an adjacent room. To open the door(s) you must solve puzzles, be observant,\n" \
				"and rely on your intuition. A wrong move could be your last. Let us begin...\n\n";			\
	cout << "********************************************\n";
	cout << "Hello friend. You have decided to try out an escape room in downtown Austin, Tx.\n"	\
			"This particular escape room is in...what some would say is an abandoned warehouse.\n"	\
			"You think this is incredible, the owner is really going for realism.\n";				\
	cout << "********************************************\n";
	cout << "You park your car. You notice how unkempt the entire property looks. Shrubs growing wildly,\n"	\
			"moss slowly taking over the building on the outside.\n"		\
			"--You see a door.\n";
}

/********************
 * Function to pause the amount of text
 * being displayed to the screen.
 ********************/
void Sim::pause(){
	cout << endl;
	cout << "-----Press ENTER to continue...";
	cin.ignore();
	cin.get();
}

/***********************
 * After player decides to play again, reset all
 * necessary variables to allow them to play
 ***********************/
void Sim::resetGame(){
	// Reset all items related to the game
	menuOptions.clear();
	choice.setDisplayMenu(menuOptions);
	p1.emptyBP();	
	playerSpace = nullptr;
	playerRoom = 0;
	gameWon = false;
	playerDied = false;
	escaped = false;
}
