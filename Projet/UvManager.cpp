#include "UvManager.h"


UVManager::UVManager():uvs(0),nbUV(0),nbMaxUV(0),modification(false){
}

UVManager::~UVManager(){
    //if (file!="") save(file);
    for(unsigned int i=0; i<nbUV; i++) delete uvs[i];
    delete[] uvs;
}

void UVManager::addItem(UV* uv){
    if (nbUV==nbMaxUV){
        UV** newtab=new UV*[nbMaxUV+10];
        for(unsigned int i=0; i<nbUV; i++) newtab[i]=uvs[i];
        nbMaxUV+=10;
        UV** old=uvs;
        uvs=newtab;
        delete[] old;
    }
    uvs[nbUV++]=uv;
}

void UVManager::ajouterUV(UV& u){
    if (trouverUV(u.getCode())) {
        throw Exception(string("erreur, UVManager, UV ")+u.getCode()+string("deja existante"));
    }else{
        UV* newuv=new UV(u);
        addItem(newuv);
        modification=true;
    }
}

UV* UVManager::trouverUV(const string& c)const{
    for(unsigned int i=0; i<nbUV; i++)
        if (c==uvs[i]->getCode()) return uvs[i];
    return 0;
}

void UVManager::affichage(){
    for(unsigned int i=0; i<nbUV; i++)
        cout<<"Manager UV "<<i<<" : "<<uvs[i]->getCode()<<endl;
}

UV& UVManager::getUV(const string& code){
    UV* uv=trouverUV(code);
    if (!uv) throw Exception("erreur, UVManager, UV inexistante");
    return *uv;
}


const UV& UVManager::getUV(const string& code)const{
    return const_cast<UVManager*>(this)->getUV(code);
}

UVManager::Handler UVManager::handler=Handler();

UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager;
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}
