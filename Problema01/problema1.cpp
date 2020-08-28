/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación del repositorio "KHvic".
https://github.com/KHvic/uva-online-judge/blob/master/11205-The%20broken%20pedometer.cpp

algoritmo:

        for(total_casos):
            for(total_symbols):
            for(minimal_representations):
                for(symbols): O(n)

para el costo temporal:

        El costo temporal esta dado por el total de casos "c" mas la lectura de los simbolos "n*p" mas
        el calculo de las representaciones minimas que corresponde a 2^p. Es decir el problema es O(c*(n*p + 2^p))
        que se puede reducir a O(c*2^p).

*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream cin("input.txt");

    int totalCases;
    int p;
    int n;
    int v;
    vector<int> symbols;

    // para cada caso
    cin >> totalCases;
    while(totalCases--){
        cin >> p;
        cin >> n;
        symbols.clear();
        for(int i=0;i<n;i++){
            int symbol = 0;

            // para cada simbolo del caso se lee sus digitos y se guardan en la variable symbol
            // luego se realiza un corrimiento de bits en la variable, de forma que en p pasos
            // se tiene la representacion codificada en symbol en la forma de valor entero.
            for(int j=0;j<p;j++){
                cin >> v;
                symbol = (symbol<<1)+v;
            }
            // una vez que se captura el simbolo, este se guarda en un vector symbols.
            symbols.push_back(symbol);
        }

        // como se tienen p digitos para representar los valores del caso,
        // se realiza la iteracion un maximo de (1<<p) veces =(2^p)
        int least = INT_MAX;
        for(int i=0;i<(1<<p);i++){
            unordered_set<int> represents;
            // se utiliza el indice de las 2^p alternativas como mascara sobre los simbolos entregados como input
            // de esta forma se obtienen los bits que influyen en la representacion de un valor especifico, ya que pueden
            // haber bits que esten o no, de todas maneras se pueda deducir el valor.
            for(auto& symbol : symbols)
                represents.insert(i&symbol);

            // si se obtiene un total de n secuencias de bits que son necesarios para representar valores,
            // se puede calcular el minimo de bits necesario.
            if(represents.size() == n){
                int numBits = 0;
                v = i;
                while(v){
                    numBits++;
                    v &= (v-1);
                }
                least = min(least, numBits);
            }
        }
        cout << least << endl;
    }
}
