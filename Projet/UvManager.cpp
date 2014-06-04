#include <fstream>
#include <QtXml>
#include "Exception.h"
#include "UvManager.h"

using namespace std;

void UvManager::load(CreditManager credman,CategorieManager cm){
    QString file="uv_utc.xml";
    QFile fichier(file);
    if(!fichier.open(QFile::ReadOnly | QFile::Text)) throw Exception("Ouverture fichier impossible!");
    // Ouverture du fichier XML en lecture seule et en mode texte
    QDomDocument doc;
    doc.setContent(&fichier, false);
    QDomElement racine = doc.documentElement();//<xml>
    racine = racine.firstChildElement();
    while(!racine.isNull())
    {
        if(racine.tagName() == "uv")
       {
            QDomElement unElement = racine.firstChildElement();
            QString strCode,cat,nom,cred;

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    strCode = unElement.text();
                    //cout<<"Code : "<<strCode.toStdString()<<endl;
                }
                else if(unElement.tagName() == "nom")
                {
                    nom = unElement.text();
                    //cout<<"Nom : "<<nom.toStdString()<<endl;
                }
                else if(unElement.tagName()=="credit")
                {
                    cred=unElement.text();
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat=unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }
            const Credits& credit=credman.getCredit(cred);
            const Categorie* categorie=cm.getCategorie(cat);
            this->ajouterUv(strCode,nom,*categorie);
            this->getUv(strCode)->ajoutCredits(credit);
    }
        racine = racine.nextSiblingElement();
  }
}
