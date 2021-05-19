/*
 * MIT License
 *
 * Copyright (c) 2019 Andreas Sagen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <exception>
#include <iostream>
#include <utility>
#include <vector>

namespace matrix {

template <typename T = int> class matrix {
private:
  size_t row_size, col_size;
  std::vector<std::vector<T>> data;

protected:
public:
  matrix() = default;

  matrix(size_t __x, T __k = 0);

  matrix(size_t __x, size_t __y, T __k = 0);

  ~matrix() = default;

  matrix(const matrix &__m);

  matrix(const std::vector<T> &__m);

  matrix(const std::vector<std::vector<T>> &__m);

  matrix(const T **__m);

  matrix operator=(const matrix &__m);

  matrix operator=(const std::vector<std::vector<T>> &__m);

  matrix operator=(const T **__m);

  /**
   * @brief Matrix subscript operator to access cell values.
   *
   * @param __x Row to access.
   * @param __y Col to access.
   * @return T Selected cell value.
   */
  T operator()(unsigned __x, unsigned __y);

  /**
   * @brief Assignment addition between two equal shaped matrices.
   *
   * @param __m Matrix to be added.
   * @return Matrix& Added matrix.
   */
  matrix operator+(const matrix &__m);

  /**
   * @brief Assignment addition between two equal shaped matrices.
   *
   * @param __m Matrix to be added.
   * @return Matrix& Added matrix.
   */
  matrix &operator+=(const matrix &__m);

  /**
   * @brief Subtraction between two equal shaped matrices.
   *
   * @param __m Matrix to be subtracted.
   * @return Matrix& Subtracted matrix.
   */
  matrix operator-(const matrix &__m);

  /**
   * @brief Assignment subtraction between two equal shaped matrices.
   *
   * @param __m Matrix to be subtracted.
   * @return Matrix& Subtracted matrix.
   */
  matrix &operator-=(const matrix &__m);

  /**
   * @brief Matrix multiplication operator
   *
   * @param __m multiplicand as a matrix object.
   * @return Matrix& Product of multiplier and multiplicand as a matrix object.
   */
  matrix &operator*(const matrix &__m);

  /**
   * @brief Matrix multiplication operator
   *
   * @param __m multiplicand as a matrix object.
   * @return Matrix& Product of multiplier and multiplicand as a matrix object.
   */
  matrix &operator*=(const matrix &__m);

  /**
   * @brief Scalar multiplication operator
   *
   * @param __n Multiplicand as a scalar value.
   * @return Matrix Product of multiplier and multiplicand.
   */
  matrix operator*(const T __n);

  /**
   * @brief Scalar multiplication operator
   *
   * @param __n Multiplicand as a scalar value.
   * @return Matrix& Product of multiplier and multiplicand.
   */
  matrix &operator*=(const T __n);

  matrix operator^(size_t n);

  matrix transpose();

  matrix inverse(const matrix &__m);

  T determinant(const matrix &__m);

  unsigned shape() const;

  void print() const;

  bool operator==(const matrix &__m);

  bool operator!=(const matrix &__m);

  void fill(T __k);
};

} // namespace matrix

#endif // MATRIX_MATRIX_HPP
