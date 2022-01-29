#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


using namespace std;

//Quelque soit un entier naturel n (pair), n est la somme de deux nombres premiers (n1 et n2).
//PB: quelque soit n, afficher (stocker) toutes les pairs (n1, n2).

//fonction qui reprend le crible d'eratosthène qui permet de faire un vecteur de nmbr premier

void crible(const unsigned &n, vector <unsigned> &vecPremier){
    //creer un vecteur des nombre de 2 a n
    for(unsigned i = 2; i< n + 1; ++i){
        vecPremier.push_back(i);
    }
    unsigned index = 0;
    //parcourir le vecteur
    while(index < vecPremier.size()){
        if (vecPremier[index] != 0){ //si le nombre n'est pas 0,

            unsigned a = vecPremier[index];
            unsigned i = index + a;
            while(i < vecPremier.size()){  // on enleve tous ses multiples dans vecteur
                vecPremier[i] = 0;
                i += a;
            }
        }
        index += 1;
    }

}
//fonction afficher
void afficher(vector<vector<unsigned>> tab){
    for(unsigned i = 0; i < tab.size(); ++i){
        cout << tab[i][0] << " + " << tab[i][1] << endl;
    }
}
//fonction qui enleve les 0 du vector de nombre premier
void enlever0(vector <unsigned> &vecPremier){

    unsigned index = 0;
    while(index < vecPremier.size()){//on parcours le vecteur
        if(vecPremier[index] == 0){ // si egale a 0,
            unsigned i = index+1;
            while(i < vecPremier.size()){ //on parcours le rese du vecteur en cherchant le prochain nombre premier
                if(vecPremier[i] != 0){
                    vecPremier[index] = vecPremier[i]; //on le met a la place du 0
                    vecPremier[i] = 0; // et on met 0 a sa place
                    index += 1;
                    break;
                }else if(i == vecPremier.size()-1){ //si l'on a parcourus toute le vecteur, on supprime tous les 0 en fin de vecteur
                    vecPremier.erase(vecPremier.begin() + (index), vecPremier.end());
                    index = vecPremier.size();
                }
                ++i;
            }

        }else{
            ++index;
        }
    }
}

void somme(const unsigned &n, vector <unsigned> &vecPremier, vector <vector <unsigned>> &addition){

    for(unsigned i = 0; i < vecPremier.size(); ++i){ //on parcours le vecteur en entier
        unsigned j = i;
        while( j < (n/2 + 1)){//on parcours le vecteur de i a la moitié du vecteur (pour éviter les doublons)
            if(vecPremier[i] + vecPremier[j] == n){
                addition.push_back({vecPremier[i],vecPremier[j]});//si d'addition = n on met n1 et n2 dans un vecteur
                break;
            }else if(vecPremier[i] + vecPremier[j] > n){//si l'adition dépasse n, on arrette de chercher avec ce nombre
                break;
            }
        ++j;
        }
    }
}



int main(){
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    unsigned nombre = 1E5;
    assert(nombre%2 ==0);//on vérifie que n soit paire
    vector <unsigned> premier; //vecteur de nombre premier
    crible(nombre, premier);
    enlever0(premier);
    vector <vector <unsigned>> addition; //vecteur avec toute les additions
    somme(nombre, premier, addition);
    chrono::high_resolution_clock::duration elapsed = chrono::high_resolution_clock::now()-start;
    cout << chrono::duration_cast<chrono::milliseconds>(elapsed).count() << " ms" << endl;
    //afficher(addition);

    return 0;
}
