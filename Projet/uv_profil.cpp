#include "uv_profil.h"

void UV::AffichageUV(){
    cout<<code<<"---"<<nom<<"---"<<description<<endl;
    cout<<" Credits : "<<cred.GetNombre()<<" "<<cat.GetCode()<<endl;
    if (prerequis!=0)
        cout<<"Prerequis : "<<prerequis->GetCode()<<endl;
}
