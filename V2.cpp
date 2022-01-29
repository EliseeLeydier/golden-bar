#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


using namespace std;

//Quelque soit un entier naturel n (pair), n est la somme de deux nombres premiers (n1 et n2).
//PB: quelque soit n, afficher (stocker) toutes les pairs (n1, n2).

//fonction qui reprend le crible d'eratosthène qui permet de faire un vecteur de nmbr premier

void crible2(vector <unsigned> &vecPremier){
    //creer un vecteur des nombre de 2 a n
    unsigned index = 2;
    //parcourir le vecteur
    while(index < vecPremier.size()){
        //cout << vecPremier[index] << "zzz\n";
        if (vecPremier[index] != 1){//si le nombre n'est pas 1,
            //cout << "aaaa\n";
            unsigned i = index * 2;
            while(i < vecPremier.size()){  // on enleve tous ses multiples dans vecteur
                vecPremier[i] = 1;
                i += index;
            }
        }
        index += 1;
    }

}

int main(){

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    unsigned nombre = 1E9;
    assert(nombre%2 ==0);//on vérifie que n soit paire
    vector <unsigned> premier(nombre - 1); //vecteur de nombre premier
    premier[0] = 1;
    premier [1] = 1;
    crible2(premier);
    //affichervect(premier);

    vector <unsigned> addition; //vecteur avec toute les additions

    for(unsigned i = 0; i < (premier.size() / 2 + 3) ; ++i){
        unsigned val = nombre - i;

        if (premier[val] == 0 && premier[i] == 0) {
            //cout << i << " + " << val << " = " <<  nombre << endl;
            addition.push_back({premier[val]});
        }
    }
    chrono::high_resolution_clock::duration elapsed = chrono::high_resolution_clock::now()-start;
    cout << chrono::duration_cast<chrono::milliseconds>(elapsed).count() << " ms" << endl;

    return 0;
}
