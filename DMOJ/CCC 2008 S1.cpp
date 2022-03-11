#include <bits/stdc++.h>
using namespace std;

bool sortingFunction(pair<string, int> a, pair<string, int> b) {
    return a.second<b.second;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<string, int>> weather;

    string city;
    cin>>city;
    int temperature;
    cin>>temperature;

    weather.push_back(make_pair(city, temperature));

    while (city != "Waterloo") {
        cin>>city;
        cin>>temperature;
        weather.push_back(make_pair(city, temperature));
    }

    sort(weather.begin(), weather.end(), sortingFunction);

    cout<<weather[0].first<<"\n";

    return 0;

}


