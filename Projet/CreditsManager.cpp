#include "CreditsManager.h"

using namespace std;

void CreditManager::load(const CategorieManager& catman)
{
    QDomDocument doc = credits.load_xml("credit_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "credits")
        {
            QString strNom,cat;
            int nombr;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    strNom = unElement.text();
                }
                else if(unElement.tagName() == "nombre")
                {
                    QString nombretemp = unElement.text();
                    nombr = nombretemp.toInt();
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            const Categorie& categorie = catman.getCategorie(cat);
            this->ajouterCredits(strNom, nombr, categorie);
        }

        racine = racine.nextSiblingElement();
    }
}

