#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Check if username already exists
bool userExists(string username) {
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser() {
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    // Username validation
    if (username.length() < 3) {
        cout << "Error: Username must contain at least 3 characters.\n";
        return;
    }

    // Duplicate username check
    if (userExists(username)) {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    // Password validation
    if (password.length() < 6) {
        cout << "Error: Password must contain at least 6 characters.\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser() {

    string username, password;
    string user, pass;

    bool found = false;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass) {

        if (user == username && pass == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login Successful! Welcome " << username << ".\n";
    else
        cout << "Error: Invalid Username or Password.\n";
}

int main() {

    int choice;

    do {

        cout << "\n========== LOGIN & REGISTRATION SYSTEM ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}