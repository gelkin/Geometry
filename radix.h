#ifndef RADIX_H
#define RADIX_H

#define __in64 long long

class Radix
{
public:
    Radix();
    Radix(__int64 n, __int64 m);
    Radix(const Radix& other);
    Radix(__int64 value);
    double get_d();
    Radix operator+(const Radix& other);
    Radix operator-(const Radix& other);
    Radix& operator+=(const Radix& other);
    Radix& operator-=(const Radix& other);
    Radix& operator=(const Radix& other);
    Radix& operator=(__int64 value);
    Radix operator*(const Radix& other);
    Radix operator/(const Radix& other);
    Radix& normalize();
    __int64 getNumerator();
    __int64 getDenominator();
private:
    __int64 n;
    __int64 m;
    __int64 gcd(__int64 u, __int64 v);
};

#endif // RADIX_H
