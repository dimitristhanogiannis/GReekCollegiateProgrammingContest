#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int N, T, ans = 0;

    cin >> N >> T;

    vector<pair<long long int,long long int>> flights(N + 1);

    for(int i = 1; i <= N; i++){
        long long int ti, bi, ci;
        cin >> ti >> bi >> ci;
        flights[i] = {ti, bi - ci};
        ans += ci;
    }

    vector<long long int> closestavailable(N + 1);

    int previous = 0;

    for(int i = 1; i <= N; i++){
        while(previous < N && flights[i].first >= flights[previous + 1].first + T) previous++;
        closestavailable[i] = previous;
    }

    vector<long long int> dp(N + 1);

    for(int i = 1; i <= N; i++){
        dp[i] = max(dp[i-1], dp[closestavailable[i]] + flights[i].second);
    }

    ans += dp[N];
    
    cout << ans;

    return 0;
}