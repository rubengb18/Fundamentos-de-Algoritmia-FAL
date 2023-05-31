#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
O(log n)
Especificacion:

n nat && (Ex. i:0<=i<n:(pt j:0<=j<n && i!=j:v[j]==v[j+1] ||v[j]==v[j-1] )v[i]!=v[j]) && v[0...n) de ent
fun resolver(v[0...n) de ent, ini ent,fin ent) dev ent
0<=pos<n && v[pos]!=v[pos+1] && v[pos]!=v[pos-1]

*/



void resolver(vector<int>&v, int ini, int fin, int &cant) {
	int mit = (fin + ini) / 2;
	if(v[mit]-1 != mit){
		cant++;
		int aux = v[mit+1];
		v[mit+1] = v[mit];
		v[mit] = aux;
		
	}
	resolver(v, ini, mit, cant);
	resolver(v, mit + 1, fin, cant);
}

bool resuelveCaso() {
	int num, cant, n;
	vector<int>v;
	cin >> num;
	if (!cin) {
		return false;
	}
	for (int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	resolver(v, 0, v.size() - 1, cant);
	cout << cant << '\n';
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