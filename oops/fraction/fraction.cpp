#include <iostream>
#include "Fraction.h"

using namespace std;

void Fraction::simplify() {
    int gcd = 1;

    int j = min(numerator, denominator);

    for (int i = 1; i <= j; i++) {
        if (numerator%i == 0 && denominator%i == 0) {
            gcd = i;
        }
    }

    numerator = numerator/gcd;
    denominator = denominator/gcd;
}

Fraction::Fraction(int numerator, int denominator)
    : numerator{numerator}, denominator{denominator} {

    }

void Fraction::print() const {
    cout << numerator << "/" << denominator << endl;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator) {
        this -> denominator = denominator;
        return;
    }

    cout << "Denominator cannot be Zero" << endl;

}

void Fraction::setNumerator(int numerator) {
    this -> numerator = numerator;
}


Fraction Fraction::operator+(Fraction const &f) const {
    int lcm = denominator * f.denominator;

    int nextNumerator = (numerator * f.denominator) + (f.numerator * denominator);

    Fraction fnew {nextNumerator, lcm};

    fnew.simplify();
    return fnew; 

}

Fraction Fraction::operator*(Fraction const &f) const {
    int newDenominator = f.denominator * denominator;
    int newNumerator = f.numerator * numerator;

    Fraction fnew {newNumerator, newDenominator};
    fnew.simplify();

    return fnew;
}

bool Fraction::operator==(Fraction const &f) const {
    if (numerator == f.numerator && denominator == f.denominator) {
        return true;
    }

    return false;
}

Fraction& Fraction::operator++() {
    numerator = numerator + denominator;

    this -> simplify();

    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction fnew {numerator, denominator};

    numerator = numerator + denominator;
    this -> simplify();
    fnew.simplify();

    return fnew;
}

Fraction& Fraction::operator+=(Fraction const &f) {
    int lcm = denominator * f.denominator;
    int num = denominator * f.numerator + numerator * f.denominator;

    numerator = num;
    denominator = lcm;

    this -> simplify();
    return *this;
}