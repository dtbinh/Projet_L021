#include "DossierManager.h"

using namespace std;

void DossierManager::load(const QString& fichier, const FormationManager& forman,const PeriodeManager& periodeman,const UVManager& uvman,const NoteManager& notman)
{
    std::vector<const Formation*> tempformations;
    std::vector<const Inscription*> tempinscriptions;
    Factory<UV> tempuvs;
    std::map<QString,Note> tempnotes;
    QString tempForma="NULL"; QString tempInscri="NULL";
    QDomDocument doc = this->load_xml(fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "dossier")
        {
            QString tempNom, tempPrenom,tempFormation,tempUv,tempNote,code;
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
                else if(unElement.tagName() == "formations"){
                    tempForma = unElement.text();
                    tempformations.push_back(&forman.getFormation(tempForma));
                }
                else if(unElement.tagName() == "inscription"){
                    QDomElement filsElement = unElement.firstChildElement();
                    while(!filsElement.isNull())
                    {
                    if(filsElement.tagName()=="code"){
                        code=filsElement.text();
                    }
                    else if(filsElement.tagName()=="semestre"){
                        tempInscri=filsElement.text();
                    }
                    else if(filsElement.tagName() =="formation"){
                        tempFormation=filsElement.text();
                    }
                    else if(filsElement.tagName() == "uv"){
                        QDomElement filsUV=filsElement.firstChildElement();
                        while(!filsUV.isNull()){
                            if(filsUV.tagName()=="codeUV"){
                                tempUv=filsUV.text();
                                tempuvs.ajouter(tempUv,uvman.getUV(tempUv));
                            }
                            if(filsUV.tagName()=="note"){
                                tempNote=filsUV.text();
                                tempnotes[tempUv]=notman.getNote(tempNote);
                            }
                            filsUV=filsUV.nextSiblingElement();
                        }
                    }
                    filsElement= filsElement.nextSiblingElement();
                    }
                    Inscription temp (code,periodeman.getPeriode(tempInscri),forman.getFormation(tempFormation));
                    tempinscriptions.push_back(&temp); // Probleme ici ca ecrase les inscriptions precedentes
                }
                unElement = unElement.nextSiblingElement();

            }
            QString login=this->ajouterDossier(tempNom,tempPrenom);
            if (tempForma!="NULL"){
                for (unsigned int i = 0; i < tempformations.size(); i++)
                {
                   this->getDossier(login).ajouterFormation(*tempformations[i]);
                }
                tempformations.clear();
                tempForma="NULL";
            }
            if (tempInscri!="NULL"){
                for(unsigned int i=0; i < tempinscriptions.size(); i++){
                    this->getDossier(login).ajouterInscription(tempinscriptions[i]->getCode(),tempinscriptions[i]->getPeriode(),
                                                                                                    tempinscriptions[i]->getFormation());
                    for (map<QString,UV>::iterator it = tempuvs.begin(); it != tempuvs.end(); it++)
                    {
                        this->getDossier(login).getInscription(tempinscriptions[i]->getCode()).ajouterUV(it->second.getCode());
                        this->getDossier(login).getInscription(tempinscriptions[i]->getCode()).
                        modifierNote(it->second.getCode(),tempnotes.find(it->second.getCode())->second.getNote());
                    }
                }
                tempinscriptions.clear();
                tempInscri="NULL";
             }
        }
        racine = racine.nextSiblingElement();
    }
}

void DossierManager::save()
{
    for(map<QString,Dossier>::const_iterator it = dossiers.begin(); it != dossiers.end(); ++it)
    {
        save(it->second.getLogin());
    }
}

void DossierManager::save(const QString& login)
{
    QDomDocument doc = this->create_xml();
    QDomElement root = doc.createElement("dossiers");
    doc.appendChild(root);
    QDomElement dossier = doc.createElement("dossier");
    root.appendChild(dossier);
    QDomElement nom = doc.createElement("nom");
    dossier.appendChild(nom);
    QDomText nomText = doc.createTextNode(this->getDossier(login).getNom());
    nom.appendChild(nomText);
    QDomElement prenom = doc.createElement("prenom");
    dossier.appendChild(prenom);
     QDomText prenomText = doc.createTextNode(this->getDossier(login).getPrenom());
    prenom.appendChild(prenomText);
    Factory<Formation> tempformation= this->getDossier(login).getFormations();
    for(map<QString,Formation>::const_iterator it = tempformation.begin(); it != tempformation.end(); it++)
    {
        QDomElement formation = doc.createElement("formations");
        dossier.appendChild(formation);
        QDomText formationText = doc.createTextNode(it->second.getCode());
        formation.appendChild(formationText);
    }
    Factory<Inscription> tempinscription= this->getDossier(login).getInscriptions();
    for(map<QString,Inscription>::const_iterator it = tempinscription.begin(); it != tempinscription.end(); it++)
    {
        QDomElement inscription = doc.createElement("inscription");
        dossier.appendChild(inscription);
        QDomElement codeinscription=doc.createElement("code");
        inscription.appendChild(codeinscription);
        QDomText codeText = doc.createTextNode(it->second.getCode());
        codeinscription.appendChild(codeText);
        QDomElement semestreinscription=doc.createElement("semestre");
        inscription.appendChild(semestreinscription);
        QDomText inscriptionText = doc.createTextNode(it->second.getPeriode().getCode());
        semestreinscription.appendChild(inscriptionText);
        QDomElement formation = doc.createElement("formation");
        inscription.appendChild(formation);
        QDomText formationText=doc.createTextNode(it->second.getFormation().getCode());
        formation.appendChild(formationText);
        Factory<UV> tempUV= it->second.getUVs();
        for (map<QString,UV>::const_iterator ituv = tempUV.begin(); ituv != tempUV.end(); ituv++)
        {
            QDomElement uv= doc.createElement("uv");
            inscription.appendChild(uv);
            QDomElement codeuv=doc.createElement("codeUV");
            uv.appendChild(codeuv);
            QDomText uvText=doc.createTextNode(ituv->second.getCode());
            codeuv.appendChild(uvText);
            QDomElement note=doc.createElement("note");
            uv.appendChild(note);
            QDomText notetext=doc.createTextNode(it->second.getNotes().get(ituv->second.getCode()).getNote());
            note.appendChild(notetext);
         }
    }

    QString fichier = login + ".xml";
    this->save_xml(fichier, doc);
}
