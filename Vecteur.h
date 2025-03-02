#pragma once

#include <vector>


class Vecteur{
private:
    std::vector<double> coordonnees;
public:
    Vecteur() = default;
    void augmente(double x);
    void set_coord(int i, double x);
    void affiche() const;
    bool compare(Vecteur const& v, double precision = 1e-10) const ;
    Vecteur addition(Vecteur const& autre);
    Vecteur soustraction(Vecteur const& autre);
    Vecteur oppose();
    Vecteur mult(double scalaire);
    double prod_scal(Vecteur const& autre); 
    Vecteur prod_vect(Vecteur const& autre);
    Vecteur prolongement_dim(size_t nouvelle_taille) const;             //renvoi vecteur car sinon change opérandes
    double norme() const;
    double norme2() const;
    Vecteur unitaire() const;
};

