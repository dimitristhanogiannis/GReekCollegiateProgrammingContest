#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

    long long int n, s, sa = 0, sb = 0;
    vector<long long int> a, b;

    cin >> n >> s;

    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        a.push_back(ai);
        sa+=ai;
    }

    for(int i = 0; i < n; i++){
        int bi;
        cin >> bi;
        b.push_back(bi);
        sb+=bi;
    }

    if(sb > sa) cout << 0;

    else{
        sort(b.begin(), b.end());

        long long int count = 0;

        for(int i = 0; i < n; i++){
            sb += (s - b[i]);
            count++;
            if(sb > sa) break;
        }

        if(sb <= sa) cout << -1;

        else cout << count;
    }

   return 0;
}