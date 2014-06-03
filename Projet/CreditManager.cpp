#include "CreditManager.h"

using namespace std;

CreditManager::CreditManager():credit(0),nbCredit(0),nbMaxCredit(0),modification(false){
}

CreditManager::~CreditManager(){
    for(unsigned int i=0; i<nbCredit; i++) delete credit[i];
    delete[] credit;
}

void CreditManager::addItem(Credits* c){
    if (nbCredit==nbMaxCredit){
        Credits** newtab=new Credits*[nbMaxCredit+10];
        for(unsigned int i=0; i<nbCredit; i++) newtab[i]=credit[i];
        nbMaxCredit+=10;
        Credits** old=credit;
        credit=newtab;
        delete[] old;
    }
    credit[nbCredit++]=c;
}

void CreditManager::ajouterCredit(Credits& c){
    if (trouverCredit(c.getCode())) {
        throw Exception(string("erreur, CreditManager, Credit : ")+c.getCode().toStdString()+string("deja existant"));
    }else{
        Credits* newcredit=new Credits(c);
        addItem(newcredit);
        modification=true;
    }
}

Credits* CreditManager::trouverCredit(const QString& c)const{
    for(unsigned int i=0; i<nbCredit; i++)
        if (c==credit[i]->getCode()) return credit[i];
    return 0;
}

void CreditManager::affichage(){
    for(unsigned int i=0; i<nbCredit; i++)
        cout<<"Manager Credit "<<i<<" : "<<credit[i]->getCode().toStdString()<<endl;
}

Credits& CreditManager::getCredit(const QString& code){
    Credits* c=trouverCredit(code);
    if (!c) throw Exception("erreur, CreditManager, Credit inexistant");
    return *c;
}


const Credits& CreditManager::getCredit(const QString& code)const{
    return const_cast<CreditManager*>(this)->getCredit(code);
}

CreditManager::Handler CreditManager::handler=Handler();

CreditManager& CreditManager::getInstance(){
    if (!handler.instance) handler.instance = new CreditManager;
    return *handler.instance;
}

void CreditManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}
