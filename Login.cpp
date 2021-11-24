#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int mainchoice;
	string username;
	string password;
	string repeatpassword;
	for(bool main = false; main == false;) 
	{
		cout << "Welcome into login pannel" << endl;
		cout << "What would you want to do?" << endl;
		cout << "1 - create an account" << endl;
		cout << "2 - login to account" << endl;
		cout << "3 - exit" << endl;
		cout <<	"Type your choice there: ";
		cin >> mainchoice;
			if (mainchoice == 1)
			{
				system("CLS");
				cout << "You've chosen to create an account" << endl;
				cout << "Choose your username: ";
				cin >> username;
				cout << "Choose your password: ";
				cin >> password;
				cout << "Repeat the password: ";
				cin >> repeatpassword;
				if (repeatpassword == password)
				{
					system("CLS");
					cout << "Your account has been created sucesfully! You can now log in!" << endl;
					system("pause");
					ofstream file;
					file.open("C:/Users/user/source/repos/Login/Login/logins/" + username + ".txt");
					file << username << endl << password;
					file.close();
					system("CLS");
				}
				else
				{
					system("CLS");
					cout << "Your passwords doesn't mach each other!\nTry again" << endl;
					system("pause");
					system("cls");
				}
			}
			
			else if (mainchoice == 2)
			{
				string usernamelog, passwordlog, un, pw;
				system("CLS");
				cout << "You've chosen to log in to account" << endl;
				cout << "Type in your username: ";
				cin >> usernamelog;
				cout << "Type in your password: ";
				cin >> passwordlog;

				ifstream read("C:/Users/user/source/repos/Login/Login/logins/" + usernamelog + ".txt");
				getline(read, un);
				getline(read, pw);
				if (un == username && pw == password)
				{
					system("cls");
					cout << "you succesfully logged in!" << endl;
					main = true;
				}
				else
				{
					system("cls");
					cout << "You typed wrong credentials!\n Try again" << endl;
					system("pause");
					system("cls");
				}
			}
			else if (mainchoice == 3)
			{ 
				system("CLS");
				cout << "Goodbye!" << endl;
				main = true;
			}
			else
			{
				system("cls");
				cout << "Please type in correct input option!" << endl;
				system("pause");
				system("cls");
			}
		}
	}

