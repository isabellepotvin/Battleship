/*

Title: Assignment 4 - Battleship
Author: Isabelle Potvin
Date: October 31, 2017

Objective: This program allows users to play the game battleship. Users have the option to play against 
an AI or against another user. Each player's boats are placed randomly on the boards. The user must then
enter coordinates to try and sink their opponent's boats. A player must sink all five of their opponent's 
boats to win the game.

*/


#include "player.h"
#include "boat.h"
#include <random>
#include <time.h>
#include <conio.h>
#include <vector>

enum States {
	menu,
	onePlayer,
	twoPlayers,
	exitGame
};

//function prototypes
States mainMenu();
void onePlayerGame();
void twoPlayerGame();
void exit();

//this function moves the cursor to a specific coordinate
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 10;
	SetConsoleCursorInfo(hStdout, &cursorInfo);
}

//this function changes the colour of the text
void textColour(Colours colour) {
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, colour);
}



int main() {

	srand(time(NULL)); //seeds random

	States currentState = menu; //sets the current state to the main menu

	do {

		//switches through the menu states
		switch (currentState) {
		case menu:
			currentState = mainMenu();
			break;

		case onePlayer:
			onePlayerGame();
			currentState = menu;
			break;

		case twoPlayers:
			twoPlayerGame();
			currentState = menu;
			break;

		default:
			break;
		}

	} while (currentState != exitGame);

	//displays exit message
	exit();

	return 0;
}



//this function draws a boat using ascii characters
void drawBoat() {

	int x = 30;
	int y = 1;

	gotoXY(x, y);

	//DRAWS SMOKE

	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255; //blanks
	cout << "( (";
	y++;
	gotoXY(x, y);

	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255; //blanks
	cout << " ) )" << "      " << "( (";
	y++;
	gotoXY(x, y);

	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255; //blanks
	cout << "( (" << "       " << " ) )";
	y++;
	gotoXY(x, y);


	//DRAWS TOWERS

	//horizontal line (top of left tower)
	for (int j = 0; j < 12; j++) {
		cout << (char)255; //blank
	}
	cout << (char)218; //left corner
	cout << (char)196 << (char)196 << (char)196; //horizontal line
	cout << (char)191; //right corner
	cout << "      " << "( ("; //bottom of right smoke

	y++;
	gotoXY(x, y);

	//vertical lines (left tower)
	for (int j = 0; j < 12; j++) {
		cout << (char)255; //blank
	}
	cout << (char)179; //vertical line
	cout << (char)255 << (char)255 << (char)255; //blank
	cout << (char)179; //vertical line

					   //horizontal line (top of right tower)
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255; //blank
	cout << (char)218; //left corner
	cout << (char)196 << (char)196 << (char)196; //horizontal line
	cout << (char)191; //right corner

	y++;
	gotoXY(x, y);

	//vertical lines (left tower)
	for (int j = 0; j < 12; j++) {
		cout << (char)255; //blank
	}
	cout << (char)179; //vertical line
	cout << (char)255 << (char)255 << (char)255; //blank
	cout << (char)179; //vertical line

					   //vertical lines (right tower)
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255; //blank
	cout << (char)179; //vertical line
	cout << (char)255 << (char)255 << (char)255; //blank
	cout << (char)179; //vertical line

	y++;
	gotoXY(x, y);


	//DRAWS UPPER LEVEL

	//horizontal line
	for (int j = 0; j < 8; j++) {
		cout << (char)255; //blank
	}
	cout << (char)218; //left corner
	cout << (char)196 << (char)196 << (char)196; //horizontal lines
	cout << (char)193; //horizontal + upper vertical line
	cout << (char)196 << (char)196 << (char)196; //horizontal lines
	cout << (char)193; //horizontal + upper vertical line
	cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196; //horizontal lines
	cout << (char)193; //horizontal + upper vertical line
	cout << (char)196 << (char)196 << (char)196; //horizontal lines
	cout << (char)193; //horizontal + upper vertical line
	cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196; //horizontal lines
	cout << (char)191; //right corner

	y++;
	gotoXY(x, y);

	//vertical lines
	for (int j = 0; j < 8; j++) {
		cout << (char)255; //blank
	}
	cout << (char)179; //vertical line
	for (int j = 0; j < 25; j++) {
		cout << (char)255; //blank
	}
	cout << (char)179; //vertical line

	y++;
	gotoXY(x, y);


	//DRAWS LOWER LEVEL

	//horizontal line
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255; //blank
	cout << (char)218; //left corner
	cout << (char)196 << (char)196; //horizontal line
	cout << (char)193; //horizontal + upper vertical line
	for (int i = 0; i < 25; i++) {
		cout << (char)196; //horizontal line
	}
	cout << (char)193; //horizontal + upper vertical line
	cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196; //horizontal line
	cout << (char)191; //right corner

	y++;
	gotoXY(x, y);

	//vertical lines
	for (int j = 0; j < 5; j++) {
		cout << (char)255; //blank
	}
	cout << (char)179; //vertical line
	for (int j = 0; j < 35; j++) {
		cout << (char)255; //blank
	}
	cout << (char)179; //vertical line
	y++;
	gotoXY(x, y);


	//DRAWS BOTTOM OF BOAT

	//draws horizontal line
	cout << (char)196 << (char)196 << (char)196 << (char)196 << (char)196; //horizontal line
	cout << (char)193; //horizontal + upper vertical line
	for (int i = 0; i < 35; i++) {
		cout << (char)196; //horizontal line
	}
	cout << (char)193; //horizontal + upper vertical line
	for (int i = 0; i < 18; i++) {
		cout << (char)196; //horizontal line
	}
	y++;
	gotoXY(x, y);

	//draws diagonal lines
	for (int i = 0; i < 6; i++) {
		cout << (char)92; //backslash

		if (i != 1) {
			for (int j = 0; j < (58 - 2 * i); j++) {
				cout << (char)255; //blank
			}
		}
		//draws windows
		else {
			for (int j = 0; j < 7; j++) {
				cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255;
				cout << "O";
			}
			cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255;
		}
		cout << (char)47; //slash
		y++;
		x++;
		gotoXY(x, y);
	}

	//draws horizontal line
	gotoXY(x, y);
	for (int i = 0; i < 48; i++) {
		cout << (char)196; //horizontal line
	}




	cout << endl << endl;
}

