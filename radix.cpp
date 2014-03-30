#include "radix.h"

Radix::Radix()
{
    this->n = 0;
    this->m = 0;
}

Radix::Radix(__int64 n, __int64 m)
{
    this->n = n;
    this->m = m;
}

Radix::Radix(const Radix &other)
{
    this->n = other.n;
    this->m = other.m;
}

Radix::Radix(__int64 value)
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

__int64 Radix::getNumerator()
{
    return n;
}

__int64 Radix::getDenominator()
{
    return m;
}

Radix& Radix::normalize()
{
    __int64 g = gcd(n, m);
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

Radix& Radix::operator=(__int64 value)
{
    n = value;
    m = 1;
    return *this;
}

__int64 Radix::gcd(__int64 u, __int64 v)
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
