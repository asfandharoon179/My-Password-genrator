#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

char RandomChar() {
    int type = rand() % 3; // 0: letter, 1: number, 2: symbol
    if (type == 0) {
        if (rand() % 2 == 0)
            return 'A' + rand() % 26;
        else
            return 'a' + rand() % 26;
    }
    else if (type == 1) {
        return '0' + rand() % 10;
    }
    else {
        //This is for different symbols
        int range = rand() % 4;
        if (range == 0)
            return 33 + rand() % 15;
        else if (range == 1)
            return 58 + rand() % 7;
        else if (range == 2)
            return 91 + rand() % 6;
        else
            return 123 + rand() % 4;
    }
}
int main() {
    srand(time(0));
    int n;
    string password = "";
    string webname;
    bool wantosave;
    cout << "Enter the length of your password: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        password += RandomChar();  
    }
    cout << "Random password: " << password << endl;
    cout << "Do you want to save the password? (1 = yes, 0 = no): ";
    cin >> wantosave;
    if (wantosave) {
        cout << "Enter website name: ";
        cin >> webname;

        ofstream topen("password.txt", ios::app);
        topen << webname << " : " << password << endl;
        topen.close();

        cout << "Password saved successfully.\n";
    }
    else {
        cout << "No problem. Password not saved.\n";
    }

    return 0;
}
