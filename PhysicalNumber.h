#pragma once
#include "Unit.h"
#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <sstream> //ostringstream
using namespace std;

namespace ariel{
    class PhysicalNumber{
        public:

        //constructors
        PhysicalNumber(double amount, Unit unit){
            this->amount = amount;
            this->unit = unit;
            converter();
        }

        //operators
        const PhysicalNumber operator+(const PhysicalNumber& other) ;
        const PhysicalNumber operator+=(const PhysicalNumber& other) ;
        const PhysicalNumber operator+() ;
        const PhysicalNumber operator-(const PhysicalNumber& other) ;
        const PhysicalNumber operator-=(const PhysicalNumber& other) ;
        const PhysicalNumber operator-() ;
        const PhysicalNumber operator++() ;
        const PhysicalNumber operator--() ;
        const PhysicalNumber operator++(int dummy_flag_for_postfix_increment) ;
        const PhysicalNumber operator--(int dummy_flag_for_postfix_increment) ;
        const bool operator== (const PhysicalNumber& other);
        const bool operator!= (const PhysicalNumber& other);
        const bool operator<= (const PhysicalNumber& other);
        const bool operator>= (const PhysicalNumber& other);
        const bool operator< (const PhysicalNumber& other);
        const bool operator> (const PhysicalNumber& other);


        //friend methodes
        friend ostream& operator<< (ostream& os, const PhysicalNumber& other);
        friend istream& operator>> (istream& os, PhysicalNumber& other);
        

        private:

        double amount;
        Unit unit;
    };
}