#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
0<n
fun(v[0...n) de ent,num ent) dev max_intent
max=(max i,j:0<i<=j<=n && v[i]<=max_valor:j-i)
con max_valor=max j:0<=j<i:v[i]

F.cota: num-i-1
Invariante: 0<n && 0<i<=num
avanza:i++

O(n) con n el tamaño del vector, ya que realizamos operaciones constantes dentor de un for que es una operacion de coste lineal
*/



bool resolver(vector<vector<int>>lista, int num, int num_lab, int num_pas,int fil_ini,int fil_fin,int col_ini,int col_fin,int &suma) {
	int suma_sub;
	if (fil_ini == fil_fin) {
		suma += lista[fil_ini][col_ini];
		return true;
	}
	else if (num_lab<pow(2, num) / 4 - 1 || num_lab >(3 * pow(2, num)) / 4) {
		return false;
	}
	else {
		suma_sub += num_lab;
		return  resolver(lista,pow(2,sqrt(num)-1),num_lab
	}
}



void resuelveCaso() {
	int num, aux,num_lab=0,num_pas=0;
	cin >> num;
	vector<vector<int>>lista;
	for (int i = 0;i < num;i++) {
		vector<int>col;
		for (int i = 0;i < num;i++) {
			cin >> aux;
			if (aux == 1) {
				num_lab++;
			}
			else {
				num_pas++;
			}
			
			
			col.push_back(aux);
		}
		lista.push_back(col);
	}


	cout << resolver(lista, num,num_lab,num_pas,0,num-1,0,num-1) << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;cin >> num;
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