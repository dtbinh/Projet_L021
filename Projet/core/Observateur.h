#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include <QString>

class Observateur
{
public:
    Observateur() {}
    virtual void notification(const QString& quoi) = 0;
};

#endif // OBSERVATEUR_H