//this function displays the main menu and allows the user to choose if they would like to play or exit the game
States mainMenu() {

	textColour(white);
	system("cls");

	textColour(turq);
	drawBoat(); //calls function that draws a boat

	//variables
	int character = NULL;
	int index = 1;
	int indexX1 = 46;
	int indexX2 = 71;
	int indexY = 22;

	textColour(white);

	//displays text

	gotoXY(44, 20);
	cout << "~ ~ ~ ~ ~ BATTLESHIP ~ ~ ~ ~ ~";

	gotoXY(48, 22);
	cout << "New Game : One Player";

	gotoXY(48, 24);
	cout << "New Game : Two Players";

	gotoXY(48, 26);
	cout << "Exit";

	//displays angle quotes to show the user's current 'state' selection
	gotoXY(indexX1, indexY);
	cout << (char)rightAngleQuotes;
	gotoXY(indexX2, indexY);
	cout << (char)leftAngleQuotes;

	//detects if the user hits the up or down arrow keys and changes the angle quotes' indexes accordingly
	while (character != enter) {

		if (_kbhit()) {

			character = _getch(); //saves which key was hit

			if (index >= 1 && index <= 3) {

				//changes the index
				switch (character) {
				case up:
					if (index != 1) { index--; }
					break;

				case down:
					if (index != 3) { index++; }
					break;

				default:
					break;

				}

				//removes the old angle brackets
				gotoXY(indexX1, indexY);
				cout << (char)blank;
				gotoXY(indexX2, indexY);
				cout << (char)blank;

				//changes the Y value depending on the index
				switch (index) {
				case 1: indexY = 22;
					break;

				case 2: indexY = 24;
					break;

				case 3:indexY = 26;
					break;

				default:
					break;
				}

				//draws the new angle brackets
				gotoXY(indexX1, indexY);
				cout << (char)rightAngleQuotes;
				gotoXY(indexX2, indexY);
				cout << (char)leftAngleQuotes;
			}
		}

	}

	return (States)index; //returns the users 'state' selection

}

