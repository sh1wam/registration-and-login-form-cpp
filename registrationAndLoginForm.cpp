#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to handle user registration
void registerUser()
{
    string username, password;

    cout << "--Registration--" << endl;
    cout << "Enter a new username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // File Handling
    ofstream file("data.txt", ios::app);
    if (file.is_open())
    {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration Successfull" << endl;
    }
    else
    {
        cerr << "Error: Unable to open file for writing" << endl;
    }
}

// Function to handle user login
void loginUser()
{
    string username, password, storedUsername, storedPassword;
    bool loggedIn = false;

    cout << "--Login--" << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Open file for reading
    ifstream file("data.txt");
    if (file.is_open())
    {
        while (file >> storedUsername >> storedPassword)
        {
            if (username == storedUsername && password == storedPassword)
            {
                loggedIn = true;
                break;
            }
        }
        file.close();

        if (loggedIn)
        {
            cout << "\n Welcome, " << username << "! logged in successful" << endl;
        }
        else
        {
            cout << "Invalid username or password, Please try again" << endl;
        }
    }
    else
    {
        cerr << "Error: no user data found, Please register first" << endl;
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n ---Main Menu---" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your Choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "GoodBye!" << endl;
            return 0;
        default:
            cout << "Invalid Choice: Please try again: " << endl;
        }
    }
    return 0;
}