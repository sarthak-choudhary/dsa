#ifndef _FRACTION_H_
#define _FRACTION_H_

class Fraction {
    int numerator;
    int denominator;

    public:

    Fraction(int numerator = 1, int denominator = 1);
    void print() const;
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    void simplify();
    bool operator==(Fraction const &f) const;
    Fraction operator+(Fraction const &f) const;
    Fraction operator*(Fraction const &f) const;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator+=(Fraction const &f);

};



#endif