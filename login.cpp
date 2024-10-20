#ifndef LOGIN_CPP
#define LOGIN_CPP

#include<string>
#include<iostream>
#include"registration.cpp"

using namespace std;

bool validCredentials(string username, string password){
    int hashindex = hashfunction(username);

    if(RegVal.mainArr[hashindex] == nullptr)
        return 0;
    else{
         registrationData* temp = RegVal.mainArr[hashindex];
        while (temp != nullptr) {
            if(temp->username == username && temp->password == password)      //username valid
                return 1;
            temp = temp->next;
        }
    }
    return 0;
}

void Login(){
    string username;
    cout << "Enter username: ";
    cin >> username;

    string password;
    cout << "Enter password: ";
    cin >> password;

    while(!validCredentials(username,password)){
        cout << "Enter valid username: ";
        cin >> username;
        cout << "Enter valid password: ";
        cin >> password;
    }

    cout << "Login Successful " << endl;
}

#endif