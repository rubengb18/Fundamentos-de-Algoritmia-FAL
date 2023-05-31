#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
O(log n) 
*/

int resolver(vector<int>v, int x,int ini,int fin) {
	int mit = (fin + ini) / 2;
	if (v[mit] == x||fin==ini) {
		return v[mit];
	}
	else {
		if (x > v[mit] && x < v[mit + 1]) {
			if (abs(v[mit] - x) > abs(v[mit + 1] - x)) {
				return v[mit + 1];
			}
			else if(abs(v[mit] - x) < abs(v[mit + 1] - x)){
				return v[mit];
			}
			else {
				return v[mit];
			}
		}
		else if (v[mit] > x) {
			return resolver(v, x, ini, mit);
		}
		else {
			return resolver(v, x, mit+1, fin);
		}
	}
}


void resuelveCaso() {
	int num, aux,x;
	cin >> x>>num;
	vector<int>v;
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v.push_back(aux);
	}
	cout << resolver(v,x,0,num-1) << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;cin >> num;
	for (int i = 0;i < num;i++) {
		(resuelveCaso());

	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}