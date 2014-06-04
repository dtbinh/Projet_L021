#include <fstream>
#include <QtXml>
#include "CreditManager.h"
#include "Exception.h"

using namespace std;


void CreditManager::load(CategorieManager cm){
    QString file="credit_utc.xml";
    QFile fichier(file);
    if(!fichier.open(QFile::ReadOnly | QFile::Text)) throw Exception("Ouverture fichier impossible!");
    // Ouverture du fichier XML en lecture seule et en mode texte
    QDomDocument doc;
    doc.setContent(&fichier, false);
    QDomElement racine = doc.documentElement();//<xml>
    racine = racine.firstChildElement();//<credit>
    while(!racine.isNull())
    {
        if(racine.tagName() == "credits")
       {
            QDomElement unElement = racine.firstChildElement();
            QString strNom,cat;
            int nombr;
            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    strNom = unElement.text();
                    //cout<<"Code : "<<strNom.toStdString()<<endl;
                }
                else if(unElement.tagName() == "nombre")
                {
                    QString nombretemp = unElement.text();
                    nombr=nombretemp.toInt();
                    //cout<<"Nombre : "<<nombr<<endl;
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat=unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }
            const Categorie* categorie=cm.getCategorie(cat);
            this->ajouterCredit(strNom,nombr,categorie);
    }
        racine = racine.nextSiblingElement();
  }
}

