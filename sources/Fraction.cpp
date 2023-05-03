#include "Fraction.hpp"
#include <cmath>
using namespace std;
namespace ariel
{
    // helper function
    void Fraction::fracReduction()
    {
        // check if some of the fraction is negative
        bool negativenumer = numerator < 0;
        bool negativedenom = denominator < 0;
        numerator = abs(numerator);
        denominator = abs(denominator);
        int div = 0;
        for (int i = numerator; i >= 1; i--)
        {
            if ((numerator % i == 0) && (denominator % i == 0))
            {
                div = i;
                break;
            }
        }
        if (div != 0)
        {
            numerator = numerator / div;
            denominator = denominator / div;
        }
        if (negativenumer && negativedenom)
        {
            return; // both negative so no need to bring - back
        }
        if (negativenumer)
        {
            numerator = -numerator;
        }
        if (negativedenom)
        {
            denominator = -denominator;
        }
    }

    // ctors
    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("you can't divide by zero");
        }
        if (numerator == 0)
        {
            this->numerator = 0;
            this->denominator = 1;
            return; // no need to reduce
        }
        this->numerator = numerator;
        this->denominator = denominator;
        fracReduction();
    }
    Fraction::Fraction(float fraction)
    {
        bool negativeflag = fraction < 0;
        fraction = abs(fraction);
        int numer = floor(fraction * 1000);
        if (numer < 0.001 && numer >= 0) // after multiplying still less than 0.001 so its 0
        {
            this->numerator = 0;
            this->denominator = 1;
            return; // no need to reduce
        }
        this->denominator = 1000;
        if (negativeflag)
        {
            this->numerator = -numer;
        }
        else
        {
            this->numerator = numer;
        }

        fracReduction();
    }
    // operators
    //  (-)
    Fraction Fraction::operator-(const Fraction &other) const
    {
        int tempnumer = (numerator * other.denominator) - (other.numerator * denominator);
        int tempdenom = denominator * other.denominator;
        return Fraction(tempnumer, tempdenom);
    }

    // (+)
    Fraction Fraction::operator+(const Fraction &other) const
    {
        int tempnumer = (numerator * other.denominator) + (other.numerator * denominator);
        int tempdenom = denominator * other.denominator;
        return Fraction(tempnumer, tempdenom);
    }

    // (*)
    Fraction Fraction::operator*(const Fraction &other) const
    {
        int tempnumer = numerator * other.numerator;
        int tempdenom = denominator * other.denominator;
        return Fraction(tempnumer, tempdenom);
    }

    // (/)
    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("dividing by zero is not allowed");
        }
        Fraction temp(other.denominator, other.numerator);
        return *this * temp;
    }

    // comparison operators
    // (==)
    bool Fraction::operator==(const Fraction &other) const
    {
        return ((numerator * other.denominator) == (other.numerator * denominator));
    }

    // (!=)
    bool Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    // (>)
    bool Fraction::operator>(const Fraction &other) const
    {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    // (<)
    bool Fraction::operator<(const Fraction &other) const
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    // (>=)
    bool Fraction::operator>=(const Fraction &other) const
    {
        return (numerator * other.denominator) >= (other.numerator * denominator);
    }

    // (<=)
    bool Fraction::operator<=(const Fraction &other) const
    {
        return (numerator * other.denominator) <= (other.numerator * denominator);
    }
    // prefix and postfix
    Fraction Fraction::operator++(int)
    {
        Fraction value_holder(numerator, denominator);
        numerator += denominator; // +1 equals to adding whole cylce of the fraction
        return value_holder;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction value_holder(numerator, denominator);
        numerator -= denominator;
        return value_holder;
    }
    Fraction &Fraction::operator++()
    {
        numerator += denominator; // +1 equals to adding whole cylce of the fraction
        return *this;
    }
    Fraction &Fraction::operator--()
    {
        numerator -= denominator;
        return *this;
    }

    // input and output
    ostream &operator<<(ostream &os, const Fraction &fraction)
    {
        if (fraction.numerator < 0)
        { // negative fraction
            if (fraction.denominator < 0)
            { // both negative, not suppsed to happen because of reduction;
            }
            else
            {
                os << -(fraction.numerator) << "/" << fraction.denominator; // so the minus is on top
                return os;
            }
        }
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
    istream &operator>>(istream &is, Fraction &fraction)
    {
        int tempnumerator, tempdenominator;
        is >> tempnumerator >> tempdenominator;
        if (tempdenominator == 0)
        {
            throw invalid_argument("dividing by zero is not allowed");
        }
        fraction.numerator = tempnumerator;
        fraction.denominator = tempdenominator;
        return is;
    }

}