#pragma once
#include "Unit.h"
#include <string>
using namespace std;

namespace ariel{
    class PhysicalNumber{
        public:

        //constructors
        PhysicalNumber(int amount, Unit unit){
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
        inline friend ostream& operator<< (ostream& os, const PhysicalNumber& other);
        friend istream& operator>> (istream& os, const PhysicalNumber& other);
        

        private:

        int amount;
        Unit unit;
        void converter(){

        }
    };



inline ostream& operator<< (ostream& os, const PhysicalNumber& other) {
    string unit = "";
    switch(other.unit){
            case Unit::CM : unit = "cm";
            break;
            case Unit::M : unit = "m";
            break;
            case Unit::KM : unit = "km";
            break;
            case Unit::SEC : unit = "sec";
            break;
            case Unit::MIN : unit = "min";
            break;
            case Unit::HOUR : unit = "hour";
            break;
            case Unit::G : unit = "g";
            break;
            case Unit::KG : unit = "kg";
            break;
            case Unit::TON : unit = "ton";
            break;
        }
    return (os << other.amount <<"[" << unit << "]"<< endl);
}

// istream& operator>> (istream& is, const PhysicalNumber& other){}
}