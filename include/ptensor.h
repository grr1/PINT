// TODO: should we add dimension verification? Don't want to allow overflow
// TODO: operator overloads for =,+,-,*

using namespace std;

namespace pint
{

class PTensor
{
public:
    int _ndim;
    int _shape[3] = {1, 1, 1};
    int _size;
        // shape[0] = nrows = column_size
        // shape[1] = ncols = row_size
        // shape[2] = nplanes = z_size

    // TODO: discuss constant get/set with reverse priority dimensions?
    inline double getElement(int i, int j, int k) { return _data[k*_shape[2]*_shape[1] + j*_shape[1] + i]; }
    inline void setElement(int i, int j, int k, double x) { _data[k*_shape[2]*_shape[1] + j*_shape[1] + i] = x; }

    PTensor(int ndim, int * shape);
    PTensor(const PTensor&); // copy constructor
    ~PTensor();

    // Assignment/compound assignment ops
    PTensor & operator=(const PTensor&);
    PTensor & operator+=(const PTensor&);
    PTensor & operator-=(const PTensor&);
    PTensor & operator*=(const PTensor&);
    PTensor & operator/=(const PTensor&);

    // Binary arithmetic ops
    const PTensor operator+(const PTensor &other) const { return PTensor(*this) += other; }
    const PTensor operator-(const PTensor &other) const { return PTensor(*this) -= other; }
    const PTensor operator*(const PTensor &other) const { return PTensor(*this) *= other; }
    const PTensor operator/(const PTensor &other) const { return PTensor(*this) /= other; }

    // Comparison ops
    bool operator==(const PTensor &) const;
    bool operator!=(const PTensor &rhs) const { return !(*this == rhs); }

    // at end because data is a flexible array member
    double * _data;
        // matrix[i][j] = data[i*shape[0]+j]
        // matrix[i][j][k] = data[i*shape[0]*shape[1] + j*shape[1] + k]
};

}
