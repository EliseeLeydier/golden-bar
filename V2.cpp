#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


using namespace std;
using namespace chrono;

//Quelque soit un entier naturel n (pair), n est la somme de deux nombres premiers (n1 et n2).
//PB: quelque soit n, afficher (stocker) toutes les pairs (n1, n2).

//fonction qui reprend le crible d'eratosthène qui permet de faire un vecteur de nmbr premier

void affichervect(vector<unsigned> tab){
    for(unsigned i = 0; i < tab.size(); ++i){
        cout << tab[i] << "    "    ;
    }
    cout << endl;
}
void affichierAddition(const unsigned nombre, vector <unsigned> &addition){
    for(unsigned i = 0; i < addition.size(); ++i){
        cout << nombre << " = "
             << addition[i] << " + "
             << nombre - addition[i] << endl ;
    }
}

int main(){

    high_resolution_clock::time_point start = high_resolution_clock::now();
    const unsigned nombre = 16;
    assert(nombre%2 ==0);//on vérifie que n soit paire
    vector <unsigned> premier(nombre - 1); //vecteur de nombre premier
    premier[0] = 1;
    premier [1] = 1;
    unsigned index = 2;
    while(index < premier.size()){
        if (premier[index] != 1){//si le nombre n'est pas 1,
            unsigned i = index * 2;
            while(i < premier.size()){  // on enleve tous ses multiples dans vecteur
                premier[i] = 1;
                i += index;
            }
        }
        index += 1;
    }
    //affichervect(premier);

    vector <unsigned> addition; //vecteur avec toute les additions

    for(unsigned i = 0; i < (premier.size() / 2 + 3) ; ++i){
        unsigned val = nombre - i;

        if (premier[val] == 0 && premier[i] == 0) {
            addition.push_back({val});
        }
    }
    high_resolution_clock::duration elapsed = high_resolution_clock::now()-start;
    cout << duration_cast<milliseconds>(elapsed).count() << " ms" << endl;
    affichierAddition(nombre, addition);
    return 0;
}
