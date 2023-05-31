#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*

dev=(max p,q:0<=p<q<N:v[q]-v[p]<lim)
*/

int resolver(vector<int>v, int num) {
	int cont = 0, max = -2;
	for (int i = 0;i < num*2;i++) {
		for (int j = i;j < num*2;j++) {
			cont += v[j%num];
			if (cont > max) {
				max = cont;
			}
		}
		cont = 0;
	}
	return max;
}


bool resuelveCaso() {
	int num,aux;

	vector<int>v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	for (int i = 0;i < num;i++) {
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

	while(resuelveCaso()) {
		
	}



	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}