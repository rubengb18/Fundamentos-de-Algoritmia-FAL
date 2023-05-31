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

bool resolver(vector<int>v,int D) {
	int dif = 0;
	for (int i = 0;i < v.size()-1;i++) {
		if (v[i] < v[i + 1]) {
			dif += v[i + 1] - v[i];
			if (dif > D) {
				return false;
			}
		}
		else {
			dif = 0;
		}
	}
	return true;
}

bool resuelveCaso() {
	int num,D,n;
	cin >> D>>num;
	if (!cin) {
		return false;
	}
	vector<int>v;
	for(int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}

	if (resolver(v, D)) {
		cout << "APTO" << '\n';
	}
	else {
		cout << "NO APTO" << '\n';
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