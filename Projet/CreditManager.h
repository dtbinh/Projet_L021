#ifndef CREDITMANAGER_H
#define CREDITMANAGER_H

#include "UV.h"

class CreditManager {
private:
    Credits** credit;
    unsigned int nbCredit;
    unsigned int nbMaxCredit;
    void addItem(Credits* c);
    bool modification;
    Credits* trouverCredit(const std::string& c) const;
    CreditManager(const CreditManager& um);
    CreditManager& operator=(const CreditManager& um);
    CreditManager();
    ~CreditManager();
    //string file;
    friend struct Handler;
    struct Handler{
        CreditManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;

public:

    //void load(const string& f);
    //void save(const string& f);
    void affichage();
    static CreditManager& getInstance();
    static void libererInstance();
    void ajouterCredit(Credits& c);
    const Credits& getCredit(const std::string& code) const;
    Credits& getCredit(const std::string& code);

    class iterator {
        Credits** current;
        iterator(Credits** c):current(c){}
        friend class CreditManager;
    public:
        iterator():current(0){};
        Credits& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(credit); }
    iterator end() { return iterator(credit+nbCredit); }

};
#endif // CREDITMANAGER_H
