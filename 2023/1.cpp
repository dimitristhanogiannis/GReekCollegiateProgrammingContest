#include <bits/stdc++.h>
using namespace std;

bool sortbyx(tuple<char, double, double> &a, tuple<char, double, double> &b){
   return get<1>(a) > get<1>(b);
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   long long int n;
   vector<tuple<char, double, double>> alloys;
   vector<char> dominants;
   
   cin >> n;

   for(int i = 0; i < n; i++){
      char c;
      double x;
      double y;
      cin >> c >> x >> y;
      alloys.push_back(make_tuple(c, x, y));
   }

   sort(alloys.begin(), alloys.end(), sortbyx);

   dominants.push_back(get<0>(alloys[0]));

   for(int i = 0; i < n; i++){

   }

   return 0;
}