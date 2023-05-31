#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(n)
Especificacion:


*/



bool resolver(int &suma) {
	bool b;
	int pi, di, pd, dd,suma_iz,suma_dr;
	cin >> pi >> di >> pd >> dd;
	if (pi != 0 && pd!=0) {
		suma = pi + pd;
		return pi * di == pd * dd;
	}
	else if(pi==0 && pd==0){
		b= resolver(suma_iz) && resolver(suma_dr)&& suma_iz * di == suma_dr * dd;
		suma = suma_iz + suma_dr;
	}
	else if(pi==0){
		b = resolver(suma_iz) && suma_iz * di == pd * dd;
		suma = suma_iz + pd;
	}
	else {
		b = resolver(suma_dr) && pi * di == suma_dr * dd;
		suma = suma_dr + pi;
		
	}
	return b;

}

void resuelveCaso() {
	int suma;
	if (resolver(suma)) {
		cout << "SI" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0;i < num;i++) { resuelveCaso(); }

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}