#include <iostream>

const unsigned MAX_SIZE = 1024;

void swap(unsigned& a, unsigned& b) {
	unsigned temp = a;
	a = b;
	b = temp;
}

void reverseArray(unsigned* arr, unsigned size) {
	for (int i = 0; i < size / 2; i++) {
		swap(arr[i], arr[size - i - 1]);
	}
}

void printArr(const unsigned* result, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cout << result[i];
	}
	std::cout << std::endl;
}

//decimal to binary
void decimalToBinary(unsigned decimal, unsigned* result, unsigned& resultSize) {
	resultSize = 0;

	while (decimal != 0) {
		result[resultSize] = decimal % 2;
		resultSize++;
		decimal /= 2;
	}

	reverseArray(result, resultSize);
}

//binary to decimal
unsigned binaryToDecimal(const unsigned* binary, unsigned& binarySize, unsigned result) {
	result = 0;
	int multiplier = 1;

	for (int i = binarySize - 1; i >= 0; i--) {
		result += binary[i] * multiplier;
		multiplier *= 2;
	}

	return result;
}

void mySwap(char& first, char& second) {
	unsigned temp = first;
	first = second;
	second = temp;
}

void reverseArray(char* arr, unsigned length) {
	for (unsigned i = 0; i < length / 2; i++) {
		mySwap(arr[i], arr[length - i - 1]);
	}
}

char decimalToChar(unsigned number) {
	if (0 <= number && number <= 9) {
		return number + '0';
	}
	if (10 <= number && number <= 36) {
		return (number - 10) + 'A';
	}

	return 0;
}

unsigned charToDecimal(char ch) {
	if ('0' <= ch && ch <= '9') {
		return ch - '0';
	}
	if ('A' <= ch && ch <= 'Z') {
		return ch - 'A' + 10;
	}

	return 0;
}

//decimal to random
void decimalToRandom(unsigned decimal, char* result, unsigned& resultSize, unsigned toBase) {
	resultSize = 0;

	while (decimal != 0) {
		result[resultSize] = decimalToChar(decimal % toBase);
		resultSize++;
		decimal /= toBase;
	}

	reverseArray(result, resultSize);
}

//random to decimal
unsigned randomToDecimal(const char* random, unsigned& randomSize, unsigned fromBase) {
	unsigned result = 0;
	int multiplier = 1;

	for (int i = randomSize - 1; i >= 0; i--) {
		result += charToDecimal(random[i]) * multiplier;
		multiplier *= fromBase;
	}

	return result;
}

void fromAnyBaseToAnyBase(
	const char* fromNumber,
	unsigned fromNumberLength,
	char* toNumber,
	unsigned& toNumberLength,
	unsigned fromBase,
	unsigned toBase
) {
	unsigned decimal = randomToDecimal(fromNumber, fromNumberLength, fromBase);
	decimalToRandom(decimal, toNumber, toNumberLength, toBase);
}

int main() {
	
}