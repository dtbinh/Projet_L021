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
    return 0;
}
