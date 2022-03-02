#ifndef TRANSAZIONIFINANZIARIE_ACQUISTO_H
#define TRANSAZIONIFINANZIARIE_ACQUISTO_H


#include <string>
#include "transazione.h"

class acquisto final : public transazione{
public:
    acquisto(int importo, const std::string &esercente);

private:
    std::string esercente;
    bool acquistoOnlineFlag;
};


#endif //TRANSAZIONIFINANZIARIE_ACQUISTO_H