//this function draws both players' names and boards
void drawGame(Player player1, Player player2) {

	//draws boards
	player2.drawOppBoard(50, 1, player1.getColour());
	player2.drawBoard(50, 17);

	//draws vertical line to seperate the boards
	textColour(white);
	gotoXY(2, 14);
	for (int i = 0; i < 110; i++) {
		cout << (char)vertLine;
	}

	//draws players names
	gotoXY(2, 0);
	cout << player1.getName();
	gotoXY(2, 16);
	cout << player2.getName();


}

//this function selects a random position for a single boat
void randomBoat(Boat &boat) {
	boat.m_direction = rand() % 2;

	if (boat.m_direction == 1) { //vertical boat
		boat.m_X = rand() % 10;
		boat.m_Y = rand() % (11 - boat.getLength());
	}
	else if (boat.m_direction == 0) { //horizontal boat
		boat.m_Y = rand() % 10;
		boat.m_X = rand() % (11 - boat.getLength());
	}
}

//this function saves a specific boat in a random position on a player's board
void placeBoat(Player &player, Boat &boat) {
	int i;
	bool collision;

	//checks if boat collides with pre-existing boat
	do {
		randomBoat(boat);
		collision = false;

		if (boat.m_direction == 1) { //vertical boat
			for (i = 0; i < boat.getLength(); i++) {
				if (player.m_board[boat.m_Y + i][boat.m_X] != full) {
					collision = true;
				}
			}
		}
		else { //horizontal boat
			for (i = 0; i < boat.getLength(); i++) {
				if (player.m_board[boat.m_Y][boat.m_X + i] != full) {
					collision = true;
				}
			}
		}

	} while (collision);

	//saves the boat in the board array
	if (boat.m_direction == 1) { //vertical boat
		player.m_board[boat.m_Y][boat.m_X] = boatTop;
		for (i = 1; i < (boat.getLength() - 1); i++) {
			player.m_board[boat.m_Y + i][boat.m_X] = boatVert;
		}
		player.m_board[boat.m_Y + i][boat.m_X] = boatBottom;
	}
	else { //horizontal boat
		player.m_board[boat.m_Y][boat.m_X] = boatLeft;
		for (i = 1; i < (boat.getLength() - 1); i++) {
			player.m_board[boat.m_Y][boat.m_X + i] = boatHori;
		}
		player.m_board[boat.m_Y][boat.m_X + i] = boatRight;
	}

}

//this function saves all 5 boats on a player's board
void placeRandomBoats(Player &player) {
	placeBoat(player, player.m_carrier);
	placeBoat(player, player.m_battleship);
	placeBoat(player, player.m_submarine);
	placeBoat(player, player.m_destroyer);
	placeBoat(player, player.m_patrol);
}

//this function checks if a specific boat has sunk
void checkSunk(Player &player, Boat &boat, int &y, int offsetY) {

	int i;
	bool isSunk = true;

	if (boat.m_direction == 1) { //vertical boat
		for (i = 0; i < boat.getLength(); i++) {
			if (player.m_oppBoard[boat.m_Y + i][boat.m_X] != hit) {
				isSunk = false;
			}
		}
	}
	else { //horizontal boat
		for (i = 0; i < boat.getLength(); i++) {
			if (player.m_oppBoard[boat.m_Y][boat.m_X + i] != hit) {
				isSunk = false;
			}
		}
	}


	if (isSunk) {
		if (boat.m_orderSunk == 0) {
			boat.m_orderSunk = y; //saves the order in which the boat sunk (to know at which y index to print the message)
			y++;
		}
		gotoXY(2, offsetY + boat.m_orderSunk);
		boat.sunk(); //calls overridden method of the boat that sunk (to display message)
	}

}

