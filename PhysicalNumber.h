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

        //constructor
        PhysicalNumber(double amount, Unit unit){
            this->amount = amount;
            this->unit = unit;
        }

        //operators
        PhysicalNumber operator+(const PhysicalNumber& other) ;
        PhysicalNumber operator-(const PhysicalNumber& other) ;

        PhysicalNumber& operator+=(const PhysicalNumber& other) ;
        PhysicalNumber& operator-=(const PhysicalNumber& other) ;

        const PhysicalNumber operator+() ;                       
        const PhysicalNumber operator-() ;                       

        PhysicalNumber& operator++() ;                           
        PhysicalNumber& operator--() ;                           

        PhysicalNumber operator++(int dummy_flag_for_postfix_increment) ;
        PhysicalNumber operator--(int dummy_flag_for_postfix_increment) ;
        
        

        //friend methodes
        friend bool operator== (const PhysicalNumber& p1, const PhysicalNumber& p2);
        friend bool operator!= (const PhysicalNumber& p1, const PhysicalNumber& p2);
        friend bool operator<= (const PhysicalNumber& p1, const PhysicalNumber& p2);
        friend bool operator>= (const PhysicalNumber& p1, const PhysicalNumber& p2);
        friend bool operator< (const PhysicalNumber& p1, const PhysicalNumber& p2);
        friend bool operator> (const PhysicalNumber& p1, const PhysicalNumber& p2);

        friend ostream& operator<< (ostream& os, const PhysicalNumber& other);
        friend istream& operator>> (istream& os, PhysicalNumber& other);
        

        private:

        double amount;
        Unit unit;
    };
    
    ostream& operator<< (ostream& os, const PhysicalNumber& other);
    istream& operator>> (istream& os, PhysicalNumber& other);
    bool operator== (const PhysicalNumber& p1, const PhysicalNumber& p2);
    bool operator!= (const PhysicalNumber& p1, const PhysicalNumber& p2);
    bool operator<= (const PhysicalNumber& p1, const PhysicalNumber& p2);
    bool operator>= (const PhysicalNumber& p1, const PhysicalNumber& p2);
    bool operator< (const PhysicalNumber& p1, const PhysicalNumber& p2);
    bool operator> (const PhysicalNumber& p1, const PhysicalNumber& p2);
}