#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Box {
  vector<int> dimensions;
  int volume;
};

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<Box> boxDimensions(n);

    for (int i = 0; i < n; i++) {
        vector<int> dimensions(3);
        cin>>dimensions[0]>>dimensions[1]>>dimensions[2];
        sort(dimensions.begin(), dimensions.end());
        boxDimensions[i].dimensions = dimensions;
        boxDimensions[i].volume = dimensions[0] * dimensions[1] * dimensions[2];
    }

    int m;
    cin>>m;

    for (int i = 0; i < m; i++) {

        int answer = 1e15;
        vector<int> dimensions(3);
        cin>>dimensions[0]>>dimensions[1]>>dimensions[2];
        sort(dimensions.begin(), dimensions.end());

        for (int j = 0; j < n; j++) {
            if (boxDimensions[j].dimensions[0] >= dimensions[0] && boxDimensions[j].dimensions[1] >= dimensions[1] && boxDimensions[j].dimensions[2] >= dimensions[2]) {
                answer = min(answer, boxDimensions[j].volume);
            }
        }

        if (answer == 1e15) {
            cout<<"Item does not fit."<<"\n";
        }
        else {
            cout<<answer<<"\n";
        }
        
    }

    return 0;

}