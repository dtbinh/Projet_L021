#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "applicationcomposant.h"
#include "accueil.h"
#include "configuration.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public ApplicationComposant
{
    Q_OBJECT

public:
    explicit MainWindow(Application *a, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_menuDossiers_clicked();
    void on_menuConfiguration_clicked();

private:
    Ui::MainWindow *ui;
    Accueil *accueil;
    Configuration *configuration;
};

#endif // MAINWINDOW_H
