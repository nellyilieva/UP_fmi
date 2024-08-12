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


int findFirstRepeating(const int* arr, unsigned length) {
	for (int i = 0; i < length; i++) {
		int curr = arr[i];

		for (int j = i + 1; j < length; j++) {
			if (curr == arr[j]) {
				return curr;
			}
		}
	}
	return -1;
}

void isPalindrom(const int* arr, unsigned length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] != arr[length - i - 1]) {
			std::cout << "false";
			return;
		}
	}
	std::cout << "true";
	return;
}

void reverseFirstHalf(int* arr, unsigned length) {
	int halfLength = length / 2;

	for (int i = 0; i < halfLength / 2; i++) {
		swap(arr[i], arr[halfLength - i - 1]);
	}
}

void removeElement(int* arr, unsigned length, unsigned idx) {
	if (!isValidIdx(length, idx)) {
		std::cout << "Invalid idx";
		return;
	}

	for (int i = idx; i < length; i++) {
		swap(arr[i], arr[i + 1]);
	}

	arr[length - 1] = -1;
}

void findMissigElement(const int* arr, unsigned length = 20) {
	int totalSum = 0;

	for (int i = 0; i <= length; i++) {
		totalSum += i;
	}

	for (int i = 0; i < length; i++) {
		totalSum -= arr[i];
	}

	std::cout << totalSum;
	return;
}

void countOfOccurances(const int* arr, unsigned length = 10) {
	int occurances = 0;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (i == arr[j]) {
				occurances++;
			}
		}

		std::cout << "Number: " << i << " Occurances: " << occurances << std::endl;
		occurances = 0;
	}
}

bool isSorted(const int* arr, unsigned length) {
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void avgValueAndClosesNumber(const int* arr, unsigned length) {
	double sumOfElements = 0;

	for (int i = 0; i < length; i++) {
		sumOfElements += arr[i];
	}

	double avg = sumOfElements / length;

	int closest = arr[0];
	double minDifference = (closest > avg) ? closest - avg : avg - closest;

	for (int i = 1; i < length; i++) {
		double currDifference = (arr[i] > avg) ? arr[i] - avg : avg - arr[i];

		if (currDifference < minDifference) {
			minDifference = currDifference;
			closest = arr[i];
		}
	}

	std::cout << avg << " " << closest;
	return;
}

void minAndMaxElement(const int* arr, unsigned length) {
	int minElement = arr[0];
	int maxElement = arr[0];

	for (int i = 1; i < length; i++) {
		if (arr[i] < minElement) {
			minElement = arr[i];
		}

		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}
	}

	std::cout << minElement << " " << maxElement;
}

int main() {
	int arr[MAX_SIZE];

	unsigned length;
	do {
		std::cin >> length;
	} while (!isValidLength(length));

	readArray(arr, length);

	minAndMaxElement(arr, length);

	//printArray(arr, length);
}