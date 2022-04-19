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
        std::string nomeDelFile = "0.csv";
        const char * nomeDelFileChar = nomeDelFile.c_str();
        remove(nomeDelFileChar);
    }
};

TEST_F(testFixture, testCostruttoreConto){
    c.letturaTransazioni(0);
    ASSERT_EQ(c.listaTransazioni.size(),3);
    ASSERT_EQ(c.prossimoIdTransazione,4);
}

TEST_F(testFixture, testAggiungiTransazione){
    c.aggiungiTransazione(10,"controparte1","1");

    ASSERT_EQ(c.listaTransazioni.size(),4);
    ASSERT_EQ(c.prossimoIdTransazione,5);
}

TEST_F(testFixture, testEliminaTransazionePresente){
    c.eliminaTransazione(2);

    ASSERT_EQ(c.listaTransazioni.size(),2);
}

TEST_F(testFixture, testEliminaTransazioneNonPresente){
    c.eliminaTransazione(100);

    ASSERT_EQ(c.listaTransazioni.size(),3);
}

TEST_F(testFixture, testConciliaTransazione){
    c.conciliaTransazione(c.listaTransazioni[0]);

    ASSERT_TRUE(c.listaTransazioni[0]->transazioneConciliataFlag);
}