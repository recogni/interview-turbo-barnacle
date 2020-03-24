#ifndef _MATRIX_H_
#define _MATRIX_H_

template <typename T, size_t M, size_t N>
class Matrix
{
   private:
    // TODO (1) : Declare storage for M and N, use any container you want.

   public:
    /*
     *  Matrix constructor, should setup all MxN elements of the matrix to
     *  the specified default value.
     */
    Matrix(const T);

    // TODO: (2) : Declare a Get which returns a `const T` based on i, j
    // TODO: (3) : Declare a GetCol and a GetRow
    // TODO: (4) : Declare the matching Set functions ^
};

#endif // _MATRIX_H_
