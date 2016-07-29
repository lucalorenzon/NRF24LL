/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NRF24.cpp
 * Author: X86
 * 
 * Created on 10 luglio 2016, 15.44
 */

#include "NRF24.h"

NRF24::NRF24() {
    
}

NRF24::NRF24(const NRF24& orig) {
    init(cePin, csnPin);
}

NRF24::NRF24(uint8_t cePin, uint8_t csnPin) {
    init(cePin, csnPin);
}

void NRF24::init(uint8_t cePin, uint8_t csnPin) {
    this->bcm2835 = new BCM283X();
    this->cePin = cePin;
    this->csnPin = csnPin;
    
    this->bcm2835->beginSPI(this->csnPin);
}

uint8_t NRF24::getStatusRegister(){
    uint8_t statusValue=0;
    if(this->bcm2835!=NULL){
       statusValue=this->bcm2835->transfer(NRF24.NOP_COMMAND); //NOP=0xFF
       this->lastStatus=statusValue;
       this->lstStatusUpdateTime=time(NULL);
    }
    return statusValue;
}

uint8_t NRF24::getByteRegister(NRF24_REGISTER register){
    uint8_t statusValue=0;
    if(this->bcm2835!=NULL){
        uint8_t *txBuff = new uint8_t[2];
        uint8_t *rxBuff = new uint8_t[2];
        txBuff[0]= OP_R_REGISTER | static_cast<uint8_t>(register);
        txBuff[1]=NOP_COMMAND;
        this->bcm2835->transferb(rxBuff, txBuff, 2);
        statusValue=rxBuff[0];
        this->lastStatus=statusValue;
        this->lstStatusUpdateTime=time(NULL);
        uint8_t returnValue=rxBuff[1];
        delete txBuff;
        delete rxBuff;
        return returnValue;
    }
}

void NRF24::getRegister(NRF24_REGISTER register, uint8_t *value, uint32_t lenght){
    uint8_t statusValue=0;
    if(this->bcm2835!=NULL){
        uint8_t *txBuff = new uint8_t[lenght+1];
        uint8_t *rxBuff = new uint8_t[lenght+1];
        txBuff[0]= OP_R_REGISTER | static_cast<uint8_t>(register);
        for (int i = 1; i < lenght+1; i++) {
            txBuff[i]=NOP_COMMAND;
        }

        this->bcm2835->transferb(rxBuff, txBuff, lenght+1);
        statusValue=rxBuff[0];
        this->lastStatus=statusValue;
        this->lstStatusUpdateTime=time(NULL);
        for (int i = 1; i < lenght+1; i++) {
            value[i-1] = rxBuff[i];
        }
        delete txBuff;
        delete rxBuff;
    }
}

void NRF24::powerUp(){
    
}

NRF24::~NRF24() {
    delete bcm2835;
}

