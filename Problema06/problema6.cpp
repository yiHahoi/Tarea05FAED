/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación propia.
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {

    int i, n;
    int bet;
    int accum;
    int max;

    ifstream cin("input.txt");  // archivo de entrada

    // para cada serie de apuestas
    while (cin >> n) {

        // condicion de termino cuando n = 0
        if(n == 0)
            break;

        max = 0;
        accum = 0;
        i = 0;
        while(i < n){
            // inputs del caso
            cin >> bet;
            // si se acaba la racha se compara lo acumulado con 
            // la mejor racha pasada
            if(bet < 0){
                if(max < accum)
                    max = accum;
                accum += bet;
                if(accum < max)
                    accum = 0;
            // racha
            } else {
                accum += bet;
            }
            i++;   
        }
        // se debe comprobar si se acumula el ultimo bet 
        if(bet > 0 && max < accum)
            max = accum;
        
        // se encontro alguna racha? o pura perdida?
        if(max != 0)
            cout << "The maximum winning streak is " << max << "." << endl;
        else
            cout << "Losing streak." << endl;
      
    }

    return(0);

}

