#ifndef RADIX_H
#define RADIX_H

class Radix
{
public:
    Radix();
    Radix(long long n, long long m);
    Radix(const Radix& other);
    Radix(long long value);
    double get_d();
    Radix operator+(const Radix& other);
    Radix operator-(const Radix& other);
    Radix& operator+=(const Radix& other);
    Radix& operator-=(const Radix& other);
    Radix& operator=(const Radix& other);
    Radix& operator=(long long value);
    Radix operator*(const Radix& other);
    Radix operator/(const Radix& other);
    Radix& normalize();
    long long getNumerator();
    long long getDenominator();
private:
    long long n;
    long long m;
    long long gcd(long long u, long long v);
};

#endif // RADIX_H
