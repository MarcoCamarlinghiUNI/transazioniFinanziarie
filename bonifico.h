#ifndef TRANSAZIONIFINANZIARIE_BONIFICO_H
#define TRANSAZIONIFINANZIARIE_BONIFICO_H


#include <string>
#include "transazione.h"

class bonifico final : public transazione{
public:
    bonifico(int importo, const std::string &causale, bool bonificoInEntrataFlag);

private:
    std::string causale;
    bool bonificoInEntrataFlag{};

};


#endif //TRANSAZIONIFINANZIARIE_BONIFICO_H
