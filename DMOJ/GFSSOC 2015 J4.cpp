#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int numEpisodes, numQueries;
    cin>>numEpisodes>>numQueries;

    vector<int> ratings(numEpisodes);
    vector <int> ratings_prefix_sum(numEpisodes);
    
    for (int i = 0; i < numEpisodes; i++) {
        cin>>ratings[i];

    }

    ratings_prefix_sum[0] = ratings[0];

    for (int i = 1; i < numEpisodes; i++) {
        ratings_prefix_sum[i] = ratings_prefix_sum[i - 1] + ratings[i];
    }

    while (numQueries--) {
        int a, b;
        cin>>a>>b;
        
        int answer;

        if (a == 1) {
            answer = ratings_prefix_sum[b-1];
        }

        else {
            answer = ratings_prefix_sum[b-1] - ratings_prefix_sum[a-2];
        }

        int finalAnswer = ratings_prefix_sum[numEpisodes - 1] - answer;

        cout<<finalAnswer<<"\n";

    }

    return 0;

}