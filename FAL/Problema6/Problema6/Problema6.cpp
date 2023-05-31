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



int resolver(vector<int>v, int num) {
	int cont = 0, max = -1;
	for (int i = 0;i < num - 1;i++) {
		if (v[i] == v[i + 1]) {
			cont++;
			if (max < cont) {
				max = cont;
			}
		}
		else {
			cont = 0;
		}
	}
	
	return max;
}


bool resuelveCaso() {
	int num,res;
	cin >> num ;
	if (num == -1) {
		return false;
	}
	vector<int>v;
	
	while (num!=-1) {
		v.push_back(num);
		cin >> num;
	}
	res = resolver(v, v.size());
	if (res == -1) {
		cout << "HOY NO COMEN" << '\n';
	}
	else {
		cout << res << '\n';
	}

	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	while (resuelveCaso()) {
		

	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}