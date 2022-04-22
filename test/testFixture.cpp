#include <fstream>
#include "gtest/gtest.h"

#include "../conto.h"

class testFixture : public ::testing::Test {
public:
    conto c;
    virtual void SetUp() {
        c.setidConto(0);
        c.setProssimoIdTransazione(1);

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
    ASSERT_EQ(c.getProssimoIdTransazione(),4);
    ASSERT_EQ(c.getBilancioTransazioni(),206);
}

TEST_F(testFixture, testAggiungiTransazione){
    c.aggiungiTransazione(10,"controparte1","1");

    ASSERT_EQ(c.getNumeroTransazioni(),4);
    ASSERT_EQ(c.getProssimoIdTransazione(),5);
    ASSERT_EQ(c.getBilancioTransazioni(),196);
}

TEST_F(testFixture, testCercaTransazionePresente){
    shared_ptr<transazione> ptr = c.cercaTransazionePerId(3);

    ASSERT_EQ(ptr->getIdTransazione(), 3);
}

TEST_F(testFixture, testCercaTransazioneNonPresente){

    ASSERT_THROW(c.cercaTransazionePerId(100),out_of_range);
}

TEST_F(testFixture, testEliminaTransazionePresente){
    c.eliminaTransazione(2);

    ASSERT_EQ(c.getNumeroTransazioni(),2);
    ASSERT_EQ(c.getBilancioTransazioni(),140);
}

TEST_F(testFixture, testModificaTransazionePresente){
    c.modificaTransazione(3,15,"barattaPostTest","1");

    ASSERT_EQ(c.getNumeroTransazioni(),3);
    ASSERT_EQ(c.cercaTransazionePerId(3)->getImporto(), 15);
    ASSERT_EQ(c.getBilancioTransazioni(),105);
}

TEST_F(testFixture, testModificaTransazioneNonPresente){

    ASSERT_THROW(c.modificaTransazione(100,15,"barattaPostTest","1"),logic_error);
}

TEST_F(testFixture, testConciliaTransazione){
    c.cercaTransazionePerId(2)->setTransazioneConciliata(1);

    ASSERT_TRUE(c.cercaTransazionePerId(2)->getTransazioneConciliata());
}