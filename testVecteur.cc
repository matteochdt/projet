#include <iostream>
#include "Vecteur.h"


using namespace std;

int main(){

// Vecteurs de test
    Vecteur v1, v2, v3, v4, v5, v6, v7;
    v1.augmente(1.0); v1.augmente(2.0); v1.augmente(-0.1);  // v1 = (1.0, 2.0, -0.1)
    v2.augmente(2.6); v2.augmente(3.5); v2.augmente(4.1);   // v2 = (2.6, 3.5, 4.1)
    v3.augmente(0.0); v3.augmente(0.0); v3.augmente(0.0);   // v3 = (0, 0, 0)
    v4.augmente(1.0); v4.augmente(2.0); v4.augmente(-0.1);  // v4 = (1.0, 2.0, -0.1)
    v5.augmente(3.0); v5.augmente(6.0); v5.augmente(-0.3); // v5 = (3.0, 6.0, -0.3)
    v6.augmente(2.6); v6.augmente(3.5); v6.augmente(4.1);  // v6 = (2.6, 3.5, 4.1)
    v7.augmente(8.55); v7.augmente(-4.36); v7.augmente(-1.7);  // v7 = (8.55, -4.36, -1.7)

    // Test 1: Addition de deux vecteurs
    Vecteur v_add = v1.addition(v2);  // (1.0, 2.0, -0.1) + (2.6, 3.5, 4.1)
    cout << "(1.0, 2.0, -0.1) + (2.6, 3.5, 4.1) = ";
    v_add.affiche();  // Doit afficher (3.6, 5.5, 4.0)

    // Test 2: Addition du vecteur nul
    Vecteur v_add_null = v1.addition(v3);  // (1.0, 2.0, -0.1) + (0, 0, 0)
    cout << "(1.0, 2.0, -0.1) + (0, 0, 0) = ";
    v_add_null.affiche();  // Doit afficher (1.0, 2.0, -0.1)

    // Test 3: Soustraction de deux vecteurs
    Vecteur v_sub = v1.soustraction(v2);  // (1.0, 2.0, -0.1) - (2.6, 3.5, 4.1)
    cout << "(1.0, 2.0, -0.1) - (2.6, 3.5, 4.1) = ";
    v_sub.affiche();  // Doit afficher (-1.6, -1.5, -4.2)

    // Test 4: Soustraction d'un vecteur à lui-même
    Vecteur v_sub_self = v1.soustraction(v1);  // (1.0, 2.0, -0.1) - (1.0, 2.0, -0.1)
    cout << "(1.0, 2.0, -0.1) - (1.0, 2.0, -0.1) = ";
    v_sub_self.affiche();  // Doit afficher (0, 0, 0)

    // Test 5: Opéré entre vecteurs de tailles différentes
    // Tu peux tester ici la gestion des dimensions différentes avec prolongation.
    // Si tu utilises la méthode prolonger_dim, assure-toi de l'appeler avant toute opération entre vecteurs de tailles différentes.

    // Test 6: L'opposé de v1
    Vecteur v_oppose = v1.oppose();  // -(1.0, 2.0, -0.1)
    cout << "L'opposé de (1.0, 2.0, -0.1) est: ";
    v_oppose.affiche();  // Doit afficher (-1.0, -2.0, 0.1)

    // Test 7: L'addition d'un opposé est égal à la soustraction
    Vecteur v_add_oppose = v1.addition(v_oppose);  // (1.0, 2.0, -0.1) + (-1.0, -2.0, 0.1)
    cout << "L'addition d'un opposé donne: ";
    v_add_oppose.affiche();  // Doit afficher (0, 0, 0)

    // Test 8: Multiplication par un scalaire
    Vecteur v_mult = v1.mult(3);  // 3 * (1.0, 2.0, -0.1)
    cout << "3 * (1.0, 2.0, -0.1) = ";
    v_mult.affiche();  // Doit afficher (3.0, 6.0, -0.3)

    // Test 9: Produit scalaire (produit point) de deux vecteurs
    double prod_scalaire = v1.prod_scal(v2);  // (1.0, 2.0, -0.1) * (2.6, 3.5, 4.1)
    cout << "(1.0, 2.0, -0.1) * (2.6, 3.5, 4.1) = ";
    cout << prod_scalaire << endl;  // Doit afficher 9.19

    // Test 10: Produit vectoriel (produit croisé) de deux vecteurs
    Vecteur v_prod_vect = v1.prod_vect(v2);  // (1.0, 2.0, -0.1) ^ (2.6, 3.5, 4.1)
    cout << "(1.0, 2.0, -0.1) ^ (2.6, 3.5, 4.1) = ";
    v_prod_vect.affiche();  // Doit afficher (8.55, -4.36, -1.7)

    // Test 11: Norme au carré d'un vecteur
    double norme_v1_carree = v1.norme2();  // ||(1.0, 2.0, -0.1)||^2
    cout << "||(1.0, 2.0, -0.1)||^2 = ";
    cout << norme_v1_carree << endl;  // Doit afficher 5.01

    double norme_v6_carree = v6.norme2();  // ||(2.6, 3.5, 4.1)||^2
    cout << "||(2.6, 3.5, 4.1)||^2 = ";
    cout << norme_v6_carree << endl;  // Doit afficher 35.82



//test égalité limite à 1e-10

cout << "test égalité limite à 1e-10" << endl;

Vecteur v9, v10;
v9.augmente(1.00000000001);
v9.augmente(2.00000000001);

v10.augmente(1.0);
v10.augmente(2.0);

if (v4.compare(v5)) {
    std::cout << "Les vecteurs sont considérés comme égaux" << std::endl;
} else {
    std::cout << "Les vecteurs sont différents" << std::endl;
}

cout << "TEST PROLONGEMENT DIM" << endl;
Vecteur vd1, vd2;
vd1.augmente(1.0);
vd2.augmente(2.0); vd2.augmente(3.0); vd2.augmente(4.0);
vd1.affiche();
vd1 = vd1.prolongement_dim(3);
vd1.affiche();

Vecteur u, v;
v.augmente(3); v.augmente(4); v.augmente(0);
u = v.unitaire();
u.affiche();

return 0;


}