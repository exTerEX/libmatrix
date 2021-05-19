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

#include "matrix/matrix.hpp"

namespace matrix {

template <typename T> matrix<T>::matrix(size_t __x, T __k) {
  this->row_size = __x;
  this->col_size = __x;

  this->fill_matrix(__k);
}

template <typename T> matrix<T>::matrix(size_t __x, size_t __y, T __k) {
  this->row_size = __x;
  this->col_size = __y;

  this->fill_matrix(__k);
}

template <typename T> matrix<T>::matrix(const matrix &__m) {
  this->row_size = __m.row_size;
  this->col_size = __m.col_size;

  this->data = __m.data;
}

template <typename T> matrix<T>::matrix(const std::vector<T> &__m) {
  this->row_size = __m.size();
  this->col_size = 1;

  this->data.resize(this->rows);
  for (size_t i = 0; i < this->row_size; i++) {
    this->data[i].resize(this->col_size, __m[i]);
  }
}

template <typename T> matrix<T> &matrix<T>::operator=(const matrix<T> &__m) {
  std::swap(this->col_size, __m.col_size); // Change to copy?
  std::swap(this->row_size, __m.row_size);

  std::swap(this->data, __m.data);

  return *this;
}

template <typename T> matrix<T>::matrix(const std::vector<std::vector<T>> &__m) {
  this->row_size = __m.row_size;
  this->col_size = __m.col_size;

  this->data = __m.data;
}

matrix(const T **__m) {}

matrix operator=(const T **__m) {}

template <typename T> T matrix<T>::operator()(unsigned __x, unsigned __y) {
  return this->data[__x][__y];
}

template <typename T> matrix<T> matrix<T>::operator+(const matrix<T> &__m) {
  if (this->col_size == __m.col_size && row_size == __m.row_size) {
    matrix<T> product(this->rows, this->col_size);

    for (size_t index = 0; index < this->row_size; index++) {
      for (size_t jndex = 0; jndex < this->col_size; jndex++) {
        product.data[index][jndex] = this->data[index][jndex] + __m.data[index][jndex];
      }
    }
    return product;
  } else {
    throw std::runtime_error("Incompatible matrices.");
  }
}

template <typename T> matrix<T> &matrix<T>::operator+=(const matrix<T> &__m) {
  return *this = *this + __m;
}

template <typename T> matrix<T> matrix<T>::operator-(const matrix<T> &__m) {
  if (this->col_size == __m.col_size && this->row_size == __m.row_size) {
    matrix<T> product(this->rows, this->col_size);

    for (size_t index = 0; index < this->row_size; index++) {
      for (size_t jndex = 0; jndex < this->col_size; jndex++) {
        product.data[index][jndex] = this->data[index][jndex] - __m.data[index][jndex];
      }
    }
    return product;
  } else {
    throw std::runtime_error("Incompatible matrices.");
  }
}

template <typename T> matrix<T> &matrix<T>::operator-=(const matrix &__m) {
  return *this = *this - __m;
}

template <typename T> matrix<T> &matrix<T>::operator*(const matrix<T> &__m) {
  return *this *= __m;
}

template <typename T> matrix<T> &matrix<T>::operator*=(const matrix<T> &__m) {
  if (this->col_size == __m.row_size) {
    matrix<T> n = *this;

    this->data.clear();
    this->row_size = n.row_size;
    this->col_size = __m.col_size;

    this->fill_matrix(0);

    // Matrix product(row_size, n.col_size);
    for (size_t i = 0; i < this->row_size; i++) {
      for (size_t j = 0; j < this->col_size; j++) {
        T temp = 0.0;
        for (size_t k = 0; k < n.col_size; k++) {
          temp += n.data[i][k] * __m.data[k][j];
        }
        this->data[i][j] = temp;
      }
    }
  } else {
    throw std::runtime_error("These matricies cannot be multiplied.");
  }
  return *this;
}

template <typename T> matrix<T> matrix<T>::operator*(const T __n) {
  matrix<T> product(this->row_size, this->col_size);
  for (size_t i = 0; i < this->row_size; i++) {
    for (size_t j = 0; j < this->col_size; j++) {
      product.data[i][j] = this->data[i][j] * __n;
    }
  }
  return product;
}

template <typename T> matrix<T> &matrix<T>::operator*=(const T __n) { return *this = *this * __n; }

template <typename T> matrix<T> matrix<T>::operator^(size_t __n) {
  matrix product(this->data);
  for (size_t index = 1; index <= __n; index++) {
    product *= product;
  }
  return product;
}

template <typename T> matrix<T> matrix<T>::transpose() {
  matrix<T> product(this->row_size, this->col_size);
  for (size_t i = 0; i < this->col_size; i++) {
    for (size_t j = 0; j < this->row_size; j++) {
      product(i, j) = this->data[j][i];
    }
  }
  return product;
}

template <typename T> matrix<T> matrix<T>::inverse(const matrix<T> &__m) {
  matrix<T> product(this->row_size, this->col_size);

  if (this->col_size == __m.rows) {
    for (size_t i = 0; i < this->row_size; i++) {
      for (size_t j = 0; j < this->col_size; j++) {
        product(i, j) = 0; // TODO: Some math shit that need to be implemented...
      }
    }
  } else {
    throw "Cannot find inverse of this Matrix.";
  }
  return product;
}

template <typename T> T matrix<T>::determinant(const matrix<T> &__m) {}

template <typename T> unsigned matrix<T>::shape() const { return 0; }

template <typename T> void matrix<T>::print() const {
  std::cout << "Matrix: " << std::endl;

  for (size_t i = 0; i < this->row_size; i++) {
    for (size_t j = 0; j < this->col_size; j++) {
      std::cout << "[" << this->data[i][j] << "]";
    }
    std::cout << std::endl;
  }
}

template <typename T> bool matrix<T>::operator==(const matrix<T> &__m) {
  if (this->col_size == __m.col_size && this->row_size == __m.row_size) {
    for (size_t i = 0; i < __m.col_size; i++) {
      for (size_t j = 0; j < __m.row_size; j++) {
        if (this->data[i][j] != __m.data[i][j]) {
          return false;
        }
      }
    }
    return true;
  } else {
    return false;
  }
}

template <typename T> bool matrix<T>::operator!=(const matrix<T> &__m) {
  if (this->col_size == __m.col_size && this->row_size == __m.row_size) {
    for (size_t i = 0; i < __m.col_size; i++) {
      for (size_t j = 0; j < __m.row_size; j++) {
        if (this->data[i][j] != __m.data[i][j]) {
          return true;
        }
      }
    }
    return false;
  } else {
    return true;
  }
}

template <typename T> void matrix<T>::fill(T __k) {
  this->data.resize(this->rows);
  for (size_t i = 0; i < this->rows; i++) {
    this->data[i].resize(this->col_size, __k);
  }
}

} // namespace matrix
