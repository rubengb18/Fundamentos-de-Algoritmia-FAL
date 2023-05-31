#include <fstream>
#include<iostream>
#include <vector>
using namespace std;



void resolver(vector<int>v, int num,int &ini,int &fin) {
	int in, fi,cont=0,max=-1;
	for (int i = 0;i < num-1;i++) {
		in = i;
		for (int j = i;j < num;j++) {
			fi = j;
			cont += v[j];
			if (cont > max) {
				max = cont;
				ini = in;
				fin = fi;
			}
			else if (cont == max) {
				if (fi - in < fin - ini) {
					fin = fi;
					ini = in;
				}
			}

		}
		cont = 0;
	}
}


void resuelveCaso() {
	int num, aux,ini,fin;
	vector<int>v;
	cin >> num;

	for (int j = 0;j < num;j++) {
		cin >> aux;
		v.push_back(aux);
	}

	resolver(v, num, ini, fin);

	cout << ini+1<<" "<<fin+1 << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int j = 0;j < num;j++) {
		resuelveCaso();
	}


	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}