#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N = 10;

  while (N--) {

    int tripCost;
    cin>>tripCost;

    double first, second, third, fourth;
    cin>>first>>second>>third>>fourth;

    int numAttendingBrunch;
    cin>>numAttendingBrunch;

    int numFirst = (int)(numAttendingBrunch * first);
    int numSecond = (int)(numAttendingBrunch * second);
    int numThird = (int)(numAttendingBrunch * third);
    int numFourth = (int)(numAttendingBrunch * fourth);

    if (numFirst + numSecond + numThird + numFourth != numAttendingBrunch) {
      double max = fmax(first, fmax(second, fmax(third, fourth)));

      if (max == first) {
        numFirst += (numAttendingBrunch - (numFirst + numSecond + numThird + numFourth));
      }
      if (max == second) {
        numSecond += (numAttendingBrunch - (numFirst + numSecond + numThird + numFourth));
      }
      if (max == third) {
        numThird += (numAttendingBrunch - (numFirst + numSecond + numThird + numFourth));
      }
      if (max == fourth) {
        numFourth += (numAttendingBrunch - (numFirst + numSecond + numThird + numFourth));
      }
       
    }

    int moneyFirst = numFirst * 12;
    int moneySecond = numSecond * 10;
    int moneyThird = numThird * 7;
    int moneyFourth = numFourth * 5;

    double totalRaised = (moneyFirst + moneySecond + moneyThird + moneyFourth)/2.0;
    if (totalRaised < tripCost) {
      cout<<"YES\n";
    }
    else {
      cout<<"NO\n";
    }
  }

  return 0;

}