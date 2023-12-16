#include <iostream>
using namespace std;
void print(const int *a, int n) {
  for(int i=0;i<n;++i) {
    cout<<a[i]<<' ';
  }
  cout<<endl;
}
void print1(int a[], int n) {
  for(int i=0;i<n;++i) {
    cout<<a[i]<<' ';
  }
  cout<<endl;
}
int main() {
  const int n=10;
  int *a=new int[n];
  for(int i=0;i<n;++i) {
    a[i]=i;
  }
  print(a+3, n-3);
  print1(a+3, n-3);
  delete []a;
  return 0;
}