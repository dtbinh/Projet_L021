#ifndef FENDOSSIER_H
#define FENDOSSIER_H

#include <QWidget>
#include <QStandardItemModel>
#include <map>
#include "applicationcomposant.h"
#include "core/Observer.h"

namespace Ui {
class FenDossier;
}

class FenDossier : public QWidget, public ApplicationComposant, public Observer
{
    Q_OBJECT

public:
    explicit FenDossier(Application *a, QWidget *parent = 0);
    ~FenDossier();
    void notification(const QStringList& quoi);

private:
    Ui::FenDossier *ui;

    void remplirInscriptions();
    void remplirCreditsFormations();
    QWidget* creerCreditsFormation(const Formation& formation);
};

#endif // FENDOSSIER_H
