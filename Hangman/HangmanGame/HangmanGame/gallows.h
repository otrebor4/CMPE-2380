#include <iostream>
#include <string>
using namespace std;

// useful thing to avoid certain include errors
#ifndef GALLOWSPOLE_H
#define GALLOWSPOLE_H

// this class keeps a count from 0 to 6, displaying it as a "hangman"
class GallowsPole
{
public:
	// default constructor sets the internal counter to 0
	GallowsPole();	

	// Done returns true if the internal counter is equal to the MAX constant
	bool Done();

	// Increment increments the internal counter
	void Increment();
	// Draw prints the gallows to the screen
	void Print();


private:
	// constant indicates how many states it can show
	static const int MAX = 6;

	// internal counter variable
	int strikes;

	// private drawing methods for organization
	void draw0();
	void draw1();
	void draw2();
	void draw3();
	void draw4();
	void draw5();
	void draw6();
};


class SecretWord
{
private:
	string secret_word;
	string revealed_word;
	int word_zise;

public:
	void set_SecretWord(string word);
	void set_RevealedWord();
	void Print();
	bool update(char ch);
	bool win();
	
};

class CharacterCheck
{
private:
	string ch_str;
	int counter;

public:
	CharacterCheck();
	void print();
	void update(char ch);
	bool repeated(char ch);
};

bool respond();

#endif
