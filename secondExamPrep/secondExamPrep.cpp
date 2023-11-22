// secondExamPrep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int returnBiggestNumber(int arr[], int SIZE) {
    int maxNumber = arr[0];

    for (int i = 1; i <= SIZE; i++) {
        if (maxNumber < arr[i]) {
            maxNumber = arr[i];
        }
    }

    return maxNumber;
}

void returnTime(int time) {
    int hours = time / 60 / 60;
    time = time % 3600;
    int minutes = time / 60;

    
    if (hours < 10 && minutes < 10) {
        cout << "0" << hours << ":" << "0" << minutes;
    }
    else if (hours < 10 && minutes > 10) {
        cout << "0" << hours << ":" << minutes;
    }
    else if (hours > 10 && minutes < 10) {
        cout << hours << ":" << "0" << minutes;
    }
    else {
        cout << hours << ":" << minutes;
    }

}

int returnSumOfOdd(double arr[], int SIZE) {
    double sumOfElements = 0;

    for (int i = 0; i < SIZE; i++) {
        if (i % 2 != 0) {
            sumOfElements += arr[i];
        }
    }

    return sumOfElements;
}

void transformNumber(int num) {
    int sumOfDigits = 0;
    int sizeOfNum = 0;

    int averageNum = 0;

    while (num > 0) {
        int lastDigit = num % 10;
        num /= 10;

        sumOfDigits += lastDigit;
        sizeOfNum++;
    }

    averageNum = sumOfDigits / sizeOfNum;

    cout << "The average number is: " << averageNum << endl;
}

int returnSumOfEven(int arr[], int SIZE) {
    int sumOfElements = 0;

    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            sumOfElements += arr[i];
        }
    }

    return sumOfElements;
}

int findSumOfDigits(int num) {
    int sumOfDigits = 0;

    while (num > 0) {
        int lastDigit = num % 10;
        num /= 10;

        sumOfDigits += lastDigit;
    }

    return sumOfDigits;
}


int main()
{
    //1
    /*const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int size;

    cout << "Enter array size: ";
    cin >> size;

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        int el;
        cin >> el;
        arr[i] = el;
    }

    int maxNum = returnBiggestNumber(arr, size);

    cout << "Max number is: " << maxNum;*/

    //2
    /*int num;
    cout << "Enter number between 0 and 86000 representing seconds: ";
    cin >> num;

    if (num >= 0 && num <= 86000) {
        returnTime(num);
    }
    else {
        cout << "Invalid number.";
    }*/

    //3
    /*int size;
    double arr1[] = { 5.3 };
    double arr2[] = { 3.4 ,2.6, 3.5 };
    double arr3[] = { 3.4 ,2.6, 3.5, 2.4, 1.3, 3.5 };

    double sum1 = returnSumOfOdd(arr1, size = 1);
    double sum2 = returnSumOfOdd(arr2, size = 3);
    double sum3 = returnSumOfOdd(arr3, size = 6);

    cout << "First sum is: " << sum1 << endl;
    cout << "Second sum is: " << sum2 << endl;
    cout << "Third sum is: " << sum3 << endl;*/

    //4
    /*int num1 = 5;
    int num2 = 87;
    int num3 = 4929;

    transformNumber(num1);
    transformNumber(num2);
    transformNumber(num3);*/

    //5
    /*int size;
    int arr1[] = { 5 };
    int arr2[] = { 3, 2, 3};
    int arr3[] = { 3, 2, 3, 8, 5, 1 };

    double sum1 = returnSumOfEven(arr1, size = 1);
    double sum2 = returnSumOfEven(arr2, size = 3);
    double sum3 = returnSumOfEven(arr3, size = 6);

    cout << "First sum is: " << sum1 << endl;
    cout << "Second sum is: " << sum2 << endl;
    cout << "Third sum is: " << sum3 << endl;*/
    
    //6
    int num1 = 5;
    int num2 = 87;
    int num3 = 4929;

    int sum1 = findSumOfDigits(num1);
    int sum2 = findSumOfDigits(num2);
    int sum3 = findSumOfDigits(num3);

    cout << "First sum is: " << sum1 << endl;
    cout << "Second sum is: " << sum2 << endl;
    cout << "Third sum is: " << sum3 << endl;
}