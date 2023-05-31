#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
n>=0
fun resolver(v[0...n) de ent, num ent) dev max ent
max=(max p,q:0<=p<q<n && A(p,q) :q-p)
con A(p,q)=(pt i:p<i<q: v[i-1]>v[i]||v[i]>v[i+1])

F. cota=num-2 -i
Invariante= 1<=i<=num-1 && 0<=cont<=max
Avanza=i++
Orden (n) con n el numero de elementos del vector

*/

int resolver(vector<int>v, int num) {
	int cont = 0,max=-1,cont_asc=1;
	if (num <=2) {
		max = num;
	} 
	else{
		for (int i = 0;i < num - 1;i++) {
			cont++;
			if (v[i] < v[i + 1]) {
				cont_asc++;
				if (cont_asc == 3){
					if (cont > max) {
						max = cont;
					}
					cont =1;
					cont_asc = 2;
				}				
			}
			else {
				cont_asc = 1;
			}
		}
		cont++;
		if (cont > max) {
			max = cont;
		}

	}
	
	return max;
}

void resuelveCaso() {
	int num, n;
	vector<int> v;
	cin >> num;

	for (int i = 0; i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	cout << resolver(v,num) << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ejer1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0; i < num;i++) {
		resuelveCaso();
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}