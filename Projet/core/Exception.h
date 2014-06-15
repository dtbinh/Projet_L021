///
/// \file Exception.h
/// \brief Implémentation concrète de l'exception.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <QString>

///
/// \class Exception
/// \brief Gestion des exceptions dans l'application
///
class Exception : public std::exception
{
protected :
    QString info;

public:
    ///
    /// \fn Exception
    /// \brief Constructeur de la classe Exception
    /// \param i Message d'erreur a transmettre
    ///
    Exception(const QString& i = "") throw() : info(i) {}
    ~Exception() throw() {}

    ///
    /// \fn what
    /// \return  const char* -> Le texte de l'erreur
    ///
    const char* what() const throw() { return info.toStdString().c_str(); }
};

#endif // EXCEPTION_H
