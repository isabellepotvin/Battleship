#pragma once

#include "enums.h"
#include <iostream>
#include <windows.h>
using namespace std;

//abstract base class
class Boat {
protected:
	int m_length;

public:
	int m_direction;
	int m_X;
	int m_Y;
	int m_orderSunk = 0;

	virtual void sunk() = 0; //pure virtual function
	int getLength(); //getter
};


//classes that inherit from boat

class Carrier : public Boat {
public:
	Carrier();
	~Carrier();
	void sunk();
};

class Battleship : public Boat {
public:
	Battleship();
	~Battleship();
	void sunk();
};

class Submarine : public Boat {
public:
	Submarine();
	~Submarine();
	void sunk();
};

class Destroyer : public Boat {
public:
	Destroyer();
	~Destroyer();
	void sunk();
};

class Patrol : public Boat {
public:
	Patrol();
	~Patrol();
	void sunk();
};



