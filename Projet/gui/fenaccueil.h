#ifndef FENACCUEIL_H
#define FENACCUEIL_H

#include <QWidget>
#include <QStandardItemModel>
#include "applicationcomposant.h"
#include "core/Observateur.h"

namespace Ui {
class FenAccueil;
}

class FenAccueil : public QWidget, public ApplicationComposant
{
    Q_OBJECT

public:
    explicit FenAccueil(Application* a, Observateur* obs, QWidget *parent = 0);
    ~FenAccueil();

private slots:
    void on_listeDossiers_doubleClicked(const QModelIndex& index);

private:
    Ui::FenAccueil *ui;
    Observateur* observateur;
};

#endif // FENACCUEIL_H
