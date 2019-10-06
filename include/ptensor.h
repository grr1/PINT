//TODO: Should we add dimension verification? Don't want 0 dimension, etc.

namespace pint
{

class PTensor
{
public:
    int _ndim;
    int _shape[3];
        // shape[0] = nrows = column_size
        // shape[1] = ncols = row_size

    inline double get2DElement(int i, int j) { return _data[i*_shape[0] + j]; }
    inline void set2DElement(int i, int j, double x) { _data[i*_shape[0] + j] = x; }

    inline double get3DElement(int i, int j, int k) { return _data[i*_shape[0]*_shape[1] + j*_shape[1] + k]; }
    inline double set3DElement(int i, int j, int k, double x) { _data[i*_shape[0]*_shape[1] + j*_shape[1] + k] = x; }

    PTensor(int ndim, int shape[])
    {
        int length = 1;

        _ndim = ndim;

        for (int i = 0; i < _ndim; i++)
        {
            _shape[i] = shape[i];
            length *= shape[i];
        }

        _data = (double *)(length * sizeof(double));
    }

private: // at end because data is a flexible array member
    double * _data; // matrix[i][j] = data[i*shape[0]+j]
};

}
