#include "pint.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace pint;

PTensor::PTensor()
{
    _ndim = 0;
    _shape[0] = _shape[1] = _shape[2] = 0;
    _size = 0;
    _data = NULL;

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

    _size = 1;
    for (int i = 0; i < _ndim; i++)
    {
        _shape[i] = shape[i];
        _size *= _shape[i];
    }
    _data = (double *)malloc(sizeof(double)*_size);
}

PTensor::PTensor(const PTensor& t)
{
    this->_ndim = t._ndim;
    this->_size = t._size;
    this->_shape[0] = this->_shape[1] = this->_shape[2] = 1;

    for (int i = 0; i < _ndim; i++)
    {
        this->_shape[i] = t._shape[i];
    }

    this->_data = (double *)malloc(sizeof(double)*this->_size);
    memcpy(this->_data, t._data, sizeof(double)*this->_size);
}

PTensor::~PTensor()
{
    if (_data != NULL)
    {
        free(_data);
    }
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

    for (int i = 0; i < _ndim; i++)
    {
        this->_shape[i] = rhs._shape[i];
    }
    if (this->_size != rhs._size)
    {
        if (this->_data != NULL)
        {
            free(this->_data);
        }
        this->_size = rhs._size;
        this->_data = (double *)malloc(sizeof(double)*this->_size);
    }
    memcpy(this->_data, rhs._data, sizeof(double)*this->_size);
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

// Double assignment ops
PTensor & PTensor::operator=(const double &rhs)
{
    for (int i = 0; i < _size; i++) { this->_data[i] = rhs; }

    return *this;
}

PTensor & PTensor::operator+=(const double &rhs)
{
    for (int i = 0; i < _size; i++) { this->_data[i] += rhs; }

    return *this;
}

PTensor & PTensor::operator*=(const double &rhs)
{
    for (int i = 0; i < _size; i++) { this->_data[i] *= rhs; }

    return *this;
}

PTensor & PTensor::operator/=(const double &rhs)
{
    for (int i = 0; i < _size; i++) { this->_data[i] /= rhs; }

    return *this;
}

// double div
const PTensor pint::operator/(const double &lhs, const PTensor &rhs)
{
    PTensor p(rhs);

    for (int i = 0; i < p._size; i++) { p._data[i] = lhs/p._data[i]; }

    return p;
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

// Tranpose
const PTensor PTensor::transpose() const
{
    int shape[3];
    shape[0] = this->_shape[1];
    shape[1] = this->_shape[0];
    shape[2] = this->_shape[2];
    PTensor t(this->_ndim, shape);

    for (int k = 0; k < t._shape[2]; k++)
    {
        for (int i = 0; i < t._shape[0]; i++)
        {
            for (int j = 0; j < t._shape[1]; j++)
            {
                t.at(i,j,k) = this->at(j,i,k);
            }
        }
    }

    return t;
}

PTensor PTensor::batch(int j, int mbs) const
{
    if (j+mbs >= _shape[1])
    {
        printf("Batch range error\n");
        exit(1);
    }

    PTensor b;
    b._ndim = this->_ndim;
    b._shape[0] = this->_shape[0];
    b._shape[1] = mbs;
    b._shape[2] = this->_shape[2];
    b._size = sizeof(double)*b._shape[0]*b._shape[1]*b._shape[2];
    b._data = &(this->at(0,j,0));

    return b;
}


// Exp
const PTensor pint::exp(const PTensor& a)
{
    PTensor b(a);
    for (int i = 0; i < a._size; i++) { b._data[i] = std::exp(a._data[i]); }

    //printf("exp a=\n");
    //printPTensor(a);
    //printf("exp b=\n");
    //printPTensor(b);

    return b;
}

// Dot prod
const PTensor pint::dot(const PTensor& a, const PTensor& x)
{
    if (a._shape[1] != x._shape[0])
    {
        printf("Incompatible matrix dimensions\n");
        exit(1);
    }
    
    if (a._shape[2] != x._shape[2])
    {
        printf("Unequal matrix planes\n");
        exit(1);
    }

    int b_shape[3];
    b_shape[0] = a._shape[0];
    b_shape[1] = x._shape[1];
    b_shape[2] = a._shape[2];

    PTensor b(3, b_shape);

    for (int i = 0; i < b._shape[0]; i++)
    {
        for (int j = 0; j < b._shape[1]; j++)
        {
            for (int k = 0; k < b._shape[2]; k++)
            {
                double dot = 0;
                for (int h = 0; h < a._shape[1]; h++)
                {
                    dot += a.at(i,h,k)*x.at(h,j,k);
                }
                b.at(i,j,k) = dot;
            }
        }
    }

    //printf("dot b=\n");
    //printPTensor(b);

    return b;
}

// Rand init
const PTensor pint::randpt(int ndim, const int* shape)
{
    PTensor p(ndim, shape);

    for (int i = 0; i < p._size; i++)
    {
        p._data[i] = (double)rand() / RAND_MAX;
    }

    return p;
}
