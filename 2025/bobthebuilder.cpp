#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    string directions;
    bool ans;

    int U = 0, D = 0, R = 0,L = 0;

    cin >> x >> y;
    cin >> directions;

    int n = directions.length();

    for(int i = 0; i < n; i++){
        if (directions[i] == 'U') U++;
        if (directions[i] == 'D') D++;
        if (directions[i] == 'R') R++;
        if (directions[i] == 'L') L++;
    }

    if(x >= 0 && y >= 0){
        if (R >= x && U >= y) cout << "YES";
        else cout << "NO";
    }
    else if(x >= 0 && y < 0){
        if (R >= x && D >= abs(y)) cout << "YES";
        else cout << "NO";
    }
    else if(x < 0 && y >= 0){
        if (L >= abs(x) && U >= y) cout << "YES";
        else cout << "NO";
    }
    else if(x < 0 && y < 0){
        if (L >= abs(x) && D >= abs(y)) cout << "YES";
        else cout << "NO";
    }

   return 0;
}