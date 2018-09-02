#include "player.h"

//function prototypes
void gotoXY(int x, int y);
void textColour(Colours colour);



/************************************
	CONSTRUCTORS AND DESTRUCTORS
************************************/

Player::Player() { }

Player::Player(string name, Colours colour) {
	m_colour = colour;
	m_name = name;
	m_indexSunk = 1;

	//sets all the elements in the arrays
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m_board[i][j] = full;
			m_oppBoard[i][j] = full;
		}
	}
}

Player::~Player(){ }




/************************************
		GETTERS AND SETTERS
************************************/

string Player::getName() { 
	return m_name; 
}
void Player::setName(string name) {
	m_name = name;
}


Colours Player::getColour() {
	return m_colour;
}



/************************************
		FUNCTION DEFINITIONS
************************************/

void Player::drawBoard(int x, int y) {

	gotoXY(x, y);

	//draws numbers
	textColour(m_colour);
	cout << "0123456789";
	x--;
	y++;
	for (int i = 0; i < 10; i++) {
		gotoXY(x, y);
		y++;
		cout << i;
	}
	x++;
	y -= 10;
	gotoXY(x, y);

	//draws board
	textColour(darkerBlue);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (m_board[i][j]) {
			case full: textColour(darkerBlue);
				break;
			case miss: textColour(grey);
				break;
			case hit: textColour(red);
				break;
			default: textColour(white);
				break;
			}

			cout << (char)m_board[i][j];
		}
		y++;
		gotoXY(x, y);
	}
}

void Player::drawOppBoard(int x, int y, Colours colour) {

	gotoXY(x, y);

	//draws numbers
	textColour(colour);
	cout << "0123456789";
	x--;
	y++;
	for (int i = 0; i < 10; i++) {
		gotoXY(x, y);
		y++;
		cout << i;
	}
	x++;
	y -= 10;
	gotoXY(x, y);

	//draws board
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			switch (m_oppBoard[i][j]) {
			case full: textColour(darkerBlue);
				break;
			case miss: textColour(grey);
				break;
			case hit: textColour(white);
				break;
			default: textColour(white);
				break;
			}
			cout << (char)m_oppBoard[i][j];

		}
		y++;
		gotoXY(x, y);
	}
}