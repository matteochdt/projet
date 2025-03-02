#include <iostream>
#include <cmath>
#include <vector>
#include "Vecteur.h"

using namespace std;


  
void Vecteur::augmente(double x){
        coordonnees.push_back(x);
    }

void Vecteur::set_coord(int i, double x){
        coordonnees[i] = x;
 }

void Vecteur::affiche() const {
        for (auto coord : coordonnees){
            cout << coord << " ";
        }
        cout << endl;
    }

bool Vecteur::compare(Vecteur const& v, double precision) const {
        if (coordonnees.size() != v.coordonnees.size()){
            return false;
        }
        for (size_t i = 0; i < coordonnees.size(); i++) {
            if (abs(coordonnees[i] - v.coordonnees[i]) > precision) {       //"precision" car jamais tester égalité entre deux doubles
            return false;

            }
        }
        return true;
}

///~CALCULS~///

//CONVENTION pour dim différentes: prolongement du vecteur le plus petit (on remplit avec des 0 avant de faire opération)


Vecteur Vecteur::prolongement_dim(size_t nouvelle_taille) const {
    Vecteur copie = *this;  // Copie l'objet courant
    copie.coordonnees.resize(nouvelle_taille, 0.0);  // Ajoute des 0 si nécessaire
    return copie;
}


Vecteur Vecteur::addition(Vecteur const& autre) {
    size_t nouvelle_taille;
    if (coordonnees.size() > autre.coordonnees.size()) {
        nouvelle_taille = coordonnees.size();
    } else {
        nouvelle_taille = autre.coordonnees.size();
    }
    Vecteur v1 = this->prolongement_dim(nouvelle_taille); 
    Vecteur v2 = autre.prolongement_dim(nouvelle_taille);  

    Vecteur res;
    for (size_t i = 0; i < nouvelle_taille; i++) {
        res.augmente(v1.coordonnees[i] + v2.coordonnees[i]);
    }
    return res;
}

Vecteur Vecteur::soustraction(Vecteur const& autre) {
    size_t nouvelle_taille;
        if (coordonnees.size() > autre.coordonnees.size()) {
        nouvelle_taille = coordonnees.size();
    } else {
        nouvelle_taille = autre.coordonnees.size();
    }
    Vecteur v1 = this->prolongement_dim(nouvelle_taille);  //
    Vecteur v2 = autre.prolongement_dim(nouvelle_taille);
    
    Vecteur res;
    for (size_t i = 0; i < coordonnees.size(); i++) {
        res.augmente(coordonnees[i] - autre.coordonnees[i]);
    }
    return res;
}

Vecteur Vecteur::oppose() {
    Vecteur res;
    for (auto coord : coordonnees) {
        res.augmente(-coord);
    }
    return res;
}

Vecteur Vecteur::mult(double scalaire) {
    Vecteur res;   
    for (auto coord : coordonnees) {
        res.augmente(coord * scalaire);
    }
    return res;
}

double Vecteur::prod_scal(Vecteur const& autret) {
    size_t nouvelle_taille;
    if (coordonnees.size() > autret.coordonnees.size()) {
        nouvelle_taille = coordonnees.size();
    } else {
        nouvelle_taille = autret.coordonnees.size();
    }
    Vecteur v1 = this->prolongement_dim(nouvelle_taille);  //
    Vecteur v2 = autret.prolongement_dim(nouvelle_taille);
    
    double res = 0;
    for (size_t i = 0; i < coordonnees.size(); i++) {
        res += coordonnees[i] * autret.coordonnees[i];
    }
    return res;
}


Vecteur Vecteur::prod_vect(Vecteur const& autre)  {
    if (coordonnees.size() != 3 or autre.coordonnees.size() != 3) {
            throw "Le produit vectoriel n'est défini que pour des vecteurs de dimension 3.";
        }

    Vecteur res;
    res.augmente(coordonnees[1] * autre.coordonnees[2] - coordonnees[2] * autre.coordonnees[1]);  // Composante x
    res.augmente(coordonnees[2] * autre.coordonnees[0] - coordonnees[0] * autre.coordonnees[2]);  // Composante y
    res.augmente(coordonnees[0] * autre.coordonnees[1] - coordonnees[1] * autre.coordonnees[0]);  // Composante z

        return res;
}

double Vecteur::norme() const {
    double somme = 0;
    for (auto coord : coordonnees) {
        somme += coord * coord;
    }
    return sqrt(somme);
}

double Vecteur::norme2() const {
    double somme = 0;
    for (auto coord : coordonnees) {
        somme += coord * coord;
    }
    return somme;
}

Vecteur Vecteur::unitaire() const {
    double n = norme();
    if (n == 0) {
        throw "Impossible de normaliser un vecteur nul.";
    }
    Vecteur res;
    for (auto coord : coordonnees) {
        res.augmente(coord / n);
    }
    return res;
}