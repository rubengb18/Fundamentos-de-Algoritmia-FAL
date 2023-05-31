#include <fstream>
#include<iostream>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;



bool esValidos(vector<int>& usados, int num_choc, int num_vain) {
	if (usados[0] > num_choc || usados[1] > num_vain) {
		return false;
	}
	return true;
}

void resolver(vector<int>v, int k, int i, int lim,int& cont,int &res) {
	if (k == 12) {
		if (cont <=lim) {
			res++;
		}
	}
	else {
		if (i < v.size()) {
			for (int j = i;j < v.size();j++) {
				cont += v[j];
				if (cont <= lim) {
					resolver(v, k + 1,j, lim, cont, res);
				}
				cont -= v[j];
			}
		}
	}
}


bool resuelveCaso() {
	int num, lim,aux,cont=0,i=0,res=0;
	vector<int>v;
	cin >>lim>> num;
	if (lim==0 & num==0) {
		return false;
	}
	for (int j = 0;j < num;j++) {
		cin >> aux;
		v.push_back(aux);
	}

	resolver(v, 0, i,lim,cont,res);
	
	cout << res<<'\n';
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
	system("PAUSE");
#endif
	return 0;
}