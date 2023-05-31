#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
0<=n<=1000
fun(v[0...n) de ent,num ent) dev max ent
max=(max i,j:0<i<=j<=n && decrec(v.j,i):j-i)
con decrec(v[0...n),j,i ent) dev b bool 
b=(pt p,t:i<=p<t<=j:v[t]<v[p])

F.cota: num-i-1
Invariante: 0<=n<=1000 && 0<=i<=num 
avanza:i++

O(n) con n el tamaño del vector, ya que realizamos operaciones constantes dentor de un for que es una operacion de coste lineal
*/

int resolver(vector<int>v,int num){
	int res = 1,max=-1;
	if (num == 0) {
		return 0;
	}
	bool dec = true;
	for (int i = 0;i < num-1;i++) {
		if (v[i] >= v[i + 1]) {
			res++;
		}
		else {
			dec = false;
			if (max < res) {
				max = res;
			}
			res = 1;
		}
	}
	if (dec||res>1) {
		max = res;
	}
	return max;
}


void resuelveCaso() {
	int num,aux;
	cin >> num;
	vector<int>v;
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v.push_back(aux);
	}
	cout << resolver(v, num) << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;cin >> num;
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