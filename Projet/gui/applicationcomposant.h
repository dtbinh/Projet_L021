#ifndef APPLICATIONCOMPOSANT_H
#define APPLICATIONCOMPOSANT_H

#include <map>
#include "core/Application.h"

class ApplicationComposant
{
public:
    ApplicationComposant(Application* a): app(a) {}

protected:
    Application* app;
};

#endif // APPLICATIONCOMPOSANT_H
