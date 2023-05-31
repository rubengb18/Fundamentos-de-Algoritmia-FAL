#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

int resolver(vector<bool>v, int k) {
	int cont = 0, max = 100000,cont_true=0;
	bool sal = false;
	for (int i = 0;i < v.size();i++) {
		int j = i;
		sal = false;
		while (j < v.size() && !sal) {
			cont++;
			if (v[j] == true) {
				cont_true++;
				if (cont_true == k) {
					if (cont < max) {
						max = cont;
					}
					sal = true;
					cont = 0;
					cont_true = 0;
				}
			}
			else {
				if (cont_true == 0) {
					cont = 0;
					sal = true;
				}
			}
			j++;
			if (j == v.size()) {
				cont = 0;
				cont_true = 0;
			}
		}
	}
	if (max==100000) {
		max = v.size() + 1;
	}
	return max;
}

bool resuelveCaso() {
	int num, k;
	bool n;
	vector<bool> v;
	cin >> num;
	if (num == -1) {
		return false;
	}
	for (int i = 0; i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	cin >> k;
	cout << resolver(v, k) << '\n';
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