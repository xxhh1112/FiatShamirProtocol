//
//  Utils.h
//  Zero Knowledge Fiat-Shamir Protocol
//
//  Created by ivan sarno on 24/08/15.
//  Copyright (c) 2015 ivan sarno.
/*
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */
//version V.4.0

#pragma once
#include <gmpxx.h>
#include <time.h>
#include <stdlib.h>
#include <random>

namespace FiatShamirProtocol
{
    namespace Utils
    {
        typedef mpz_class BigInteger;
        BigInteger pow(BigInteger base, BigInteger exp);
        BigInteger mod_pow(BigInteger base, BigInteger exp, const BigInteger &mod);
        bool coprime (BigInteger a, BigInteger b);
        BigInteger byte2biginteger(uint8_t *byte, unsigned int size);
        
        
        class Generator
        {
        public:
            virtual BigInteger getBig(unsigned int size)=0;//return a positive BigInteger of size bit
        };
        
        class TestGenerator: public Generator
        {
        private:
            gmp_randstate_t rstate;
            mpz_t rand;
            unsigned long long seed;
        public:
            TestGenerator();
            TestGenerator(unsigned long long seed);
            ~TestGenerator();
            BigInteger getBig(unsigned int size);
            unsigned long long getInt();//return a positive BigInteger of size bit
        };
    }
}
