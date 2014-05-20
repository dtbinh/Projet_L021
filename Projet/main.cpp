#include "uv_profil.h"

using namespace std;

int main()
{
    Dossier D1 ("szewe","nicolas");
    Dossier D2("germain","audrey");
    Dossier D3("chan","li");
    D1.Affichage();
    D2.Affichage();
    D3.Affichage();
    Categorie TM("TM","Techniques et Methodes");
    Credit TM_Classique(6,TM);
    UV NF01("NF01","Algorithmique","On apprend le Pascal",TM_Classique,TM);
    UV LO21("LO21","Programmation orienté objet","Une UV ou l'on apprend le C++",TM_Classique,TM,&NF01);
    NF01.AffichageUV();
    LO21.AffichageUV();
    return 0;
}
