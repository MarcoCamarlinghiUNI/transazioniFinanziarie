#ifndef TRANSAZIONIFINANZIARIE_BONIFICO_H
#define TRANSAZIONIFINANZIARIE_BONIFICO_H


#include <string>
#include "transazione.h"

class bonifico : public transazione{
private:
    std::string causale;

};


#endif //TRANSAZIONIFINANZIARIE_BONIFICO_H
