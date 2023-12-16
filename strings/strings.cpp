// strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int findSizeOfArray(char text[], int SIZE) {
    int sizeOfArray = 0;

    for (int i = 0; i < SIZE; i++) {
        if (text[i] == '\0') {
            sizeOfArray = i;
            return sizeOfArray;
        }
    }
}

bool isLowerCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return true;
    }
    return false;
}

int main()
{
    /*const int SIZE = 1000;
    char text[SIZE];
    cin.getline(text, SIZE);

    int sizeOfArray = findSizeOfArray(text, SIZE);
    bool isPalindrom = true;

    for (int i = 0; i < sizeOfArray; i++) {
        if (text[i] != text[sizeOfArray - i - 1]) {
            cout << "Not palindrom";
            isPalindrom = false;
            break;
        }
    }
    if (isPalindrom) {
        cout << "Is palindrom";
    }*/
    
    /*const int SIZE = 1000;
    char text[SIZE];
    cin.getline(text, SIZE);

    int sizeOfArray = findSizeOfArray(text, SIZE);

    int countOfExMark = 0;
    int countOfQuestionMark = 0;
    int countOfComma = 0;

    for (int i = 0; i < sizeOfArray; i++) {
        if (text[i] == '!') {
            countOfExMark++;
        }
        else if (text[i] == '?') {
            countOfQuestionMark++;
        }
        else if (text[i] == ',') {
            countOfComma++;
        }
    }*/

    /*const int SIZE = 1000;
    char text[SIZE];
    cin.getline(text, SIZE);

    int sizeOfArray = findSizeOfArray(text, SIZE);

    for (int i = 0; i < sizeOfArray; i++) {
        text[i] = text[i] + 32;
    }

    cout << text;*/

    const int SIZE = 1000;
    char text1[SIZE];
    cin.getline(text1, SIZE);

    int sizeOfArray1 = findSizeOfArray(text1, SIZE);

    char text2[SIZE];
    cin.getline(text2, SIZE);

    int sizeOfArray2 = findSizeOfArray(text2, SIZE);

    for (int i = 0; i < sizeOfArray1; i++) {
        if (isLowerCase(text1[i])) {
            for (int j = 0; j < sizeOfArray2; j++) {
                if (isLowerCase(text2[i])) {
                    if (text1[i] == text2[j]) {
                        cout << text1[i] << " ";
                    }
                }
            }
        }
    }
}
