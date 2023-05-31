#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*

dev=(max p,q:0<=p<q<N:v[q]-v[p]<lim)
*/


int polidactilia(vector<int>& v, int A) {
	int max = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		while (abs(v[i] - v[v.size() - 1]) >= A) 
			v.pop_back();
		if ((v.size() - i) > max) 
			max = (v.size() - i);
	}
	return max;
}

int resolver(vector<int>v, int num,int lim) {
	int in, fi, cont = 1, max = -1;
	for (int i = 0;i < num-1;i++) {
		for (int j = i+1;j < num;j++) {
			if (v[j] <= v[i]+lim-1) {
				cont++;
			}
			if (cont > max) {
				max = cont;
			}
		}
		cont = 1;
	}
	return max;
}


bool resuelveCaso() {
	int num, aux,lim;
	vector<int>v;
	cin >> num>>lim;
	if (lim == 0 && num == 0) {
		return false;
	}
	for (int j = 0;j < num;j++) {
		cin >> aux;
		v.push_back(aux);
	}

	

	cout << polidactilia(v, lim)<< '\n';
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