#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

bool resolver(vector<int>v, int &suma,int ini,int fin) {
	int mit = (fin + ini) / 2;
	bool b;
	if (ini == fin) {
		if (v[mit] % 2 == 0) {
			suma=1;
		}
		else {
			suma = 0;
		}
		return true;
	}
	else {
		int suma_iz, suma_dr;
		b= resolver(v, suma_iz, ini, mit) && resolver(v, suma_dr, mit + 1, fin) && abs(suma_iz - suma_dr) < 3;
		if(b)
			suma = suma_iz + suma_dr;
	}
	return b;
}

bool resuelveCaso() {
	int num, n,suma=0;
	vector<int> v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	for (int i = 0; i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	if (resolver(v, suma, 0, num - 1)) {
		cout << "SI" << '\n';

	}
	else {
		cout << "NO" << '\n';

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