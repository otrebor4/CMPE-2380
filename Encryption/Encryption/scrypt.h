#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;



class Encrypt
{
private:
	string Scrypt_message;  //Scrypted Message variable
	string key;				//Key
	string rotate_key;		//
	void check_string(string s);
	int encode_ch(char ch);
	int decode_ch(char ch);
	string rotate(string keyTR);

public:
	Encrypt();
	Encrypt(string key_string);
	void Set_key(string input_key);
	string encoding(string message);
	string decoding();
	string decode_message(string message);
};
