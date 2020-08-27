/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación propia.
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

    while(totalBachelors != 0 && totalSpinsters != 0) {

        youngest = 60; // la maxima edad permitida

        if (totalBachelors - totalSpinsters > 0)
            left = totalBachelors - totalSpinsters;
        else
            left = 0;

        // para cada bachelor
        for (int i=0; i<totalBachelors; i++) {
            cin >> temp;
            if(temp < youngest)
                youngest = temp;
        }

        // para cada spinster
        for (int i=0; i<totalSpinsters; i++) {
            cin >> temp;
        }

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
