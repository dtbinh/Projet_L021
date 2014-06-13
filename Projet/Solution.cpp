#include "Solution.h"

// MARCHE QUE POUR UNE FORMATION POUR LE MOMENT

Solution::Solution(const QString& c,const Dossier& D,const CategorieManager& catman)
{
    Credits CS_Besoin("CS_Besoin",0,catman.getCategorie("CS"));
    Credits TM_Besoin("TM_Besoin",0,catman.getCategorie("TM"));
    Credits TSH_Besoin("TSH_Besoin",0,catman.getCategorie("TSH"));
    Credits SP_Besoin("SP_Besoin",0,catman.getCategorie("SP"));
    code=c;
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

    std::cout<<"Proposition de CS pour valider votre formation"<<std::endl;
    std::vector<const UV*> uvbranche= form.begin()->second.getUVs();
        for (unsigned int i=0; i <uvbranche.size();i++){
            if(uvbranche[i]->getCategorie().getCode()=="CS"){
                for(unsigned int j=0;j<uvbranche[i]->getCredits().size();j++){
                    if(uvbranche[i]->getCredits()[j]->getCategorie().getCode()=="CS"){
                            std::cout<<uvbranche[i]->getCode().toStdString()<<std::endl;
                            CS_Besoin.setNombre(CS_Besoin.getNombre()-uvbranche[i]->getCredits()[j]->getNombre());
                            if (CS_Besoin.getNombre() <=0 ) i=uvbranche.size()-1;
                     }
                }
            }
        }

        std::cout<<"Proposition de TM pour valider votre formation"<<std::endl;
        std::vector<const UV*> uvbranch= form.begin()->second.getUVs();
            for (unsigned int i=0; i <uvbranch.size();i++){
                if(uvbranch[i]->getCategorie().getCode()=="TM"){
                    for(unsigned int j=0;j<uvbranch[i]->getCredits().size();j++){
                        if(uvbranch[i]->getCredits()[j]->getCategorie().getCode()=="TM"){
                                std::cout<<uvbranch[i]->getCode().toStdString()<<std::endl;
                                TM_Besoin.setNombre(TM_Besoin.getNombre()-uvbranch[i]->getCredits()[j]->getNombre());
                                if (TM_Besoin.getNombre() <=0 ) i=uvbranch.size()-1;
                         }
                    }
                }
            }

  Inscription strategie();
}
