#include <iostream>

bool isEven(int n) {
	unsigned int mask = 1;

	return !(n & mask);
}

unsigned powTwo(int k) {
	if (k > 31) {
		return 0;
	}

	return 1 << k;
}

unsigned makeBitZero(unsigned int n, unsigned int idx) {
	unsigned int mask = 1;
	mask <<= idx;

	return n & ~mask;
}

unsigned makeBitOne(unsigned int n, unsigned int idx) {
	unsigned int mask = 1;
	mask <<= idx;

	return n | mask;
}

bool checkBitValue(unsigned int n, unsigned int idx) {
	unsigned int mask = 1;
	mask <<= idx;

	return (n & mask) == mask;
}

unsigned toggleBit(unsigned int n, unsigned int idx) {
	unsigned int mask = 1;
	mask <<= idx;

	return n ^ mask;
}


unsigned missingNumber(unsigned int* arr, unsigned size) {
	int result = 0;

	for (int i = 0; i < size; i++) {
		result ^= arr[i];
	}

	return result;
}

void printSubset(const int* arr, unsigned size, unsigned mask) {
	for (int i = 0; i < size; i++) {
		if (mask & 1) {
			std::cout << arr[i] << " ";
		}

		mask >>= 1;
	}
}

void printSubsets(const int* arr, unsigned size) {
	unsigned subsetsCount = 1 << size;

	for (int i = 0; i < subsetsCount; i++) {
		printSubset(arr, size, i);
	}
}

int main() {
	const unsigned LENGTH = 5;
	int arr[LENGTH] = { 1, 2, 3, 4, 5 };

	printSubsets(arr, LENGTH);
}