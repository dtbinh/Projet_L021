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

///
/// \class Completion
/// \brief La completion se compose d'un ensemble de solutions de completion et des préferences de l'utilisateursau
///
class Completion : public Manager
{
    QString fichier_preferences;
    std::vector<Solution> solutions;
    std::map<QString,QString> preferences; // Associe au code d'une UV une préference

public:
    ///
    /// \fn Completion
    /// \brief Constructeur du completion
    /// \param uvman Manager des uvs
    ///
    Completion(const QString& cf,const QString& f, const UVManager& uvman);

    ///
    /// \fn Completion
    /// \brief Constructeur par défault
    ///
    Completion();

    ///
    /// \fn ajouterSolution
    /// \brief Pour ajouter une solution de completion.
    /// \param D Reference vers le dossier sur lequel doit etre effectué la completion
    /// \param catman Reference sur le categorie manager
    /// \param uvman Reference sur l'UV Manager
    /// \param notman Reference sur le Manag
    /// \param activation Booléen pour savoir si l'utilisateur veut activer ses préférences ou non
    ///
    void ajouterSolution(const Dossier& D,const CategorieManager& catman,const UVManager& uvman,const NoteManager& notman,bool activation);

    ///
    /// \fn sauvegarderSolution
    /// \brief Sauvegarde une solution dans un fichier xml
    ///
    void sauvegarderSolution();

    ///
    /// \fn chargerSolution
    /// \brief Charger les solutions existantes
    /// \param uvman Le manager d'UV
    ///
    void chargerSolution(const UVManager& uvman);

    ///
    /// \fn affichageSolution
    /// \brief Affichage d'une solution
    ///
    void affichageSolution();

    ///
    /// \fn getPreferences
    /// \brief Methode pour récuperer les préférences d'un utilisateur
    /// \return const std::map<QString,QString>& -> L'ensemble des préférences d'un utilisateur
    ///
    const std::map<QString,QString>& getPreferences() const { return preferences; }

    ///
    /// \fn ajouterPreference
    /// \brief Methode pour ajouter une préférence dans l'ensemble des préférences
    /// \param codeuv Code de l'UV sur lequel l'utilisateur souhaite emettre une préférence
    /// \param pref Préférence a stocker
    ///
    void ajouterPreference(const QString& codeuv, const QString& pref){
        preferences[codeuv]=pref;}

    ///
    /// \fn retirerPreference
    /// \brief Pour retirer une préférence de l'ensemble des préférences
    /// \param codeuv
    ///
    void retirerPreference(const QString& codeuv){ preferences.erase(codeuv);}

    ///
    /// \fn setPreference
    /// \brief Pour modifier une préférence de l'ensemble des préférences
    /// \param uvman Manager d'UV
    /// \param codeuv Le code de l'UV dont on doit modifier la préférence
    /// \param pref La nouvelle préférence
    ///
    void setPreference(const UVManager& uvman,const QString& codeuv, const QString& pref){
        preferences[uvman.getUV(codeuv).getCode()]=pref; }

    ///
    /// \fn chargerPreference
    /// \brief Charger le fichier xml de préférence
    void chargerPreference();

    ///
    /// \fn sauvegarderPreference
    /// \brief Sauvegarder dans un fichier xml des préférences
    ///
    void sauvegarderPreference();
};

#endif // COMPLETION_H
