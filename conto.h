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
    explicit conto(int id, string dataAperturaz, string titolarez);
    virtual ~conto() = default;

    vector<transazione*> letturaTransazioni(int idContoz);
    int trovaProssimoIdTransazione ();
    tm convertiStringInData(string s);

    transazione* aggiungiTransazione(int importoz, string contropartez, string transazioneInUscitaFlagz);
    void eliminaTransazione(int idTransazioneDaEliminare);
    void conciliaTransazione(transazione* t);

    void aggiornaCSV ();


    int idConto;
    tm dataApertura;
    string titolare;

    vector<transazione*> listaTransazioni;
    int prossimoIdTransazione;
};


#endif //TRANSAZIONIFINANZIARIE_CONTO_H
