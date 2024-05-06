#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include "Vector.hpp"
#include <vector>
#include <cassert>

template<typename T>
class Matrix
{
private:
    std::vector<T> mData;
    int mNumRows, mNumCols; 

public:

    Matrix(int numRows, int numCols) : mNumRows(numRows), mNumCols(numCols), mData(numRows * numCols, T{}) {}

    T& operator()(int i, int j) {
        assert(i >= 0 && i < mNumRows);
        assert(j >= 0 && j < mNumCols);
        return mData[i * mNumCols + j];
    }

    T const& operator()(int i, int j) const {
        assert(i >= 0 && i < mNumRows);
        assert(j >= 0 && j < mNumCols);
        return mData[i * mNumCols + j];
    }



    int GetNumberOfRows() const { return mNumRows; }



    int GetNumberOfColumns() const { return mNumCols; }





    Matrix<T> operator-() const {
        Matrix<T> result(mNumRows, mNumCols);
        for (int i = 0; i < mData.size(); ++i) {
            result.mData[i] = -mData[i];
        }
        return result;
    }



    Matrix<T> operator+(const Matrix<T>& m1) const {
        assert(mNumRows == m1.mNumRows && mNumCols == m1.mNumCols);
        Matrix<T> result(mNumRows, mNumCols);
        for (int i = 0; i < mData.size(); ++i) {
            result.mData[i] = mData[i] + m1.mData[i];
        }
        return result;
    }



    Matrix<T> operator-(const Matrix<T>& m1) const {
        assert(mNumRows == m1.mNumRows && mNumCols == m1.mNumCols);
        Matrix<T> result(mNumRows, mNumCols);
        for (int i = 0; i < mData.size(); ++i) {
            result.mData[i] = mData[i] - m1.mData[i];
        }
        return result;
    }



    Matrix<T> operator*(T scalar) const {
        Matrix<T> result(mNumRows, mNumCols);
        for (int i = 0; i < mData.size(); ++i) {
            result.mData[i] = mData[i] * scalar;
        }
        return result;
    }



    std::vector<T> const& getStorage() const {
        return mData;
    }
};



template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v) {
    assert(m.GetNumberOfColumns() == v.size());
    Vector<T> result(m.GetNumberOfRows());
    for (int i = 0; i < m.GetNumberOfRows(); ++i) {
        for (int j = 0; j < m.GetNumberOfColumns(); ++j) {
            result[i] += m(i, j) * v[j];
        }
    }
    return result;
}

template<typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m) {
    assert(v.size() == m.GetNumberOfRows());
    Vector<T> result(m.GetNumberOfColumns());
    for (int i = 0; i < m.GetNumberOfColumns(); ++i) {
        for (int j = 0; j < m.GetNumberOfRows(); ++j) {
            result[i] += v[j] * m(j, i);
        }
    }
    return result;
}

#endif // MATRIXHEADERDEF
