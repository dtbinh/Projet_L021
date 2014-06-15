#include "Solution.h"

void Solution::affichage() const{
    for(unsigned int i=0; i < strategie.size();i++){
        std::cout<<strategie[i].getCategorie().getCode().toStdString()<<" : "<<strategie[i].getCode().toStdString()<<std::endl;
    }
}

Solution::Solution(const Dossier& D,const CategorieManager& catman, std::map<QString,QString> preferences,const UVManager& uvman,const NoteManager& notman,bool activation)
{
    choix="Refus";
    Credits CS_Besoin("CS_Besoin",0,catman.getCategorie("CS"));
    Credits TM_Besoin("TM_Besoin",0,catman.getCategorie("TM"));
    Credits TSH_Besoin("TSH_Besoin",0,catman.getCategorie("TSH"));
    Credits SP_Besoin("SP_Besoin",0,catman.getCategorie("SP"));
    std::vector<Credits> cred_doss=D.getCredits(catman);
    Factory <Formation> form=D.getFormations();
    for (std::map<QString,Formation>::const_iterator f=form.begin(); f!=form.end();f++){
        const std::vector<const Credits*> cred_forma=f->second.getCredits();
                for (unsigned int i=0;i<cred_forma.size();i++)
                {
                    if(cred_forma[i]->getCategorie().getCode()=="CS"){
                        CS_Besoin.setNombre(CS_Besoin.getNombre()+cred_forma[i]->getNombre());
                    }
                    else if (cred_forma[i]->getCategorie().getCode()=="TM"){
                        TM_Besoin.setNombre(TM_Besoin.getNombre()+cred_forma[i]->getNombre());
                    }
                    else if(cred_forma[i]->getCategorie().getCode()=="TSH"){
                        TSH_Besoin.setNombre(TSH_Besoin.getNombre()+cred_forma[i]->getNombre());
                    }
                    else if(cred_forma[i]->getCategorie().getCode()=="SP"){
                        SP_Besoin.setNombre(SP_Besoin.getNombre()+cred_forma[i]->getNombre());
                    }

                }
    }

    for (unsigned int i=0;i<cred_doss.size();i++)
{
        if(cred_doss[i].getCategorie().getCode()=="CS"){
            CS_Besoin.setNombre(CS_Besoin.getNombre()-cred_doss[i].getNombre());
        }
        else if (cred_doss[i].getCategorie().getCode()=="TM"){
            TM_Besoin.setNombre(TM_Besoin.getNombre()-cred_doss[i].getNombre());
        }
        else if(cred_doss[i].getCategorie().getCode()=="TSH"){
            TSH_Besoin.setNombre(TSH_Besoin.getNombre()-cred_doss[i].getNombre());
        }
        else if(cred_doss[i].getCategorie().getCode()=="SP"){
            SP_Besoin.setNombre(SP_Besoin.getNombre()-cred_doss[i].getNombre());
        }
}
   std::cout<<"IL te reste a valider  : "<<std::endl;
    std::cout<<"Credit "<<CS_Besoin.getCategorie().getCode().toStdString()<<"  "<<CS_Besoin.getNombre()<<std::endl;
    std::cout<<"Credit "<<TM_Besoin.getCategorie().getCode().toStdString()<<"  "<<TM_Besoin.getNombre()<<std::endl;
    std::cout<<"Credit "<<TSH_Besoin.getCategorie().getCode().toStdString()<<"  "<<TSH_Besoin.getNombre()<<std::endl;
    std::cout<<"Credit "<<SP_Besoin.getCategorie().getCode().toStdString()<<"  "<<SP_Besoin.getNombre()<<std::endl;
    std::cout<<std::endl<<std::endl;

    if (activation==true){

    for (std::map<QString,QString>::const_iterator it = preferences.begin(); it != preferences.end(); it++)
    {
        if (TM_Besoin.getNombre() >0 && CS_Besoin.getNombre() >0 && TSH_Besoin.getNombre() >0 && SP_Besoin.getNombre() >0){
            if(it->second=="Exigence"){
                if(uvman.getUV(it->first).getCategorie().getCode()=="CS"){
                    strategie.push_back(uvman.getUV(it->first));
                    for(unsigned int j=0;j<uvman.getUV(it->first).getCredits().size();j++){
                        CS_Besoin.setNombre(CS_Besoin.getNombre()-uvman.getUV(it->first).getCredits()[j]->getNombre());

                }}
                if(uvman.getUV(it->first).getCategorie().getCode()=="TM"){
                        strategie.push_back(uvman.getUV(it->first));
                        for(unsigned int j=0;j<uvman.getUV(it->first).getCredits().size();j++){
                        TM_Besoin.setNombre(TM_Besoin.getNombre()-uvman.getUV(it->first).getCredits()[j]->getNombre());

                    }
                }
                 if(uvman.getUV(it->first).getCategorie().getCode()=="TSH"){
                      strategie.push_back(uvman.getUV(it->first));
                      for(unsigned int j=0;j<uvman.getUV(it->first).getCredits().size();j++){
                         TSH_Besoin.setNombre(TSH_Besoin.getNombre()-uvman.getUV(it->first).getCredits()[j]->getNombre());

                        }}

        }
    }
    }
    }
    std::vector<const UV*> uvbranche;
    for (std::map<QString,Formation>::iterator f=form.begin(); f!=form.end();f++)
                for(unsigned int i=0;i<f->second.getUVs().size();i++){
                    uvbranche.push_back(f->second.getUVs()[i]);

}
    bool temp;
    for (unsigned int i=0; i <uvbranche.size();i++){
            temp=true;
            for (std::map<QString,Inscription>::const_iterator ins = D.getInscriptions().begin(); ins!=D.getInscriptions().end();ins++) {
                const Factory<Note> tempnotes=ins->second.getNotes();
                for(std::map<QString,UV>::const_iterator it = ins->second.getUVs().begin(); it != ins->second.getUVs().end(); it++){
                    if (temp==false) {}
                    else if(uvbranche[i]->getCode()==it->second.getCode()){
                        QString t=tempnotes.get(it->second.getCode()).getNote();
                        if(t=="A" ||t=="B" || t=="C" ||t=="D"||t=="E")
                            temp=false;
                     }
                     else temp=true;
                }
}
        if (temp==true) {

            if (activation==true){
            if(preferences.count(uvbranche[i]->getCode())!=0){
                if(preferences[uvbranche[i]->getCode()]=="Refus"){
                    i++;
            }}
            }
            if(uvbranche[i]->getCategorie().getCode()=="CS" && CS_Besoin.getNombre() >0){
                for(unsigned int j=0;j<uvbranche[i]->getCredits().size();j++){
                        if(uvbranche[i]->getCredits()[j]->getCategorie().getCode()=="CS"){
                            strategie.push_back(*uvbranche[i]);
                            CS_Besoin.setNombre(CS_Besoin.getNombre()-uvbranche[i]->getCredits()[j]->getNombre());
               }}}
            /*else if(uvbranche[i]->getCategorie().getCode()=="TSH"){
                 for(unsigned int j=0;j<uvbranche[i]->getCredits().size();j++){
                        if(uvbranche[i]->getCredits()[j]->getCategorie().getCode()=="TSH"){
                             strategie.push_back(uvbranche[i]);
                             TSH_Besoin.setNombre(TSH_Besoin.getNombre()-uvbranche[i]->getCredits()[j]->getNombre());
                }}}*/ //En attente du fichier de TSH ou je ne sais quoi
            else if(uvbranche[i]->getCategorie().getCode()=="TM" && TM_Besoin.getNombre() >0){
                 for(unsigned int j=0;j<uvbranche[i]->getCredits().size();j++){
                        if(uvbranche[i]->getCredits()[j]->getCategorie().getCode()=="TM"){
                             strategie.push_back(*uvbranche[i]);
                             TM_Besoin.setNombre(TM_Besoin.getNombre()-uvbranche[i]->getCredits()[j]->getNombre());
               }} }
            /*else if(uvbranche[i]->getCategorie().getCode()=="SP" && SP_Besoin.getNombre() >0){
                 for(unsigned int j=0;j<uvbranche[i]->getCredits().size();j++){
                        if(uvbranche[i]->getCredits()[j]->getCategorie().getCode()=="SP"){
                             strategie.push_back(uvbranche[i]);
                             SP_Besoin.setNombre(SP_Besoin.getNombre()-uvbranche[i]->getCredits()[j]->getNombre());
               }} }*/ // SP Marche pas car il n'y a pas TN09 Et TN10 dans le fichier d'uv

                  if (TM_Besoin.getNombre() <=0 && CS_Besoin.getNombre() <=0) //&& TSH_Besoin.getNombre() <=0 && SP_Besoin.getNombre() <=0)
                            i=uvbranche.size()-1; // Pour sortir plus vite si on a finis la completion

                }
}}

