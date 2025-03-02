#include <iostream>
#include "Vecteur.h"


using namespace std;

int main(){

Vecteur v1;
Vecteur v2;
Vecteur v3;

v1.augmente(1.0); v1.augmente(0.0); v1.augmente(-0.1);
v1.set_coord(1, 2.0);

v2.augmente(2.6); v2.augmente(3.5); v2.augmente(4.1);

v3 = v1;

cout << "v1 = "; 
v1.affiche();
cout << endl;

cout << "v2 = ";
v2.affiche();
cout << endl;

cout << "Le vecteur 1 est: ";
if (v1.compare(v2)){
    cout << "égal au vecteur 2" << endl;
}
else{
    cout << "différent du vecteur 2" << endl;
}

cout << "Le vecteur 2 est: ";
if (v1.compare(v2)){
    cout << "égal au vecteur 1" << endl;
}
else{
    cout << "différent du vecteur 1" << endl;

}

//test égalité limite à 1e-10

cout << "test égalité limite à 1e-10" << endl;

Vecteur v4, v5;
v4.augmente(1.00000000001);
v4.augmente(2.00000000001);

v5.augmente(1.0);
v5.augmente(2.0);

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