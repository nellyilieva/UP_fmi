#include <iostream>

int main()
{
	//1
	//::cout << "Oh what" << std::endl << "a happy day!" << std::endl << "Oh yes," << std::endl << "what a happy day!";

	//2
	/*const double a = 5.4;
	const double b = 7.9;

	double perimetar = 2 * (a + b);
	double area = a * b;

	std::cout << "Perimetar: " << perimetar << std::endl << "Area: " << area;*/

	//3
	/*const double euro = 0.51;
	const double dollar = 0.56;

	double n;
	std::cin >> n;

	std::cout << "In euros: " << n * euro << std::endl << "In dollars: " << n * dollar;*/

	//4
	/*double a;
	double b;

	std::cout << "Please enter the length of the first";
	std::cin >> a;
	std::cout << "Please enter the length of the second";
	std::cin >> b;

	std::cout << "Perimetar: " << 2 * (a + b) << std::endl << "Area: " << a * b;*/

	//5
	/*double a;
	double b;

	std::cin >> a >> b;

	std::cout << ((a < b) ? "true" : "false");*/

	//6
	/*int dividend;
	int divisor;

	std::cout << "Enter dividend";
	std::cin >> dividend;
	std::cout << "Enter divisor";
	std::cin >> divisor;

	std::cout << "The quotient of the division is: " << dividend / divisor << std::endl;
	std::cout << "The remainder of the division is: " << (dividend % divisor);*/

	//7
	/*int apples;
	int pears;
	int bananas;

	std::cin >> apples >> pears >> bananas;
	std::cout << "Pesho, don’t forget to buy " << apples << " apples, " << pears << " pears and " << bananas << " bananas!";*/

	//8
	/*const double PI = 3.14159265;

	double r;
	std::cin >> r;
	std::cout << "Length: " << 2 * PI * r << std::endl << "Area: " << PI * r * r;*/

	//9
	/*double a;
	double b;
	double c;

	std::cin >> a >> b >> c;

	double d = sqrt(b * b - 4 * a * c);

	double first = (-b + d) / 2 * a;
	double second = (-b - d) / 2 * a;

	std::cout << first << " " << second;*/

	//10
	/*double a;
	double b;

	std::cin >> a >> b;

	a += b;
	b = a - b;
	a -= b;

	std::cout << a << " " << b;*/

	//11
	/*double a;
	double b;

	std::cin >> a >> b;

	bool isSmaller = a < b;

	std::cout << isSmaller * a + !isSmaller * b;*/

	//12
	/*const int secondsInDay = 24 * 60 * 60;

	int dataSeconds;
	std::cin >> dataSeconds;

	int days = dataSeconds / secondsInDay;
	int hours = (dataSeconds % secondsInDay) / 3600;
	int minutes = (dataSeconds % secondsInDay) % 3600 / 60;
	int seconds = (dataSeconds % secondsInDay) % 3600 % 60;

	std::cout << days << " days, " << hours << " hours, " << minutes << " minutes and " << seconds << " seconds";*/

	//13
	/*double a1;
	double a2;

	double b1;
	double b2;

	std::cin >> a1 >> a2 >> b1 >> b2;

	double d = sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));

	std::cout << d;*/

	//14
	/*long long n;
	std::cin >> n;

	std::cout << "XXXXXXXXXXXX" << n % 10000;*/

	//15
	/*int a;
	int b;
	int c;
	int d;

	std::cin >> a >> b >> c >> d;

	std::cout << (a % 2 == 0) * a + (b % 2 == 0) * b + (c % 2 == 0) * c + (d % 2 == 0) * d;*/

	//16
	/*int a;
	int b;
	int c;
	int d;

	std::cin >> a >> b >> c >> d;

	bool isInOrder = (b - a == c - b == d - c);

	std::cout << isInOrder;*/

	//17
	/*int a;
	int b;
	int c;
	int d;

	std::cin >> a >> b >> c >> d;

	bool isInOrder = (b / a == c / b && c / b == d / c);

	std::cout << isInOrder;*/

	//18
	int n;
	std::cin >> n;

	bool isTwoDigit = (10 <= n && n <= 99);

	std::cout << n % 10 + (isTwoDigit * n / 10) * 10;

}