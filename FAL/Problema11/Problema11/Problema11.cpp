#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(n)
Especificacion:
mit:=(ini+fin)/2

fun maximo(v[0...n) ent,ini ent,fin ent) dev ent:max
max=(max i:ini<=i<fin:v[i])

fun minimo(v[0...n) ent,ini ent,fin ent) dev ent:min
min=(min i:ini<=i<fin:v[i])

0<=n<100101 && E x nat:x<n:2^x=n && pt i:0<=i<n:v[i]>0
fun resolver(v[0...n) ent,ini ent,fin ent) dev b bool
b=maximo(v, mit, fin) >= maximo(v, ini, mit) && minimo(v, ini,mit) <= minimo(v, mit, fin) && resolver(v, mit, fin) && resolver(v, ini, mit) && ini==fin-1

*/

int maximo(vector<int>v, int ini, int fin) {
	int max = v[ini];
	for (int i = ini;i < fin;i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}
	return max;
}
int minimo(vector<int>v, int ini, int fin) {
	int min = v[ini];
	for (int i = ini;i < fin;i++) {
		if (v[i] < min) {
			min = v[i];
		}
	}
	return min;
}


bool resolver(vector<int>v,int ini,int fin) {
	if (ini == fin) {
		return true;
	}
	int mit = (ini + fin) / 2;
	return maximo(v, mit+1, fin) >= maximo(v, ini, mit) && minimo(v, ini,mit) <= minimo(v, mit+1, fin) && resolver(v, mit+1, fin) && resolver(v, ini, mit);
}

bool resuelveCaso() {
	int num;
	vector<int> v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	
	while (num!=0) {
		v.push_back(num);
		cin >> num;
	}
	if (resolver(v,0,v.size()-1)) {
		cout <<"SI"  << '\n';
	}
	else {
		cout << "NO" << '\n';
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