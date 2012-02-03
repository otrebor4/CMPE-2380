/**********************************************************************
 Roberto Flores
 CSCI/CMPE 2380
 Homework assignment #1
**********************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*********************************************
 Hangman version 1 algorithm

 1) pick a secret word
 2) draw the empty gallows
 3) get a user guess
 4) add to the gallows, draw it again
 5) see if they lost, tell them so and exit
 6) ...or, loop back to step 3

*********************************************/

// include those other classes
#include "filedb.h"
#include "gallows.h"

int main()
{

	do{
	GallowsPole hangman;
	FileDB get_word;
	SecretWord s_word;
	CharacterCheck user_string;
	string secret_word;
	bool repeated = false;
	char ch;

	get_word.Init("secret_words.txt");
	secret_word = get_word.RandomLine();
	s_word.set_SecretWord(secret_word);
	s_word.set_RevealedWord();
	


	do{
		system("cls");
		cout<<"================ HANGMAN =================\n";
		hangman.Print();

		if(repeated)
		{
			cout << "repeated character " << ch << "!!";
		}
		cout << "\n\n";
		s_word.Print();
		cout << "  ";
		user_string.print();
		cout << "\n";

		cout << "Enter a character: ";
		cin >> ch;

		if(s_word.update(ch) && !user_string.repeated(ch))
		{
			hangman.Increment();
		}

		if(user_string.repeated(ch))
		{
			repeated = true;
		}

		if(!user_string.repeated(ch))
		{
			repeated = false;
			user_string.update(ch);
		}

		if(hangman.Done())
		{
			system("cls");
			cout<<"================ HANGMAN =================\n";
			hangman.Print();
			cout << "\n\n";
			s_word.Print();
			cout << "  ";
			user_string.print();
			cout << "\n\n";
			cout << "you lose!  The word was:" << secret_word <<"\n";
		}

		if(s_word.win())
		{
			system("cls");
			cout<<"================ HANGMAN =================\n";
			hangman.Print();
			cout << "\n\n";
			s_word.Print();
			cout << "  ";
			user_string.print();
			cout << "\n\n";
			cout << "YOU WIN! \n";
		}

	}while(!hangman.Done() && !s_word.win());


	}while( respond());
	system("pause");
	return 0;
}

