#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "registration.cpp"
#include "login.cpp"
#include "home.cpp"

using namespace std;

bool isLoggedIn = false;  // New variable to track login status

int main() {

  while (1) {
    int firstoption;
    cout << "1. Register " << endl << "2. Log In" << endl << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> firstoption;

  s1:
    if (firstoption == 1) {   // Registration
      Register();
    } else if (firstoption == 2) {  // Login
      Login();
      isLoggedIn = true;  // Set to true after successful login
    } else if (firstoption == 3){
      return 0;
    } else {  // Invalid input
      cout << "Invalid selection! ";
      goto s1;
    }

    // Check login status and display appropriate menu
    if (isLoggedIn) {
      homepage();
      isLoggedIn = false; // Reset login status after exiting home menu
    }
  }

  return 0;
}