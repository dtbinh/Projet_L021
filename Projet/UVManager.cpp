#include "UVManager.h"

using namespace std;

void UVManager::load(const CreditsManager& credman,const CategorieManager& catman,FormationManager& forman)
{
    std::vector<const Formation*> tempformations;
    QDomDocument doc = load_xml("uv_utc.xml");

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
                    tempformations.push_back(&forman.getFormation(forma));
                }
                unElement = unElement.nextSiblingElement();
            }
            this->ajouterUV(strCode,nom,catman.getCategorie(cat));
            this->getUV(strCode).ajoutCredits(credman.getCredits(cred));
            if(cat=="TSH"){
                // Doit on l'ajouter aux formations ou on considere ça "à part" avec les mineurs?
            }
            else {
                for (unsigned int i = 0; i < tempformations.size(); i++)
                {
                    forman.getFormation(tempformations[i]->getCode()).ajouterUV(this->getUV(strCode));
                }
                tempformations.clear();
            }
        }
        racine = racine.nextSiblingElement();
  }
}

void UVManager::save()
{
    QDomDocument doc = save_xml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);

    for (map<QString,UV>::const_iterator it = uvs.begin(); it != uvs.end(); it++)
    {
        QDomElement uv = doc.createElement("uv");
        root.appendChild(uv);
        QDomElement code = doc.createElement("code");
        uv.appendChild(code);
        QDomText codeText = doc.createTextNode(it->second.getCode());
        code.appendChild(codeText);
        QDomElement nom = doc.createElement("nom");
        uv.appendChild(nom);
        QDomText nomText = doc.createTextNode(it->second.getNom());
        nom.appendChild(nomText);
        std::vector<const Credits*> tempcredits= it->second.getCredits();
        for(unsigned int i=0;i<tempcredits.size();++i){
            QDomElement credits = doc.createElement("credit");
            uv.appendChild(credits);
            QDomText creditText = doc.createTextNode(tempcredits[i]->getNom());
            credits.appendChild(creditText);
        }
        QDomElement categorie = doc.createElement("categorie");
        uv.appendChild(categorie);
        QDomText categorieText = doc.createTextNode(it->second.getCategorie().getCode());
        categorie.appendChild(categorieText);

        /*Ici si on garde le schéma, ca va être méga galere pour écrire les formations à laquelle appartiennet les uvs. c'est pour ca
         que je pense qu'il faut qu'on change. Les uvs appartiennent à des formations.  Ce chargement n'est pas fonctionnelle de ce fait
         C'est pour ça que j'ai crée un nouveau fichier pour le moment. */

    }
    QFile file( "uv.xml" );
    file.open(QIODevice::WriteOnly);
    QTextStream ts(&file);
    int indent = 2;
    doc.save(ts, indent);
}
