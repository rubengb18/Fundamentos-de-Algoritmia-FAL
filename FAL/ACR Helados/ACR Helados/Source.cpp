#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

void pintar(vector<int>& res) {
	for (int i = 0;i < res.size();i++) {
		if (res[i] == 0) {
			cout << "C";
		}
		else {
			cout << "V";
		}
	}
	cout << " ";
}

bool esValidos(vector<int>& usados, int num_choc, int num_vain) {
	if (usados[0] > num_choc || usados[1] > num_vain) {
		return false;
	}
	return true;
}

void resolver(int num_choc,int num_vain,int k, vector<int>&usados, vector<int>&res) {
	if (k == num_choc + num_vain) {
			pintar(res);
	}
	else {
		for (int i = 0;i < 2;i++) {
			res.push_back(i);
			usados[i]++;
			if (esValidos(usados,num_choc,num_vain)) {
				resolver(num_choc, num_vain, k+1, usados, res);
			}
			res.pop_back();
			usados[i]--;
		}
	}
}


void resuelveCaso() {
	int num_choc, num_vain;
	vector<int>usados,res;
	for (int i = 0;i < 2;i++) {
		usados.push_back(0);
	}
	cin >> num_choc >> num_vain;
	resolver(num_choc, num_vain,0,usados,res);
	cout << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for(int i=0;i<num;i++){
		resuelveCaso();

	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}