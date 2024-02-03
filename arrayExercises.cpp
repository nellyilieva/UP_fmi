// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const unsigned int MAX_SIZE = 1000;

void swap(unsigned a, unsigned b) {
	unsigned temp = a;
	a = b;
	b = temp;
}

bool isValidLength(unsigned size) {
	return 1 <= size && size <= MAX_SIZE;
}

void readArray(int* arr, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void printArray(const int* arr, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int firstRepeatingElement(const int* arr, unsigned size) {
	unsigned idx = 0;

	for (int i = 1; i < size; i++) {
		unsigned curr = arr[idx];

		if (curr == arr[i]) {
			return curr;
		}
		else if (i == size - 1) {
			idx++;
		}
	}
}

bool isPalindrom(const int* arr, unsigned size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] != arr[size - i - 1]) {
			return false;
		}
	}
	return true;
}

void reverseFirstPart(int* arr, unsigned size) {
	int halfSize = size / 2;

	for (int i = 0; i < halfSize; i+=2) {
		swap(arr[i], arr[halfSize - i - 1]);
	}
}

void deleteElement(int* arr, unsigned size, unsigned idx) {
	for (int i = idx; i < size; i++) {
		if (i == size - 1) {
			arr[size - 1] = -1;
		}
		else {
			swap(arr[i], arr[i + 1]);
		}
	}
}


int main()
{
	int arr[MAX_SIZE];

	unsigned n;
	do {
		cin >> n;
	} while (!isValidLength(n));

	readArray(arr, n);
	unsigned idx;
	cin >> idx;

	deleteElement(arr, n, idx);

	printArray(arr, n);


}
