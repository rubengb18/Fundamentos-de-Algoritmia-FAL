#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

int maximo(vector<int>v) {
	int max = v[0];
	for (int i = 1; i < v.size();i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

int minimo(vector<int>v) {
	int min = v[0];
	for (int i = 1; i < v.size();i++) {
		if (min > v[i]) {
			min = v[i];
		}
	}
	return min;
}
bool resolver(vector<int>v1, vector<int>v2) {
	if (maximo(v1) < minimo(v2)) {
		return true;
	}
	return false;
}

void resuelveCaso() {
	int num,p, n;
	vector<int> v1,v2;
	cin >> num>>p;

	for (int i = 0; i <= p;i++) {
		cin >> n;
		v1.push_back(n);
	}
	for (int i = p+1; i <num;i++) {
		cin >> n;
		v2.push_back(n);
	}
	if (v1.size() > 0 && v2.size() > 0) {
		if (resolver(v1, v2)) {
			cout << "SI" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	else {
		cout << "SI" << '\n';
	}
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for(int i =0;i<num;i++)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}