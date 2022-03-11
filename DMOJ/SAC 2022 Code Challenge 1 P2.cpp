#include <bits/stdc++.h>
using namespace std;

double const pi = M_PI;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int L, H, W;
  cin>>L>>H>>W;

  int D;
  cin>>D;

  double radius = (double) D / 2.0;

  double volumeRectangle = (double)(L * H * W);

  double volumeCylinder = pi * (double)pow(radius, 2) * (double)H;

  double leftOver = volumeRectangle - volumeCylinder;

  cout<<leftOver<<"\n";

  return 0;
  
}