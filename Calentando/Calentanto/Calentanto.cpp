/*
Lervis Pinales 1096323
Check if an string is a Palindrome
*/

#include <iostream>
using namespace std;

int main() {
    char string1[20];
    int i, length;
    int flag = 0;

    cout << "Escribe el texto: "; cin >> string1;

    length = strlen(string1);

    for (i = 0; i < length; i++) {
        if (string1[i] != string1[length - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        cout << string1 << " No es un palíndromo " << endl;
    }
    else {
        cout << string1 << " Es un palíndromo " << endl;
    }
    system("pause");
    return 0;
}