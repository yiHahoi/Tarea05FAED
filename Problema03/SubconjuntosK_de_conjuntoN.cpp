/*
Revisar la materia de espacios binomiales de FTC para cachar la cantidad de permutaciones totales dado cualquier n y k
*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
	// Variables para testear
	int n = 10;
	int k = 8;

	// Con esto realizamos una mascara de N
	vector<char> mask(k,1);
	mask.resize(n,0);

	// El contenedor para los conjuntos
	vector<char> conjuntoN(n,0);
	vector<char> conjuntoK(k,0);

	// ConjuntoN con elementos random
	srand(time(0));
	for (int i=0; i<n; i++)
		conjuntoN[i] = rand()%100;

	// Imprimir los valores del conjuntoN
	cout << "conjuntoN: [ ";
	for (int i=0; i<n; i++)
		cout << int(conjuntoN[i]) << " ";
	cout << "]" << endl;

	// Con el sort te aseguras de que comienza con el minimo valor lexicografico
	sort(mask.begin(), mask.end());

	// Crear todas las permutaciones e imprimirlas
	int n_permutacion = 0;
	do {
		cout << endl << "Permutacion " << ++n_permutacion << endl;
		// Imprimir mascara para poder verla
		cout << "Mask: [ ";
		for (int i=0; i<n; i++)
			cout << int(mask[i]) << " ";
		cout << "]" << endl;

		// usar mascara para crear el conjunto K
		for (int i=0, index=0; i<n; i++)
			if(mask[i]==1) conjuntoK[index++] = conjuntoN[i];

		// imprimir el subconjunto con K elementos en su permutacion n_permutacion
		cout << "ConjuntoK: [ ";
		for (int i=0; i<k; i++)
			cout << int(conjuntoK[i]) << " ";
		cout << "]" << endl;
	} while(next_permutation(mask.begin(), mask.end()));

	return 0;
}