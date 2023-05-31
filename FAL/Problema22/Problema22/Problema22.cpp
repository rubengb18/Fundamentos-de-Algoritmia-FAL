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

bool esValida(vector<int>& sol, vector<int>lista_consumos, int longitud, int num_colores, int consumo_max, vector<int>& suma_tipo,int k) {
	int i=0,total_consumo = 0;
	if (sol.size() > 2){
		if (sol[sol.size() - 3]==sol[sol.size()-2]&& sol[sol.size() - 2] == sol[sol.size()-1]) {
			return false;
		}
	}
	for (int i = 0;i < num_colores;i++) {
		if (suma_tipo[i] > k - suma_tipo[i] + 2) {
			return false;
		}
	}
	while (i < num_colores) {
		total_consumo += suma_tipo[i] * lista_consumos[i];
		if (total_consumo > consumo_max) {
			return false;
		}
		i++;
	}
	return true;
}

void resolver(vector<int>& sol, vector<int>lista_consumos, int longitud,int num_colores,int consumo_max,int k,int &soluciones,vector<int>&suma_tipo) {
	if (k == longitud) {
		if (esValida(sol,lista_consumos,longitud,num_colores,consumo_max, suma_tipo,k)) {
			//imprimir_sol(sol);
			soluciones++;
		}
	}
	else {
		for (int i = 0;i < num_colores;i++) {
			sol.push_back(i);
			suma_tipo[i]++;
			if (esValida(sol, lista_consumos, longitud, num_colores, consumo_max, suma_tipo,k)) {
				resolver(sol, lista_consumos, longitud, num_colores, consumo_max, k+1, soluciones, suma_tipo);
			}
			sol.pop_back();
			suma_tipo[i]--;
		}
	}
}

bool resuelveCaso() {
	int longitud, num_colores, consumo_max,n,soluciones=0;
	vector<int>lista_consumos,sol,suma_tipo;
	cin >> longitud >> num_colores >> consumo_max;
	if (longitud == 0) {
		return false;
	}
	for (int i = 0;i < num_colores;i++) {
		cin >> n;
		lista_consumos.push_back(n);
		suma_tipo.push_back(0);
	}
	resolver(sol,lista_consumos,longitud, num_colores,consumo_max,0, soluciones, suma_tipo);
	if (soluciones == 0) {
		cout << "SIN SOLUCION" << '\n';
	}
	else {
		cout << soluciones << '\n';
	}

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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