#include "boat.h"

/************************************
	CONSTRUCTORS AND DESTRUCTORS
************************************/

Carrier::Carrier() {
	m_length = 5;
}
Carrier::~Carrier(){ }

Battleship::Battleship() {
	m_length = 4;
}
Battleship::~Battleship() { }

Submarine::Submarine() {
	m_length = 3;
}
Submarine::~Submarine() { }

Destroyer::Destroyer() {
	m_length = 3;
}
Destroyer::~Destroyer() { }

Patrol::Patrol() {
	m_length = 2;
}
Patrol::~Patrol() { }


/************************************
			GETTER
************************************/

int Boat::getLength() {
	return m_length;
}


/************************************
		OVERRIDDEN METHODS
************************************/

void Carrier::sunk() {
	cout << "Aircraft Carrier has sunk";
}
void Battleship::sunk() {
	cout << "Battleship has sunk";
}
void Submarine::sunk() {
	cout << "Submarine has sunk";
}
void Destroyer::sunk() {
	cout << "Destroyer has sunk";
}

void Patrol::sunk() {
	cout << "Patrol Boat has sunk";
}