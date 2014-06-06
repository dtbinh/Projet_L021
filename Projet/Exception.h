///
/// \file Exception.h
/// \brief Implémentation concrète de l'exception.
/// \author Erwan Normand
/// \date 05 juin 2014
///

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <QString>

class Exception : public std::exception
{
protected :
    QString info;

public:
    Exception(const QString& i = "") throw() : info(i) {}
    ~Exception() throw() {}
    const char* what() const throw() { return info.toStdString().c_str(); }
};

#endif // EXCEPTION_H
