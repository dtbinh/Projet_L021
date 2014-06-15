#include "UV.h"

using namespace std;

UV::UV(const UV& u)
{
    code = u.code;
    nom = u.nom;
    categorie = u.categorie;
    for(unsigned int i = 0; i < u.cred.size(); i++) {
            cred.push_back(u.cred[i]);
    }
}
