#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    string masterPassword = "master123"; // Replace with your master password
    string passwordList[10];
    int numPasswords = 0;

    string enteredPassword;
    int counter = 0;
    bool loggedIn = false;

    while (counter < 3) {
        cout << "Enter Master Password: ";
        cin >> enteredPassword;
        
        if (enteredPassword == masterPassword) {
            loggedIn = true;
            break;
        } else {
            cout << "\nIncorrect Master Password" << endl;
            counter++;
        }
    }

    if (!loggedIn) {
        cout << "\nToo many incorrect attempts. Exiting." << endl;
        return 0;
    }

    do {
        cout << "\n\t**************PASSWORD MANAGER**************";
        cout << "\n\t*                                       *";
        cout << "\n\t*     1.Add Password                     *";
        cout << "\n\t*     2.Display Passwords                *";
        cout << "\n\t*     3.Exit                             *";
        cout << "\n\t*                                       *";
        cout << "\n\t*****************************************" << endl;
        cout << "Please choose an option: ";
        int option;
        cin >> option;
        
        switch (option) {
            case 1:
                if (numPasswords >= 10) {
                    cout << "Password manager is full. Cannot add more passwords." << endl;
                } else {
                    cout << "Enter the password to add: ";
                    cin.ignore(); // Ignore newline left in buffer
                    getline(cin, passwordList[numPasswords]);
                    numPasswords++;
                    cout << "Password added successfully!" << endl;
                }
                break;
            case 2:
                cout << "\nStored Passwords:" << endl;
                for (int i = 0; i < numPasswords; i++) {
                    cout << i + 1 << ". " << passwordList[i] << endl;
                }
                break;
            case 3:
                cout << "Exiting Password Manager." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (true);

    getch();
    return 0;
}
