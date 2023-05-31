
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

int resolver(vector<int>v, int num) {
	int max_valor = v[0], cont = 0, max_int = -1;
	for (int i = 1;i < num;i++) {
		if (v[i] <= max_valor) {
			cont++;
		}
		else {
			max_valor = v[i];
			if (cont > max_int) {
				max_int = cont;

			}
			cont = 0;
		}
	}
	if (cont > max_int) {
		max_int = cont;
	}
	return max_int;
}



void resuelveCaso() {
	int num, aux;
	cin >> num;
	vector<int>v;
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v.push_back(aux);
	}


	cout << resolver(v, num) << '\n';
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