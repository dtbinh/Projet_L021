///
/// \file Completion.h
/// \brief Completion automatique.
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef COMPLETION_H
#define COMPLETION_H

#include <QString>
#include <QtXml>
#include "Application.h"
#include "Factory.h"
#include "Solution.h"
#include "Manager.h"
#include "Dossier.h"

class Completion : public Manager
{
std::vector<Solution> solutions;
std::map<QString,QString> preferences; // Associe au code d'une UV une préference

public:
    Completion(const UVManager& uvman);
    Completion();
    void ajouterSolution(const Dossier& D,const CategorieManager& catman,const UVManager& uvman,const NoteManager& notman,bool activation);
    //void retirerSolution(const QString& code) {solutions.erase(find(code));}

    void sauvegarderSolution();
    void chargerSolution(const UVManager& uvman);
    void affichageSolution();

    const std::map<QString,QString>& getPreferences() const { return preferences; }
    void ajouterPreference(const QString& codeuv, const QString& pref){
        preferences[codeuv]=pref;}
    void retirerPreference(const QString& codeuv){ preferences.erase(codeuv);}
    void setPreference(const UVManager& uvman,const QString& codeuv, const QString& pref){
            preferences[uvman.getUV(codeuv).getCode()]=pref; }

    void chargerPreference(); // A appeler lors de la création d'une completion
    void sauvegarderPreference();
       };

#endif // COMPLETION_H
