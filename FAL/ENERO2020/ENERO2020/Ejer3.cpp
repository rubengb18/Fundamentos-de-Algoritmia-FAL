#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

/*
T(n) == k si ini_fil == fin_fil

*/
                            

void resolver(vector<vector<int>> v, int num_playas, int num_personas, int &cont, int &max, int k,int lim_playas,vector<int>&kilos_por_playa,vector<bool>&personas_enviadas,int &playas_limpias,int &aux,vector<int>maximos) {
	if (k == num_personas) {
		if (cont > max && aux>=lim_playas) {
			max = cont;
			playas_limpias = lim_playas;
		}
	}
	else {
		for (int i =0;i <num_playas;i++) {
			
			if (kilos_por_playa[i] <=v[k][i]) {
				cont += kilos_por_playa[i];
			}
			else {
				cont += v[k][i];
			}
			kilos_por_playa[i] -= v[k][i];
			
			if (!personas_enviadas[k] && cont+maximos[k+1]>max) {
				personas_enviadas[k] = true;
				if (kilos_por_playa[i] <= 0) {
					aux++;
					resolver(v, num_playas, num_personas, cont, max, k + 1, lim_playas, kilos_por_playa, personas_enviadas, playas_limpias,aux, maximos);
					aux--;
				}
				else {
					resolver(v, num_playas, num_personas, cont, max, k + 1, lim_playas, kilos_por_playa, personas_enviadas, playas_limpias, aux, maximos);

				}
				personas_enviadas[k] = false;
			}
			kilos_por_playa[i] += v[k][i];
			
			if (kilos_por_playa[i]<= v[k][i]) {
				cont -= kilos_por_playa[i];
			}
			else {
				cont -= v[k][i];
			}
		}
	}
}

void hallarmaximos(vector<int>& v) {
	for (int i = v.size()-1;i > 0;i--) {
		v[i - 1] += v[i];
	}
}
void resuelveCaso() {
	int num_playas,num_personas,cont=0,max=-1,lim_playas,n,k=0,l=0,aux=0,aux_max=-1;
	vector<vector<int>> v;
	vector<int>kilos_por_playa;
	
	cin >> num_personas >> num_playas >> lim_playas;
	vector<int>maximos(num_personas + 1);
	vector<bool> personas_enviadas;
	for (int i = 0; i < num_playas;i++) {
		cin >> n;
		kilos_por_playa.push_back(n);

	}
	for (int i = 0; i < num_personas;i++) {
		vector<int>aux;
		personas_enviadas.push_back(false);
		for (int j= 0; j < num_playas;j++) {
			cin >> n;
			aux.push_back(n);
			if (n > aux_max) {
				aux_max = n;
			}
		}
		maximos[i] = aux_max;
		v.push_back(aux);
	}
	hallarmaximos(maximos);
	resolver(v, num_playas,num_personas,cont,max,k,lim_playas,kilos_por_playa, personas_enviadas,l,aux,maximos);
	if (max == -1) {
		cout << "IMPOSIBLE" << '\n';
	}
	else {
		cout << max << " "<<l << '\n';
	}

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ejer3.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int i = 0; i < num;i++) {
		resuelveCaso();
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}