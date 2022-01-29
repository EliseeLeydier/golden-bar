#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


using namespace std;

//Quelque soit un entier naturel n (pair), n est la somme de deux nombres premiers (n1 et n2).
//PB: quelque soit n, afficher (stocker) toutes les pairs (n1, n2).

//fonction qui reprend le crible d'eratosthène qui permet de faire un vecteur de nmbr premier

void crible(vector <unsigned> &vecPremier){
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
//fonction afficher
void afficher(vector<vector<unsigned>> tab){
    for(unsigned i = 0; i < tab.size(); ++i){
        cout << tab[i][0] << " + " << tab[i][1] << endl;
    }
}
//fonction afficher
void affichervect(vector<unsigned> tab){
    for(unsigned i = 0; i < tab.size(); ++i){
        cout << tab[i] << endl;
    }
}
//fonction qui enleve les 0 du vector de nombre premier
void enlever0(vector <unsigned> &vecPremier){

    unsigned index = 2;
    while(index < vecPremier.size()){//on parcours le vecteur
        if(vecPremier[index] == 1){ // si egale a 1
            unsigned i = index+1;
            while(i < vecPremier.size()){ //on parcours le rese du vecteur en cherchant le prochain nombre premier
                if(vecPremier[i] != 1){
                    vecPremier[index] = i; //on le met a la place du 0
                    vecPremier[i] = 1; // et on met 0 a sa place
                    index += 1;
                    break;

                }else if(i == vecPremier.size()-1){ //si l'on a parcourus toute le vecteur, on supprime tous les 0 en fin de vecteur
                    vecPremier.erase(vecPremier.begin() + (index), vecPremier.end());
                    index = vecPremier.size();
                }
                ++i;
            }

        }else{
            vecPremier[index] = index;
            ++index;
        }
    }
}

int main(){
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    unsigned nombre = 1E5;
    assert(nombre%2 ==0);//on vérifie que n soit paire
    vector <unsigned> premier(nombre); //vecteur de nombre premier
    crible(premier);
    enlever0(premier);
    //unsigned ind = *premier[1];
    premier.erase(premier.begin(), premier.begin() + 2);
    //affichervect(premier);


    vector <unsigned> addition; //vecteur avec toute les additions
    //somme(nombre, premier, addition);

    for(unsigned i = 0; i < (premier.size()/2 + 1) ; ++i){
        unsigned val = nombre - premier[i];
        //cout << "rentrer"<<val<<endl;
        unsigned deb, fin, mili;
        deb = 0;
        fin = premier.size();
        while( deb <= fin) {
            mili = (deb + fin) / 2;
            if (premier[mili] == val){
                //cout << premier[i] << " + " << val << " = " <<  nombre << endl;
                addition.push_back({premier[mili]});
                break;
            }else if(val > premier[mili]){
                deb = mili + 1;
            }else{
                fin = mili - 1;
            }
        }
    }

    chrono::high_resolution_clock::duration elapsed = chrono::high_resolution_clock::now()-start;
    cout << chrono::duration_cast<chrono::milliseconds>(elapsed).count() << " ms" << endl;
    //cout << addition.size() << " : taille" << endl;
    //affichervect(addition);

    return 0;
}
