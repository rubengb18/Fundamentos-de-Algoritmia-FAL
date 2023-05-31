#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(n)
Especificacion:


*/



int resolver(vector<int>v,int ini,int fin) {
	int mit = (ini + fin) / 2;
	if (fin == ini) {
		return v[mit];
	}
	else if (fin-ini!=1) {
		if (v[mit]<v[mit - 1] && v[mit]<v[mit + 1]) {
			return v[mit];
		}
		else if (v[mit] > v[mit + 1]) {
			return resolver(v, mit+1, fin);
		}
		else {
			return resolver(v, ini, mit);
		}
	}
	else{
		if (v[mit] > v[mit + 1]) {
			return v[mit+1];
		}
		else {
			return v[mit];
		}
	}
}

bool resuelveCaso() {
	int num,n;
	vector<int>v;
	cin >> num;
	if (!cin) {
		return false;
	}
	for (int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	cout << resolver(v,0,v.size()-1) << '\n';
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso()) {  }

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}