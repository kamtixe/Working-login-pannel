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
	string usernamelog;
	string passwordlog;
	string inputusername;
	string inputpassword;
	int choiceending;
	for (bool main = false; main == false;)
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
					file.open(username + ".txt", ios::out);
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
				system("CLS");
				cout << "You've chosen to log in to account" << endl;
				cout << "Type in your username: ";
				cin >> usernamelog;
				cout << "Type in your password: ";
				cin >> passwordlog;
				system("cls");
				cout << "Confirm logging in by clicking enter!";
				ifstream read(usernamelog + ".txt");
				getline(read, inputusername);
				getline(read, inputpassword);
				if (inputusername == usernamelog && inputpassword == passwordlog)
				{
					system("cls");
					cout << "you succesfully logged in!" << endl;
					cout << "What would you want to do now?" << endl;
					cout << "1 - come back to main menu\n2 - exit the program" << endl;
					cout << "Enter your input here : ";
					cin >> choiceending;
					switch (choiceending)
					{
					case 1:
						system("cls");
						break;
					case 2:
						system("cls");
						main = true;
						system("pause");
						break;
					default:
						system("cls");
						cout << "Type in correct input!" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
				else
				{
					system("cls");
					cout << "You typed wrong credentials!\nTry again" << endl;
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

