#include <fstream>
#include<iostream>
#include <vector>
using namespace std;



int resolver(vector<int>v, int num) {
	bool abadia = true;
	int cont = 1;
	for (int i = 0;i < num-1 ;i++) {
		int j = i + 1;
		while (j < num && abadia) {
			if (v[i] <= v[j]) {
				abadia = false;
			}
			j++;

		}
		if (abadia) {
			cont++;
		}
		else {
			abadia = true;
		}
	}
	return cont;
}


bool resuelveCaso() {
	int num, aux;
	vector<int>v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	for (int j = 0;j < num;j++) {
		cin >> aux;
		v.push_back(aux);
	}



	cout << resolver(v, num) << '\n';
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}