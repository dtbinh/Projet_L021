#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include <QString>

class Observer
{
public:
    Observer() {}
    virtual void notification(const QStringList& quoi) = 0;
};

#endif // OBSERVATEUR_H
