#include <fstream>
#include<iostream>
#include <vector>
using namespace std;




bool escalera_asc(vector<int>v, int ini, int fin, int& ancho,int& asc) {
	ancho = 0;
	bool b = true;
	int cont = 1, cont_asc = 1, max_asc = -1, max = -1;
	for (int i = ini;i < fin;i++) {
		if (v[i] > v[i + 1]) {
			b = false;
			if (cont > max) {
				max = cont;
			}
			if (cont_asc > max_asc) {
				max_asc = cont_asc;
			}
			cont = 1, cont_asc = 1;
		}
		else if (v[i] == v[i + 1]) {
			cont++;
			cont_asc++;
		}
		else {
			cont_asc++;
			if (cont > max) {
				max = cont;
			}
		}
	}
	if (cont > max) {
		max = cont;
	}
	if (cont_asc > max_asc) {
		max_asc = cont_asc;
	}
	ancho=max;
	asc = max_asc;
	return b;
}
bool escalera_des(vector<int>v, int ini, int fin, int& ancho, int& asc) {
	ancho = 0;
	bool b = true;
	int cont = 1, cont_asc = 1, max_asc = -1, max = -1;
	for (int i = ini;i < fin;i++) {
		if (v[i] < v[i + 1]) {
			b = false;
			if (cont > max) {
				max = cont;
			}
			if (cont_asc > max_asc) {
				max_asc = cont_asc;
			}
			cont = 1, cont_asc = 1;
		}
		else if (v[i] == v[i + 1]) {
			cont++;
			cont_asc++;
		}
		else {
			cont_asc++;
			if (cont > max) {
				max = cont;
			}
		}
	}
	if (cont > max) {
		max = cont;
	}
	if (cont_asc > max_asc) {
		max_asc = cont_asc;
	}
	ancho = max;
	asc = max_asc;
	return b;
}

void resolver(vector<int>v,int num,int &ancho,bool &escalera,int &asc,int &des) {
	int mit = (num-1) / 2;
	int ancho_iz, ancho_dr;
	bool b1 = escalera_asc(v, 0, mit, ancho_iz, asc),b2= escalera_des(v, mit + 1, num - 1, ancho_dr, des);
	
	if ((b1 && b2)) {
		escalera= true;
		int cont = 1;
		for (int i = 0;i < num;i++) {
			if (i!=mit&&v[i] == v[mit]) {
				cont++;
			}
		}
		if (ancho_dr >= cont && ancho_dr >= ancho_iz) { ancho = ancho_dr; }
		if (ancho_iz >= cont && ancho_iz >= ancho_dr) { ancho = ancho_iz; }
		if (cont >= ancho_iz && cont >= ancho_dr) { ancho = cont; }
	}
	else {
		escalera = false;
	}
}

bool resuelveCaso() {
	int num, n, ancho = 0,asc,des;
	bool escalera = false;
	vector<int>v;
	cin >> num;
	if (num == -1) {
		return false;
	}
	for (int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	resolver(v, num,ancho,escalera,asc,des);
	if (escalera) {
		cout << "SI " << ancho << '\n';
	}
	else {
		cout << "NO " << asc << " " << des << '\n';
	}
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ejer1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}