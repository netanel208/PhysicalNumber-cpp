#include "PhysicalNumber.h"
using namespace ariel;


bool isSameType(Unit a, Unit b){
    int this_type = ((int)a - 1) / 3;
    int other_type = ((int)b - 1) / 3;
    return this_type == other_type;
}

double base(double value, Unit u){
    if(u == Unit::CM || u == Unit::SEC || u == Unit::G){
        return value;
    }
    else{
        double result = 0;
        switch(u){
            case Unit::MIN: result = value * 60;
                break;
            case Unit::HOUR: result = value * 3600;
                break;
            case Unit::KG: result = value * 1000;
                break;
            case Unit::TON: result = value * 1000 * 1000;
                break;
            case Unit::M: result = value * 100;
                break;
            case Unit::KM: result = value * 1000 * 100;  
                break;  
        }
        return result;
    }
}

double returnToThisUnit(double value, Unit u){
    if(u == Unit::CM || u == Unit::SEC || u == Unit::G){
        return value;
    }
    else{
        double result = 0;
        switch(u){
            case Unit::MIN: result = value / 60;
                break;
            case Unit::HOUR: result = value / 3600;
                break;
            case Unit::KG: result = value / 1000;
                break;
            case Unit::TON: result = value / (1000 * 1000);
                break;
            case Unit::M: result = value / 100;
                break;
            case Unit::KM: result = value / (1000 * 100);  
                break;  
        }
        return result;
    }
}

