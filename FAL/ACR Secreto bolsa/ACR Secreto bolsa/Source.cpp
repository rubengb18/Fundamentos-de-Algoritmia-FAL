#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*

dev=(max p,q:0<=p<q<N:v[q]-v[p]<lim)
*/

int resolver(vector<int>v, int num, int lim) {
	int cont = 0,res=0;

	for (int i = 0;i < num;i++) {
		int j = i;
		bool pasado = false;
		while (j < num && !pasado) {
			cont += v[j];
			if (cont==lim) {
				res++;
				pasado = true;
			}
			j++;
		}
		cont = 0;
	}
	return res;
}


void resuelveCaso() {
	int num;
	string c;

	vector<int>v;
	cin >> num;
	cin >> c;
	for (int i = 0;i < c.size();i++) {
		v.push_back(c[i] - 48);
	}
	cout << resolver(v,v.size(), num) << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int j = 0;j < num;j++) {
		resuelveCaso();
	}
	


	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}