//this function checks all the boats to see if any have sunk
void checkAllBoats(Player &playerTop, Player &playerBottom) {
	//checks if the bottom player has sunk any of the top player's boats
	checkSunk(playerBottom, playerTop.m_carrier, playerTop.m_indexSunk, 1);
	checkSunk(playerBottom, playerTop.m_battleship, playerTop.m_indexSunk, 1);
	checkSunk(playerBottom, playerTop.m_submarine, playerTop.m_indexSunk, 1);
	checkSunk(playerBottom, playerTop.m_destroyer, playerTop.m_indexSunk, 1);
	checkSunk(playerBottom, playerTop.m_patrol, playerTop.m_indexSunk, 1);

	//checks if the top player has sunk any of the bottom player's boats
	checkSunk(playerTop, playerBottom.m_carrier, playerBottom.m_indexSunk, 17);
	checkSunk(playerTop, playerBottom.m_battleship, playerBottom.m_indexSunk, 17);
	checkSunk(playerTop, playerBottom.m_submarine, playerBottom.m_indexSunk, 17);
	checkSunk(playerTop, playerBottom.m_destroyer, playerBottom.m_indexSunk, 17);
	checkSunk(playerTop, playerBottom.m_patrol, playerBottom.m_indexSunk, 17);
}

//this function prints and returns if the player got a hit or a miss at a certain coordinate
string printResult(Player player, int offsetY, int x, int y, string result) {
	string resultString;

	gotoXY(45, offsetY);
	cout << player.getName() << " " << result << " at X:" << x << ", Y:" << y;

	resultString = player.getName() + " " + result + " at X:" + (char)(48 + x) + ", Y:" + (char)(48 + y);

	return resultString;
}

//this function runs through a single turn in the game (called by onePlayerGame and twoPlayerGame)
string game(Player &playerBottom, Player &playerTop) {

	//variables
	bool isValidChoice;
	int choiceX, choiceY;
	string result;

	drawGame(playerTop, playerBottom);

	//asks user to enter coordinates
	do {
		isValidChoice = true;

		gotoXY(70, 20);
		cout << "Enter X: ";
		cin >> choiceX;

		gotoXY(70, 21);
		cout << "Enter Y: ";
		cin >> choiceY;

		if (choiceX < 0 || choiceX > 9 || choiceY < 0 || choiceY > 9) {
			gotoXY(70, 22);
			cout << "Invalid. Please re-enter.";
			isValidChoice = false;

			//erases previous number
			gotoXY(79, 20);
			cout << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank;
			gotoXY(79, 21);
			cout << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank << (char)blank;
		}

	} while (!isValidChoice);


	system("cls"); //clears the console window

	//saves whether the entered coordinate was a hit or a miss
	if (playerTop.m_board[choiceY][choiceX] != full) {
		playerBottom.m_oppBoard[choiceY][choiceX] = hit;
		playerTop.m_board[choiceY][choiceX] = hit;
		result = printResult(playerBottom, 13, choiceX, choiceY, "hit"); //prints result to screen
	}
	else {
		playerBottom.m_oppBoard[choiceY][choiceX] = miss;
		result = printResult(playerBottom, 13, choiceX, choiceY, "missed"); //prints result to screen
	}

	//checks if any boats have sunk
	checkAllBoats(playerTop, playerBottom);

	if (playerTop.m_indexSunk == 6 || playerBottom.m_indexSunk == 6) {
		drawGame(playerTop, playerBottom);
	}

	return result;
}

//this function runs through the game where a user plays against an AI
void onePlayerGame() {

	system("cls"); //clears the console window

	//variables
	string userName;
	int randomX;
	int randomY;
	vector<int> Xrandoms, Yrandoms;
	bool isRepeat;
	string computerResult;
	string userResult;


	//asks user for their name
	gotoXY(40, 10);
	cout << "Please enter your name: ";
	cin >> userName;

	Player user = Player(userName, turq); //creates user
	Player computer = Player("Computer", pink); //creates computer

	//places the boats randomly for both players
	placeRandomBoats(user);
	placeRandomBoats(computer);

	system("cls"); //clears the console window

	//runs through the game until one user sinks all of the opponent boats
	while (computer.m_indexSunk <= 5 && user.m_indexSunk <= 5) {

		//calls function that iterates through the user's side of the game
		userResult = game(user, computer);

		do {
			isRepeat = false; //resets isRepeat

			//generates random coordinate
			randomX = rand() % 10;
			randomY = rand() % 10;

			//checks if the coordinate has already been generated
			for (int i = 0; i < Xrandoms.size(); i++) {
				if (randomX == Xrandoms[i] && randomY == Yrandoms[i]) {
					isRepeat = true;
				}
			}
		} while (isRepeat); //loops until a new coordinate is generated

		//saves the random values
		Xrandoms.push_back(randomX);
		Yrandoms.push_back(randomY);

		//saves whether the generated coordinate was a hit or a miss
		if (user.m_board[randomY][randomX] != full) {
			user.m_board[randomY][randomX] = hit;
			computer.m_oppBoard[randomY][randomX] = hit;
			computerResult = printResult(computer, 15, randomX, randomY, "hit"); //prints result to screen
		}
		else {
			computer.m_oppBoard[randomY][randomX] = miss;
			computerResult = printResult(computer, 15, randomX, randomY, "missed"); //prints result to screen
		}

		//checks if any boats have sunk
		checkAllBoats(computer, user);

		if (computer.m_indexSunk == 6 || user.m_indexSunk == 6) {
			drawGame(computer, user);
		}
	}


	//displays the winner of the game
	textColour(blackWhite);
	if (computer.m_indexSunk == 6) { //if the user wins
		gotoXY(75, 20);
		cout << "Congratulations " << user.getName() << "! ";
		gotoXY(75, 21);
		cout << "You have won the game.";
		gotoXY(75, 23);
		system("pause");
	}
	else { //if the computer wins
		gotoXY(75, 20);
		cout << "The computer has won.";
		gotoXY(75, 21);
		cout << "Better luck next time " << user.getName() << ".";
		gotoXY(75, 23);
		system("pause");
	}
}

