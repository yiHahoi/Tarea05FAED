/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución basada en repositorio "KHvic".

algoritmo:

        for(total_casos):
            for(total_permutations):
                compare()
                compare()


para el costo temporal:

        Al ser un algoritmo por fuerza bruta, el peor caso se obtiene cuando no es posible
        encontrar una permutacion valida obligando a realizar la comparacion con todas las permutaciones
        posibles para ambas palabras.

        costo_total = total_casos * total_permutaciones * (2*costo_total_compare)
        asi, el costo temporal está dado por O(n) donde n es el total de casos ya que aunque el total de permutaciones a realizar
        sea muy alto, sigue siendo constante ya que depende del largo de las palabras y este no cambia.

para el costo espacial:

      el algoritmo procesa los datos de uno en uno a medida que los va leyendo aprovechando las mismas variables
      para todos los calculos, por lo tanto el costo espacial es de O(1). Si se considera el archivo de entrada en el costo, entonces sería O(n).


*/

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// realiza variaciones a una palabra y con cada cambio compara con la permutacion de colores
// de esta forma se puede encontrar si es posible obtener la permutación especifica realizando
// cambios a la palabra, o si es imposible.
bool compare(string word, int n0, int n1, string colors){
    unordered_set<char> contains(colors.begin()+2, colors.end());
    int exact = 0;
    int colorMatch = 0;
    for(int i=0;i<4;i++){
        char cur = word[i];
        if(colors[i+2] == cur)
            exact++;
        if(contains.count(cur)) colorMatch++;
    }
    colorMatch -= exact;
    return exact == n0 && colorMatch == n1;
}

int main (int argc, char** argv) {

    int totalCases;
    int n0, n1, n2, n3;
    string word1, word2;
    string colors = "ROYGBV";

    //ifstream cin("input.txt");  // archivo de entrada

    // total de casos
    cin >> totalCases;

    // para cada caso
    for (int i=0; i<totalCases; i++) {

        // se leen los parametros del caso
        cin >> word1;
        cin >> n0;
        cin >> n1;
        cin >> word2;
        cin >> n2;
        cin >> n3;

        // para ambas palabras se comparan las distintas permutaciones buscando
        // una alternativa que coincida en ambos casos, lo que significa que si es
        // posible llegar a estas dos palabras desde la permutacion correcta.
        while(1){
            // se realiza la comparación utilizando la última permutación obtenida
            if(compare(word1,n0,n1,colors) && compare(word2,n2,n3,colors)){
                cout << "Possible" << endl;
                break;
            }
            // se prueban todas las permutaciones que sean necesarias. Si no se encuentra
            // ninguna opcion y se han probado todas las permutaciones, se puede concluir que
            // no existe una respuesta correcta considerando las dos entregadas.
            if(!next_permutation(colors.begin(),colors.end())){
                cout << "Cheat" << endl;
                break;
            }
        }
    }

    return(0);

}
