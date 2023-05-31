#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;



int resolver(int num) {
	if (num==1) {
		return 4;
	}
	else {
		return num * 4 + 4 * resolver(num / 2);
	}
}

bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin) {
		return false;
	}
	cout<<resolver(num)<<'\n';
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