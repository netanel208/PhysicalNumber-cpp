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
        inline friend ostream& operator<< (ostream& os, const PhysicalNumber& other);
        inline friend istream& operator>> (istream& os, PhysicalNumber& other);
        

        private:

        double amount;
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

    ////////////////////////////////////////////////////////////////////
    /////////////////////check unit input correct///////////////////////
    ////////////////////////////////////////////////////////////////////
    static int getUnitSize(string str){//check unit size 1,2,3,4 (km,m,sec,hour)
        int unit_size = 1;//min unit length
        int size = str.length();
        
        if(str.at(size - 1)  != ']'){//check last char
            // throw std::out_of_range{"Input not correct!!!"};
            return 0;
        }
        
        while(str.at(size - unit_size - 1) >= 'a' && str.at(size - unit_size - 1) <= 'z'){
            unit_size++;
        }
        
        if(str.at(size - unit_size - 1) != '['){//check char before unit type
            return 0;
        }

        return unit_size - 1;
    }

    static Unit getUnit(int unit){
        Unit temp;
        switch (unit)
        {
            case 1: temp = Unit::CM;
                break;
            case 2: temp = Unit::M;
                break;
            case 3: temp = Unit::KM;
                break;
            case 4: temp = Unit::SEC;
                break;
            case 5: temp = Unit::MIN;
                break;
            case 6: temp = Unit::HOUR;
                break;
            case 7: temp = Unit::G;
                break;
            case 8: temp = Unit::KG;
                break;    
            case 9: temp = Unit::TON;
                break;
        }
        return temp;
    } 

    static int unitCorrect(string str){
        int unitSize = getUnitSize(str);//get unit length of input
        int unit = 0; //type of unit

        if(unitSize == 0 || unitSize > 4){//if unitSize = 0 or more than 4 so input is not correct
            return 0;
        }
        else{
            string tempUnit = str.substr(str.length() - unitSize - 1, unitSize);
            if(!tempUnit.compare("CM")){ unit = (int)Unit::CM; }
            if(!tempUnit.compare("M")){ unit = (int)Unit::M; }
            if(!tempUnit.compare("KM")){ unit = (int)Unit::KM; }
            if(!tempUnit.compare("sec")){ unit = (int)Unit::SEC; }
            if(!tempUnit.compare("min")){ unit = (int)Unit::MIN; }
            if(!tempUnit.compare("HOUR")){ unit = (int)Unit::HOUR; }
            if(!tempUnit.compare("G")){ unit = (int)Unit::G; }
            if(!tempUnit.compare("kg")){ unit = (int)Unit::KG; }
            if(!tempUnit.compare("ton")){ unit = (int)Unit::TON; }
        }
        return unit;//return 0 if tempUnit string not equals to some Unit type
    }
    ////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////////////////////
    ///////////////////check amount input correct///////////////////////
    ////////////////////////////////////////////////////////////////////
    static int amountCorrect(string str){
        int unitSize = getUnitSize(str);//find unit length
        int size = str.length() - unitSize - 2;//unit length + []
        string amount = str.substr(0, size);//cut string from 0 to '['
        int dotCount = 0;//count of dots
        for(int i = 0; i < size; i++){
            if(amount.at(i) < '0' || amount.at(i) > '9'){
                if(amount.at(i) == '.'){//if char is '.' so dotCount ++
                    dotCount++;
                }
                else{//if char is not number or dot so amount input is wrong
                    return 0;
                }
            }
            if(dotCount > 1){ // more than 1 dot so amount input is wrong
                return 0;
            }
        }
        return 1;
    }

    //this function will work only if input of unit and amount is correct
    //this function parse amount from string to double
    static double getAmount(string str){
        int unitSize = getUnitSize(str); //find unit length
        int size = str.length() - unitSize - 2;//unit length + []
        string amount = str.substr(0, size);//cut string from 0 to '['
        double value = stod(amount);//parsing
        return value;
    }
    ////////////////////////////////////////////////////////////////////

 
    inline istream& operator>> (istream& input, PhysicalNumber& other){
        int amount;
        string unit;
        Unit u;

        //convert input istream to string
        ostringstream os;       //
        input >> os.rdbuf();    //
        string str = os.str();  //
        int size = str.length();//
        //////////////////////////

        //check input correct 
        int unitSize = unitCorrect(str); //if unit correct return unit size else 0
        int amountSize = amountCorrect(str); //if amount correcr return 1 else 0

        // remember place for rewinding
        ios::pos_type startPosition = input.tellg();

        if (!unitSize || !amountSize) { //if amount or unit 0 so input wrong
            // cout << "WRONGGGGGGGGGGGGGGGGGG" << endl;
            // rewind on error
            auto errorState = input.rdstate(); // remember error state
            input.clear(); // clear error so seekg will work
            input.seekg(startPosition); // rewind
            input.clear(errorState); // set back the error flag

        } else {
            other.amount = getAmount(str);
            other.unit = getUnit(unitSize);
        }

        return input;
    } 
}