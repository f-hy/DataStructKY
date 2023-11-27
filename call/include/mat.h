//
// Created by f on 2023/11/27.
//

#ifndef MAT_H
#define MAT_H
#include<iostream>
#include<vector>
#include<armadillo>
#include <boost/rational.hpp>
// using namespace arma;
// using namespace boost;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::getline;
using arma::mat;
arma::mat readMat();
vector<mat> readMats();
#endif //MAT_H
