#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*
O(log n)
Especificacion:

n nat && (Ex. i:0<=i<n:(pt j:0<=j<n && i!=j:v[j]==v[j+1] ||v[j]==v[j-1] )v[i]!=v[j]) && v[0...n) de ent
fun resolver(v[0...n) de ent, ini ent,fin ent) dev ent
0<=pos<n && v[pos]!=v[pos+1] && v[pos]!=v[pos-1]

*/


void resolver(vector<int> &v1, vector<int> &v2,int &pos,bool &existe,int ini,int fin){
	int mit = (fin + ini) / 2;
	if (ini == fin && ini==0 && !existe) {
		pos = -1;
	}
	else {
		if (v1[mit] - v2[mit] == 0) {
			pos = mit;
			existe = true;
		}
		else {
			if (v1[mit] - v2[mit] < 0 && v1[mit + 1] - v2[mit + 1]>0) {
				pos = mit;
			}
			else if (v1[mit] - v2[mit] < 0 && v1[mit + 1] - v2[mit + 1] < 0) {
				resolver(v1, v2, pos, existe, mit + 1, fin);
			}
			else {
				resolver(v1, v2, pos, existe, ini, mit);
			}
		}
	}
}

bool resuelveCaso() {
	int num,aux,pos=-1;
	bool existe=false;
	cin >> num;
	if (num== 0) {
		return false;
	}
	vector<int> v1,v2;
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v1.push_back(aux);
	}
	for (int i = 0;i < num;i++) {
		cin >> aux;
		v2.push_back(aux);
	}
	resolver(v1,v2,pos,existe,0,num-1);
	if (existe) {
		cout << "SI " <<pos<< '\n';
	}
	else {
		cout << "NO " << pos << " " << pos+1<< '\n';
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