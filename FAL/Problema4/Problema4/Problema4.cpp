#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
0<num<=10000 && (pt i:0<=i<num:-274<v[i]<1000)
fun resolver(v[0...n) de ent,num ent) dev num_picos,num_valles ent E/S
num_picos=(#i:0<i<num-1:v[i-1]<v[i] && v[i+1]<v[i])
num_valles=(#i:0<i<num-1:v[i-1]>v[i] && v[i+1]>v[i])

inicializacion: num_picos=0 && num_valles=0 && i=1
f.cota=num-2-i
invariante:0<num<=10000 && (pt i:0<=i<num:-274<v[i]<1000) && 0<=num_picos<=i && 0<=num_valles<=i
avanza:i++
O(n) ya que recorro los elementos del vector(todos menos el primero y el ultimo solo una vez
*/



void resolver(vector<int>v,int num, int &num_picos,int &num_valles) {
	for (int i = 1;i < num-1;i++) {
		if (v[i - 1] < v[i] && v[i + 1] < v[i]) {
			num_picos++;
		}
		else if (v[i - 1] > v[i] && v[i + 1] > v[i]) {
			num_valles++;
		}
	}
}


void resuelveCaso() {
	int num, num_picos=0, num_valles = 0,aux;
	cin >> num;
	vector<int>v;
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v.push_back(aux);
	}
	resolver(v, num, num_picos, num_valles);
	cout << num_picos << " " << num_valles << '\n';
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