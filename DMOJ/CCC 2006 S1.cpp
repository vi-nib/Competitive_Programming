#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  string parent1, parent2;

  getline(cin, parent1);
  getline(cin, parent2);

  vector<pair<char, char>> options(5);

  int counter = 0;

  for (int i = 0; i < parent1.size()-1; i += 2) {
    int num = 0;
    if (parent1[i] >= 97) {
      num++;
    }
    if (parent2[i] >= 97) {
      num++;
    }
    if (parent1[i+1] >= 97) {
      num++;
    }
    if (parent2[i+1] >= 97) {
      num++;
    }
    if (num == 4) {
      options[counter] = {'a', 'a'};
      counter++;
   }
   else if (num == 3) {
     options[counter] = {'a', 'A'};
     counter++;
   }
    else if (((parent1[i] >= 97 && parent1[i+1] <= 90) || (parent1[i+1] >= 97 && parent1[i] <= 90)) && ((parent2[i] >= 97 && parent2[i+1] <= 90) || (parent2[i+1] >= 97 && parent2[i] <= 90))) {
      options[counter] = {'a', 'A'};
      counter++;
    }
    else {
      options[counter] = {'A', 'A'};
      counter++;
    }
  }

  int n;
  cin>>n;

  while (n--) {

    string baby;
    cin>>baby;

    bool babyYes = true;

    for (int i = 0; i < baby.length(); i++) {
      int num = options[i].first;
      int num2 = options[i].second;
      if ((baby[i] <= 90 && num >= 97 && num2 >= 97) || (baby[i] >= 97 && num <= 90 && num2 <= 90)) {
        cout<<"Not their baby!\n";
        babyYes = false;
        break;
      }
    }

    if (babyYes) {
      cout<<"Possible baby.\n";
    }
  }

  return 0;
  
}