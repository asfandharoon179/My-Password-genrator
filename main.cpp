#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Generate a single random character of any type
char RandomChar() {
    int type = rand() % 3; // 0: letter, 1: number, 2: symbol

    if (type == 0) { // Letter
        if (rand() % 2 == 0)
            return 'A' + rand() % 26;
        else
            return 'a' + rand() % 26;
    }
    else if (type == 1) { // Number
        return '0' + rand() % 10;
    }
    else { // Symbol
        int range = rand() % 4;
        if (range == 0)
            return 33 + rand() % 15;  // ! to /
        else if (range == 1)
            return 58 + rand() % 7;   // : to @
        else if (range == 2)
            return 91 + rand() % 6;   // [ to `
        else
            return 123 + rand() % 4;  // { to ~
    }
}
int main() {
    srand(time(0)); // Seed once
    int n;
    cout << "Enter the length of your password: ";
    cin >> n;
    cout << "Random password: ";
    for (int i = 0; i < n; i++) {
        cout << RandomChar();
    }
    cout << endl;
    return 0;
}