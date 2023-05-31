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

void imprimir_sol(vector<int>& sol) {
	for (int i = 0;i < sol.size();i++) {
		cout << sol[i] << " ";
	}
	cout << '\n';
}

bool esValida(vector<int>& prod_en_mercado, int& coste, int& coste_min,int i) {
	if (prod_en_mercado[i] > 3||coste>coste_min) {
		return false;
	}
	return true;
}

void resolver(vector<vector<int>>lista,int k,int &soluciones,int &coste,int &coste_min,int num_supermercados, int num_productos, vector<int>&prod_en_mercado,vector<int>minimos) {
	if (k == num_productos) {
		if (coste < coste_min) {
			coste_min = coste;
		}
		soluciones++;
	}
	else {
		for (int i = 0;i< num_supermercados;i++) {
			coste += lista[i][k];
			prod_en_mercado[i]++;
			if (prod_en_mercado[i]<4 && coste+minimos[k+1] < coste_min) {
				resolver(lista, k+1, soluciones, coste, coste_min, num_supermercados, num_productos, prod_en_mercado,minimos);
			}
			coste -= lista[i][k];
			prod_en_mercado[i]--;
		}
	}
}


void creaMinimosParciales(vector<int>& minimos, int numprod) {
	for (int i = numprod - 2; i >= 0; i--) {
		minimos[i] += minimos[i + 1];
	}
}

void resuelveCaso() {
	vector<vector<int>>lista;
	
	
	int num_productos,n, num_supermercados,coste=0, soluciones=0, coste_min=1000000;
	
	cin >> num_supermercados >> num_productos;
	vector<int>prod_en_mercado, minimos(num_productos + 1);
	for (int j = 0;j < num_productos;j++) {
		minimos[j] = 10000000;
	}
	for (int i = 0;i < num_supermercados;i++) {
		prod_en_mercado.push_back(0);
		vector<int>super;
		for (int j = 0;j < num_productos;j++) {
			cin >> n;
			super.push_back(n);
			if (n < minimos[j]) {
				minimos[j] = n;
			}
		}
		lista.push_back(super);
	}
	creaMinimosParciales(minimos, num_productos);
	resolver(lista, 0,soluciones,coste,coste_min, num_supermercados, num_productos, prod_en_mercado,minimos);
		if (soluciones == 0) {
			cout <<"Sin solucion factible" << '\n';
		}
		else {
			cout << coste_min << '\n';
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

	for (int i = 0;i < num;i++ ){
		(resuelveCaso());
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}