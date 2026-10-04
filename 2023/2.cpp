#include <bits/stdc++.h>
using namespace std;

long long int N, M;
vector<long long int> lakes;
vector<vector<bool>> grid, visited;

long long int dfs(int start_i, int start_j){
   long long int size = 0;
   
   stack<pair<int, int>> st;
   st.push({start_i, start_j});
   visited[start_i][start_j] = true;
   
   while (!st.empty()) {
      auto [i, j] = st.top();
      st.pop();
      size++;
      
      if (i > 0 && !visited[i-1][j] && grid[i-1][j]) {
         visited[i-1][j] = true;
         st.push({i-1, j});
      }
      if (j > 0 && !visited[i][j-1] && grid[i][j-1]) {
         visited[i][j-1] = true;
         st.push({i, j-1});
      }
      if (i + 1 < N && !visited[i+1][j] && grid[i+1][j]) {
         visited[i+1][j] = true;
         st.push({i+1, j});
      }
      if (j + 1 < M && !visited[i][j+1] && grid[i][j+1]) {
         visited[i][j+1] = true;
         st.push({i, j+1});
      }
   }
   
   return size;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N >> M;

   grid.assign(N, vector<bool>(M));
   visited.assign(N, vector<bool>(M, false));

   for (int i = 0; i < N; i++){
      string s;
      cin >> s;
      for (int j = 0; j < M; j++){
         grid[i][j] = (s[j] == '1');
      }
   }

   for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
         if (grid[i][j] && !visited[i][j]) {
            lakes.push_back(dfs(i, j));
         }
      }
   }

   sort(lakes.begin(), lakes.end());

   cout << lakes.size() << "\n";

   for(int i = 0; i < lakes.size(); i++){
      cout << lakes[i];
      if (i < lakes.size() - 1) cout << " ";
   }
   cout << "\n";
          
   return 0;
}