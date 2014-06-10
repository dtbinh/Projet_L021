#include "Inscription.h"

using namespace std;

void Inscription::ajouterUV(const UV& uv)
{
    uvs.ajouter(uv.getCode(), uv);
    notes.ajouter(uv.getCode(), Note());
}

void Inscription::ajouterUV(const QString& code, const QString& nom, const Categorie& cat)
{
    uvs.ajouter(code, UV(code, nom, cat));
    notes.ajouter(code, Note());
}

void Inscription::retirerUV(const QString& code)
{
    uvs.retirer(code);
    notes.retirer(code);
}

void Inscription::afficher()
{
    cout << code.toStdString() << " " << periode->getCode().toStdString() << endl;
    //<< " " << formation->getCode().toStdString() << endl;

    cout << "UVs : ";
    for (map<QString,UV>::const_iterator it = uvs.begin(); it != uvs.end(); it++)
    {
        cout << it->second.getCode().toStdString() << " " << notes.get(it->second.getCode()).getNote().toStdString() << "  ";
    }
    cout << endl;
}
