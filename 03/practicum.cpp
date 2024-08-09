#include <iostream>

int main()
{
	//1
	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << j;
		}
		std::cout << std::endl;
	}*/

	//2
	/*int n;
	std::cin >> n;

	for (int i = 1; i < n; i++) {
		std::cout << "x = " << i << " y = " << n - i << std::endl;
	}*/

	//3
	/*int n;
	std::cin >> n;

	int sqrNum = n * n;
	int newNum = 0;

	while (sqrNum != 0) {
		int lastDigit = sqrNum % 10;

		if (lastDigit == 0) {
			sqrNum /= 10;
			continue;
		}

		newNum = newNum * 10 + lastDigit;
		sqrNum /= 10;
	}

	std::cout << newNum;*/

	//4
	/*int n;
	std::cin >> n;

	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	std::cout << result;*/

	//5
	/*int m, n;
	std::cin >> m >> n;

	int counter = 1;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << counter << " ";
			counter++;
		}
		std::cout << std::endl;
	}*/

	//6
	/*int n;
	std::cin >> n;

	int num;

	do {
		std::cin >> num;
		if (n < num) {
			std::cout << "Bigger";
		}
		else if (n > num) {
			std::cout << "Smaller";
		}

	} while (n != num);*/

	//7
	/*int n;
	std::cin >> n;

	int sumOfNumbers = (1 + n) * n / 2;
	int currSum = 0;

	for (int i = 1; i < n; i++) {
		int num;
		std::cin >> num;
		currSum += num;
	}

	std::cout << sumOfNumbers - currSum;*/

	//8
	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				if (i * i + j * j == k * k) {
					std::cout << i << " " << j << " " << k << std::endl;
				}
			}
		}
	}*/

	//10
	/*int m, n;
	std::cin >> m >> n;

	int sum = 0;

	for (int i = m; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			std::cout << i << std::endl;
		}
		sum = 0;
	}*/

	//11
	/*int n;
	std::cin >> n;

	int firstNum = 1;
	int secondNum = 1;

	std::cout << firstNum << " " << secondNum << " ";

	int currNum = 0;

	while (true) {
		currNum = firstNum + secondNum;
		if (currNum < n) {
			std::cout << currNum << " ";
			firstNum = secondNum;
			secondNum = currNum;
		}
		else {
			break;
		}
	}*/

	//12
	/*int n;
	std::cin >> n;

	int copy = n;
	int count = 0;

	while (copy > 0) {
		count++;
		copy /= 10;
	}

	int left_part = 0, right_part = 0, middle = 0;
	int left_divisor = std::pow(10, (count + 1) / 2);
	int right_divisor = std::pow(10, count / 2);

	left_part = n / left_divisor;
	right_part = n % right_divisor;

	if (count % 2 == 0) {
		middle = left_part * right_divisor + right_part;
	}
	else {
		middle = left_part * right_divisor + right_part;
	}

	std::cout << middle << ", " << middle + 1;*/

	//13
	/*int a, b;
	std::cin >> a >> b;

	int begin = a < b ? a : b;
	int end = a > b ? a : b;

	for (int i = begin; i <= end; i++) {
		bool isPrime = true;

		if (i == 2) {
			std::cout << i << " ";
			continue;
		}

		if (i == 1 || i % 2 == 0) {
			isPrime = false;
			continue;
		}

		for (int j = 3; j < sqrt(i); j+=2) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			std::cout << i << " ";
		}
	}*/

	//14
	int n;
	std::cin >> n;

	if (n == 1) {
		std::cout << "true";
		return 0;
	}

	while (n != 0) {
		if (n % 2 != 0) {
			std::cout << "false";
			return 0;
		}
		n /= 2;
	}
	std::cout << "true";

}