//this function runs through the game where a user plays another user
void twoPlayerGame() {

	system("cls"); //clears the console window

	//variables
	string player1Name, player2Name;
	int turn = 1;
	string previousResult = " ";

	//asks player 1 to enter their name
	gotoXY(40, 10);
	cout << "Player 1, please enter your name: ";
	cin >> player1Name;

	//asks player 2 to enter their name
	gotoXY(40, 12);
	cout << "Player 2, please enter your name: ";
	cin >> player2Name;


	Player player1 = Player(player1Name, turq); //creates player 1
	Player player2 = Player(player2Name, pink); //creates player 2

	//places the boats randomly for both players
	placeRandomBoats(player1);
	placeRandomBoats(player2);

	system("cls"); //clears the console window

	//runs through the game until one user sinks all of the opponent boats
	while (player1.m_indexSunk <= 5 && player2.m_indexSunk <= 5) {

		//displays who's turn it is
		system("cls");
		if (turn == 1) {
			gotoXY(45, 13);
			cout << player1.getName() << "'s turn.";
		}
		else {
			gotoXY(45, 13);
			cout << player2.getName() << "'s turn.";
		}

		gotoXY(45, 15);
		system("pause");
		system("cls"); //clears the console window

		//displays if the player got a hit or a miss during the previous turn
		gotoXY(45, 15);
		cout << previousResult;

		//runs through the current turn
		switch (turn) {

		case 1:

			checkAllBoats(player2, player1); //checks and displays if any boats have sunk
			previousResult = game(player1, player2); //calls function that iterates through the player1's side of the game
			drawGame(player2, player1); //calls function that draws both players' names and boards

			gotoXY(70, 23);
			system("pause");
			turn = 2; //changes to player2's turn
			break;

		case 2:
			checkAllBoats(player1, player2); //checks and displays if any boats have sunk
			previousResult = game(player2, player1); //calls function that iterates through the player2's side of the game
			drawGame(player1, player2); //calls function that draws both players' names and boards

			gotoXY(70, 23);
			system("pause");
			turn = 1; //changes to player1's turn
			break;
		}



	}

	//displays the winner of the game
	textColour(blackWhite);
	if (player1.m_indexSunk == 6) { //if player2 wins
		gotoXY(65, 20);
		cout << "Congratulations " << player2.getName() << "! You have won the game.";
		gotoXY(65, 21);
		cout << player1.getName() << ", better luck next time.";
		gotoXY(70, 23);
		system("pause");
	}
	else { //if player1 wins
		gotoXY(65, 20);
		cout << "Congratulations " << player1.getName() << "! You have won the game.";
		gotoXY(65, 21);
		cout << player2.getName() << ", better luck next time.";
		gotoXY(70, 23);
		system("pause");
	}

}

//this function displays the exit message
void exit() {
	system("cls");
	gotoXY(45, 10);

	cout << "Thanks for playing! Goodbye." << endl << endl;

	gotoXY(45, 13);
	system("pause");

}
