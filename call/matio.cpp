//
// Created by f on 2023/11/27.
//
#include"mat.h"

arma::mat readMat() {
  int rows, cols;
  std::cin >> rows >> cols;
  arma::mat A(rows, cols);
  std::istringstream iss;
  double numerator, denominator;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::string a;
      std::cin >> a;
      switch (a[0]) {
        case '/': {
          a = a.substr(1);
          iss.str(a);
          std::getline(iss, a, '/');
          numerator = std::stod(a);
          iss >> denominator;
          A(i, j) = static_cast<double>(numerator / denominator);
          break;
        }
        default: {
          A(i, j) = std::stod(a);
          break;
        }
      }
    }
  }
  return A;
}

vector<mat> readMats() {
  int nmats;
  std::cin >> nmats;
  vector<mat> mats(nmats);
  for(auto &mat:mats){
    mat = readMat();
  }
  return mats;
};
