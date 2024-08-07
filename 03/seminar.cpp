#include <iostream>

int main()
{
	//1
	/*int n;
	std::cin >> n;

	int sum = 0;
	
	while (n != 0) {
		sum += n;
		std::cin >> n;
	}

	std::cout << sum;*/

	//2
	/*int n;
	std::cin >> n;

	int newNum = 0;

	while (n != 0) {
		int lastDigit = n % 10;
		newNum = newNum * 10 + lastDigit;
		n /= 10;
	}

	std::cout << newNum + 1;*/

	//3
	/*int n;
	std::cin >> n;

	int counter = 0;
	int mostRecent = 0;

	for (int i = 0; i <= 9; i++) {
		int currentCounter = 0;
		int copy = n;

		while (copy != 0) {
			int digit = copy % 10;
			copy /= 10;
			if (digit == i) {
				currentCounter++;
			}
		}

		if (currentCounter > counter) {
			counter = currentCounter;
			mostRecent = i;
		}
	}

	std::cout << mostRecent;*/

	//4 GCD - Euclidean Algorithm
	//int a, b;
	//std::cin >> a >> b;   //a,b

	//while (b != 0) {
	//	int temp = a % b;    //(b, a % b) //(a % b, b % (a % b)) //
	//	a = b;
	//	b = temp;
	//}

	//std::cout << a;

	//5 LCM
	//int a, b;
	//std::cin >> a >> b;

	//int tempA = a, tempB = b;

	//while (tempB != 0) {
	//	int temp = tempA % tempB;    //GCD
	//	tempA = tempB;
	//	tempB = temp;
	//}

	//int gcd = tempA;

	//int lcm = a * b / gcd;
	//std::cout << lcm;

	//6
	//int n;
	//std::cin >> n;

	//if (n == 2) {
	//	std::cout << "Prime";
	//	return 0; //za da izlezem ot programata
	//}

	//if (n == 1 || n % 2 == 0) {
	//	std::cout << "Not prime";
	//	return 0;
	//}

	//for (int i = 3; i < sqrt(n); i+=2) {
	//	if (n % i == 0) {
	//		std::cout << "Not prime";
	//		return 0;
	//	}
	//}

	//std::cout << "Prime";

	//7
	int n;
	std::cin >> n;

	for (int i = n; i >= 1; i--) {
		bool isPrime = true;

		if (i == 2) {
			while (n % i == 0) {
				std::cout << i << " ";
				n /= i;
			}

			continue;
		}

		if (i == 1 || i % 2 == 0) {
			isPrime = false;
			continue;
		}

		double sqrtN = sqrt(i);
		for (int j = 3; j <= sqrtN; j += 2) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			while (n % i == 0) {
				std::cout << i << " ";
				n /= i;
			}
		}
	}
}