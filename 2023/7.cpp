#include <bits/stdc++.h>
using namespace std;

vector<int> parent, length;

int find(int x){
   if (parent[x] != x) parent[x] = find(parent[x]);
   return parent[x];
}

bool same(int x, int y){
   return find(x) == find(y);
}

void unite(int x, int y){
   int a = find(x);
   int b = find(y);

   if(length[a] < length[b]) swap(a,b);
   length[a] += length[b];
   parent[b] = a;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   long long int N, M;
   vector<char> ans;

   cin >> N >> M;

   for(int i = 0; i <= 2 * N; i++){
      parent.push_back(i);
      length.push_back(1);
   }

   for (int i = 0; i < M; i++){
      int n, m;
      cin >> n >> m;
      if (n == abs(m)){
         if(m >= 0) ans.push_back('E');
         else {
            ans.push_back('C');
            break;
         }
      }
      else {
         if (m >= 0){
            if (same(n, m) || same(n + N, m + N)) ans.push_back('E');
            else{
               unite(n, m);
               unite(n + N, m + N);
               if (find(n) == find(n + N)) {
                  ans.push_back('C');
                  break;
               }
               else ans.push_back('N');
            }
         }
         else{
            m = abs(m);
            if (same(n, m + N) || same(n, m + N)) ans.push_back('E');
            else{
               unite(n, m + N);
               unite(n + N, m);
               if (find(n) == find(n + N)) {
                  ans.push_back('C');
                  break;
               }
               else ans.push_back('N');
            }
         }
      }
   }

   for(int i = 0; i < ans.size(); i++){
      cout << ans[i] << "\n";
   }

   return 0;
}