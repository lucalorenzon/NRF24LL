/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NRF24.h
 * Author: X86
 *
 * Created on 10 luglio 2016, 15.44
 */

#ifndef NRF24_H
#define NRF24_H

#include "BCM283X.h"

class NRF24 {
public:
    NRF24();
    NRF24(const NRF24& orig);
    virtual ~NRF24();
private:
    BCM283X bcm2835;
};

#endif /* NRF24_H */

