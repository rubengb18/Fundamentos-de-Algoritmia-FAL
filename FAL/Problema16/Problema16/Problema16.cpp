#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(log n)
Especificacion:

n nat && (Ex. i:0<=i<n:(pt j:0<=j<n && i!=j:v[j]==v[j+1] ||v[j]==v[j-1] )v[i]!=v[j]) && v[0...n) de ent
fun resolver(v[0...n) de ent, ini ent,fin ent) dev ent
0<=pos<n && v[pos]!=v[pos+1] && v[pos]!=v[pos-1]

*/



int resolver(vector<int>v, int ini, int fin) {
	int mit = (ini + fin) / 2;
	if (fin == ini) {
		return mit;
	}
	else {
		if (v[mit] != v[mit - 1] && v[mit] != v[mit + 1]) {
			return mit;
		}
		if (mit % 2 == 1) {
			if (v[mit] == v[mit - 1]) {
				return resolver(v, mit + 1, fin);
			}
			else {
				return resolver(v, ini, mit-1);
			}
		}
		else {
			if (v[mit] == v[mit - 1]) {
				return resolver(v, ini, mit);
			}
			else {
				return resolver(v, mit, fin);
			}
		}
	}
}

void resuelveCaso() {
	int num, n;
	vector<int>v;
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	cout << resolver(v, 0, v.size() - 1) << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0;i < num;i++) { (resuelveCaso()); }

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}