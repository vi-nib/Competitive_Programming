#include <bits/stdc++.h>
using namespace std;

bool sortFunction(pair<char, string> one, pair<char, string> two) {

    int length = one.second.size();
    int length2 = two.second.size();

    return length < length2;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin>>k;

    vector<pair<char, string>> huffman(k);

    for (int i = 0; i < k; i++) {

        char character;
        cin>>character;

        string value;
        cin>>value;

        huffman[i] = {character, value};
    }

    string code;
    cin>>code;

    sort(huffman.begin(), huffman.end(), sortFunction);

    int i = 0;

    vector<char> decoder;

    while (i <= (code.size() - huffman[0].second.size())) {

        for (int j = 0; j < k; j++) {
            int index = code.find(huffman[j].second, i);
            if (index == i) {
                decoder.push_back(huffman[j].first);
                i += huffman[j].second.size();
                break;
            }
        }
    }

    for (int i = 0; i < (int)decoder.size(); i++) {
        cout<<decoder[i];
    }
    
    return 0;

}