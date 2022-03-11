#include <bits/stdc++.h>
using namespace std;

struct computer {

  string name;
  int calculation;

};

bool sorting(computer a, computer b) {
  if (a.calculation == b.calculation) {
    return a.name < b.name;
  }
  return a.calculation > b.calculation;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  vector<computer> options(N);

  for (int i = 0; i < N; i++) {
    string compName;
    cin>>compName;

    int R, S, D;
    cin>>R>>S>>D;

    int calc = (2 * R) + (3 * S) + D;
    options[i].name = compName;
    options[i].calculation = calc;
  }

  sort(options.begin(), options.end(), sorting);

  if ((int)options.size() > 1) {
    cout<<options[0].name<<"\n";
    cout<<options[1].name<<"\n";
  }

  else if ((int)options.size() == 1){
    cout<<options[0].name<<"\n";
  }


  return 0;
}