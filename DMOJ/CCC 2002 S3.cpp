#include <bits/stdc++.h>
using namespace std;

int r, c, m;

vector<char> commands;
char grid[377][82];

void printGrid() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}

pair<int, int> check(int startY, int startX, int direction) {

    int dir = direction; // 0 is up(north), 1 is right(east), 2 is down(south), 3 is left(west)

    int newX = startX;
    int newY = startY;

    for (int i = 0; i < m; i++) {
        if (commands[i] == 'F') {
            if (dir == 0) {
                newY--;
                if (grid[newY][newX] == 'X') {
                    break;
                }
                if (newY < 0 || newY >= r) {
                    break;
                }
            }
            else if (dir == 1) {
                newX++;
                if (grid[newY][newX] == 'X') {
                    break;
                }
                if (newX < 0 || newX >= c) {
                    break;
                }
            }
            else if (dir == 2) {
                newY++;
                if (grid[newY][newX] == 'X') {
                    break;
                }
                if (newY < 0 || newY >= r) {
                    break;
                }
            }
            else if (dir == 3) {
                newX--;
                if (grid[newY][newX] == 'X') {
                    break;
                }
                if (newX < 0 || newX >= c) {
                    break;
                }
            }
         }
         else if (commands[i] == 'L') {
            if (dir == 0) {
                dir = 3;
            }
            else if (dir == 1) {
                dir = 0;
            }
            else if (dir == 2) {
                dir = 1;
            }
            else if (dir == 3) {
                dir = 2;
            }
         }
         else if (commands[i] == 'R') {
            if (dir == 0) {
                dir = 1;
            }
            else if (dir == 1) {
                dir = 2;
            }
            else if (dir == 2) {
                dir = 3;
            }
            else if (dir == 3) {
                dir = 0;
            }
         }
    }

    if (newX >= 0 && newX < c && newY >= 0 && newY < r) {
        if (grid[newY][newX] != 'X') {
            return make_pair(newY, newX);
        }
    }
    return make_pair(-1, -1);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin>>r>>c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin>>grid[i][j];
        }
    }

    cin>>m;
    commands.resize(m+1);

    for (int i = 0; i < m; i++) {
        cin>>commands[i];
    }

    for (int i = 0; i < m-1; i++) {
        if (commands[i] == 'L' && commands[i+1] == 'R') {
            commands.erase(commands.begin()+i);
            commands.erase(commands.begin()+i);
            i -= 1;
        }
        else if (commands[i] == 'R' && commands[i+1] == 'L') {
            commands.erase(commands.begin()+i);
            commands.erase(commands.begin()+i);
            i -= 1;
        }
    }

    vector<pair<int, int>> locs;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != 'X') {
                pair<int, int> p0 = check(i, j, 0);
                if (p0.first != -1 && p0.second != -1) {
                    locs.push_back(p0);
                }
                else {
                    pair<int, int> p1 = check(i, j, 1);
                    if (p1.first != -1 && p1.second != -1) {
                        locs.push_back(p1);
                    }
                    else {
                        pair<int, int> p2 = check(i, j, 2);
                        if (p2.first != -1 && p2.second != -1) {
                            locs.push_back(p2);
                        }
                        else {
                            pair<int, int> p3 = check(i, j, 3);
                            if (p3.first != -1 && p3.second != -1) {
                                locs.push_back(p3);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < (int)locs.size(); i++) {
        grid[locs[i].first][locs[i].second] = '*';
    }

    printGrid();

    return 0;

}