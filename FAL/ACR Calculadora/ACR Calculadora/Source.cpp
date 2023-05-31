#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;



int resolver(char &simbolo, char &num1, char &num2) {
	cin >> simbolo;
	if (simbolo == '*' || simbolo == '+' || simbolo == '-' || simbolo == '/') {
		cin >> num1;
	}
	else {
		num1 = simbolo;
	}
	if (num1 == '*' || num1 == '+' || num1 == '-' || num1 == '/') {
		if (num1 == '+')
			return num1 + num2;
		else if (num1 == '-')
			return num1 - num2;
		else if (num1 == '*')
			return num1 * num2;
		else {
			return resolver(num1, num1, num2) / num2;
		}

	}
	else {
		cin >> num2;
		if (num2 == '*' || num2 == '+' || num2 == '-' || num2 == '/') {
			char num = resolver(num2, num1, num2);
			return resolver(num2, num1, num);
		}
		else {
			num1 = num1 - 48;
			num2 = num2 - 48;
			if (simbolo == '+')
				return num1 + num2;
			else if (simbolo == '-')
				return num1 - num2;
			else if (simbolo == '*')
				return num1 * num2;
			else {
				return num1 / num2;
			}
		}
	}
}

void resuelveCaso() {
	char simbolo;
	char num1, num2;
	cout << resolver(simbolo,num1,num2) << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0;i < num;i++) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
