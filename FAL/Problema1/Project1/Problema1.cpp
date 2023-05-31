#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

string resolver(vector<int>v) {
	for (int i = 0;i < v.size()-1;i++) {
		if (v[i] >= v[i + 1]) {
			return "DESCONOCIDOS";
		}
	}
	return "DALTON";
}

bool resuelveCaso() {
	int num, n;
	vector<int> v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	for (int i = 0; i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	cout << resolver(v) << '\n';
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