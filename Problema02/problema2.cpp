/*
Nombre: Diego Ignacio Carrasco Vásquez
ID: yihahoi
Autoría: Solución e implementación del repositorio "KHvic".
https://github.com/KHvic/uva-online-judge/blob/master/624-CD.cpp

algoritmo:

        for(total_casos):
            for(total_tracks):
            dfs()
            for(total_tracks):
                output


para el costo temporal:

        Algoritmo por fuerza bruta. El peor caso se obtiene cuando se tiene una combinacion de parametros que
        obligan a la funcion de busqueda dfs a comprobar todas las alternativas posibles.

        costo_total = total_casos * (costo_dfs() + 2*lectura_total_de_tracks())
        asi, el costo temporal está dado por O(n*(2*t+2^t)) donde n es el total de casos y t es el total de tracks del caso.
        Para los casos con un numero de tracks mayores a 2, se tiene un costo O(n*2^t)

para el costo espacial:

        El costo en espacio estará dado por el total de tracks del caso, ya que estos ocupan espacio en un vector.
        Además, se tiene el costo de stack al realizar las llamadas recursivas de dfs las que atravesarán ramas del arbol.
        Así, el costo total en espacio estára dado por: O(t)


*/


#include <bits/stdc++.h>

using namespace std;

int res;
int best;

// se hace el equivalente a una busqueda por profundidad en el arbol (abstracto) de
// soluciones posibles. La mejor opcion se va guardando a medida que se realiza la busqueda
// en las variables globales.
void dfs(int i, vector<int>& nums, int sum, int cur, int limit){

    if(sum > limit) // condicion de termino
        return;
    else if(sum > best){ // si se encuentra una mejor opcion se guarda
        best = sum;
        res = cur;
    }
    if(i >= nums.size()) // condicion de termino de la rama
        return;

    // busqueda por las dos subramas con:
    // 1 track menos,
    // tiempo incrementado en minutos del track seleccionado,
    // selector de track movido
    // considerando el mismo tiempo maximo del cassette
    dfs(i+1,nums,sum+nums[i],cur|(1<<i),limit);
    dfs(i+1,nums,sum,cur,limit);
}

int main()
{
    int n,t,m;
    vector<int> nums;

    ifstream cin("input.txt");

    // para cada caso
    while(cin >> n){
        cin >> t;
        nums.clear();
        // se leen los tracks con sus tiempos
        for(int i=0;i<t;i++){
            cin >> m;
            nums.push_back(m);
        }
        // se hace una "búsqueda por profundidad" de todas las alternativas
        // y el resultado se guarda en las variables globales res y best
        res = 0;
        best = 0;
        dfs(0,nums,0,0,n); // llamada inicial de dfs
        // para cada track se revisa si fue seleccionado como parte del conjunto
        // de tracks que iran en el cassette mediante una mascara de bits
        for(int i=0;i<t;i++)
            if(res & (1<<i)) { // mascara de bits de tracks en resultado
                printf("%d ",nums[i]);
            }
        // se imprime el mejor uso
        printf("sum:%d\n",best);
    }
}

