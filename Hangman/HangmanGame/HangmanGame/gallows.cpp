
#include "gallows.h"

void GallowsPole::draw0()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

void GallowsPole::draw1()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |   O  " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

void GallowsPole::draw2()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |   O  " << endl;
    cout << " |   |  " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

void GallowsPole::draw3()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |   O  " << endl;
    cout << " |  /|  " << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

void GallowsPole::draw4()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |   O  " << endl;
    cout << " |  /|\\" << endl;
    cout << " |      " << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

void GallowsPole::draw5()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |   O  " << endl;
    cout << " |  /|\\" << endl;
    cout << " |  /   " << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

void GallowsPole::draw6()
{
    cout << " _____  " << endl;
    cout << " |   |  " << endl;
    cout << " |   O  " << endl;
    cout << " |  /|\\" << endl;
    cout << " |  / \\" << endl;
    cout << " |      " << endl;
    cout << "--------" << endl;
}

GallowsPole::GallowsPole()
{
	strikes = 0;
}

void GallowsPole::Print()
{
	if(strikes == 0)
	{
		draw0();
	}
	if(strikes == 1)
	{
		draw1();
	}
	if(strikes == 2)
	{
		draw2();
	}
	if(strikes == 3)
	{
		draw3();
	}
	if(strikes == 4)
	{
		draw4();
	}
	if(strikes == 5)
	{
		draw5();
	}
	if(strikes == 6)
	{
		draw6();
	}
}

void GallowsPole::Increment()
{
	if(strikes != MAX)
	{
		strikes++;
	}
}

bool GallowsPole::Done()
{
	if(strikes == MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//SercretWord

void SecretWord::set_SecretWord(string word)
{
	secret_word = word;
}

void SecretWord::set_RevealedWord()
{
	revealed_word = "";
	word_zise=secret_word.length();

	for(int i = 0; i < word_zise; i++)
	{
		revealed_word = revealed_word + "_";
	}
}

void SecretWord::Print()
{

	for(int i = 0 ; i < word_zise; i++)
	{
		cout << revealed_word[i]<<" ";
	}
}

bool SecretWord::update(char ch)
{
	bool err_check = true;

	for(int i = 0; i < word_zise; i++)
	{
		if(ch == secret_word[i])
		{
			revealed_word[i] = ch;
			err_check = false;
		}

	}

	return err_check;
}

bool SecretWord::win()
{
	if(revealed_word == secret_word)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Character checker
CharacterCheck::CharacterCheck()
{
	ch_str = "";
	counter = 0;
}

void CharacterCheck::print()
{
	cout << "( ";
	for(int i = 0; i < counter; i ++)
	{
		cout << ch_str[i] << " ";
	}
	cout << " )";
}

bool CharacterCheck::repeated(char ch)
{
	bool repeated = false;
	for(int i = 0; i < counter; i ++)
	{
		if(ch == ch_str[i])
		{
			repeated = true;
		}
	}
	return repeated;
}

void CharacterCheck::update(char ch)
{
	ch_str = ch_str + ch;
	counter++;
}


bool respond()
{
	char resp = 'y';
	int retry = 1;
	do{
	cout << "Would you like play again? (y/n): ";
	cin >> resp;
	
	cin.ignore(10000,'\n');

	if(resp =='y' || resp == 'Y')
		{
			
			return true;
		}

	else if(resp == 'n' || resp == 'N'||retry > 2)
		{
			return false;
		}
	else 
		{
			retry++;
		}
	}while(true);
}