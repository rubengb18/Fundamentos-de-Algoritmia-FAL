#include <fstream>
#include<iostream>
#include <vector>
using namespace std;



typedef struct {
	int cantidad;
	int precio;
}tEsc;


void resolver(vector<int>anchos_esc, vector<tEsc>&info_col, int num_esc,int num_col,int k, vector<int>&colores_usados, vector<int>& colores_usados_fin,int &min,int &cont) {
	if (k == num_esc) {
		if (cont < min) {
			min = cont;
			for (int i = 0;i < num_esc;i++) {
				colores_usados_fin[i] = colores_usados[i];
			}
		}
	}
	else {
		for (int i = 0;i < num_col;i++) {
			colores_usados[k]=i;
			cont += info_col[i].precio* anchos_esc[k];
			info_col[i].cantidad -= anchos_esc[k];
			if (info_col[i].cantidad >=0 && cont<min) {
				if (k > 0) {
					if (colores_usados[k] != colores_usados[k - 1]) {
						resolver(anchos_esc, info_col, num_esc, num_col, k+1, colores_usados, colores_usados_fin, min, cont);
					}
				}
				else {
					resolver(anchos_esc, info_col, num_esc, num_col, k + 1, colores_usados, colores_usados_fin, min, cont);
				}
			}
			colores_usados[k] = -1;
			info_col[i].cantidad += anchos_esc[k];
			cont -= info_col[i].precio * anchos_esc[k];
		}
	}

}

bool resuelveCaso() {
	int num_esc,num_col,k=0,n,min=10000000,cont=0;
	vector<int>anchos_esc;
	vector<int>colores_usados,aux;
	vector<tEsc>info_col;
	cin >> num_esc >> num_col;
	if (num_esc == -1) {
		return false;
	}
	for (int i = 0;i < num_esc;i++) {
		cin >> n;
		anchos_esc.push_back(n);
		colores_usados.push_back(-1);
		aux.push_back(-1);
	}
	for (int i = 0;i < num_col;i++) {
		tEsc aux;
		cin >> aux.cantidad >> aux.precio;
		info_col.push_back(aux);
	}
	resolver(anchos_esc, info_col, num_esc, num_col, k, colores_usados, aux, min, cont);
	if (min == 10000000) {
		cout << "NO" << '\n';
	}
	else {
		cout << min << '\n';
		for (int i = 0;i < aux.size();i++) {
			cout << aux[i] << " ";
		}
	}
	cout << '\n';
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ejer2.txt");
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