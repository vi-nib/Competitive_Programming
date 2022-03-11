#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int grid[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>grid[i][j];
        }
    }

    /* Rotation of 180 Degrees Right and Left Characteristics
    - Elements in first row are in descending order (ex. 9 6 4)
    - Elements in first column are in descending order (ex. 9 7 3)
    */

    /* Rotation of 90 Degrees Right Characteristics
    - Elements in first row are in descending order (ex. 4 3 1)
    - Elements in first column are in ascending order (ex. 4 6 9)
    */

    /* Rotation of 90 Degrees Left Characteristics
    - Elements in first row are in ascending order (ex. 3 7 9)
    - Elements in first column are in descending order (ex. 3 2 1)
    */

    /* Rotation of 270 Degrees Right Characteristics
    - Same as 90 degrees left
    */

    /* Rotation of 270 Degrees Left Characteristics
    - Same as 90 degrees right
    */

    /* Rotation of 360 Degrees Right Characteristics
    - Same as original
        - Elements in first row are ascending (ex. 1 2 3)
        - Elements in first column are ascending (ex. 1 2 3)
    */
 
    // Determining the rotation

    bool rotation90right = false;
    bool rotation90left = false;
    bool rotation180 = false;
    bool normal = false;

    for (int i = 0; i < N - 1; i++) {
        if (grid[0][i] > grid[0][i + 1] && grid[i][0] < grid[i + 1][0]) {
            rotation90right = true;
        }
        else if (grid[0][i] < grid[0][i + 1] && grid[i][0] > grid[i + 1][0]) {
            rotation90left = true;
        }
        else if (grid[0][i] > grid[0][i + 1] && grid[i][0] > grid[i + 1][0]) {
            rotation180 = true;
        }
        else {
            normal = true;
        }
    }

    if (normal) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    if (rotation180) {
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    if (rotation90left) {
        for (int j = 0; j < N; j++) {
            for (int i = N - 1; i >= 0; i--) {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    if (rotation90right) {
        for (int j = N - 1; j >= 0; j--) {
            for (int i = 0; i < N; i++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;

}