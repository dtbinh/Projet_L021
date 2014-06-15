#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include <QString>

///
/// \class Observer
/// \brief Design pattern Observer.
///
class Observer
{
public:
    ///
    /// \fn Observer
    /// \brief Constructeur d'Observer. Permet la communication entre deux classes
    ///
    Observer() {}

    ///
    /// \fn notification
    /// \brief Transmet le message à la classe
    /// \param quoi
    ///
    virtual void notification(const QStringList& quoi) = 0;
};

#endif // OBSERVATEUR_H
