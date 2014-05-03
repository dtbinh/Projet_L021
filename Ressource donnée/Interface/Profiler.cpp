#include "Profiler.h"
#include "UVEditeur.h"
#include "UTProfiler.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

Profiler::Profiler(QWidget *parent):QMainWindow(parent){
    setWindowTitle("UT-Profiler");
    QMenu* mFichier = menuBar()->addMenu("&Fichier");
    QMenu* mCharger=mFichier->addMenu("&Charger");
    QAction * actionChargerUV=mCharger->addAction("Catalogue UVs");
    mFichier->addSeparator();
QAction *actionQuitter = mFichier->addAction("&Quitter"); QMenu* mEdition = menuBar()->addMenu("&Edition"); QAction* actionUV=mEdition->addAction("&UV");
// connections
connect(actionChargerUV, SIGNAL(triggered()),this,SLOT(openChargerUV())); connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit())); connect(actionUV, SIGNAL(triggered()),this,SLOT(openUV()));
}

void Profiler::openChargerUV(){
    QString chemin = QFileDialog::getOpenFileName();
    try {
        if (chemin!="") UVManager::getInstance().load(chemin);
        QMessageBox::information(this, "Chargement Catalogue", "Le catalogue d’UVs a été chargé.");
        }
        catch(UTProfilerException& e){
            QMessageBox::warning(this, "Chargement Catalogue", "Erreur lors du chargement du fichier (non valide ?)");
    }}
void Profiler::openUV(){
    QString code=QInputDialog::getText(this,"Entrez le code de l’UV à éditer","UV");
    if (code!="")
    try {
        UV& uv=UVManager::getInstance().getUV(code); UVEditeur* fenetre=new UVEditeur(uv,this); setCentralWidget(fenetre);
    }catch(UTProfilerException& e){QMessageBox::warning(this, "Edition UV", QString("Erreur : l’UV ")+code+" n’existe pas.");
} }
