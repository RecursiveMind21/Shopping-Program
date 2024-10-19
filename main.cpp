#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include"registration.cpp"

using namespace std;

int main() {
    int choice;

    cout << "----------------------------------------------------" << endl;
    cout << "DO YOU WANT TO ENTER (1 TO CONTINUE, 0 TO EXIT): ";
    cin >> choice;
    cout << "----------------------------------------------------" << endl;

    while (choice) {
        int firstoption;
        cout << "1. Register " << endl << "2. Log In" << endl;
        cin >> firstoption;

    s1:
        if (firstoption == 1) {   // Registration
            Register();
        } else if (firstoption == 2) {  // Login
            cout << "Log In functionality not implemented yet!" << endl;
        } else {  // Invalid input
            cout << "Invalid selection! ";
            goto s1;
        }

        // Ask the user again if they want to continue
        cout << "----------------------------------------------------" << endl;
        cout << "DO YOU WANT TO ENTER AGAIN (1 TO CONTINUE, 0 TO EXIT): ";
        cin >> choice;
        cout << "----------------------------------------------------" << endl;
    }

    return 0;
}
