#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
0<num && alt>0 && (E i:0<=i<num:v[i]<alt)
fun resolver(v[0...n) de ent,num ent,alt ent) dev ini,fin ent
num_valles=(#i:0<i<num-1:v[i-1]>v[i] && v[i+1]>v[i])

inicializacion: ini=-1 && fin=-1 && i=0
f.cota=num-i
invariante:0<num && (E i:0<=i<num:v[i]<alt) && -1<=in<=i && -1<=fi<=i && ini<=fin && in<=fi
avanza:i++
O(n) ya que recorro los elementos del vector(todos menos el primero y el ultimo solo una vez
*/



void resolver(vector<int>v, int num, int alt,int &ini,int &fin) {
	bool esta = false;
	int fi=-1, in=-1;
	for (int i = 0;i < num;i++) {
		if (v[i] > alt) {
			if (!esta) {
				in = i;
			}
			fi = i;
			esta = true;
		}
		else {
			esta = false;
			if (fin - ini < fi-in) {
				fin = fi;
				ini= in;
			}
		}
	}
	if (fin - ini < fi - in) {
		fin = fi;
		ini = in;
	}
}


void resuelveCaso() {
	int num, alt, aux,ini=0,fin;
	cin >> num>>alt;
	vector<int>v;
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v.push_back(aux);
	}
	resolver(v, num, alt, ini, fin);
	cout << ini <<" "<<fin<< '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
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