#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{   int choice;

    while (true)
    {   cout << "\n===== LOGIN AND REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {   string username, password;
            cout << "\nEnter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            ofstream file("users.txt", ios::app);
            file << username << " " << password << endl;
            file.close();
            cout << "\nRegistration Successful!\n";
        }

        else if (choice == 2)
        {   string username, password;
            string storedUser, storedPass;
            bool found = false;
            cout << "\nEnter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            ifstream file("users.txt");
            while (file >> storedUser >> storedPass)
            {   if (username == storedUser && password == storedPass)
                {   found = true;
                    break;
                }
            }
            file.close();

            if (found)
            {  cout << "\nLogin Successful!\n";
            }
            else
            {  cout << "\nInvalid Username or Password!\n";
            }
        }

        else if (choice == 3)
        {   cout << "\nThank You!\n";
            break;
        }

        else
        {cout << "\nInvalid Choice!\n";
        }
    }
    return 0;
}