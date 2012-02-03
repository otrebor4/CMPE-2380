#include<iostream>
#include<string>

#include"scrypt.h"

using namespace std;


int main()
{
	string key = "qwertyuiopasdfghjklzxcvbnm";
	string key2 ="defghijklmnopqrstuvwxyzabc";

	Encrypt message;
	string user_message;

	cout << "Enter a Message: ";
	getline(cin, user_message);

	cout << message.encoding(user_message);
	cout << "\n";

	cout << message.decoding();
	cout <<"\n";

	message.Set_key(key);

	cout << message.decode_message("nhv mdl mgd xad! yxl ixzpbf cphxrk px povlicktbt.");
	cout <<"\n";
	system("pause");
	return 0;
}
