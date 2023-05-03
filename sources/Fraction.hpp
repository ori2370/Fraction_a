#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;
namespace ariel
{
    class Fraction
    {
        int numerator;
        int denominator;
        void fracReduction();

    public:
        // ctors
        Fraction(int numerator, int denominator);
        Fraction(float fraction);

        /*all the operators can work as fraction with fraction/float,
        and float with fraction*/
        // (-)
        Fraction operator-(const Fraction &other) const;
        friend Fraction operator-(const Fraction &fraction, float &ffraction)
        {
            Fraction temp(ffraction);
            return fraction - temp;
        }
        friend Fraction operator-(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return temp - fraction;
        }
        // (+)
        Fraction operator+(const Fraction &other) const;
        friend Fraction operator+(const Fraction &fraction, const float &ffraction)
        {
            Fraction floattemp(ffraction);
            return fraction + floattemp;
        }
        friend Fraction operator+(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return temp + fraction;
        }
        // (*)
        Fraction operator*(const Fraction &other) const;
        friend Fraction operator*(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return fraction * temp;
        }
        friend Fraction operator*(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return temp * fraction;
        }
        // (/)
        Fraction operator/(const Fraction &other) const;
        friend Fraction operator/(const Fraction &fraction, const float &ffraction)
        {
            if (ffraction == 0)
            {
                throw invalid_argument("division by zero is not allowed");
            }
            Fraction temp(ffraction);
            return fraction / temp;
        }
        friend Fraction operator/(const float &ffraction, const Fraction &fraction)
        {
            if (fraction.numerator == 0)
            {
                throw invalid_argument("division by zero is not allowed");
            }
            Fraction temp(ffraction);
            return temp / fraction;
        }
        // comparison operators
        // (==)
        bool operator==(const Fraction &other) const;
        friend bool operator==(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return fraction == temp;
        }
        friend bool operator==(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return temp == fraction;
        }
        // (!=)
        bool operator!=(const Fraction &other) const;
        friend bool operator!=(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return (fraction != temp);
        }
        friend bool operator!=(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return (temp != fraction);
        }
        // (>)
        bool operator>(const Fraction &other) const;
        friend bool operator>(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return (fraction > temp);
        }
        friend bool operator>(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return (temp > fraction);
        }
        // (<)
        bool operator<(const Fraction &other) const;
        friend bool operator<(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return (fraction < temp);
        }
        friend bool operator<(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return (temp < fraction);
        }
        // (>=)
        bool operator>=(const Fraction &other) const;
        friend bool operator>=(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return (fraction >= temp);
        }
        friend bool operator>=(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return (temp >= fraction);
        }
        // (<=)
        bool operator<=(const Fraction &other) const;
        friend bool operator<=(const Fraction &fraction, const float &ffraction)
        {
            Fraction temp(ffraction);
            return (fraction <= temp);
        }
        friend bool operator<=(const float &ffraction, const Fraction &fraction)
        {
            Fraction temp(ffraction);
            return (temp <= fraction);
        }

        // prefix and postfix
        Fraction operator++(int);
        Fraction operator--(int);
        Fraction &operator++();
        Fraction &operator--();
        // input and output
        friend ostream &operator<<(ostream &ostream, const Fraction &fraction);
        friend istream &operator>>(istream &istream, Fraction &fraction);

        // getters and setters
        int getNumerator() const
        {
            return numerator;
        }
        int getDenominator() const
        {
            return denominator;
        }
        void setNumerator(int numerator)
        {
            this->numerator = numerator;
        }
        void setDenominator(int denominator)
        {
            this->denominator = denominator;
        }
    };

}

#endif