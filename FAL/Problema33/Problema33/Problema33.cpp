#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
O(log n)
*/

typedef struct {
	int grupo;
	bool usada;
}tUso;

bool sepuede(vector<vector<int>>& lista_vetos, int num, int k,int i, vector<tUso>& hora_usada) {
		if (hora_usada[i].usada == true) {
			return false;
		}
		if (i > 0) {
			if (lista_vetos[k][i-1] == 0) {
				return false;
			}
		}
		
	
	return true;
}

void resolver(vector<vector<int>>& lista_donaciones, vector<vector<int>>& lista_vetos, int k, int& don, int& don_max, int& sol, int num,vector<tUso>&hora_usada) {
	if (k == num) {
		if (don > don_max) {
			don_max = don;
		}
		sol++;
	}
	else {
		for (int i = 0;i < num;i++) {
			don += lista_donaciones[k][i];
			if (sepuede(lista_vetos,num,k,i,hora_usada)) {
				hora_usada[i].usada = true;
				hora_usada[i].grupo = k;
				resolver(lista_donaciones, lista_vetos, k+1, don, don_max, sol, num, hora_usada);
				hora_usada[i].usada = false;
				hora_usada[i].grupo = -1;
			}
			don -= lista_donaciones[k][i];
		}
	}
}


void resuelveCaso() {
	int num, aux, k=0,don=0,don_max=-1,sol=0;
	cin >> num;
	vector<vector<int>>lista_donaciones,lista_vetos;
	vector<tUso>hora_usada;
	for (int i = 0;i < num;i++) {
		vector<int>col;
		for (int j = 0;j < num;j++) {
			cin >> aux;
			col.push_back(aux);
		}
		tUso uso;
		uso.usada = false;
		uso.grupo = -1;
		hora_usada.push_back(uso);
		lista_donaciones.push_back(col);
	}
	for (int i = 0;i < num;i++) {
		vector<int>col;
		for (int j = 0;j < num;j++) {
			cin >> aux;
			col.push_back(aux);
		}
		lista_vetos.push_back(col);
	}
	resolver(lista_donaciones, lista_vetos, k, don, don_max, sol, num, hora_usada);
	if (sol == 0) {
		cout << "NEGOCIA CON LOS ARTISTAS" << '\n';
	}
	else {
		cout << don_max << '\n';
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