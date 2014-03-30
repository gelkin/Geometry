#include "radix.h"

Radix::Radix()
{
    this->n = 0;
    this->m = 0;
}

Radix::Radix(long long n, long long m)
{
    this->n = n;
    this->m = m;
}

Radix::Radix(const Radix &other)
{
    this->n = other.n;
    this->m = other.m;
}

Radix::Radix(long long value)
{
    operator =(value);
}

Radix Radix::operator +(const Radix& other)
{
    return Radix(this->n * other.m + other.n * this->m, this->m * other.m).normalize();
}

Radix& Radix::operator +=(const Radix& other)
{
    this->n = this->n * other.m + other.n * this->m;
    this->m = this->m * other.m;
    this->normalize();
    return *this;
}

Radix& Radix::operator -=(const Radix& other)
{
    this->n = this->n * other.m - other.n * this->m;
    this->m = this->m * other.m;
    this->normalize();
    return *this;
}

Radix Radix::operator -(const Radix& other)
{
    return Radix(this->n * other.m - other.n * this->m, this->m * other.m).normalize();
}

Radix Radix::operator *(const Radix& other)
{
    return Radix(this->n * other.n, this->m * other.m).normalize();
}

Radix Radix::operator /(const Radix& other)
{
    return Radix(this->n * other.m, this->m * other.n).normalize();
}

long long Radix::getNumerator()
{
    return n;
}

long long Radix::getDenominator()
{
    return m;
}

Radix& Radix::normalize()
{
    long long g = gcd(n, m);
    n /= g;
    m /= g;
    return *this;
}

Radix& Radix::operator=(const Radix& other)
{
    if (this == &other)
    {
        return *this;
    }
    n = other.n;
    m = other.m;
    return *this;
}

Radix& Radix::operator=(long long value)
{
    n = value;
    m = 1;
    return *this;
}

long long Radix::gcd(long long u, long long v)
{
    int shift;
    if (u == 0 || v == 0)
    {
        return u | v;
    }

    for (shift = 0; ((u | v) & 1) == 0; ++shift)
    {
        u >>= 1;
        v >>= 1;
    }
    while ((u & 1) == 0)
    {
        u >>= 1;
    }

    do
    {
        while ((v & 1) == 0)
        {
            v >>= 1;
        }
        if (u < v)
        {
            v -= u;
        }
        else
        {
            unsigned int diff = u - v;
            u = v;
            v = diff;
        }
        v >>= 1;
    } while (v != 0);

    return u << shift;
}

double Radix::get_d()
{
    return ((double)n) / m;
}
