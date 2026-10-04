#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int n, m;
   double maxincrease = -1e9;

   vector<double> temp;

   cin >> n;
   cin >> m;

   for(int i = 0; i < n; i++){
        double t;
        cin >> t;
        temp.push_back(t);
   }

   for(int i = 0; i + m - 1 < n; i++){
        double windowMin = temp[i];
        for(int j = i; j < i + m; j++){
            windowMin = min(windowMin, temp[j]);
            maxincrease = max(maxincrease, temp[j] - windowMin);
        }
   }

   cout << fixed << setprecision(6) << maxincrease;

   return 0;
}