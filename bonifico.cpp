#include "bonifico.h"

bonifico::bonifico(int importo, const std::string &causale, bool bonificoInEntrataFlag)
        : transazione(importo), causale(causale), bonificoInEntrataFlag(bonificoInEntrataFlag) {}
