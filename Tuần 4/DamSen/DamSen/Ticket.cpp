#include "Ticket.h"

Ticket::Ticket(string ID, string owner, int year, int game) {
	this->ID = ID;
	this->owner = owner;
	this->year = year;
	this->game = game;
}

Ticket::~Ticket() {
	this->ID = ID;
	this->owner = owner;
	this->year = year;
	this->game = game;
}

void Ticket::input() {
	cout << "- Nhap ma ve: ";
	cin >> ID;
	cout << endl << "- Nhap ten chu ve: ";
	cin >> owner;
	cout << endl << "- Nhap nam sinh:";
	cin >> year;
	cout << endl << "- Nhap so tro choi da choi";
	cin >> game;
}

string Ticket::getID() {
	return ID;
}

void Ticket::setID(string ID) {
	this->ID = ID;
}

string Ticket::getOwner() {
	return owner;
}

void Ticket::setOwner(string owner) {
	this->owner = owner;
}

int Ticket::getYear() {
	return year;
}

void Ticket::setYear(int year) {
	this->year = year;
}

int Ticket::getGame() {
	return game;
}

void Ticket::setGame(int game) {
	this->game = game;
}