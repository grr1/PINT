#include "pint.h"

#include <algorithm>
#include <stdio.h>
#include <cstring>

using namespace pint;

PTensor::PTensor()
{
    _ndim = 1;
    _shape[0] = _shape[1] = _shape[2] = 1;
    _size = sizeof(double);
    _data = (double *)malloc(_size);
}

/*PTensor::PTensor(int ndim, int * shape)
{
    _ndim = min(ndim, 3);

    _size = sizeof(double);
    for (int i = 0; i < _ndim; i++)
    {
        _shape[i] = shape[i];
        _size *= shape[i];
    }

    _data = (double *)malloc(_size);
}*/

PTensor::PTensor(int ndim, const int* shape)
{
    _ndim = min(ndim, 3);
    _shape[0] = _shape[1] = _shape[2] = 1;

    _size = sizeof(double);
    for (int i = 0; i < _ndim; i++)
    {
        _shape[i] = shape[i];
        _size *= shape[i];
    }

    _data = (double *)malloc(_size);
}

PTensor::PTensor(const PTensor& t)
{
    this->_ndim = t._ndim;
    this->_size = t._size;

    for (int i = 0; i < _ndim; i++)
    {
        this->_shape[i] = t._shape[i];
    }

    this->_data = (double *)malloc(this->_size);
    std::memcpy(this->_data, t._data, this->_size);
}

PTensor::~PTensor()
{
    free(_data);
}


// Assignment/compound assignment ops

PTensor & PTensor::operator=(const PTensor &rhs)
{
    if (this == &rhs) { return *this; }

    /*if (this->_size != rhs._size)
    {
        printf("Unequal PTensor sizes\n");
        exit(1);
    }*/

    this->_ndim = rhs._ndim;
    this->_size = rhs._size;

    for (int i = 0; i < _ndim; i++)
    {
        this->_shape[i] = rhs._shape[i];
    }

    free(this->_data);
    _data = (double *)malloc(this->_size);
    memcpy(this->_data, rhs._data, this->_size);
    return *this;
}

PTensor & PTensor::operator+=(const PTensor &rhs)
{
    if (this->_size != rhs._size)
    {
        printf("Unequal PTensor sizes\n");
        exit(1);
    }

    for (int i = 0; i < _size; i++) { this->_data[i] += rhs._data[i]; }

    return *this;
}

PTensor & PTensor::operator-=(const PTensor &rhs)
{
    if (this->_size != rhs._size)
    {
        printf("Unequal PTensor sizes\n");
        exit(1);
    }

    for (int i = 0; i < _size; i++) { this->_data[i] -= rhs._data[i]; }

    return *this;
}

PTensor & PTensor::operator*=(const PTensor &rhs)
{
    if (this->_size != rhs._size)
    {
        printf("Unequal PTensor sizes\n");
        exit(1);
    }

    for (int i = 0; i < _size; i++) { this->_data[i] *= rhs._data[i]; }

    return *this;
}

PTensor & PTensor::operator/=(const PTensor &rhs)
{
    if (this->_size != rhs._size)
    {
        printf("Unequal PTensor sizes\n");
        exit(1);
    }

    for (int i = 0; i < _size; i++) { this->_data[i] /= rhs._data[i]; }

    return *this;
}

// = double
PTensor & PTensor::operator=(const double &rhs)
{
    for (int i = 0; i < _size; i++) { this->_data[i] = rhs; }

    return *this;
}


// Comparison op
bool PTensor::operator==(const PTensor &rhs) const
{
    if (this == &rhs) { return true; }

    if (this->_size != rhs._size) { return false; }

    for (int i = 0; i < _size; i++)
    {
        if (this->_data[i] != rhs._data[i])
        {
            return false;
        }
    }

    return false;
}

// Exp
const PTensor exp(const PTensor a)
{
    PTensor b(a);
    for (int i = 0; i < a._size; i++) { b._data[i] = exp(a._data[i]); }

    return b;
}
// Dot prod
const PTensor dot(const PTensor a, const PTensor x)
{
    if (a.shape[1] != x.shape[0])
    {
        printf("Incompatible matrix dimensions\n");
        exit(1);
    }
    
    if (a._shape[2] != x.shape[2])
    {
        printf("Unequal matrix planes\n");
        exit(1);
    }

    int b_shape[3];
    b_shape[0] = a.shape[0];
    b_shape[1] = x.shape[1];
    b_shape[2] = a.shape[2];

    PTensor b(a._ndim, b_shape);

    for (int i = 0; i < b._shape[0]; i++)
    {
        for (int j = 0; j < b._shape[1]; j++)
        {
            for (int k = 0; k < b._shape[2]; k++)
            {
                int dot = 0;
                for (int h = 0; h < a._shape[1]; h++)
                {
                    dot += a.at(i,h,,k)*b.at(h,j,k);
                }
                b.at(i,j,k) = dot;
            }
        }
    }

    return b;
}

// Rand init
const PTensor ptrand(int ndim, const int* shape)
{
    PTensor p(ndim, shape);

    for (int i = 0; i < p._size; i++)
    {
        p._data[i] = rand();
    }

    return p;
}
