#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, U, D, F;
    
    while (cin>>H>>U>>D>>F) {
        if (H == 0) {
            break;
        }
        double percentage = (double) F / (double) 100;
        double reductionEachDay = percentage * U;

        double snailPosition = 0.0;
        int index = 0;
         while (snailPosition <= H) {
             double reductionToday = U-(reductionEachDay*index);
             if (reductionToday >= 0) {
                 snailPosition += reductionToday;
                 if (snailPosition > H) {
                    cout<<"success on day "<<index+1<<"\n";
                    break;
                }
            }
            snailPosition -= D;
            if (snailPosition < 0) {
                cout<<"failure on day "<<index+1<<"\n";
                break;
            }
            index++;
        }
    }

    return 0;
}