#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    private:
        vector<int> p, setSize, rank;
        int numDisjoint;
    public:
        // Constructor for Union Find Disjoint Set Class
        UnionFind(int N) {
            setSize.assign(N, 1);
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++) {
                p[i] = i;
            }
            numDisjoint = N;
        }
        // finding the representative item of the set
        int findSet(int i) {
            if (p[i] == i) {
                return i;
            }
            else {
                return p[i] = findSet(p[i]);
            }
        }
        // returns number of disjoint sets
        int numDisjointSets() {
            return numDisjoint;
        }
        // returns the size of a specific disjoint set
        int size(int i) {
            return setSize[findSet(i)];
        }
        // Checking if two nodes are in same disjoint set
        bool sameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
        // connecting two nodes
        void unionSet(int i, int j) {
            if (!sameSet(i, j)) {
                numDisjoint--;
                int x = findSet(i), y = findSet(j);
                // implementing path compression
                if (rank[x] > rank[y]) {
                    p[y] = x;
                    setSize[x] += setSize[y];
                }
                else {
                    p[x] = y;
                    setSize[y] += setSize[x];
                    if (rank[x] == rank[y]) {
                        rank[y]++;
                    }
                }
            }
        }

};


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    cin>>ws;

    while (t--) {
        map<char, int> conversion;
        string pair, listNodes;
        vector<string> connections;
        while (getline(cin, pair)) {
            if (pair[0] == '*') {
                break;
            }
            else {
                connections.push_back(pair);
            }
        }
        getline(cin, listNodes);
        int numNodes = ((int)listNodes.size()/2) + 1;

        UnionFind a(numNodes);

        int looper = 0;

        for (int i = 0; i < (int)connections.size(); i++) {
            auto it1 = conversion.find(connections[i][1]);
            auto it2 = conversion.find(connections[i][3]);
            if (it1 == conversion.end()) {
                conversion[connections[i][1]] = looper;
                looper++;
            }
            if (it2 == conversion.end()) {
                conversion[connections[i][3]] = looper;
                looper++;
            }
            a.unionSet(conversion[connections[i][1]], conversion[connections[i][3]]);
        }

        int acorns = 0;
        int totSets = a.numDisjointSets();

        for (int i = 0; i < numNodes; i++) {
            if (a.size(i) == 1) {
                acorns++;
            }
        }
        int trees = totSets - acorns;

        cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s).\n";

        conversion.clear();
        connections.clear();

    }

    return 0;

}