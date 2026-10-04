#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   long long int m,n;

   unordered_set<string> courses;

   cin >> m;

   for(int i = 0; i < m; i++){
      string st;
      cin >> st;
      courses.insert(st);
   }

   cin >> n;
   long long int count;

   for(int i = 0; i < n; i++){
      string st;
      cin >> st;
      if (courses.count(st) == 1) count++;
   }

   if (count == n) cout << 1;
   else cout << 0;

   return 0;
}