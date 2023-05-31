#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

int contarCifras(int num) {
	if (num < 10) {
		return 1;
	}
	else if (num / 10 > 0) {
		return 1 + contarCifras(num / 10);
	}
}

bool resolver(int num) {
	if (num < 10) {
		return true;
	}
	int cont = 0,cifras=contarCifras(num),aux=num;
	for (int i = 0;i < cifras;i++) {
		cont += aux % 10;
		aux /= 10;
	}
	return cont % cifras == 0 && resolver(num / 10);
}

bool resuelveCaso() {

	int num;

	cin >> num;
	if (num == 0) {
		return false;
	}
	if (resolver(num)) {
		cout << "SI" << '\n';
	}
	else {
		cout <<"NO"  << '\n';
	}
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}