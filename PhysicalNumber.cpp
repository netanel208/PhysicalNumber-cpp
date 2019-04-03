#include "PhysicalNumber.h"
using namespace ariel;

//operators
        const PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& other) {
            return other;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator+=(const PhysicalNumber& other) {
            return other;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator+() {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& other) {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator-=(const PhysicalNumber& other) {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator-() {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator++() {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator--() {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator++(int dummy_flag_for_postfix_increment) {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const PhysicalNumber ariel::PhysicalNumber::operator--(int dummy_flag_for_postfix_increment) {
            PhysicalNumber p(1,Unit::KM);
            return p;
        };
        const bool ariel::PhysicalNumber::operator== (const PhysicalNumber& other){
            return true;
        };
        const bool ariel::PhysicalNumber::operator!= (const PhysicalNumber& other){
            return true;
        };
        const bool ariel::PhysicalNumber::operator<= (const PhysicalNumber& other){
            return true;
        };
        const bool ariel::PhysicalNumber::operator>= (const PhysicalNumber& other){
            return true;
        };
        const bool ariel::PhysicalNumber::operator< (const PhysicalNumber& other){
            return true;
        };
        const bool ariel::PhysicalNumber::operator> (const PhysicalNumber& other){
            return true;
        };