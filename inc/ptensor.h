// TODO: discuss public/private vars
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


    // TODO: should we add dimension verification? Don't want to allow overflow
    // at(1, 2, 3) means term #1, vector #2, color #3
    inline double & at(int i=0, int j=0, int k=0) const { return _data[j*_shape[0]*_shape[2] + k*_shape[0] + i]; }

    PTensor();
    //PTensor(int ndim, int * shape);
    PTensor(int ndim, const int* shape);
    PTensor(const PTensor&); // copy constructor
    ~PTensor();


    // TODO: which op overloads should be inline?
    // Assignment/compound assignment ops
    PTensor & operator=(const PTensor&);
    PTensor & operator+=(const PTensor&);
    PTensor & operator-=(const PTensor&);
    PTensor & operator*=(const PTensor&);
    PTensor & operator/=(const PTensor&);

    // TODO: increment/decrement prefix/postfix ops
    PTensor & operator=(const double &rhs);
    PTensor & operator+=(const double &rhs);
    inline PTensor & operator-=(const double &rhs) { return *this += -rhs; }
    PTensor & operator*=(const double &rhs);
    PTensor & operator/=(const double &rhs);

    // Binary arithmetic ops
    const PTensor operator+(const PTensor &other) const { return PTensor(*this) += other; }
    const PTensor operator-(const PTensor &other) const { return PTensor(*this) -= other; }
    const PTensor operator*(const PTensor &other) const { return PTensor(*this) *= other; }
    const PTensor operator/(const PTensor &other) const { return PTensor(*this) /= other; }

    const PTensor operator+(const double &other) const { return PTensor(*this) += other; }
    const PTensor operator-(const double &other) const { return PTensor(*this) -= other; }
    const PTensor operator*(const double &other) const { return PTensor(*this) *= other; }
    const PTensor operator/(const double &other) const { return PTensor(*this) /= other; }

    // Unary arithmetic ops
    const PTensor operator+() const { return PTensor(*this); }
    const PTensor operator-() const { return PTensor(*this) *= -1; }

    // Comparison ops
    bool operator==(const PTensor &) const;
    bool operator!=(const PTensor &rhs) const { return !(*this == rhs); }

    // Auxiliary ops
    const PTensor transpose() const;
    PTensor batch(int j=0, int l=1) const;

    // at end because data is a flexible array member
    double * _data;
        // matrix[i][j] = data[i*shape[0]+j]
        // matrix[i][j][k] = data[i*shape[0]*shape[1] + j*shape[1] + k]
};

// Non-assignment non-member overloads
inline const PTensor operator+(const double &lhs, const PTensor &rhs) { return rhs + lhs; }
inline const PTensor operator-(const double &lhs, const PTensor &rhs) { return -rhs + lhs; }
inline const PTensor operator*(const double &lhs, const PTensor &rhs) { return rhs * lhs; }
const PTensor operator/(const double &lhs, const PTensor &rhs);
 

// TODO: is this the best place for these?
// Auxiliary ops
inline const PTensor transpose(const PTensor &p) { return p.transpose(); }
const PTensor exp(const PTensor&);
const PTensor dot(const PTensor&, const PTensor&);
const PTensor randpt(int ndim, const int* shape);

}

#endif
