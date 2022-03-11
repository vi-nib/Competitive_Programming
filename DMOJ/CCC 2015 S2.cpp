#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int J, A;
  cin>>J>>A;

  vector<int> jerseyRequirements(J+1);

  for (int i = 1; i <= J; i++) {
    char size;
    cin>>size;
    
    if (size == 'S') {
      jerseyRequirements[i] = 0;
    }
    else if (size == 'M') {
      jerseyRequirements[i] = 1;
    }   
    else {
      jerseyRequirements[i] = 2; 
    }

  }

  int count = 0;

  for (int i = 1; i <= A; i++) {
    int number;
    char size;
    cin>>size;
    cin>>number;
    int sizeNumber;
    if (size == 'S') {
      sizeNumber = 0;
    }
    else if (size == 'M') {
      sizeNumber = 1;
    }
    else {
      sizeNumber = 2;
    }
    if (1 <= number && number <= J && jerseyRequirements[number] >= sizeNumber) {
      count++;
      jerseyRequirements[number] = -5;
    }
  }

  cout<<count<<"\n";

  return 0;
  
}