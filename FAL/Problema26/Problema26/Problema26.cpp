#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*
O(log n)
Especificacion:

n nat && (Ex. i:0<=i<n:(pt j:0<=j<n && i!=j:v[j]==v[j+1] ||v[j]==v[j-1] )v[i]!=v[j]) && v[0...n) de ent
fun resolver(v[0...n) de ent, ini ent,fin ent) dev ent
0<=pos<n && v[pos]!=v[pos+1] && v[pos]!=v[pos-1]


*/

void resolver(vector<vector<int>>& lista, vector<int>anchuras_maquinas, vector<int> anchuras_carreteras,int k, int num_maquinas,int num_carreteras,int &calidad,int &calidad_maxima, vector<bool>&usadas_maq, vector<bool>& usadas_car,vector<int>maximos) {
	if (k == num_maquinas) {
		if (calidad > calidad_maxima) {
			calidad_maxima = calidad;
		}
	}
	else {
		for (int i = 0;i < num_carreteras;i++) {
			calidad += lista[k][i];
			if (anchuras_maquinas[k]<= anchuras_carreteras[i] && !usadas_maq[k] && !usadas_car[i] && calidad+maximos[k+1]>calidad_maxima) {
				usadas_maq[k] = true;
				usadas_car[i] = true;
				resolver(lista, anchuras_maquinas, anchuras_carreteras, k+1, num_maquinas, num_carreteras, calidad, calidad_maxima, usadas_maq, usadas_car,maximos);
				usadas_maq[k] = false;
				usadas_car[i] = false;
			}
			calidad -= lista[k][i];
		}
	}
}

void hacervectormaximos(vector<int>& maximos, int num) {
	for (int i = num - 2;i >= 0;i--) {
		maximos[i] += maximos[i + 1];
	}
}


void resuelveCaso() {
	int num_maquinas, num_carreteras,aux,calidad=0,calidad_maxima=-1;
	cin >> num_maquinas >> num_carreteras;
	vector<int>anchuras_maquinas,anchuras_carreteras,maximos(num_maquinas+1);
	vector<vector<int>>lista;
	vector<bool>usadas_maq, usadas_car;
	for (int i = 0;i < num_maquinas;i++) {
		cin >> aux;
		anchuras_maquinas.push_back(aux);
		usadas_maq.push_back(false);
		maximos[i] = -1;
	}
	for (int i = 0;i < num_carreteras;i++) {
		cin >> aux;
		anchuras_carreteras.push_back(aux);
		usadas_car.push_back(false);
	}
	for (int i = 0;i < num_maquinas;i++) {
		vector<int>col;
		for (int j = 0;j < num_carreteras;j++) {
			cin >> aux;
			col.push_back(aux);
			if (aux > maximos[i]) {
				maximos[i] = aux;
			}
		}
		lista.push_back(col);
		
	}
	hacervectormaximos(maximos, num_maquinas);
	resolver(lista, anchuras_maquinas, anchuras_carreteras, 0, num_maquinas, num_carreteras, calidad, calidad_maxima, usadas_maq, usadas_car,maximos);
	cout << calidad_maxima<<'\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;cin >> num;
	for (int j = 0;j < num;j++) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}