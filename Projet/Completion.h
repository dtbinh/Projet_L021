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

class Completion
{
Factory<Solution> solutions; //il faut associer un choix
std::map<Preference,UV> preferences; // Il faut associer une preference

public:
    Completion();
};

#endif // COMPLETION_H
