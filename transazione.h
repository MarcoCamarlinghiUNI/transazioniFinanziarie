#ifndef TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
#define TRANSAZIONIFINANZIARIE_TRANSAZIONE_H


class transazione {
public:
    explicit transazione(int importo);
    virtual ~transazione() {}

    virtual transazione* crea() const = 0;

private:
    int importo;
};


#endif //TRANSAZIONIFINANZIARIE_TRANSAZIONE_H
