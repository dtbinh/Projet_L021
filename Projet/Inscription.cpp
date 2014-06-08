#include "Inscription.h"

using namespace std;

void Inscription::ajouterUV(const UV& uv)
{
    uvs.ajouter(uv.getCode(), uv);
    notes[uv.getCode()];
}

void Inscription::ajouterUV(const QString& code, const QString& nom, const Categorie& cat)
{
    uvs.ajouter(code, UV(code, nom, cat));
    notes[code];
}

void Inscription::retirerUV(const QString& code)
{
    uvs.retirer(code);
    notes.erase(code);
}

void Inscription::afficher()
{
    cout << code.toStdString() << " " << periode->getCode().toStdString() << endl;
    //<< " " << formation->getCode().toStdString() << endl;

    cout << "UVs : ";
    for (map<QString,UV>::const_iterator it = uvs.begin(); it != uvs.end(); it++)
    {
        cout << it->second.getCode().toStdString() << " " << notes.find(it->second.getCode())->second.getNote().toStdString() << "  ";
    }
    cout << endl;
}
