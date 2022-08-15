#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isloggedin() {
    string username,password,un,pw;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream read("C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\login and register\\info\\" + username + ".txt");
    getline(read,un);
    getline(read,pw);

    if (un == username && pw == password) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int choice;
    
    cout << "1. Register\n2. Login\nChoose a number: ";
    cin >> choice;

    if (choice == 1) {
        string username,password;

        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        ofstream file;
        file.open("C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\login and register\\info\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    } else if (choice == 2) {
        bool status = isloggedin();

        if (!status) {
            cout << "False login!" << endl;
            return 0;
        } else {
            cout << "Successfully logged in!" << endl;
            return 1;
        }
    }


}