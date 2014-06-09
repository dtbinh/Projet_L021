#ifndef COMPLETION_H
#define COMPLETION_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Solution.h"

///
/// \enum Preference
/// \brief Un étudiant peut donner une préférence quand à la volonté de faire une UV ou non
///
enum Preference{
    Exigence,Refus,NSP
};

///
/// \enum Choix
/// \brief Différents choix pour une complétion
///
enum Choix {
    Confirmer,Refuser,Retarder,Avancer
};

class Completion :public Manager
{
Factory<Solution> solutions;
std::map <QString,Choix> choix;//Associe au code d'une solution, un choix
std::map<QString,Preference> preferences; // Associe au code d'une UV une préference

public:
    Completion(const UVManager& uvman);
    Solution& getSolution(const QString& code) { return solutions.get(code); }
    const Solution& getSolution(const QString& code) const { return solutions.get(code); }
    void ajouterSolution(const QString& code) { solutions.ajouter(code, Solution()); }
    void retirerSolution(const QString& code) { solutions.retirer(code); }
};

#endif // COMPLETION_H
