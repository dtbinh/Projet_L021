#ifndef FENACCUEIL_H
#define FENACCUEIL_H

#include <QWidget>
#include <QStandardItemModel>
#include "applicationcomposant.h"
#include "core/Observer.h"

namespace Ui {
class FenAccueil;
}

class FenAccueil : public QWidget, public ApplicationComposant
{
    Q_OBJECT

public:
    explicit FenAccueil(Application* a, Observer* obs, QWidget *parent = 0);
    ~FenAccueil();

private slots:
    void on_listeDossiers_doubleClicked(const QModelIndex& index);
    void on_creer_clicked();

private:
    Ui::FenAccueil *ui;
    Observer* mainwindow;

    void remplirListeDossiers();
};

#endif // FENACCUEIL_H
