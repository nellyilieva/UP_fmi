#include <iostream>

const unsigned MAX_SIZE = 1000;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool isValidIdx(unsigned length, unsigned idx) {
	return 0 <= idx && idx <= length - 1;
}

bool isValidLength(unsigned length) {
	return 0 < length && length <= MAX_SIZE;
}

void readArray(int* arr, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cin >> arr[i];
	}
}

void printArray(const int* arr, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


void fillTheArray(const int* arr, unsigned arrSize, int* result, unsigned resultSize, int a, int b) {
	resultSize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (a <= arr[i] && arr[i] <= b) {
			result[resultSize] = arr[i];
			resultSize++;
		}
	}
}

int countOfDecSet(const int* arr, unsigned size) {
	int count = 0;
	int currCount = 1;
	
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] >= arr[i + 1]) {
			currCount++;
		}
		else {
			if (currCount > count) {
				count = currCount;
			}
			currCount = 1;
		}
	}

	return count;
}

int countOfEqualNum(const int* arr, unsigned size) {
	int count = 0;
	int currCount = 1;

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			currCount++;
		}
		else {
			if (currCount > count) {
				count = currCount;
			}
			currCount = 1;
		}
	}

	return count;
}

bool isInNumber(int num, int idx) {
	while (num != 0) {
		int lastDigit = num % 10;
		if (lastDigit == idx) {
			return true;
		}
		num /= 10;
	}

	return false;
}

int* nullArray(int* arr, unsigned size) {
	for (int i = 0; i < size; i++) {
		if (!isInNumber(arr[i], i)) {
			arr[i] = 0;
		}
	}

	return arr;
}

int main() {
	int arr[MAX_SIZE];

	unsigned length;
	do {
		std::cin >> length;
	} while (!isValidLength(length));

	readArray(arr, length);

	printArray(nullArray(arr, length), length);
}