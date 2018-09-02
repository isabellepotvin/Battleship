#pragma once

#include "enums.h"
#include "boat.h"
#include <iostream>
#include <string>
using namespace std;

class Player {

private:
	Colours m_colour;
	string m_name;

public:
	int x;
	int y;
	ascii m_board[10][10];
	ascii m_oppBoard[10][10];
	Carrier m_carrier;
	Battleship m_battleship;
	Submarine m_submarine;
	Destroyer m_destroyer;
	Patrol m_patrol;
	int m_indexSunk;

	//constructors and destructors
	Player();
	Player(string name, Colours colour);
	~Player();
	
	//getters and setters
	string getName();
	void setName(string name);
	Colours getColour();

	//function prototypes
	void drawBoard(int x, int y);
	void drawOppBoard(int x, int y, Colours colour);

};

