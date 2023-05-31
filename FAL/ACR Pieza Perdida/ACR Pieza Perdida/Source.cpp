#include <fstream>
#include<iostream>
#include <vector>
using namespace std;



int resolver(vector<int>v, int num,vector<bool>&res) {
	for (int j = 0;j < num-1;j++) {
		res[v[j]-1] = true;
	}
	for (int j = 0;j < num;j++) {
		if (res[j] == false) {
			return j + 1;
		}
	}
}


bool resuelveCaso() {
	int num,aux;
	vector<int>v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	vector<bool>res;
	res.push_back(false);
	for (int j = 0;j < num-1;j++) {
		cin >> aux;
		v.push_back(aux);
		res.push_back(false);
	}

	

	cout << resolver(v, num, res) << '\n';
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