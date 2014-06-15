#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "applicationcomposant.h"
#include "core/Observateur.h"
#include "fenaccueil.h"
#include "fenconfiguration.h"
#include "fendossier.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public ApplicationComposant, public Observateur
{
    Q_OBJECT

public:
    explicit MainWindow(Application *a, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_menuAccueil_clicked();
    void on_menuDossiers_clicked();
    void on_menuConfiguration_clicked();
    void notification(const QString& quoi);

private:
    Ui::MainWindow *ui;
    FenAccueil* fenaccueil;
    FenConfiguration* fenconfiguration;
    FenDossier* fendossier;
};

#endif // MAINWINDOW_H
