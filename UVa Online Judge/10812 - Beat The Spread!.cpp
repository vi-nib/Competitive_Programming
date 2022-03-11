#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  int sum, difference;
  int value, answer1, answer2;

  while (n--) {
    cin>>sum>>difference;
    if (sum < difference) {
      cout<<"impossible\n";
    }
    else if (sum == difference) {
      cout<<sum<<" "<<0<<"\n";
    }
    else {
      value = sum - difference;
      if (value % 2 == 0) {
        answer1 = value / 2;
        answer2 = sum - answer1;
        cout<<max(answer1, answer2)<<" "<<min(answer1, answer2)<<"\n";
      }
      else {
          cout<<"impossible\n";
      }
    }
  }

  return 0;
  
}