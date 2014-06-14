#ifndef COMPLETION_H
#define COMPLETION_H

#include <QString>
#include <QtXml>
#include "Application.h"
#include "Factory.h"
#include "Solution.h"
#include "Manager.h"
#include "Dossier.h"

///
/// \enum Choix
/// \brief Différents choix pour une complétion
///
enum Choix {
    Confirmer,Refuser
};


class Completion : public Manager
{
std::vector<Solution> solutions;
std::map<QString,QString> preferences; // Associe au code d'une UV une préference

public:
    Completion(const UVManager& uvman);
    Completion();
    void ajouterSolution(const Dossier& D,const CategorieManager& catman,const UVManager& uvman,bool activation);
    //void retirerSolution(const QString& code) {}

    //void saveSolution(); //Utiliser dans ajouterSolution, car on demandera à l'utilisateur si il l'accepte ou non. Si il accepte on sauvegarde
    //void loadSolution(); //Utiliser dans a la creation d'une completion
    void affichageSolution(); // Pour consulter des solutions déja existantes

    const std::map<QString,QString>& getPreferences() const { return preferences; }
    void ajouterPreference(const QString& codeuv, const QString& pref){
        preferences[codeuv]=pref;}
    void retirerPreference(const QString& codeuv){ preferences.erase(codeuv);}
    void setPreference(const UVManager& uvman,const QString& codeuv, const QString& pref){
            preferences[uvman.getUV(codeuv).getCode()]=pref; }

    void loadPreference(); // A appeler lors de la création d'une completion
    void savePreference();
       };

#endif // COMPLETION_H
