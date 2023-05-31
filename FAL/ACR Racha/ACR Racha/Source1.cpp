#include <fstream>
#include<iostream>
#include <vector>
using namespace std;



void resolver(vector<int>v, int &ini,int &end) {
	int n, num= v.size(), max, maxTemp, tempL;
	ini = 0;
	end = 0;
	tempL = 0;
	max = maxTemp = 0;
	for (int i = 0;i <num ;i++) {
		maxTemp += num;
		if (num > max) {
			max = num;
			ini = end = (i + 1);
		}
		if (maxTemp > max || (maxTemp == max && (end - ini > (i - tempL)))) {
			ini = tempL + 1;
			end = i + 1;
			max = maxTemp;
		}
		if (maxTemp <= 0) {
			maxTemp = 0;
			tempL = (i + 1);
		}
	}
}


bool resuelveCaso() {
	int num, aux,ini,fin;
	vector<int>v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	for (int j = 0;j < num;j++) {
		cin >> aux;
		v.push_back(aux);
	}
	resolver(v, ini, fin);



	cout << ini<<" "<<fin << '\n';
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