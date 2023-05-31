#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(n)
precondicion: 0<num<=10^18
fun: resolver(
poscondicion: nmax=(#i:0<=i<n:v[i]=max) && nmin=(#i:0<=i<n:v[i]=min) && max=(max i:0<=i<n:v[i]) && min=(min i:0<=i<n:v[i])

Invariante: 0<=i<=N && nmax=(#k:0<=k<i:v[i]=max)
F cota=N-i
Avanza=i++

*/

void resolver(long long int &max, long long int &nmax, long long int &min, long long int &nmin, vector<int>v) {
	max = v[0];
	min = v[0];
	nmax = 0;
	nmin = 0;
	for (int i = 0;i < v.size();i++) {
		
			if (v[i] > max) {
				max = v[i];
				nmax = 1;
			}
			else if (v[i] == max) {
				nmax++;
			}
			if (v[i] < min) {
				min = v[i];
				nmin = 1;
			}
			else if (v[i] == min) {
				nmin++;
			}
	}
}

void resuelveCaso() {
	long long int max, min, nmax, nmin;
	vector<int>v;
	long long int num;
	cin >> num;
	while (num != 0) {
		v.push_back(num);
		cin >> num;
	}
	resolver(max, nmax, min, nmin,v);
	cout << min << " " << nmin << " " << max << " " << nmax<<'\n';
}

int main() {
		// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
		int num;
		cin >> num;
		for (int i = 0;i < num;i++)
			resuelveCaso();
		// para dejar todo como estaba al principio
#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
#endif
		return 0;
}
