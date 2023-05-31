#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
T(n) == k si ini_fil == fin_fil

*/

int diag_prin(vector<vector<int>> v, int ini_fil, int fin_fil, int ini_col, int fin_col) {
	int total = 1;
	int i = ini_fil;
	int j = ini_col;
	while (i < fin_fil + 1) {
		total *= v[i][j];
		i++;
		j++;
	}
	return total;
}
int diag_sec(vector<vector<int>> v, int ini_fil, int fin_fil, int ini_col, int fin_col) {
	int total = 1;
	int i = ini_fil;
	int j = fin_col;
	while (i < fin_fil + 1) {
		total *= v[i][j];
		i++;
		j--;
	}
	return total;
}

bool resolver(vector<vector<int>> v, int& prod,int ini_fil,int fin_fil,int ini_col,int fin_col) {
	if (ini_fil == fin_fil) {
		prod = v[ini_fil][ini_col];
		return true;
	}
	else {
		int mit_fil = (fin_fil + ini_fil) / 2;
		int mit_col = (fin_col + ini_col) / 2;
		bool b = resolver(v, prod, ini_fil, mit_fil, ini_col, mit_col) && resolver(v, prod, ini_fil, mit_fil, mit_col + 1, fin_col) && resolver(v, prod, mit_fil + 1, fin_fil, ini_col, mit_col) && resolver(v, prod, mit_fil + 1, fin_fil, mit_col + 1, fin_col);
		bool quasi = diag_prin(v, ini_fil, fin_fil, ini_col, fin_col) == diag_sec(v, ini_fil, fin_fil, ini_col, fin_col);
		prod = diag_prin(v, ini_fil, fin_fil, ini_col, fin_col);
		return b && quasi;
	}
	
}

void resuelveCaso() {
	int num, n,prod;
	vector<vector<int>> v;
	cin >> num;

	for (int i = 0; i < num;i++) {
		vector<int>aux;
		for (int j = 0;j < num;j++) {
			cin >> n;
			aux.push_back(n);
		}
		v.push_back(aux);
	}
	if (resolver(v, prod, 0, num - 1, 0, num - 1)) {
		cout <<"SI "<< prod << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ejer2.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0; i < num;i++) {
		resuelveCaso();
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}