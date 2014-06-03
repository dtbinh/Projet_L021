#include <fstream>
#include <QtXml>
#include "CategorieManager.h"
#include "Exception.h"

using namespace std;

void CategorieManager::load(){
    QString file="uv_utc.xml";
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
            QDomElement unElement = racine.firstChildElement();
            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    QString strNom = unElement.text();
                }
                else if(unElement.tagName() == "nom")
                {
                    QString strURL = unElement.text();
                }

                unElement = unElement.nextSiblingElement();
            }
        }
        /*if(racine.tagName() == "credit")
        {
            QDomElement unElement = racine.firstChildElement();
            while(!unElement.isNull())
            {
                cout<<"COUCOU"<<endl;
                if(unElement.tagName() == "code")
                {
                    QString strNom = unElement.text();
                }
                else if(unElement.tagName() == "nombre")
                {
                    QString strURL = unElement.text();
                }
                else if(unElement.tagName()=="Categorie"){}
                unElement = unElement.nextSiblingElement();
            }
        }

        // On va à l'élément fils de <root> suivant*/
        racine = racine.nextSiblingElement();
    }

}
