#include "Dossier.h"

using namespace std;

void Dossier::setLogin()
{
    if (nom != "" && prenom != "" && nom.size() >= 7)
    {
        login = prenom.at(0);
        for (int j=0; j<7; j++) {
            login += nom.at(j);
        }
    }
    else if (nom != "" && prenom != "" && (nom.size() + prenom.size()) >= 8)
    {
        login = nom;
        for (int i=0; i<8-nom.size(); i++)
            login += prenom.at(i);
    }
    else {
        login = nom + prenom;
    }

    //login.toLower();
}

void Dossier::charger(const FormationManager& forman,const PeriodeManager& periodeman,const UVManager& uvman,const NoteManager& notman)
{
    QDomDocument doc = this->chargerXml(chemin_fichier + "/" + fichier);
    QDomElement racine = doc.documentElement();

    std::vector<const Formation*> tempformations;
    std::vector<Inscription> tempinscriptions;
    Factory<UV> tempuvs;
    std::map<QString,Note> tempnotes;
    QString tempForma = "NULL", tempInscri = "NULL";

    if(racine.tagName() == "dossier")
    {
        QString tempNom, tempPrenom, tempFormation, tempUv, tempNote, code;
        QDomElement unElement = racine.firstChildElement();

        while(!unElement.isNull())
        {
            if(unElement.tagName() == "nom")
            {
                tempNom = unElement.text();
            }
            else if(unElement.tagName() == "prenom")
            {
                tempPrenom = unElement.text();
            }
            else if(unElement.tagName() == "formations")
            {
                tempForma = unElement.text();
                tempformations.push_back(&forman.getFormation(tempForma));
            }
            else if(unElement.tagName() == "inscription")
            {
                QDomElement filsElement = unElement.firstChildElement();
                while(!filsElement.isNull())
                {
                    if(filsElement.tagName()=="code"){
                        code = filsElement.text();
                    }
                    else if(filsElement.tagName()=="semestre"){
                        tempInscri = filsElement.text();
                    }
                    else if(filsElement.tagName() =="formation"){
                        tempFormation = filsElement.text();
                    }
                    else if(filsElement.tagName() == "uv")
                    {
                        QDomElement filsUV = filsElement.firstChildElement();
                        while(!filsUV.isNull())
                        {
                            if(filsUV.tagName() == "codeUV"){
                                tempUv = filsUV.text();
                                tempuvs.ajouter(tempUv,uvman.getUV(tempUv));
                            }
                            if(filsUV.tagName() == "note"){
                                tempNote = filsUV.text();
                                tempnotes[tempUv] = notman.getNote(tempNote);
                            }
                            filsUV = filsUV.nextSiblingElement();
                        }
                    }
                filsElement = filsElement.nextSiblingElement();
                }
                Inscription temp(code,periodeman.getPeriode(tempInscri),forman.getFormation(tempFormation));
                tempinscriptions.push_back(temp);
            }
            unElement = unElement.nextSiblingElement();
        }

        this->setLogin();
        this->setNom(tempNom);
        this->setPrenom(tempPrenom);
        this->setLogin();
        if (tempForma != "NULL")
        {
            for (unsigned int i = 0; i < tempformations.size(); i++)
            {
               ajouterFormation(*tempformations[i]);
            }
            tempformations.clear();
            tempForma = "NULL";
        }
        if (tempInscri!="NULL")
        {
            for(unsigned int i=0; i < tempinscriptions.size(); i++)
            {
                ajouterInscription(tempinscriptions[i].getCode(),tempinscriptions[i].getPeriode(),tempinscriptions[i].getFormation());
                for (map<QString,UV>::iterator it = tempuvs.begin(); it != tempuvs.end(); it++)
                {
                    getInscription(tempinscriptions[i].getCode()).ajouterUV(it->second.getCode());
                    getInscription(tempinscriptions[i].getCode()).
                    modifierNote(it->second.getCode(),tempnotes.find(it->second.getCode())->second.getNote());
                }
            }
            tempinscriptions.clear();
            tempInscri="NULL";
         }
    }
}

void Dossier::sauvegarder()
{
    QDomDocument doc = this->creerXml();

    QDomElement root = doc.createElement("dossier");
    doc.appendChild(root);

    QDomElement nom = doc.createElement("nom");
    root.appendChild(nom);
    QDomText nomText = doc.createTextNode(this->getNom());
    nom.appendChild(nomText);

    QDomElement prenom = doc.createElement("prenom");
    root.appendChild(prenom);
    QDomText prenomText = doc.createTextNode(this->getPrenom());
    prenom.appendChild(prenomText);

    Factory<Formation> tempformation = getFormations();
    for(map<QString,Formation>::const_iterator it = tempformation.begin(); it != tempformation.end(); it++)
    {
        QDomElement formation = doc.createElement("formations");
        root.appendChild(formation);
        QDomText formationText = doc.createTextNode(it->second.getCode());
        formation.appendChild(formationText);
    }

    Factory<Inscription> tempinscription= getInscriptions();
    for(map<QString,Inscription>::const_iterator it = tempinscription.begin(); it != tempinscription.end(); it++)
    {
        QDomElement inscription = doc.createElement("inscription");
        root.appendChild(inscription);

        QDomElement codeinscription=doc.createElement("code");
        inscription.appendChild(codeinscription);

        QDomText codeText = doc.createTextNode(it->second.getCode());
        codeinscription.appendChild(codeText);

        QDomElement semestreinscription = doc.createElement("semestre");
        inscription.appendChild(semestreinscription);

        QDomText inscriptionText = doc.createTextNode(it->second.getPeriode().getCode());
        semestreinscription.appendChild(inscriptionText);

        QDomElement formation = doc.createElement("formation");
        inscription.appendChild(formation);

        QDomText formationText = doc.createTextNode(it->second.getFormation().getCode());
        formation.appendChild(formationText);

        Factory<UV> tempUV = it->second.getUVs();
        for (map<QString,UV>::const_iterator ituv = tempUV.begin(); ituv != tempUV.end(); ituv++)
        {
            QDomElement uv = doc.createElement("uv");
            inscription.appendChild(uv);
            QDomElement codeuv = doc.createElement("codeUV");
            uv.appendChild(codeuv);
            QDomText uvText = doc.createTextNode(ituv->second.getCode());
            codeuv.appendChild(uvText);
            QDomElement note = doc.createElement("note");
            uv.appendChild(note);
            QDomText notetext = doc.createTextNode(it->second.getNotes().get(ituv->second.getCode()).getNote());
            note.appendChild(notetext);
         }
    }

    this->sauvegarderXml(chemin_fichier + "/" + fichier, doc);
}

void Dossier::vider()
{
    formations.vider();
    inscriptions.vider();
    nom = "";
    prenom = "";
    login = "";
    chemin_fichier = "";
    fichier = "";
}
