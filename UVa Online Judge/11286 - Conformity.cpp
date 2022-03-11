#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	map<vector<int>, int> freq;
	vector<int> courses;
	vector<int> popularity;
	
	while (cin>>N) {
	    if (N == 0) {
	        break;
	    }
	    for (int i = 0; i < N; i++) {
	        int a, b, c, d, e;
	        cin>>a>>b>>c>>d>>e;
	        courses.push_back(a);
	        courses.push_back(b);
	        courses.push_back(c);
	        courses.push_back(d);
	        courses.push_back(e);
	        sort(courses.begin(), courses.end());
	        freq[courses]++;
	        courses.clear();
	    }
	    for (auto i : freq) {
	        popularity.push_back(i.second);
	    }
	    sort(popularity.rbegin(), popularity.rend());
	    int count = popularity[0];
	    bool done = false;
	    for (int i = 0; i < popularity.size(); i++) {
	        if (popularity[i] > popularity[i+1]) {
	            cout<<count<<"\n";
	            done = true;
	            break;
	        }
	        else if (popularity[i] == popularity[i+1]) {
	            count += popularity[i+1];
	        }
	    }
	    if (!done) {
	        cout<<count<<"\n";
	    }
	    freq.clear();
	    popularity.clear();
	}
	
	return 0;
	
}
