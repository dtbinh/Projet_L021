#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include "applicationcomposant.h"

namespace Ui {
class Accueil;
}

class Accueil : public QWidget, public applicationcomposant
{
    Q_OBJECT

public:
    explicit Accueil(Application *a, QWidget *parent = 0);
    ~Accueil();

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H
