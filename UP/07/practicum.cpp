#include <iostream>

int countOfOnes(int num) {
	int count = 0;

	while (num != 0) {
		if (num % 2 == 1) {
			count++;
		}

		num /= 2;
	}

	return count;
}

int countOfOnesBitwiseOperations(int num) {
	int count = 0;

	while (num != 0) {
		if (num & 1) {
			count++;
		}
		num >>= 1;
	}

	return count;
}

int ternaryToDecimal(int ternary) {
	int result = 0;
	int pow = 1;

	while (ternary != 0) {
		int lastDigit = ternary % 10;
		result += lastDigit * pow;
		pow *= 3;
		ternary /= 10;
	}

	return result;
}

int decimalToOcta(int decimal) {
	int result = 0;
	int pow = 1;

	while (decimal != 0) {
		int lastDigit = decimal % 8;
		result += lastDigit * pow;
		pow *= 10;
		decimal /= 8;
	}

	return result;
}

int octalToDecimal(int octal) {
	int result = 0;
	int pow = 1;

	while (octal != 0) {
		int lastDigit = octal % 10;
		result += lastDigit * pow;
		pow *= 8;
		octal /= 10;
	}

	return result;
}

int decimalToTernary(int decimal) {
	int result = 0;
	int pow = 1;

	while (decimal != 0) {
		int lastDigit = decimal % 3;
		result += lastDigit * pow;
		pow *= 10;
		decimal /= 3;
	}

	return result;
}

int ternaryToOctal(int ternary) {
	return decimalToOcta(ternaryToDecimal(ternary));
}

int octalToTernary(int octal) {
	return decimalToTernary(octalToDecimal(octal));
}


void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

void reverse(char* arr, int size) {
	for (int i = 0; i < size / 2; i++) {
		swap(arr[i], arr[size - i - 1]);
	}
}

void print(const char* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
	}
}

int charToNum(char ch) {
	if ('0' <= ch && ch <= '9') {
		return ch - '0';
	}

	if ('A' <= ch && ch <= 'Z') {
		return ch - 'A' + 10;  //!!!
	}
}

char numToChar(int n) {
	if (0 <= n && n <= 9) {
		return n + '0';
	}

	if (10 <= n && n <= 36) {
		return (n - 10) + 'A'; //!!!
	}
}

int randomToDecimal(const char* number, int& size, int fromBase) {
	int result = 0;
	int pow = 1;

	for (int i = size - 1; i >= 0; i--) {
		result += charToNum(number[i]) * pow;
		pow *= fromBase;
	}

	return result;
}

void decimalToRandom(int number, char* result, int& size, int toBase) {
	while (number != 0) {
		result[size] = numToChar(number % toBase);
		size++;
		number /= toBase;
	}

	reverse(result, size);
}

void twelveToThirteen(const char* fromNum, int& sizeFrom, char* toNum, int& sizeTo, int fromBase = 12, int toBase = 13) {
	int result = randomToDecimal(fromNum, sizeFrom, fromBase = 12);

	decimalToRandom(result, toNum, sizeTo, toBase = 13);
}


void printBinary(int num) {
	const int BIT_COUNT = 32;
	int result[BIT_COUNT];

	for (int i = 0; i < BIT_COUNT; i++) {
		result[i] = 0;
	}

	for (int i = BIT_COUNT - 1; i >= 0; i--) {
		result[i] = num % 2;
		num /= 2;
	}

	for (int i = 0; i < BIT_COUNT; i++) {
		std::cout << result[i];
	}
}

int main() {
	/*char fromNum[1024];
	char toNum[1024] = {};
	int sizeFrom, sizeTo = 0;

	std::cin >> fromNum;
	sizeFrom = std::strlen(fromNum);

	twelveToThirteen(fromNum, sizeFrom, toNum, sizeTo);

	print(toNum, sizeTo);*/
	
	printBinary(10);
}