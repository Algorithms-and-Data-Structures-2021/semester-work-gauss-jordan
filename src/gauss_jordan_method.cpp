//
// Created by Тимур on 23.05.2021.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "gauss_jordan_method.hpp"

#define SIZE 5

using namespace std;

  vector<float> gauss_jordan_method::gauss(float a[5][5]) {
    int x[SIZE], ratio;
    int i, j, k, n;
    n = 2;

    cout << setprecision(3) << fixed;

//    cout << "Enter number of unknowns: ";
//    cin >> n;
//
//    cout << "Enter Coefficients of Augmented Matrix: " << endl;
//    for (i = 1; i <= n; i++) {
//      for (j = 1; j <= n + 1; j++) {
//        cout << "a[" << i << "]" << j << "]= ";
//        cin >> a[i][j];
//      }
//    }

    for (i = 1; i <= n; i++) {
      if (a[i][i] == 0.0) {
        cout << "Mathematical Error!";
//        exit(0);
      }
      for (j = 1; j <= n; j++) {
        if (i != j) {
          ratio = a[j][i] / a[i][i];
          for (k = 1; k <= n + 1; k++) {
            a[j][k] = a[j][k] - ratio * a[i][k];
          }
        }
      }
    }

    for (i = 1; i <= n; i++) {
      x[i] = a[i][n + 1] / a[i][i];
    }

    vector<float> result = {};

    cout << endl << "Solution: " << endl;
    for (i = 1; i <= n; i++) {
      cout << "x[" << i << "] = " << x[i] << endl;
      result.push_back(x[i]);
    }

    return result;
  }
