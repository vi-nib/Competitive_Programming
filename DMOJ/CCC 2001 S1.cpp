#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    string hand;
    cin>>hand;

    // Determining suits

    string clubs;
    int x = hand.find('D');
    clubs = hand.substr(1, x-1);

    string diamonds;
    int y = hand.find('H');
    int location = y - x;
    diamonds = hand.substr(x+1, location-1);

    string hearts;
    int g = hand.find('S');
    int distance = g - (location+x);
    hearts = hand.substr(location+x + 1, distance-1);

    string spades;
    spades = hand.substr(g+1, hand.length() - g);

    // for clubs

    int clubPoints = 0;

    map<char, int> clubsOccurrences;

    for (int i = 0; i < clubs.length(); i++) {
        clubsOccurrences[clubs[i]]++;
    }

    if (clubsOccurrences.size() == 0) {
        clubPoints += 3;
    }

    else if (clubsOccurrences.size() == 1) {
        clubPoints += 2;
        clubPoints += 4 * clubsOccurrences['A'] + 3 * clubsOccurrences['K'] + 2 * clubsOccurrences['Q'] + 1 * clubsOccurrences['J'];
    }

    else if (clubsOccurrences.size() == 2) {
        clubPoints += 1;
        clubPoints += 4 * clubsOccurrences['A'] + 3 * clubsOccurrences['K'] + 2 * clubsOccurrences['Q'] + 1 * clubsOccurrences['J'];
    }

    else {
        clubPoints += 4 * clubsOccurrences['A'] + 3 * clubsOccurrences['K'] + 2 * clubsOccurrences['Q'] + 1 * clubsOccurrences['J'];
    }

    // for diamonds

    int diamondPoints = 0;

    map<char, int> diamondsOccurrences;

    for (int i = 0; i < diamonds.length(); i++) {
        diamondsOccurrences[diamonds[i]]++;
    }

    if (diamondsOccurrences.size() == 0) {
        diamondPoints += 3;
    }

    else if (diamondsOccurrences.size() == 1) {
        diamondPoints += 2;
        diamondPoints += 4 * diamondsOccurrences['A'] + 3 * diamondsOccurrences['K'] + 2 * diamondsOccurrences['Q'] + 1 * diamondsOccurrences['J'];
    }

    else if (diamondsOccurrences.size() == 2) {
        diamondPoints += 1;
        diamondPoints += 4 * diamondsOccurrences['A'] + 3 * diamondsOccurrences['K'] + 2 * diamondsOccurrences['Q'] + 1 * diamondsOccurrences['J'];
    }

    else {
        diamondPoints += 4 * diamondsOccurrences['A'] + 3 * diamondsOccurrences['K'] + 2 * diamondsOccurrences['Q'] + 1 * diamondsOccurrences['J'];
    }

    // for hearts

    int heartPoints = 0;

    map<char, int> heartsOccurrences;

    for (int i = 0; i < hearts.length(); i++) {
        heartsOccurrences[hearts[i]]++;
    }

    if (heartsOccurrences.size() == 0) {
        heartPoints += 3;
    }

    else if (heartsOccurrences.size() == 1) {
        heartPoints += 2;
        heartPoints += 4 * heartsOccurrences['A'] + 3 * heartsOccurrences['K'] + 2 * heartsOccurrences['Q'] + 1 * heartsOccurrences['J'];
    }

    else if (heartsOccurrences.size() == 2) {
        heartPoints += 1;
        heartPoints += 4 * heartsOccurrences['A'] + 3 * heartsOccurrences['K'] + 2 * heartsOccurrences['Q'] + 1 * heartsOccurrences['J'];
    }

    else {
        heartPoints += 4 * heartsOccurrences['A'] + 3 * heartsOccurrences['K'] + 2 * heartsOccurrences['Q'] + 1 * heartsOccurrences['J'];
    }

    // for spades

    int spadePoints = 0;

    map<char, int> spadesOccurrences;

    for (int i = 0; i < spades.length(); i++) {
        spadesOccurrences[spades[i]]++;
    }

    if (spades.length() == 0) {
        spadePoints += 3;
    }

    else if (spadesOccurrences.size() == 1) {
        spadePoints += 2;
        spadePoints += 4 * spadesOccurrences['A'] + 3 * spadesOccurrences['K'] + 2 * spadesOccurrences['Q'] + 1 * spadesOccurrences['J'];
    }

    else if (spadesOccurrences.size() == 2) {
        spadePoints += 1;
        spadePoints += 4 * spadesOccurrences['A'] + 3 * spadesOccurrences['K'] + 2 * spadesOccurrences['Q'] + 1 * spadesOccurrences['J'];
    }

    else {
        spadePoints += 4 * spadesOccurrences['A'] + 3 * spadesOccurrences['K'] + 2 * spadesOccurrences['Q'] + 1 * spadesOccurrences['J'];
    }

    int total = clubPoints + diamondPoints + heartPoints + spadePoints;

    // Printing out results in proper format

    cout<<"Cards Dealt"<<" "<<"Points"<<"\n";
    cout<<"Clubs ";
    for (int i = 0; i < clubs.length(); i++) {
        cout<<clubs[i]<<" ";
    }
    cout<<clubPoints<<"\n";

    cout<<"Diamonds ";
    for (int i = 0; i < diamonds.length(); i++) {
        cout<<diamonds[i]<<" ";
    }
    cout<<diamondPoints<<"\n";

    cout<<"Hearts ";
    for (int i = 0; i < hearts.length(); i++) {
        cout<<hearts[i]<<" ";
    }
    cout<<heartPoints<<"\n";

    cout<<"Spades ";
    for (int i = 0; i < spades.length(); i++) {
        cout<<spades[i]<<" ";
    }
    cout<<spadePoints<<"\n";

    cout<<" Total "<<total<<"\n";

    return 0;

}
