#include <fstream>
#include<iostream>
#include <vector>
using namespace std;






int resolver(vector<int>v, int ancho,int ini,int fin) {
	int mit = (fin + ini) / 2;
	if (ini == fin) {
		return v[mit];
	}
	else if (fin - ini == 1) {
		if (v[mit] >= v[mit + 1]) {
			return v[mit];
		}
		else {
			return v[mit + 1];
		}
	}
	else {
		if (v[mit] > v[mit + 1] && v[mit] > v[mit - 1]) {
			return v[mit];
		}
		else if (v[mit] < v[mit + 1]) {
			return resolver(v, ancho, mit + 1, fin);
		}
		else {
			return resolver(v, ancho, ini, mit);
		}
	}
}

bool resuelveCaso() {
	int num, ancho,n;
	vector<int>v;
	cin >> num>>ancho;
	if (num == -1) {
		return false;
	}
	for (int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	cout << resolver(v, ancho,0,num-1)<< '\n';
	
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ejer2.txt");
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