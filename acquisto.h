#ifndef TRANSAZIONIFINANZIARIE_ACQUISTO_H
#define TRANSAZIONIFINANZIARIE_ACQUISTO_H


#include <string>
#include "transazione.h"

class acquisto : public transazione{
private:
    std::string esercente;
};


#endif //TRANSAZIONIFINANZIARIE_ACQUISTO_H
