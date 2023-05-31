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
		if (sol[i] == 0) {
			std::cout << "azul ";
		}
		else if (sol[i] == 1) {
			std::cout << "rojo ";
		}
		else if (sol[i] == 2) {
			std::cout << "verde ";
		}
	}
	cout << '\n';
}

bool esValida(vector<int>& sol, vector<int>& colocadas,int a,int r,int v) {
	int i = 0;
	bool valido = true;
	if (sol[0] != 1) {
		return false;
	}
	if (colocadas[2] > colocadas[0]) {
		return false;
	}
	while (i < sol.size() - 1) {
		if (sol[i] == 2 && sol[i] == sol[i + 1]) {
			return false;
		}
		i++;
	}
	if (colocadas[0] > a || colocadas[1] > r || colocadas[2] > v) {
		return false;
	}
	return true;
}

void resolver(int alt, int a, int r, int v, vector<int>& colocadas, vector<int>& sol, int k, int &soluciones) {
	if (k == alt) {
		if (colocadas[1] > colocadas[0] + colocadas[2] && esValida(sol, colocadas, a, r, v)) {
			imprimir_sol(sol);
			soluciones++;
		}

	}
	else {
		for (int i = 0;i < 3;i++) {
			sol.push_back(i);
			colocadas[i]++;
			if (esValida(sol, colocadas,a,r,v)) {
				resolver(alt, a, r, v, colocadas, sol, k + 1, soluciones);
			}
			sol.pop_back();
			colocadas[i]--;
			
		}
	}

}

bool resuelveCaso() {
	int alt, a, v, r, soluciones=0;
	cin >> alt >> a >> r >> v;
	if (alt == 0 && a == 0 && v == 0 && r == 0) {
		return false;
	}
	vector<int>colocadas;
	vector<int> sol;
	for (int i = 0;i < 3;i++) {
		colocadas.push_back(0);
	}
	resolver(alt, a, r,v, colocadas, sol, 0, soluciones);
	if (soluciones == 0) {
		cout << "SIN SOLUCION" << '\n';
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

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}