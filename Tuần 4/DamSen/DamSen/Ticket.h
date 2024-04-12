#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket {
private:
	string ID;
	string owner;
	int year;
	int game;
public:
	Ticket(string ID, string owner, int year, int game);
	~Ticket();
	void input();
	string getID();
	void setID(string ID);
	string getOwner();
	void setOwner(string owner);
	int getYear();
	void setYear(int year);
	int getGame();
	void setGame(int game);
};