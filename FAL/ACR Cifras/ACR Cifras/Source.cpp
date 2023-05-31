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

void resolver(vector<int>v,int k,bool &encontrado,int &res,int num) {
	if (k == v.size()) {
		if (res == num) {
			encontrado = true;
		}
	}
	else {
		if(!encontrado)
			for (int i = 0;i < 4;i++) { // i=0 + i=1 - i=2 * i=3 /
			if (i == 0) {
				res += v[k];
			}
			else if (i==1) {
				res -= v[k];
			}
			else if (i == 2) {
				res *= v[k];
			}
			else {
				
					res /= v[k];
				
			}
			resolver(v, k + 1, encontrado, res, num);
			if (i == 0) {
				res -= v[k];
			}
			else if (i == 1) {
				res += v[k];
			}
			else if (i == 2) {
				res /= v[k];
			}
			else {
				
					res *= v[k];
				
			}
		}
	}
}


bool resuelveCaso() {
	int num,aux,res;
	bool encontrado = false;
	vector<int>v;
	cin >> num;
	if (!cin) {
		return false;
	}
	cin.ignore();
	string linea;
	getline(cin,linea);
	stringstream ss(linea);
	while (ss >> aux) {
		v.push_back(aux);
	}
	res = 0;
	resolver(v,0,encontrado,res,num);
	if (encontrado) {
		cout << "SI";
	}
	else {
		cout << "NO";
	}
	cout << '\n';
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