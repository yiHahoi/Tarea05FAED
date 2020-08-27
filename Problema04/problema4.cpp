/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación propia.

algoritmo:

        for(total_casos):
            se_procesan_edades()
            for(total_bachelors_por_caso):
                left
            for(total_spinsters_por_caso):


para el costo temporal:

      costo_total = total_casos * (costo_total_bachelors_por_caso + costo_total_spinsters_por_caso)
      asi, el costo temporal está dado por O(n+m) cuando n es el total de bachelors de todos los casos sumados
      y m es el total de spinsters de todos los casos sumados

para el costo espacial:

      el algoritmo procesa los datos de uno en uno a medida que los va leyendo aprovechando las mismas variables
      para todos los calculos, por lo tanto el costo espacial es de O(1). Si se considera el archivo de entrada en el costo, entonces sería O(n+m).


*/

#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {

    int totalBachelors;
    int totalSpinsters;
    int temp;
    int left;
    int caseNumber = 1;
    int youngest;

    ifstream cin("input.txt");  // archivo de entrada

    // total de bachelors y spinsters
    cin >> totalBachelors;
    cin >> totalSpinsters;

    // para cada set de bachelors y spinsters
    while(totalBachelors != 0 && totalSpinsters != 0) {

        youngest = 60; // se parte con la maxima edad permitida

        // se puede asumir que se formaron la mayoria de las parejas
        // hasta el punto en que solo queden los ultimos candidatos
        if (totalBachelors - totalSpinsters > 0)
            left = totalBachelors - totalSpinsters;
        else
            left = 0;

        // se obtiene la edad del menor bachelor y se aprovecha de avanzar en el input
        for (int i=0; i<totalBachelors; i++) {
            cin >> temp;
            if(temp < youngest)
                youngest = temp;
        }

        // se avanza en el input con cada spinster
        for (int i=0; i<totalSpinsters; i++) {
            cin >> temp;
        }

        // se retorna el total de bachelors sobrantes y la menor edad en caso de existir
        if(left == 0)
            cout << "Case " << caseNumber << ": " << 0 << endl;
        else
            cout << "Case " << caseNumber << ": " << left << " " << youngest << endl;

        // total de bachelors y spinsters
        cin >> totalBachelors;
        cin >> totalSpinsters;

        caseNumber++;

    }

    return(0);

}
