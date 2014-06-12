#ifndef COMPLETION_H
#define COMPLETION_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Solution.h"

///
/// \enum Choix
/// \brief Différents choix pour une complétion
///
enum Choix {
    Confirmer,Refuser,Retarder,Avancer
};

class Completion : public Manager
{
Factory<Solution> solutions;
std::map <QString,Choix> choix;//Associe au code d'une solution, un choix
std::map<QString,QString> preferences; // Associe au code d'une UV une préference

public:
    Completion(const UVManager& uvman);
    Solution& getSolution(const QString& code) { return solutions.get(code); }
    const Solution& getSolution(const QString& code) const { return solutions.get(code); }
    void ajouterSolution(const QString& code) { solutions.ajouter(code, Solution()); }
    void retirerSolution(const QString& code) { solutions.retirer(code); }

    void ajouterPreference(const UVManager& uvman,const QString& codeuv, const QString& pref){
        preferences[uvman.getUV(codeuv).getCode()]=pref;}
    void retirerPreference(const UVManager& uvman,const QString& codeuv){ preferences.erase(uvman.getUV(codeuv).getCode());}
    void setPreference(const UVManager& uvman,const QString& codeuv, const QString& pref){
            preferences[uvman.getUV(codeuv).getCode()]=pref; }

    void loadPreference(const UVManager& uvman); // A appeler lors de la création d'une completion
    void savePreference(); //A Appeler a chaque ajout ou modification?
       };

#endif // COMPLETION_H
