#include "scrypt.h"


Encrypt::Encrypt()
{
	//set defaul key lenght in to 91 character key.
	key = "NOPQRSTUVWXYZABCDEFGHIJKLM !()*+,-./0123\"#$%&'456789:;<=>?[\\]^_`@opqrstuvwxyzabcdefghijklmn";

}

Encrypt::Encrypt(string key_string)
{
	Set_key(key_string);	
}

void Encrypt::check_string(string s)
{
	for(int i = 0; i + 1 < s.length(); i++)
	{
		for(int j = i + 1; j < s.length(); j++)
		{
			if(s[i] == s[j])
			{
				cout << "Error 1: String key have repeated characters.\n";
				system("pause");
				exit(1);
			}
		}
	}
}

void Encrypt::Set_key(string input_key)
{
	//can handle scrypt key length of 26, 58, and 91;
	if(input_key.length() == 26 || input_key.length() == 58 || input_key.length()==91)
	{

		check_string(input_key);
		key = input_key;
	}

	else
	{
		cout << "Error 2: String length of the input_key is out of range. Please use a string length of 26, 58 or 91.";
		system("pause");
		exit(2);
	}
}


int Encrypt::encode_ch(char ch)
{
	if(key.length() == 26) //to scrypt in to 26 character key
	{
		if((ch >= 97 && ch <= 122))
		{
			return (ch-97);
		}
	}

	else if(key.length() == 65) //to scrypt in to 65 character key
	{
		if((ch >= 65 && ch <= 122))
		{

			return (ch-65);
		}
		else
		{
			return -1; //-1 to represent space since 32 is in the range of the key
		}
	}

	else if(key.length() == 91) //scrypt in to 91 character key.
	{
		if(ch >= 32 && ch <= 122)
		{
			return (ch-32);

		}
	}

	return ch;//return unescrypted character.
}

string Encrypt::encoding(string message)
{
	int temp;
	rotate_key = key;


	for(int i = 0; i < message.length(); i++)//lop on the message to scrypted
	{
		temp = encode_ch(message[i]);//used to store the temporal porsition of the key
		
		

		if(key.length() == 26)//check if the leng of the key is 26 character.
		{
			if(temp >=0 && temp <26)
			{
				Scrypt_message = Scrypt_message + rotate_key[temp];//set encoded character
				rotate_key = rotate(rotate_key);
			}
			else
			{
				Scrypt_message = Scrypt_message + message[i];//set unidoded character since is out of range of the character key.
			}
		}

		else if(key.length() == 58)//check if is a 58 character key.
		{
			if(temp >= 0 && temp < 58)
			{
				Scrypt_message = Scrypt_message + rotate_key[temp];//set encode character
				rotate_key = rotate(rotate_key);
			}
			else if(temp == -1)
			{
				Scrypt_message = Scrypt_message + ' ';//set ' ' since [space] is in the range of the character key. 
			}
			else
			{
				Scrypt_message = Scrypt_message + message[i];//set unicoded character
			}
		}

		else if(key.length() == 91)//Check is is using 91 character key.
		{
			if(temp >= 0 && temp < 91)
			{
				Scrypt_message =Scrypt_message + rotate_key[temp]; //set  scrypted character.
				rotate_key = rotate(rotate_key);
			}

			else
			{
				Scrypt_message =Scrypt_message + message[i];//set unescrypted character;
			}
		}
		

	}

	return Scrypt_message;
}


int Encrypt::decode_ch(char ch)
{
	for(int i = 0; i < key.length(); i++)
	{
		if(ch == rotate_key[i])
		{
			return i;
		}
	}
	return -1;//character unescryted.
}

string Encrypt::decoding()
{
	string decode_message;  //used to store the message
	int temp;				//used to store the key[index]
	char ch_temp;			//used to store the unicoded character.

	rotate_key = key;

	for(int i = 0; i < Scrypt_message.length(); i++)
	{
		temp = decode_ch(Scrypt_message[i]); //set temp to the location of the character. if temp == -1 the character is unicoded.
		if(temp >= 0)
		{
			ch_temp = temp + (123-key.length());//set the unicoded character.
			decode_message = decode_message + ch_temp;//add character to the string 
			rotate_key = rotate(rotate_key);
		}
		else
		{
			decode_message = decode_message + Scrypt_message[i];//add unicoded character to the string.
		}
		
	}
	return decode_message;
}

string Encrypt::decode_message(string message)
{
	string decode_message;  //used to store the message
	int temp;				//used to store the key[index]
	char ch_temp;			//used to store the unicoded character.
	
	rotate_key = key;

	for(int i = 0; i < message.length(); i++)
	{
		temp = decode_ch(message[i]); //set temp to the location of the character. if temp == -1 the character is unicoded.
		if(temp >= 0)
		{
			ch_temp = temp + (123-key.length());//set the unicoded character.
			decode_message = decode_message + ch_temp;//add character to the string 
			rotate_key = rotate(rotate_key);
		}
		else
		{
			decode_message = decode_message + message[i];//add unicoded character to the string.
		}
		
	}
	return decode_message;
}

string Encrypt::rotate(string keyTR)
{
	int i;
	char temp_ch = keyTR[0];
	for(i = 0; i + 1 < keyTR.length(); i++)
	{
		keyTR[i] = keyTR[i+1];
	}
	keyTR[i] = temp_ch;

	return keyTR;
}