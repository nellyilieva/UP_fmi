#include <iostream>

int main()
{
	//2
	/*char ch;
	std::cin >> ch;

	bool isVowel = (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i'
		|| ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I');

	if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
		if (isVowel) {
			std::cout << "Vowel";
		}
		else {
			std::cout << "Not vowel";
		}
	}
	else {
		std::cout << "Not letter";
	}*/

	//3
	/*double a;
	double b;
	std::cin >> a >> b;

	std::cout << (a < b ? "The first is smaller" : "The second is smaller");*/

	//4
	/*int n;
	std::cin >> n;

	if (n >= 90) {
		std::cout << "6+";
	}
	else if (n >= 80) {
		std::cout << "6";
	}
	else if (n >= 70) {
		std::cout << "5";
	}
	else if (n >= 60) {
		std::cout << "4";
	}
	else if (n >= 40) {
		std::cout << "3";
	}
	else {
		std::cout << "2";
	}*/

	//5
	/*double a, b, c;
	std::cin >> a >> b >> c;

	if (a > b + c && b > a + c && c > a + b) {
		std::cout << "Valid";
	}
	else {
		std::cout << "Invalid";
	}*/

	//7
	/*char ch;
	std::cin >> ch;

	if ('a' <= ch && ch <= 'z') {
		char upperCh = ch - 32;
		std::cout << upperCh;
	}
	else {
		std::cout << "Invalid character";
	}*/

	//8
	/*int n;
	std::cin >> n;

	switch (n) {
	case 1: std::cout << "I"; break;
	case 2: std::cout << "II"; break;
	case 3: std::cout << "III"; break;
	case 4: std::cout << "IV"; break;
	case 5: std::cout << "V"; break;
	case 6: std::cout << "VI"; break;
	case 7: std::cout << "VII"; break;
	case 8: std::cout << "VIII"; break;
	case 9: std::cout << "IX"; break;
	default: std::cout << "Not a digit"; break;
	}*/

	//9
	/*int a, b, c;
	std::cin >> a >> b >> c;

	if (a < b && a < c) {
		std::cout << a << " ";
		if (b < c) {
			std::cout << b << " " << c;
		}
		else {
			std::cout << c << " " << b;
		}
	}
	else if (b < a && b < c) {
		std::cout << b << " ";
		if (a < c) {
			std::cout << a << " " << c;
		}
		else {
			std::cout << c << " " << a;
		}
	}
	else if (c < a && c < b) {
		std::cout << c << " ";
		if (a < b) {
			std::cout << a << " " << b;
		}
		else {
			std::cout << b << " " << a;
		}
	}
	else if (a < c && a == b) {
		std::cout << a << " " << b << " " << c;
	}
	else if (a < b && a == c) {
		std::cout << a << " " << c << " " << b;
	}
	else if (b == c && a < b) {
		std::cout << a << " " << c << " " << b;
	}
	else if (b == c && b < a) {
		std::cout << b << " " << c << " " << a;
	}
	else {
		std::cout << a << " " << b << " " << c;
	}*/

	//10
	/*double a, b;
	char operation;

	std::cin >> a >> operation >> b;

	if (operation == '+') {
		std::cout << a + b;
	}
	else if (operation == '-') {
		std::cout << a - b;
	}
	else if (operation == '*') {
		std::cout << a * b;
	}
	else if (operation == '/') {
		if (b == 0) {
			std::cout << "Division by 0";
		}
		else {
			std::cout << a / b;
		}
	}
	else {
		std::cout << "Invalid charcter";
	}*/

	//11
	/*int a, b, c;
	std::cin >> a >> b >> c;

	int largest;
	int middle;
	int smallest;

	if (a >= b && a >= c) {
		largest = a;
		if (b >= c) {
			middle = b;
			smallest = c;
		}
		else {
			middle = c;
			smallest = b;
		}
	}
	else if (b >= a && b >= c) {
		largest = b;
		if (a >= c) {
			middle = a;
			smallest = c;
		}
		else {
			middle = c;
			smallest = a;
		}
	}
	else {
		largest = c;
		if (a >= b) {
			middle = a;
			smallest = b;
		}
		else {
			middle = b;
			smallest = a;
		}
	}

	std::cout << largest * 100 + middle * 10 + smallest;*/

	//13
	int n;
	std::cin >> n;

	int first = (n / 1000) * 10 + n % 10;
	int second = (n % 1000) / 10;

	if (first < second) {
		std::cout << "less " << first << " < " << second;
	}
	else if (first > second) {
		std::cout << "more " << first << " > " << second;
	}
	else {
		std::cout << "equal " << first << " = " << second;
	}
}