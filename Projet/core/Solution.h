///
/// \file Solution.h
/// \brief Objet Solution, construit une completion automatique
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef SOLUTION_H
#define SOLUTION_H

#include <QString>
#include <QtXml>
#include <map>
#include "Application.h"
#include "Factory.h"
#include "Dossier.h"

///
/// \class Solution
/// \brief Solution correspond à une complétion automatique. Elle recherche les UVs qu'un étudiant doit choisir en fonction de son dossier
///
class Solution
{
    QString choix;
    std::vector<UV> strategie;
public:
    ///
    /// \fn Solution
    /// \brief Constructeur d'une Solution.
    /// \param D Reference vers le dossier sur lequel la solution doit etre calculée
    /// \param catman Reference vers le manager des categories
    /// \param preferences Les préférences d'un utilisateur
    /// \param uvman Reference vers le manager des uvs.
    /// \param notman Reference vers le manager des notes.
    /// \param activation Bool qui determine si les préferences doivent etre prise en compte ou non
    ///
    Solution(const Dossier& D,const CategorieManager& catman,std::map <QString,QString> preferences,const UVManager& uvman,const NoteManager& notman,bool activation);

    ///
    /// \fn Solution
    /// \brief Constructeur par défault de la classe Solution
    ///
    Solution(){}

    ///
    /// \fn getChoix
    /// \brief Pour acceder au choix de l'utilisateur concernant une solution
    /// \return const QString& -> Choix sur la solution
    ///
    const QString& getChoix()const {return choix;}

    ///
    /// \fn setChoix
    /// \brief Pour modifier le choix d'une solution
    /// \param c Nouveau choix pour la solution
    ///
    void setChoix(QString c) {choix=c;}

    ///
    /// \fn getStrategie
    /// \brief Pour acceder à la strategie d'une solution. La strategie est une liste d'uv à choisir
    /// \return const std::vector<UV>& -> Liste d'uv à choisir
    ///
    const std::vector<UV>& getStrategie() const {return strategie;}

    ///
    /// \fn ajouterUVStrategie
    /// \brief Pour ajouter une UV dans une strategie.
    /// \param u Reférence sur l'UV a ajouter
    ///
    void ajouterUVStrategie(const UV& u){strategie.push_back(u);}

    ///
    /// \fn affichage
    /// \brief Affichage d'une solution particulière
    ///
    void affichage()const;

};

#endif // SOLUTION_H
