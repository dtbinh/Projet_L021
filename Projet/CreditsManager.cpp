#include "CreditsManager.h"

using namespace std;

void CreditsManager::load(const CategorieManager& catman)
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

void CreditsManager::save(){
    QDomDocument doc = credits.save_xml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);

    for (map<QString,Credits>::const_iterator it = credits.begin(); it != credits.end(); it++)
    {
        QDomElement credits = doc.createElement("credits");
        root.appendChild(credits);
        QDomElement nom = doc.createElement("code");
        credits.appendChild(nom);
        QDomText nomText = doc.createTextNode(it->second.getNom());
        nom.appendChild(nomText);
        QDomElement nombre = doc.createElement("nombre");
        credits.appendChild(nombre);
        QString tempNombre=QString::number(it->second.getNombre());
        QDomText nombreText = doc.createTextNode(tempNombre);
        nombre.appendChild(nombreText);
        QDomElement categorie = doc.createElement("categorie");
        credits.appendChild(categorie);
        QDomText categorieText = doc.createTextNode(it->second.getCategorie().getCode());
        categorie.appendChild(categorieText);
    }
    QFile file( "credit_utc.xml" );
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}


