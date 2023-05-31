#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(n)
Especificacion:


*/



void resolver(vector<char>v,char ini,char fin,char &res,bool &encontrado) {
	int mit = (ini + fin) / 2;
	if (ini != fin && !encontrado) {
		if (v[mit] + 1 != v[mit + 1]) {
			res= v[mit] + 1;
			encontrado = true;
		}
		else {
			resolver(v, ini, mit,res, encontrado);
			resolver(v, mit+1, fin, res, encontrado);
		}
	}
}

void resuelveCaso() {
	vector<char>v;
	char prim, ult, c,res;
	bool encontrado = false;
	cin >> prim >> ult;
	for (int i = 0;i < ult - prim;i++){
		cin >> c;
		v.push_back(c);
	}
	resolver(v, 0, ult - prim - 1, res, encontrado);
	if (!encontrado) {
		if (v[0] == prim) {
			cout << ult << '\n';
		}
		else {
			cout << prim << '\n';
		}
	}
	else {
		cout << res << '\n';
	}
	
	
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0;i < num;i++) { resuelveCaso(); }

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}