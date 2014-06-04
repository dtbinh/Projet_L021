#include <fstream>
#include <QtXml>
#include "CategorieManager.h"
#include "Exception.h"

using namespace std;

void CategorieManager::load(){
    QString file="categorie_utc.xml";
    QFile fichier(file);
    if(!fichier.open(QFile::ReadOnly | QFile::Text)) throw Exception("Ouverture fichier impossible!");
    // Ouverture du fichier XML en lecture seule et en mode texte
    QDomDocument doc;
    doc.setContent(&fichier, false);
    QDomElement racine = doc.documentElement();//<xml>
    racine = racine.firstChildElement();//<categorie>

    while(!racine.isNull())
    {
        if(racine.tagName() == "categorie")
        {
            QString tempNom,tempURL;
            QDomElement unElement = racine.firstChildElement();
            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    tempNom = unElement.text();
                }
                else if(unElement.tagName() == "nom")
                {
                    tempURL = unElement.text();

                }
                unElement = unElement.nextSiblingElement();
            }
        this->ajouterCategorie(tempNom,tempURL);

        }

        racine = racine.nextSiblingElement();
    }
}
