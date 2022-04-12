#ifndef TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
#define TRANSAZIONIFINANZIARIE_TRANSAZIONE_H

#include <string>
#include <ctime>
using namespace std;

class transazione {
public:
    explicit transazione(int importo);
    virtual ~transazione() {}

    virtual transazione* crea() const = 0;

private:
    unsigned int idTransazione;
    int importo;
    string controparte;         // chi riceve o invia il denaro
    tm dataContabile;
    tm dataConciliazione;
    bool transazioneInUscitaFlag;
    bool transazioneConciliataFlag;
};


#endif //TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
