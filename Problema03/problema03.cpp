/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación basados en repositorio "KHvic".
*/

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

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
        //cout << word1[0] << n0 << n1 << word2[0] << n2 << n3 << endl;

        while(1){
            if(compare(word1,n0,n1,colors) && compare(word2,n2,n3,colors)){
                cout << "Possible" << endl;
                break;
            }
            if(!next_permutation(colors.begin(),colors.end())){
                cout << "Cheat" << endl;
                break;
            }
        }
    }

    return(0);

}
