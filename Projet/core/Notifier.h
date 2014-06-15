#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "Observer.h"

class Notifier
{
protected:
    Observer* observer;

public:
    Notifier(): observer(0) {}

    Observer* getObserver() const { return observer; }
    void setObserver(Observer* o) { observer = o; }
};


#endif // NOTIFIER_H
