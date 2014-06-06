﻿#include "UVManager.h"

using namespace std;

void UVManager::load(CreditsManager credman, CategorieManager catman, FormationManager forman)
{
    QDomDocument doc = uvs.load_xml("uv_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "uv")
       {
            QDomElement unElement = racine.firstChildElement();
            QString strCode,cat,nom,cred,forma;

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    strCode = unElement.text();
                }
                else if(unElement.tagName() == "nom")
                {
                    nom = unElement.text();
                }
                else if(unElement.tagName()=="credit")
                {
                    cred=unElement.text();
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat=unElement.text();
                }
                else if(unElement.tagName() == "branche")
                {
                    forma=unElement.text();
                    //cout<<forma.toStdString()<<endl;
                }
                unElement = unElement.nextSiblingElement();
            }
            this->ajouterUV(strCode,nom,catman.getCategorie(cat));
            this->getUV(strCode).ajoutCredits(credman.getCredits(cred));
            //forman.getFormation(forma).ajouterUV(*this->getUV(strCode));
        }
        racine = racine.nextSiblingElement();
  }
}
