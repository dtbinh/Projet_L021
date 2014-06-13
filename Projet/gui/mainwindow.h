#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "applicationcomposant.h"
#include "accueil.h"
#include "configuration.h"
//#include "menuconfiguration.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public applicationcomposant
{
    Q_OBJECT

public:
    explicit MainWindow(Application *a, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_menuBoutonDossiers_clicked();
    void on_menuBoutonConfiguration_clicked();

private:
    Ui::MainWindow *ui;
    Accueil *accueil;
    Configuration *configuration;
    //MenuConfiguration *menuconfiguration;
};

#endif // MAINWINDOW_H
