#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N;
   cin >> N;
   vector<long long> h(N);
   for(int i = 0; i < N; i++) cin >> h[i];

   if(N == 0) {
      cout << 0 << "\n";
      return 0;
   }

   vector<long long> left_max(N), right_max(N);
   left_max[0] = h[0];
   for(int i = 1; i < N; i++) left_max[i] = max(left_max[i-1], h[i]);

   right_max[N-1] = h[N-1];
   for(int i = N-2; i >= 0; i--) right_max[i] = max(right_max[i+1], h[i]);

   long long total_water = 0;
   for(int i = 0; i < N; i++) {
      long long water = min(left_max[i], right_max[i]) - h[i];
      if(water > 0) total_water += water;
   }

   cout << total_water << "\n";
   return 0;
}