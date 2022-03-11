#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;

bool visited(string start, string end) {
  queue<string> q;
  map<string, bool> visited;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    string current = q.front();
    q.pop();
    for (auto next : adj[current]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }

  return visited[end];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    string newLink;
    cin>>newLink;
    
    vector<pair<string, string>> connections;
    
    string string1;

    getline(cin, string1);


      while (n--) {

          while (string1.find("</HTML>") == -1) {
          int num = 0;
          while (num < string1.length()) {
             if (string1.find("A HREF=\"", num) != -1) {
              int start = string1.find("A HREF=\"", num);
              int end = string1.find("\"", start+8);
              string link2;
              for (int i = start+8; i < end; i++) {
                  link2 += string1[i];
              }
              connections.push_back({newLink, link2});
              num += end;
          }
            else {
                break;
          }

        }
          
        getline(cin, string1);
    }

    if (n != 0) {
      string linkNext;
      cin>>linkNext;
      newLink = linkNext;
      getline(cin, string1);
    }

}

    for (int i = 0; i < connections.size(); i++) {
      string a = connections[i].first;
      string b = connections[i].second;
      adj[a].push_back(b);
    }


    for (int i = 0; i < connections.size(); i++) {
      cout<<"Link from "<<connections[i].first<<" to "<<connections[i].second<<"\n";
    }

    string pair1, pair2;
    getline(cin, pair1);
    getline(cin, pair2);

    while (pair1 != "The End" && pair2 != "The End") {
        bool path = visited(pair1, pair2);
        if (path) {
          cout<<"Can surf from "<<pair1<<" to "<<pair2<<".\n";
        }
        if (!path) {
          cout<<"Can't surf from "<<pair1<<" to "<<pair2<<".\n";
        }
        getline(cin, pair1);
        getline(cin, pair2);

    }

    return 0;
    
}