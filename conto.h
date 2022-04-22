#ifndef TRANSAZIONIFINANZIARIE_CONTO_H
#define TRANSAZIONIFINANZIARIE_CONTO_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include "transazione.h"

using namespace std;

class conto {
public:
    conto(){};
    conto(int id, const string &dataAperturaz, const string &titolarez);

    void aggiungiTransazione(int importoz, const string &contropartez, const string &transazioneInUscitaz);
    void eliminaTransazione(int idTransazioneDaEliminare);
    void modificaTransazione(int id, int importoz, const string &contropartez, const string &transazioneInUscitaz);
    shared_ptr<transazione> cercaTransazionePerId(int idTransazione);

    int getNumeroTransazioni();
    int getBilancioTransazioni();
    int getProssimoIdTransazione();
    shared_ptr<transazione> getPrimaTransazione();
    void setidConto(int id);
    void setProssimoIdTransazione(int pid);


private:
    void caricaDati();
    void trovaProssimoIdTransazione ();
    tm convertiStringInData(string s);
    void salvaDati ();

    int idConto;
    tm dataApertura;
    string titolare;
    list<shared_ptr<transazione>> elencoTransazioni;
    int prossimoIdTransazione;
};


#endif //TRANSAZIONIFINANZIARIE_CONTO_H
