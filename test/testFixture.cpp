#include <fstream>
#include "gtest/gtest.h"

#include "../conto.h"

class testFixture : public ::testing::Test {
public:
    conto c;
    virtual void SetUp() {
        c.idConto = 0;
        c.prossimoIdTransazione = 1;

        c.aggiungiTransazione(54,"baratta","0");
        c.aggiungiTransazione(66,"baratta","0");
        c.aggiungiTransazione(86,"baratta","0");
    }

    virtual void TearDown(){
        std::string nomeDelFile = "0.csv";                    //////////// ma se creo direttamente il char?
        const char * nomeDelFileChar = nomeDelFile.c_str();
        remove(nomeDelFileChar);
    }
};

TEST_F(testFixture, testCostruttoreConto){

    ASSERT_EQ(c.getNumeroTransazioni(),3);
    ASSERT_EQ(c.prossimoIdTransazione,4);
    ASSERT_EQ(c.getBilancioTransazioni(),206);
}

TEST_F(testFixture, testAggiungiTransazione){
    c.aggiungiTransazione(10,"controparte1","1");

    ASSERT_EQ(c.getNumeroTransazioni(),4);
    ASSERT_EQ(c.prossimoIdTransazione,5);
    ASSERT_EQ(c.getBilancioTransazioni(),196);
}

TEST_F(testFixture, testCercaTransazionePresente){
    shared_ptr<transazione> ptr = c.cercaTransazionePerId(3);

    ASSERT_EQ(ptr->idTransazione, 3);
}

TEST_F(testFixture, testCercaTransazioneNonPresente){
    try {
        shared_ptr<transazione> ptr = c.cercaTransazionePerId(100);
    } catch (const char*){

    }

    ASSERT_THROW(c.cercaTransazionePerId(100),const char*);
}

TEST_F(testFixture, testEliminaTransazionePresente){
    c.eliminaTransazione(2);

    ASSERT_EQ(c.getNumeroTransazioni(),2);
    ASSERT_EQ(c.getBilancioTransazioni(),140);
}

TEST_F(testFixture, testEliminaTransazioneNonPresente){
    c.eliminaTransazione(100);

    ASSERT_EQ(c.getNumeroTransazioni(),3);
}

TEST_F(testFixture, testModificaTransazionePresente){
    c.modificaTransazione(3,15,"barattaPostTest","1");

    ASSERT_EQ(c.getNumeroTransazioni(),3);
    ASSERT_EQ(c.cercaTransazionePerId(3)->importo, 15);
    ASSERT_EQ(c.getBilancioTransazioni(),105);
}

TEST_F(testFixture, testModificaTransazioneNonPresente){
    try {
        c.modificaTransazione(100, 15, "barattaPostTest", "1");
    }catch (const char*){

    }

    ASSERT_ANY_THROW(c.modificaTransazione(100,15,"barattaPostTest","1"));
}

TEST_F(testFixture, testConciliaTransazione){
    c.elencoTransazioni.front()->setTransazioneConciliataFlag(1);

    ASSERT_TRUE(c.elencoTransazioni.front()->transazioneConciliataFlag);
}