#include <iostream>

int returnModule(int n) {
	if (n >= 0) {
		return n;
	}
	else {
		return -n;
	}
}

int returnCount(int n) {
	int count = 0;

	if (n == 0) {
		return 1;
	}

	if (n < 0) {
		n *= -1;
	}

	while (n != 0) {
		count++;
		n /= 10;
	}

	return count;
}

int powFunc(int num, int pow) {
	int result = 1;

	for (int i = 0; i < pow; i++) {
		result *= num;
	}

	return result;
}

int concatNumbers(int a, int b) {
	int result = 0;
	int secondCount = returnCount(b);

	return a * powFunc(10, secondCount) + b;

	return result;
}

int reverseNumber(int n) {
	int newNum = 0;

	while (n != 0) {
		int lastDigit = n % 10;
		newNum = newNum * 10 + lastDigit;
		n /= 10;
	}

	return newNum;
}

int concatReversed(int n) {
	return concatNumbers(n, reverseNumber(n));
}

int isDigit(char ch) {
	if ('0' <= ch && ch <= '9') {
		return ch - '0';
	}
	else {
		return -1;
	}
}

int sumOfDigits(int n) {
	int result = 0;

	while (n != 0) {
		int lastDigit = n % 10;
		result += lastDigit;
		n /= 10;
	}

	return result;
}

int returnSumOfDigits(int n) {
	do {
		n = sumOfDigits(n);
	} while (n > 10);

	return n;


}



int main()
{
	int n;
	std::cin >> n;
	std::cout << returnSumOfDigits(n);


}