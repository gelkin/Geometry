#ifndef VECTORND_H
#define VECTORND_H

#include <vector>

class VectorND
{
public:
    VectorND(int n);
    virtual ~VectorND();
    VectorND& operator +=(const VectorND& other);
    VectorND& operator -=(const VectorND& other);
    double operator[](int i) const;
    int getN() const;
private:
    int n;
    std::vector<double>* m;
};

#endif // VECTORND_H
