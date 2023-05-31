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

bool es_sumadivisible(int num) {
	if (num < 10) {
		return true;
	}
	int cont = 0, cifras = contarCifras(num), aux = num;
	for (int i = 0;i < cifras;i++) {
		cont += aux % 10;
		aux /= 10;
	}
	return cont % cifras == 0 && es_sumadivisible(num / 10);
}

void resolver(long long int num,int digitos, int &total,int k,int acum) {
	if (k == digitos) {
			if (es_sumadivisible(num)) {
				total++;
			}
	}
	else{
		for (int i = 0;i < 10;i++) {
			acum += i;
			if (acum%(k+1)==0) {
				resolver(num * 10 + i, digitos, total, k + 1,acum);
			}
			acum -= i;
		}
	}
}

bool resuelveCaso() {

	int digitos, total = 0,k=1;
	long long int num;
	
	cin >> num>>digitos;
	long long int acum = num;
	if (num == 0) {
		return false;
	}
	resolver(num, digitos, total, k,acum);
	cout << total << '\n';
	
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