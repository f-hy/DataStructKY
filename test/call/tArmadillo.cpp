//
// Created by f on 2023/11/27.
//
#include<iostream>
#include<armadillo>
#include <boost/rational.hpp>
#include"mat.h"
using namespace std;
using namespace arma;
using namespace boost;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); //freopen(#x ".out", "w", stdout);

int main() {
  ios::sync_with_stdio(false);
  file(arma);
  // mat m = readMat();
  const vector<mat> mats = readMats();
  for(const auto& mat:mats){
    cout<<mat<<endl;
  }
  cout<<mats[0]*mats[1]<<endl;
  return 0;
}
