#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   long long int N, M;
   queue<pair<long long int, long long int>> R;
   vector<pair<long long int, long long int>> ans;

   cin >> N >> M;

   /*for(int i = 0; i < N; i++){
        long long int n;
        cin >> n;
        R.push(make_pair(i + 1,n));
   }

   while(!R.empty()){
        if(R.front().second > M) {
            long long int element = R.front().second, pos = R.front().first;
            element -= M;
            R.pop();
            R.push(make_pair(pos, element));
        }
        else {
            long long int sequence = R.front().first;
            R.pop();
            cout << sequence << " ";
        }
   }*/

    for(int i = 0; i < N; i++){
        long long int n, times;

        cin >> n;

        if(n % M != 0) times = (n / M) + 1;
        else times = (n / M);
        
        ans.push_back(make_pair(times, i + 1));
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < N; i++){
        cout << ans[i].second << " ";
    }


   return 0;
}