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
    explicit FenDossier(Application *a, Observer* obs, QWidget *parent = 0);
    ~FenDossier();
    void notification(const QStringList& quoi);

private slots:
    void on_inscriptions_clicked(const QModelIndex& index);
    void on_ajouterInscription_clicked();

private:
    Ui::FenDossier *ui;
    Observer* mainwindow;

    void remplirInscriptions();
    void remplirCreditsFormations();
    QWidget* creerCreditsFormation(const Formation& formation);
};

#endif // FENDOSSIER_H
