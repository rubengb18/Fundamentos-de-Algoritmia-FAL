#include <iostream>
#include <vector>
using namespace std;

int resolver(int N, vector<int>& v) {
	int p = 0, q = 1, crec = 1, l_max = q - p;

	while (q < N) {
		if (v[q] > v[q - 1]) {
			crec++;
			if (crec == 3) {
				l_max = (l_max > q - p) ? l_max : q - p;
				p = q - 1;
				crec = 2;
			}
		}
		else crec = 1;
		l_max = (l_max > q - p + 1) ? l_max : q - p + 1;
		q++;
	}
	return (N == 0) ? 0 : l_max;
}

void resuelveCaso() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cout << resolver(N, v) << endl;
}


int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("pause");
	return 0;
}