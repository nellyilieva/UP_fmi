#include <iostream>

int main()
{
	//1
	/*int n;
	std::cin >> n;

	switch (n) {
	case 1: std::cout << "Monday";
		break;
	case 2: std::cout << "Tuesday";
		break;
	case 3: std::cout << "Wednesday";
		break;
	case 4: std::cout << "Thursday";
		break;
	case 5: std::cout << "Friday";
		break;
	case 6: std::cout << "Saturday";
		break;
	case 7: std::cout << "Sunday";
		break;
	default: std::cout << "Invalid input";
		break;
	}*/

	//2
	/*int n;
	std::cin >> n;

	if (n < 100) {
		std::cout << "Less than 100";
	}
	else if (100 <= n && n <= 200) {
		std::cout << "Between 100 and 200";
	}
	else {
		std::cout << "Greater than 200";
	}*/

	//3
	/*double speed;
	std::cin >> speed;

	if (speed <= 10) {
		std::cout << "Slow";
	}
	else if (speed <= 50){
		std::cout << "Average";
	}
	else if (speed <= 150) {
		std::cout << "Fast";
	}
	else if (speed <= 1000) {
		std::cout << "Ultra fast";
	}
	else {
		std::cout << "Extremely fast";
	}*/

	//4
	/*char ch;
	std::cin >> ch;

	if (ch == 'c') {
		int a;
		std::cin >> a;
		std::cout << "Area: " << 3.14 * a * a;
	}
	else if (ch == 's') {
		int a;
		std::cin >> a;
		std::cout << "Area: " << a * a;
	}
	else if (ch == 'r') {
		int a;
		int b;
		std::cin >> a >> b;
		std::cout << "Area: " << a * b;
	}
	else if (ch == 't') {
		int a;
		int b;
		std::cin >> a >> b;
		std::cout << "Area: " << a * b / 2;
	}
	else {
		std::cout << "Invalid character";
	}*/

	//5
	int hour;
	int minutes;

	std::cin >> hour >> minutes;

	minutes += 15;

	if (minutes > 59) {
		hour++;
		minutes -= 60;
	}

	if (hour > 23) {
		hour -= 24;
	}

	/*if (hour < 10 && minutes < 10) {
		std::cout << "0" << hour << ":" << "0" << minutes;
	}
	else if (hour < 10) {
		std::cout << "0" << hour << ":" << minutes;
	}
	else if (minutes < 10) {
		std::cout << hour << ":" << "0" << minutes;
	}
	else {
		std::cout << hour << ":" << minutes;
	}*/

	std::cout << (hour < 10 ? "0" : "") << hour << ":" << (minutes < 10 ? "0" : "") << minutes;

	//6
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	bool isSaw = (a >= b && b <= c && c >= d && d <= e)
		|| (a <= b && b >= c && c <= d && d >= e);

	std::cout << (isSaw ? "yes" : "no");

	//7
	double r;
	std::cin >> r;

	double x, y;
	std::cin >> x >> y;

	if ((x == r && y <= r) || (x <= r && y == r)) {
		std::cout << "On the circle";
	}
	else if (x < r && y < r) {
		std::cout << "In the circle";
	}
	else {
		std::cout << "Out of the circle";
	}

}