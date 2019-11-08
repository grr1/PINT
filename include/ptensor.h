// TODO: should we add dimension verification? Don't want to allow overflow
// TODO: discuss public/private vars
// TODO: actually implement dot prod/matrix mult
// TODO: add rand inits
#ifndef PTENSOR_H
#define PTENSOR_H

using namespace std;

namespace pint
{

class PTensor
{
public:
    int _ndim;
    int _size;
    int _shape[3];
        // shape[0] = nrows = column_size
        // shape[1] = ncols = row_size
        // shape[2] = nplanes = z_size (ncolors)

    // at(1, 2, 3) means term #1, vector #2, color #3
    inline double & at(int i=0, int j=0, int k=0) { return _data[k*_shape[1]*_shape[0] + j*_shape[0] + i]; }
    inline double getElement(int i=0, int j=0, int k=0) { return _data[k*_shape[1]*_shape[0] + j*_shape[0] + i]; }
    inline void setElement(double x=0, int i=0, int j=0, int k=0) { _data[k*_shape[1]*_shape[0] + j*_shape[0] + i] = x; }

    PTensor();
    //PTensor(int ndim, int * shape);
    PTensor(int ndim, const int* shape);
    PTensor(const PTensor&); // copy constructor
    ~PTensor();

    // Assignment/compound assignment ops
    PTensor & operator=(const PTensor&);
    PTensor & operator+=(const PTensor&);
    PTensor & operator-=(const PTensor&);
    PTensor & operator*=(const PTensor&);
    PTensor & operator/=(const PTensor&);

/*    PTensor & operator=(const double &rhs) { return *this += PTensor(this->_ndim, this->_shape, rhs); }
    PTensor & operator+=(const double &rhs) { return *this += PTensor(this->_ndim, this->_shape, rhs); }
    PTensor & operator-=(const double &rhs) { return *this += PTensor(this->_ndim, this->_shape, rhs); }
    PTensor & operator*=(const double &rhs) { return *this += PTensor(this->_ndim, this->_shape, rhs); }
    PTensor & operator/=(const double &rhs) { return *this += PTensor(this->_ndim, this->_shape, rhs); }
*/
    // Binary arithmetic ops
    const PTensor operator+(const PTensor &other) const { return PTensor(*this) += other; }
    const PTensor operator-(const PTensor &other) const { return PTensor(*this) -= other; }
    const PTensor operator*(const PTensor &other) const { return PTensor(*this) *= other; }
    const PTensor operator/(const PTensor &other) const { return PTensor(*this) /= other; }

/*    const PTensor operator+(const double &other) const { return PTensor(*this) += other; }
    const PTensor operator-(const double &other) const { return PTensor(*this) -= other; }
    const PTensor operator*(const double &other) const { return PTensor(*this) *= other; }
    const PTensor operator/(const double &other) const { return PTensor(*this) /= other; }
*/

    // Comparison ops
    bool operator==(const PTensor &) const;
    bool operator!=(const PTensor &rhs) const { return !(*this == rhs); }

    // Auxiliary ops

    // at end because data is a flexible array member
    double * _data;
        // matrix[i][j] = data[i*shape[0]+j]
        // matrix[i][j][k] = data[i*shape[0]*shape[1] + j*shape[1] + k]
};

const PTensor dot(PTensor, PTensor);
PTensor ptrand(int ndim, const int* shape);

}

#endif
