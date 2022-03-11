#include <bits/stdc++.h>
using namespace std;
#define int long long

int SZ, P;

int findCenter(int size) {
    int x = ceil((double)size/2);
    return x;
}


void solve(int x1, int y1, int x2, int y2, int length, int odd1, int odd2, int topLow, int topHigh) {

    // top
    int line = y1+1;
    int column = x1;

    // left
    int line2 = y1;
    int column2 = column - length;

    // bottom
    int line3 = line2 - length;
    int column3 = column2 + 1;

    // right
    int line4 = line3 + 1;
    int column4 = y2;

    int topL = topLow;
    int topH = topHigh;
    int leftLow = topH + 1;
    int leftHigh = leftLow + length;
    int bottomLow = leftHigh + 1;
    int bottomHigh = bottomLow + length;
    int rightLow = bottomHigh + 1;
    int rightHigh = rightLow + length;
    
    if (P == odd1) {
        cout<<"Line = "<<x1<<", column = "<<y1<<".\n";
    }
    else if (P == odd2) {
        cout<<"Line = "<<x2<<", column = "<<y2<<".\n";
    }


    else if (P >= topL && P <= topH) {
        for (int i = topL; i <= topH; i++) {
            if (P == i) {
                break;
            }
            column--;
        }
        cout<<"Line = "<<line<<", column = "<<column<<".\n";
    }

    else if (P >= leftLow && P <= leftHigh) {
        for (int i = leftLow; i <= leftHigh; i++) {
            if (P == i) {
                break;
            }
            line2--;
        }
        cout<<"Line = "<<line2<<", column = "<<column2<<".\n";
    }


    else if (P >= bottomLow && P <= bottomHigh) {
        for (int i = bottomLow; i <= bottomHigh; i++) {
            if (P == i) {
                break;
            }
            column3++;
        }
        cout<<"Line = "<<line3<<", column = "<<column3<<".\n";
    }


    else if (P >= rightLow && P <= rightHigh) {
        for (int i = rightLow; i <= rightHigh; i++) {
            if (P == i) {
                break;
            }
            line4++;
        }
        cout<<"Line = "<<line4<<", column = "<<column4<<".\n";
    }

}


signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin>>SZ>>P) {
        if (SZ == 0 && P == 0) {
            break;
        }
        int center = findCenter(SZ);
        
        int firstOddSquare = 1;
        int secondOddSquare = 1;

        for (int i = 1; i <= SZ-2; i+=2) {
            int first = pow(i, 2);
            int second = pow(i+2, 2);
            if (P >= first && P <= second) {
                firstOddSquare = first;
                secondOddSquare = second;
            }
        }

        int xFirst = center, yFirst = center;
        int xSecond = center, ySecond = center;

        for (int i = 1; i < sqrt(firstOddSquare); i+=2) {
            xFirst++;
            yFirst++;
        }

        for (int i = 1; i < sqrt(secondOddSquare); i+=2) {
            xSecond++;
            ySecond++;
        }

        int length = sqrt(firstOddSquare);

        int topMin = firstOddSquare + 1;
        int topMax = topMin + length;

        solve(xFirst, yFirst, xSecond, ySecond, length, firstOddSquare, secondOddSquare, topMin, topMax);

    }

    return 0;
    
}