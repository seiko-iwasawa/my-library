#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
  int n, m;
  vector<vector<int>> matrix;

  void swap_rows(int i, int j) { swap(matrix[i], matrix[j]); }

  void swap_columns(int i, int j) {
    for (int k = 0; k < i; ++k) {
      swap(matrix[k][i], matrix[k][j]);
    }
  }

  Matrix() {}
  Matrix(int n, int m, int filler = 0)
      : n(n), m(m), matrix(n, vector<int>(m, filler)) {}
  Matrix(vector<vector<int>> matrix) : matrix(matrix) {
    n = matrix.size();
    m = (matrix.empty() ? 0 : matrix[0].size());
  }

  auto& operator[](int i) { return matrix[i]; }
};

istream& operator>>(istream& in, Matrix& a) {
  int n, m;
  in >> n >> m;
  a = Matrix(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      in >> a[i][j];
    }
  }
  return in;
}

ostream& operator<<(ostream& out, Matrix a) {
  for (int i = 0; i < a.n; ++i) {
    for (int j = 0; j < a.m; ++j) {
      out << a[i][j] << ' ';
    }
    out << '\n';
  }
  return out;
}

bool operator==(Matrix a, Matrix b) { return a.matrix == b.matrix; }

bool operator!=(Matrix a, Matrix b) { return !(a == b); }

Matrix operator-(Matrix a) {
  for (int i = 0; i < a.n; ++i) {
    for (int j = 0; j < a.m; ++j) {
      a[i][j] = -a[i][j];
    }
  }
  return a;
}

Matrix operator+(Matrix a, Matrix b) {
  assert(a.n == b.n && a.m == b.m);
  Matrix res(a.n, a.m);
  for (int i = 0; i < res.n; ++i) {
    for (int j = 0; j < res.m; ++j) {
      res[i][j] = a[i][j] + b[i][j];
    }
  }
  return res;
}

Matrix operator-(Matrix a, Matrix b) { return a + -b; }

Matrix operator*(int k, Matrix a) {
  for (int i = 0; i < a.n; ++i) {
    for (int j = 0; j < a.m; ++j) {
      a[i][j] *= k;
    }
  }
  return a;
}

Matrix operator*(Matrix a, int k) { return k * a; }

Matrix operator*(Matrix a, Matrix b) {
  assert(a.m == b.n);
  Matrix res(a.n, b.m);
  for (int i = 0; i < res.n; ++i) {
    for (int j = 0; j < res.m; ++j) {
      for (int k = 0; k < a.m; ++k) {
        res[i][j] += a[i][k] * a[k][j];
      }
    }
  }
  return res;
}

Matrix& operator+=(Matrix& a, Matrix b) { return a = a + b; }

Matrix& operator-=(Matrix& a, Matrix b) { return a = a - b; }

Matrix& operator*=(Matrix& a, Matrix b) { return a = a * b; }

Matrix& operator*=(Matrix& a, int k) { return a = k * a; }

Matrix identity_matrix(int n) {
  Matrix res(n, n);
  for (int i = 0; i < n; ++i) {
    res[i][i] = 1;
  }
  return res;
}

Matrix transpose(Matrix a) {
  Matrix res(a.m, a.n);
  for (int i = 0; i < a.n; ++i) {
    for (int j = 0; j < a.m; ++j) {
      res[j][i] = a[i][j];
    }
  }
  return res;
}

Matrix zero_matrix(int n, int m) { return Matrix(n, m); }

Matrix rotation_matrix(int n, int i, int j, double alpha) {
  Matrix res = identity_matrix(n);
  res[i][i] = res[i][j] = cos(alpha);
  res[i][j] = sin(alpha);
  res[j][i] = -sin(alpha);
}

int trace(Matrix a) {
  assert(a.n == a.m);
  int res = 0;
  for (int i = 0; i < a.n; ++i) {
    res += a[i][i];
  }
  return res;
}

int inv(vector<int> arr) {
  int res = 0;
  for (int i = 0; i < (int)arr.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      res += (arr[i] < arr[j]);
    }
  }
  return res;
}

int determinant(Matrix a) {
  assert(a.n == a.m);
  vector<int> ind;
  int d = 1;
  for (int i = 0; i < a.n; ++i) {
    int j = 0;
    for (j = 0; j < a.n; ++j) {
      if (a[i][j]) {
        break;
      }
    }
    if (j == a.n) {
      return 0;
    }
    for (int k = 0; k < a.n; ++k) {
      if (k == j || a[i][k] == 0) {
        continue;
      }
      int x = a[i][j];
      int y = a[i][k];
      d *= x;
      for (int t = 0; t < a.n; ++t) {
        a[t][k] = x * a[t][k] - y * a[t][j];
      }
    }
    for (int k = 0; k < a.n; ++k) {
      if (k != i) {
        a[k][j] = 0;
      }
    }
    ind.push_back(j);
  }
  int res = 1;
  for (int i = 0; i < a.n; ++i) {
    res *= a[i][ind[i]];
  }
  return res * (inv(ind) % 2 == 0 ? +1 : -1) / d;
}

Matrix qp(Matrix a, int k) {
  assert(a.n == a.m);
  Matrix res = identity_matrix(a.n);
  while (k) {
    if (k & 1) {
      res *= a;
    }
    a *= a;
    k >> 1;
  }
  return res;
}
