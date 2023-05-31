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
int contarCifras(long long n) {
	int cont = 0;
	while (n / 10 != 0) {
		cont++;
		n /= 10;
	}

	return cont + 1;
}

void escribePolidivisibles(long long num, int lim) {
	std::cout << num << std::endl;
	for (int i = 0; i < 10; ++i) {
		esPolidivisible(contarCifras(num) + 1, num * 10 + i, lim);
	}
}

void esPolidivisible(int numDigitos, long long int num, int lim) {
	if (numDigitos <= lim && num % numDigitos == 0) {
		escribePolidivisibles(num, lim);
	}
}



bool resuelveCaso() {
	long long raiz, int maxDigitos;
	cin >> raiz>>maxDigitos;
	if (!cin) {
		return false;
	}
	escribePolidivisibles(raiz,maxDigitos);
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