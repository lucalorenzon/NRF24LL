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

uint8_t NRF24::getStatus(){
    uint8_t statusValue=0;
    if(this->bcm2835!=NULL){
       statusValue=this->bcm2835->transfer(NRF24.NOP_COMMAND); //NOP=0xFF
       this->lastStatus=statusValue;
       this->lstStatusUpdateTime=time(NULL);
    }
    return statusValue;
}

NRF24::~NRF24() {
    delete bcm2835;
}

