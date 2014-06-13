#ifndef APPLICATIONCOMPOSANT_H
#define APPLICATIONCOMPOSANT_H

#include <map>
#include "core/Application.h"

class applicationcomposant
{
public:
    applicationcomposant(Application* a): app(a) {}

protected:
    Application* app;
};

#endif // APPLICATIONCOMPOSANT_H
