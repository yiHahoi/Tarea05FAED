/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación propia.

Resumen del Programa:

	asdf


Análisis Asintótico de la Solución:

    considerando las siguientes constantes y pseudocodigo,

    n = proporcional al total de lineas de input al programa
    m = proporcional al número de casos

    ##############################################################

    main():

        Declaracion inicial de variables            # Ot(1)     y   Oe(1)
        for(case):                                  # Ot(m)     y   Oe(m)
            for(cars):                              # Ot(n/m)   y   Oe(n/m)
                front y pop (queue)                 # Ot(1)     y   Oe(1)
            for(k)                                  # Ot(n/m)   y   Oe(n/m)
                se imprimen resultados              # Ot(1)     y   Oe(1)


    ##############################################################

    Considerando lo anterior se tiene que el orden temporal y espacial del problema será O(n)


*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {

    int totalCases;
    int n0, n1, n2, n3;
    string word1, word2;

    ifstream cin("input.txt");  // archivo de entrada

    // total de casos
    cin >> totalCases;

    // para cada caso
    for (int i=0; i<totalCases; i++) {

        // inputs del caso
        cin >> word1;
        cin >> n0;
        cin >> n1;
        cin >> word2;
        cin >> n2;
        cin >> n3;
        cout << word1[0] << n0 << n1 << word2[0] << n2 << n3 << endl;



    }

    return(0);

}




/*
contenedor_iterable  conjunto_de_n_elementos = {e0,...,eN}
contenedor_iterable mascara = {1_0, 1_2,....,1_k, 0_N-k,....,0_N}

sort (conjunto_de_n_elementos)

do
    contenedor conjunto_de_k_elementos;
    for (i=0; i<N; i++)
        if (mascara[i]==1) contenedor_de_k_elementos.push_back(conjunto_de_n_elementos[i])
while (next_permutation(mascara))
*/


