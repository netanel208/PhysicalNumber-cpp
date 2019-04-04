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
        inline friend istream& operator>> (istream& os, PhysicalNumber& other);
        

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

static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}
    inline istream& operator>> (istream& input, PhysicalNumber& other){
        int amount;
        string unit;
        Unit u;


        // remember place for rewinding
        ios::pos_type startPosition = input.tellg();

        // auto splitText = text | view::split(' ');

        if ( (!(input >> amount))                 ||
            (!getAndCheckNextCharIs(input,'[')) ||
            (!(input >> unit))                 ||
            (!(getAndCheckNextCharIs(input,']'))) ) {

            // rewind on error
            auto errorState = input.rdstate(); // remember error state
            input.clear(); // clear error so seekg will work
            input.seekg(startPosition); // rewind
            input.clear(errorState); // set back the error flag

        } else {
            cout << "dudu"<<endl;
            other.amount = amount;
            other.unit = Unit::KM;
            //convert from string to unit (create switch case function)
        }

        return input;
    }

    

    
}