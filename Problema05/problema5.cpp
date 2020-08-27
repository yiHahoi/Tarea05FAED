/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación propia.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {

    // archivo de entrada
    ifstream cin("input.txt");

    // total de casos
    int totalCases;
    cin >> totalCases;

    int coinTypes, temp;
    vector<int> coins;
    // para cada caso
    for(int i=0; i<totalCases; i++) {

        cin >> coinTypes;

        for(int j=0; j<coinTypes; j++){
            cin >> temp;
            coins.push_back(temp);
        }

        // se comprueba que la suma de monedas 0 a n-1 sea menor que
        // el valor de la moneda n. Si esto se cumple, se acumula el valor
        // de la moneda n-1 y se aumenta el contador.
        int sum = 0;
        int ctr = 1;
        for(int k=0; k<coinTypes-1; k++){
            if(sum + coins[k] < coins[k+1]){
                sum += coins[k];
                ctr++;
            }
        }

        cout << ctr << endl;
        coins.clear();
    }

    return(0);

}
