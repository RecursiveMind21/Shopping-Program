#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

// Registration data class
class registrationData {
public:
    string name;
    string DOB;
    string username;
    string password;
    registrationData* next;

    // Constructor
    registrationData(string name, string DOB, string username, string password) {
        this->name = name;
        this->DOB = DOB;
        this->username = username;
        this->password = password;
        this->next = nullptr;
    }
};

// Handling registered persons data
class RegisteredValues {
public:
    vector<registrationData*> mainArr = vector<registrationData*>(10, nullptr);

    void insertValues(int index, registrationData* newentry) {
        if (mainArr[index] == nullptr) {
            // Insert directly if it's the first entry at this index
            mainArr[index] = newentry;
        } else {
            // Use a temporary pointer to traverse
            registrationData* temp = mainArr[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newentry;
        }
    }

    void print() {
        cout << "Printing HashTable : " << endl;
        for (int i = 0; i < 10; i++) {
            if (mainArr[i] != nullptr) {
                cout << i << " -> ";
                registrationData* temp = mainArr[i];
                while (temp != nullptr) {
                    cout << temp->username << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

// Global object
RegisteredValues RegVal;

// Hash function to calculate index
int hashfunction(string username) {
    username = username.substr(4, 4);  // Extract numeric part
    int tempnumber = stoi(username);

    // Reduce to a single digit
    while (tempnumber >= 10) {
        int rem = tempnumber % 10;
        tempnumber /= 10;
        tempnumber += rem;
    }

    return tempnumber;
}

//------------------------------------------------------------------------------------------------------------
                                    //->Validation<-//

int findUsername(string username){
    int hashindex = hashfunction(username);

    if(RegVal.mainArr[hashindex] == nullptr)
        return 0;
    else{
         registrationData* temp = RegVal.mainArr[hashindex];
        while (temp != nullptr) {
            if(temp->username == username)      //username already found
                return 1;
            temp = temp->next;
        }
    }
    return 0;
}
int validateUsername(string username) {
    // Check if the length is exactly 8 characters
    if (username.length() != 8) {
        return 1; 
    }

    // Check if the first 4 characters are alphabetical (A-Z or a-z)
    for (int i = 0; i < 4; i++) {
        if (!((username[i] >= 'A' && username[i] <= 'Z') || (username[i] >= 'a' && username[i] <= 'z'))) {
            return 1; 
        }
    }

    // Check if the last 4 characters are numeric (0-9)
    for (int i = 4; i < 8; i++) {
        if (username[i] < '0' || username[i] > '9') {
            return 1;  
        }
    }

    if(findUsername(username) == 1)
        return 2;

    return 0;
}
int validatePassword(string username, string password) {
    if (password.length() < 4)
        return 1;  // Password is too short
    
    bool alphabets = false;
    bool numbers = false;

    for (char c : password) {
        if (isdigit(c)) 
            numbers = true;  // Check if there is a number
        if (isalpha(c)) 
            alphabets = true;  // Check if there is a letter
    }

    if (!(alphabets && numbers))
        return 1;  // Password must be alphanumeric

    return 0;  // Password is valid
}


//------------------------------------------------------------------------------------------------------------
                                    //->Validation Ends<-//

// Register function to input and insert user data
void Register() {
    string name;
    string DOB;
    string username;
    string password;

    cout << "-------------------------------------------" << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your date of birth (DDMMYYYY): ";
    cin >> DOB;
    cout << "Enter username (Format -> ABCD1234): ";
    cin >> username;

    // Username validation loop
    while (true) {
        int usernameValidation = validateUsername(username);
        if (usernameValidation == 1) {
            cout << "Invalid username (username should be of format ABCD1234): ";
            cin >> username;
        } else if (usernameValidation == 2) {
            cout << "Username already exists! \n";
            cout << "Enter a different username: ";
            cin >> username;
        } else {
            break;  // Username is valid and unique
        }
    }

    cout << "Enter password: ";
    cin >> password;

    // Password validation loop
    while (true) {
        int passwordValidation = validatePassword(username, password);
        if (passwordValidation == 1) {
            cout << "Invalid password (password must be alphanumeric and at least 4 characters long): ";
            cin >> password;
        }else {
            break;  // Password is valid and unique
        }
    }

    cout << "-------------------------------------------" << endl;

    // Create new registration data object
    registrationData* newvalue = new registrationData(name, DOB, username, password);

    // Calculate index using hash function
    int index = hashfunction(username);

    // Insert the new entry into the hash table
    RegVal.insertValues(index, newvalue);
}
