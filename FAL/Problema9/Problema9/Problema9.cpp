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


int resolver(int num) {
	if (num == 0) {
		return 1;
	}
}


bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin) {
		return false;
	}
	cout << resolver(num) << '\n';
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