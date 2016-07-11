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
    bcm2835 = new BCM283X();
}

NRF24::NRF24(const NRF24& orig) {
    bcm2835 = new BCM283X();
}

NRF24::~NRF24() {
    delete bcm2835;
}

