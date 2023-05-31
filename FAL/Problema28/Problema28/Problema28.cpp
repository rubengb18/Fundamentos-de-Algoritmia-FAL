#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool todostienen(vector<int>& juguetes_por_ninio, int num_minimo_juguetes,int num_ninios) {
	for (int i = 0;i < num_ninios;i++) {
		if (juguetes_por_ninio[i] < num_minimo_juguetes) {
			return false;
		}
	}
	return true;
}


void resolver(vector<vector<int>>lista_satisfacciones, vector<int>lista_ninios, vector<int>edades_recomendadas, int num_juguetes,int num_ninios,int num_minimo_juguetes,int k,int &sat,int &sat_max, vector<int>&juguetes_por_ninio, vector<bool>&juguete_usado, vector<int>& maximos) {
	if (k == num_juguetes) {
		if (sat > sat_max && todostienen(juguetes_por_ninio, num_minimo_juguetes, num_ninios)) {
			sat_max = sat;
		}
	}
	else {
		for (int i = 0;i < num_ninios;i++) {
			sat += lista_satisfacciones[i][k];
			juguetes_por_ninio[i]++;
			if (lista_ninios[i]>=edades_recomendadas[k] && !juguete_usado[k] && sat+maximos[k+1]>sat_max) {
				juguete_usado[k] = true;
				resolver(lista_satisfacciones, lista_ninios, edades_recomendadas, num_juguetes, num_ninios, num_minimo_juguetes, k+1, sat, sat_max, juguetes_por_ninio, juguete_usado, maximos);
				juguete_usado[k] = false;
			}
			sat -= lista_satisfacciones[i][k];
			juguetes_por_ninio[i]--;
		}
		if (!juguete_usado[k]) {
			resolver(lista_satisfacciones, lista_ninios, edades_recomendadas, num_juguetes, num_ninios, num_minimo_juguetes, k + 1, sat, sat_max, juguetes_por_ninio, juguete_usado, maximos);
		}
	}
}

void hallarmaximos(vector<int>& maximos,int num) {
	for (int i = num - 2;i >= 0;i--) {
		maximos[i] += maximos[i + 1];
	}
}

bool resuelveCaso() {
	int num_juguetes,num_ninios,num_minimo_juguetes,aux,sat=0,sat_max=-1;
	cin >> num_juguetes >> num_ninios >> num_minimo_juguetes;
	vector<int>edades_recomendadas;//En la posicion i esta la edad recomendada para el juguete i
	vector<int>lista_ninios,maximos(num_juguetes+1);
	vector<vector<int>>lista_satisfacciones;
	vector<int>juguetes_por_ninio;
	vector<bool>juguete_usado;
	if (num_juguetes == 0 && num_ninios == 0 && num_minimo_juguetes == 0) {
		return false;
	}
	for (int i = 0;i < num_juguetes;i++) {
		cin >> aux;
		edades_recomendadas.push_back(aux);
		juguete_usado.push_back(false);
		maximos[i] = -1;
	}
	for (int i = 0;i < num_ninios;i++) {
		cin >> aux;
		lista_ninios.push_back(aux);
		juguetes_por_ninio.push_back(0);
	}
	for (int i = 0;i < num_ninios;i++) {
		vector<int>col;
		for (int j = 0;j < num_juguetes;j++) {
			cin >> aux;
			col.push_back(aux);
			if (maximos[j] < aux) {
				maximos[j] = aux;
			}
		}
		lista_satisfacciones.push_back(col);
	}
	hallarmaximos(maximos, num_juguetes);
	resolver(lista_satisfacciones, lista_ninios, edades_recomendadas, num_juguetes, num_ninios, num_minimo_juguetes,0,sat,sat_max, juguetes_por_ninio, juguete_usado,maximos);
	cout << sat_max << '\n';
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {

	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}