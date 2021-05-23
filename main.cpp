#include <iostream>
#include <vector>
#include "gauss_jordan_method.hpp"

#define SIZE 10

using namespace std;

int main(int argc, char *argv[]) {
  vector<float> result =  gauss();

  for (int i = 0; i < result.size(); i++) {
    cout << result.at(i) << " !!!" << endl;
  }

  return 0;
}