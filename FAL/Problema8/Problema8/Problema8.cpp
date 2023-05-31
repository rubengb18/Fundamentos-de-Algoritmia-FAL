#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(n)
precondicion: 0<=D<=1000000 && 1<=n<=2000000
fun: resolver(v[0...num),D ent):dev bool
poscondicion: b=(pt p,q:0<=p<q<num:v[q]-v[p]<=D)

Invariante: 0<=i<N && 0<=dif<=v[num-1]-v[0]
F cota=N-i-1
Avanza=i++

*/


int tam_orden(int orden) {
	if (orden == 1) {
		return 3;
	}
	else {
		return 2 * tam_orden(orden - 1) + orden + 2;
	}
}

char resolver(int orden,int pos) {
	char c;
	if (orden == 1) {
		if (pos == 1) {
			c = 'B';
		}
		else if (pos == 3) {
			c = 'H';
		}
		else {
			c = 'U';
		}
	}
	else {
		int t = tam_orden(orden - 1);
		int izq = t;
		int der = t + orden + 3;
		if (pos > izq && pos < der) {
			if (pos == izq + 1) {
				c = 'B';
			}
			else if (pos == der -1) {
				c = 'H';
			}
			else {
				c = 'U';
			}
		}
		else if (pos <= izq) {
			c=resolver(orden - 1, pos);
		}
		else {
			pos = pos - der+1;
			c=resolver(orden - 1, pos);
		}
	}
	return c;
}


bool resuelveCaso() {
	int orden,pos;
	cin >> orden >> pos;
	if (!cin) {
		return false;
	}
	cout << resolver(orden, pos)<<'\n';
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