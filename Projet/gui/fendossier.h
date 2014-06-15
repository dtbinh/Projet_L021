#ifndef FENDOSSIER_H
#define FENDOSSIER_H

#include <QWidget>
#include "applicationcomposant.h"

namespace Ui {
class FenDossier;
}

class FenDossier : public QWidget, public ApplicationComposant
{
    Q_OBJECT

public:
    explicit FenDossier(Application *a, QWidget *parent = 0);
    ~FenDossier();

private:
    Ui::FenDossier *ui;
};

#endif // FENDOSSIER_H
