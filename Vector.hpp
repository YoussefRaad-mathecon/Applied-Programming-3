#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <vector>
#include <cassert>
#include <cmath>

template<typename T>
class Vector
{
private:
    std::vector<T> mData; 

public:


    Vector(int size = 0) : mData(size, T{}) {}



    Vector(const Vector<T>& otherVector) : mData(otherVector.mData) {}



    int size() const { return mData.size(); }



    T& operator[](int i) {
        assert(i >= 0 && i < size());
        return mData[i];
    }



    T const& operator[](int i) const {
        assert(i >= 0 && i < size());
        return mData[i];
    }




    Vector<T>& operator=(const Vector<T>& otherVector) {
        mData = otherVector.mData;
        return *this;
    }



    Vector<T> operator-() const {
        Vector<T> result(size());
        for (int i = 0; i < size(); ++i) {
            result[i] = -mData[i];
        }
        return result;
    }




    Vector<T> operator+(const Vector<T>& v1) const {
        assert(size() == v1.size());
        Vector<T> result(size());
        for (int i = 0; i < size(); ++i) {
            result[i] = mData[i] + v1.mData[i];
        }
        return result;
    }

    Vector<T> operator-(const Vector<T>& v1) const {
        assert(size() == v1.size());
        Vector<T> result(size());
        for (int i = 0; i < size(); ++i) {
            result[i] = mData[i] - v1.mData[i];
        }
        return result;
    }


    Vector<T> operator*(T scalar) const {
        Vector<T> result(size());
        for (int i = 0; i < size(); ++i) {
            result[i] = mData[i] * scalar;
        }
        return result;
    }


    double CalculateNorm(int p = 2) const {
        double sum = 0.0;
        for (const T& value : mData) {
            sum += std::pow(std::abs(value), p);
        }
        return std::pow(sum, 1.0 / p);
    }


    std::vector<T> const& getStorage() const {
        return mData;
    }
};

#endif // VECTORHEADERDEF
