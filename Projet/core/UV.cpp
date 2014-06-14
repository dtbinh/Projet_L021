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
    for(unsigned int i = 0; i < u.prerequis.size(); i++) {
            prerequis.push_back(u.prerequis[i]);
    }
}

UV::~UV()
{
    code="NULL";
    nom="NULL";
}