//operators
PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& other) {
    if(!isSameType(this->unit, other.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }
    else{
        double thisAmount = base(this->amount, this->unit);
        double otherAmount = base(other.amount, other.unit);
        thisAmount += otherAmount;
        thisAmount = returnToThisUnit(thisAmount, this->unit);
        return PhysicalNumber(thisAmount, this->unit);
    }
};

PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& other) {
    if(!isSameType(this->unit, other.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }
    else{
        double thisAmount = base(this->amount, this->unit);
        double otherAmount = base(other.amount, other.unit);
        thisAmount -= otherAmount;
        thisAmount = returnToThisUnit(thisAmount, this->unit);
        return PhysicalNumber(thisAmount, this->unit);
    }
};

PhysicalNumber& ariel::PhysicalNumber::operator+=(const PhysicalNumber& other) {
    if(!isSameType(this->unit, other.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }
    else{
        double thisAmount = base(this->amount, this->unit);
        double otherAmount = base(other.amount, other.unit);
        thisAmount += otherAmount;
        thisAmount = returnToThisUnit(thisAmount, this->unit);
        this->amount = thisAmount;
    }
    return *this;
};

PhysicalNumber& ariel::PhysicalNumber::operator-=(const PhysicalNumber& other) {
    if(!isSameType(this->unit, other.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }
    else{
        double thisAmount = base(this->amount, this->unit);
        double otherAmount = base(other.amount, other.unit);
        thisAmount -= otherAmount;
        thisAmount = returnToThisUnit(thisAmount, this->unit);
        this->amount = thisAmount;
    }
    return *this;
};

const PhysicalNumber ariel::PhysicalNumber::operator-() {
    return PhysicalNumber(-1*(this->amount), this->unit);
};

const PhysicalNumber ariel::PhysicalNumber::operator+() {
    if(this->amount < 0)
     return PhysicalNumber((-1)*this->amount, this->unit);
    else
     return PhysicalNumber(this->amount, this->unit);
};

PhysicalNumber& ariel::PhysicalNumber::operator++() {
    amount++;
    return *this;
};
PhysicalNumber& ariel::PhysicalNumber::operator--() {
    amount--;
    return *this;
};
const PhysicalNumber ariel::PhysicalNumber::operator++(int dummy_flag_for_postfix_increment) {
    PhysicalNumber copy = *this;
    amount++;
    return copy;
};
const PhysicalNumber ariel::PhysicalNumber::operator--(int dummy_flag_for_postfix_increment) {
    PhysicalNumber copy = *this;
    amount--;
    return copy;
};


bool ariel::operator== (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!isSameType(p1.unit, p2.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double amount1 = base(p1.amount, p1.unit);
    double amount2 = base(p2.amount, p2.unit);
    return amount1 == amount2;
};

bool ariel::operator!= (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!isSameType(p1.unit, p2.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double amount1 = base(p1.amount, p1.unit);
    double amount2 = base(p2.amount, p2.unit);
    return amount1 != amount2;
};

bool ariel::operator<= (const PhysicalNumber& p1, const PhysicalNumber& p2){    
    if(!isSameType(p1.unit, p2.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double amount1 = base(p1.amount, p1.unit);
    double amount2 = base(p2.amount, p2.unit);
    return amount1 <= amount2;
};

bool ariel::operator>= (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!isSameType(p1.unit, p2.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double amount1 = base(p1.amount, p1.unit);
    double amount2 = base(p2.amount, p2.unit);
    return amount1 >= amount2;
};
bool ariel::operator< (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!isSameType(p1.unit, p2.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double amount1 = base(p1.amount, p1.unit);
    double amount2 = base(p2.amount, p2.unit);
    return amount1 < amount2;
};
bool ariel::operator> (const PhysicalNumber& p1, const PhysicalNumber& p2){
    if(!isSameType(p1.unit, p2.unit)){
        throw std::out_of_range{"Error: Numbers with differents type..."};
    }

    double amount1 = base(p1.amount, p1.unit);
    double amount2 = base(p2.amount, p2.unit);
    return amount1 > amount2;
};

/****************************************/
/*             operator<<               */ 
/****************************************/
ostream& ariel::operator<< (ostream& os, const PhysicalNumber& p) {
    string unit = "";
    switch(p.unit) {                //convert Unit to string
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
    return (os << p.amount << '[' << unit << ']');
};



/**
 * this function check unit input correct
 */
int getUnitSize(string str){//check unit size 1,2,3,4 (km,m,sec,hour)
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


/**
 * this function return the correct Unit after convert string unit to int
 */ 
Unit getUnit(int unit){
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


/**
 * this function return int that represent the string Unt from the input
 */ 
int unitCorrect(string str){
    int unitSize = getUnitSize(str);//get unit length of input
    int unit = 0; //type of unit

    if(unitSize == 0 || unitSize > 4){//if unitSize = 0 or more than 4 so input is not correct
        return 0;
    }
    else{
        string tempUnit = str.substr(str.length() - unitSize - 1, unitSize);
        if(!tempUnit.compare("cm")){ unit = (int)Unit::CM; }
        if(!tempUnit.compare("m")){ unit = (int)Unit::M; }
        if(!tempUnit.compare("km")){ unit = (int)Unit::KM; }
        if(!tempUnit.compare("sec")){ unit = (int)Unit::SEC; }
        if(!tempUnit.compare("min")){ unit = (int)Unit::MIN; }
        if(!tempUnit.compare("hour")){ unit = (int)Unit::HOUR; }
        if(!tempUnit.compare("g")){ unit = (int)Unit::G; }
        if(!tempUnit.compare("kg")){ unit = (int)Unit::KG; }
        if(!tempUnit.compare("ton")){ unit = (int)Unit::TON; }
    }
    return unit;//return 0 if tempUnit string not equals to some Unit type
}


/**
 *  this function check amount input correct
 */
int amountCorrect(string str){
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


/**
 * this function will work only if input of unit and amount is correct
 * this function parse amount from string to double.
 * */
double getAmount(string str){
    int unitSize = getUnitSize(str); //find unit length
    int size = str.length() - unitSize - 2;//unit length + []
    string amount = str.substr(0, size);//cut string from 0 to '['
    double value = stod(amount);//parsing
    return value;
}

/****************************************/
/*             operator>>               */ 
/*with checking correctness of the input*/
/****************************************/
istream& ariel::operator>> (istream& input, PhysicalNumber& other){
    int amount;
    string unit;
    Unit u;

    //convert input istream to string
    ostringstream os;       //
    input >> os.rdbuf();    //
    string str = os.str();  //
    //int size = str.length();//

    //check input correct 
    int unitSize = unitCorrect(str); //if unit correct return unit size else 0
    int amountSize = amountCorrect(str); //if amount correcr return 1 else 0

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if (!unitSize || !amountSize) { //if amount or unit 0 so input wrong
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
} ;