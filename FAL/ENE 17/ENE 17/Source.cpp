#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*b=pt i,j:0<=i<j<N:long(i,v)<=long(j,v)
con long(i,v)=(#i:(pt j:i<j<N-1:v[i]==v[j]):v[i])*/

bool resolver(vector<int>v, int num) {
	int longi = 1,long_ant=-1;
	for (int i = 0;i < num-1;i++) {
		if (v[i] == v[i + 1]) {
			longi++;
		}
		else {
			if (longi < long_ant) {
				return false;
			}
			long_ant = longi;
			longi = 1;
		}
	}
	if (longi > long_ant) {
		return false;
	}
	return true;
}

bool resuelveCaso() {
	int num,n;
	vector<int> v;
	cin >> num;
	if (num == 0) {
		return false;
	}
	for (int i = 0; i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	if (resolver(v, num)) {
		cout << "SI" << '\n';
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