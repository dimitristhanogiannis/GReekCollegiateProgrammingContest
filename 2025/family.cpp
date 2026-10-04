#include <bits/stdc++.h>
using namespace std;

vector<int> parent1, length1;
vector<int> parent2, length2;

int find1(int x){
   if (parent1[x] != x) parent1[x] = find1(parent1[x]);
   return parent1[x];
}

bool same1(int x, int y){
   return find1(x) == find1(y);
}

void unite1(int x, int y){
   int a = find1(x);
   int b = find1(y);

   if(length1[a] < length1[b]) swap(a,b);
   length1[a] += length1[b];
   parent1[b] = a;
}

int find2(int x){
   if (parent2[x] != x) parent2[x] = find2(parent2[x]);
   return parent2[x];
}

bool same2(int x, int y){
   return find2(x) == find2(y);
}

void unite2(int x, int y){
   int a = find2(x);
   int b = find2(y);

   if(length2[a] < length2[b]) swap(a,b);
   length2[a] += length2[b];
   parent2[b] = a;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int n, m;

   cin >> n >> m;

   for(int i = 0; i <= n; i++){
      parent1.push_back(i);
      length1.push_back(1);
   }

   for(int i = 0; i <= n; i++){
      parent2.push_back(i);
      length2.push_back(1);
   }

   for (int i = 0; i < m; i++){
      int u, v, c;
      cin >> u >> v >> c;
      if(c == 1) unite1(u, v);
      else unite2(u, v);
   }

   /*vector<unordered_set<int>> neighbours1(n+1);
   vector<unordered_set<int>> neighbours2(n+1);
   vector<int> ans(n+1, -1);
   
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         if(same1(i,j)) neighbours1[i].insert(j);
      }
   }

   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         if(same2(i,j)) neighbours2[i].insert(j);
      }
   }

   for(int i = 1; i <= n; i++){
      for(auto& j : neighbours2[i]) if(neighbours2[i].count(j) == neighbours1[i].count(j)) ans[i]++;
   }

   for(int i = 1; i <= n; i++){
      cout << ans[i] << " ";
   }*/

   vector<pair<int, int>> parents(n+1, {0, 0});

   for(int i = 1; i <= n; i++){
      parents[i] = {find1(i), find2(i)};
   }

   map<pair<int, int>, int> components;

   for(int i = 1; i <= n; i++){
      components[parents[i]]++;
   }

   for(int i = 1; i <= n; i++){
      cout << components[parents[i]] - 1 << " ";
   }

   return 0;
}