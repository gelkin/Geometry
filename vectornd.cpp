#include "vectornd.h"

VectorND::VectorND(int n)
{
    m = new std::vector<double>(n, 0);
    this->n = n;
}

VectorND::~VectorND()
{
    delete m;
}

VectorND& VectorND::operator +=(const VectorND& other)
{
    if (n != other.getN())
    {
        return *this;
    }
    for (int i = 0; i < n; ++i)
    {
        m->at(i) += other[i];
    }
    return *this;
}

VectorND& VectorND::operator -=(const VectorND& other)
{
    if (n != other.getN())
    {
        return *this;
    }
    for (int i = 0; i < n; ++i)
    {
        m->at(i) -= other[i];
    }
    return *this;
}

double VectorND::operator [](int i) const
{
    return m->at(i);
}

int VectorND::getN() const
{
    return this->n;
}
