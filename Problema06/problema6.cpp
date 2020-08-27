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

    //ifstream cin("input.txt");  // archivo de entrada

    // para cada secuencia de apuestas
    while (cin >> n) {

        // condicion de termino cuando n = 0
        if(n == 0)
            break;

        max = 0;
        accum = 0;
        i = 0;
        // para cada apuesta
        while(i < n){
            // Se acumula la apuesta
            cin >> bet;
            accum += bet;
            // si la apuesta resulto en perdida y nos
            // quedamos sin dinero se acaba la racha
            if(bet < 0 && accum <= 0){
                accum = 0;
            // si la apuesta resulto en ganancia y 
            // es una mejor racha, se guarda
            } else if(max < accum){
                max = accum;
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

