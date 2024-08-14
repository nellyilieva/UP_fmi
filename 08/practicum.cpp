#include <iostream>

unsigned changeFirstOne(unsigned int n) {
	unsigned mask = 1;

	while (!(n & mask)) {
		mask <<= 1;
	}

	return n & ~mask;
}

unsigned returnCodedNumber(unsigned int n, unsigned int k) {
	unsigned mask = 1;
	mask <<= k;
	mask -= 1;

	return n & mask;
}

bool isInNum(unsigned int n, unsigned int k) {
	int sizeK = 0;
	int copy = k;

	while (copy != 0) {
		sizeK++;
		copy >>= 1;
	}

	while (n >= k) {
		if ((n & ((1 << sizeK) - 1)) == k) {  //last sizeK bits -> last bits that are not 0, to not have leading zeros
			return true;
		}
		n >>= 1;
	}

	return false;
}

unsigned missingNumber(unsigned int* arr, unsigned size) {
	unsigned result = 0;

	for (int i = 0; i < size; i++) {
		result ^= arr[i];
	}

	return result;
}

void printSubset(unsigned int* arr, unsigned size, unsigned mask) {
	std::cout << "[ ";

	for (int i = 0; i < size; i++) {
		if (1 & mask) {
			std::cout << arr[i] << " ";
		}
		mask >>= 1;
	}

	std::cout << "]";
}

void printSubsets(unsigned int* arr, unsigned size) {
	unsigned countOfSubsets = 1 << size;

	for (int i = 0; i < countOfSubsets; i++) {
		printSubset(arr, size, i);
	}
}

unsigned newNumber(unsigned int x, unsigned int m, unsigned int n) {
	unsigned mask = 1;
	mask <<= n;
	mask -= 1;

	mask <<= m;

	return (x & mask) >> m;
}

unsigned changeGivenBit(unsigned int n, unsigned int p, unsigned int b) {
	unsigned mask = 1;
	mask <<= p;

	n &= ~mask; // bit becomes 0

	if (b) {
		return n | mask;
	}

	return n;
}

unsigned changeBit(unsigned int n, unsigned int p) {
	unsigned mask = 1;
	mask <<= p;

	return n ^ mask;
}

bool arePermutation(unsigned int a, unsigned int b) {
	unsigned mask = 1;

	unsigned countA = 0;
	unsigned countB = 0;

	while (a != 0) {
		countA += a & mask;
		a <<= 1;
	}

	while (b != 0) {
		countB += b & mask;
		b <<= 1;
	}

	return countA == countB;
}

int main() {
	unsigned int arr[] = { 1, 3 };
	printSubsets(arr, 2);

	std::cout << arePermutation(7, 11);
}