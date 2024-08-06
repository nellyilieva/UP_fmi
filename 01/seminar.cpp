#include <iostream>

int main()
{

	//1
	/*int n;
	std::cin >> n;

	bool result = !(n % 2);
	std::cout << result;*/

	//2
	/*int n;
	std::cin >> n;

	int first = n / 100;
	int second = (n / 10) % 10;
	int third = n % 10;

	int result = third * 100 + second * 10 + first + 1;

	std::cout << result;*/

	//3
	/*char ch;
	std::cin >> ch;

	bool isVowel = (ch =='a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i'
					|| ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I');

	std::cout << isVowel;*/

	//4
	/*int n;
	std::cin >> n;

	bool isValid = (2 <= n <= 6);

	std::cout << isValid;*/

	//5
	/*int n;
	std::cin >> n;

	std::cout << n / 10;*/

	//6
	//int a;
	//int b;

	//std::cin >> a >> b;

	///*int result = (a + b) * (a + b) * (a + b) * (a + b) - (a - b) * (a - b);
	//std::cout << result;*/

	//int expr1 = a + b;
	//int expr2 = a - b;

	//int result = expr1 * expr1 * expr1 * expr1 - expr2 * expr2;
	//std::cout << result;

	//7
	/*int n;
	std::cin >> n;

	int count100 = n / 100;
	n %= 100;

	int count50 = n / 50;
	n %= 50;

	int count20 = n / 20;
	n %= 20;

	int count10 = n / 10;
	n %= 10;

	int count5 = n / 5;
	n %= 5;

	int count2 = n / 2;
	n %= 2;

	int count1 = n;

	std::cout << "Count of 100: " << count100 << " Count of 50: " << count50 << " Count of 20: " << count20 <<
		" Count of 10: " << count10 << " Count of 5: " << count5 << " Count of 2: " << count2 << " Count of 1: " << count1;*/

	//8
	/*int a;
	int b;

	std::cin >> a >> b;

	bool isFirstBigger = a > b;

	std::cout << a * isFirstBigger + b * !isFirstBigger;*/

	//9
	int a;
	int b;
	std::cin >> a >> b;

	a += b;
	b = a - b;
	a -= b;

	std::cout << a << " " << b;

}