#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;



int resolver(int largo,int ancho) {
	if (largo<10 || ancho<10) {
		return 0;
	}
	else {
		int num;
		if (largo > ancho) {
			 num=largo/ancho;
			 return num + resolver(largo - num * ancho, ancho);
		}
		else {
			 num = ancho / largo;
			 return num + resolver(ancho - num * largo, largo);
		}
	}
}

bool resuelveCaso() {
	int largo,ancho;
	cin >> largo>>ancho;
	if (largo==0 && ancho==0) {
		return false;
	}
	cout << resolver(largo,ancho) << '\n';
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
