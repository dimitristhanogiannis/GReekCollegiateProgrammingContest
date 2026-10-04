#include <bits/stdc++.h>
using namespace std;

bool isCapital(char c) {
   return (c >= 'A' && c <= 'Z');
}

bool isLowercase(char c) {
   return (c >= 'a' && c <= 'z');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}


int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   long long int n;
   stack<char> storage;

   cin >> n;

   for(int i = 0; i < n; i++){
      char c;
      cin >> c;
      if (isLowercase(c)) storage.push(c);
      else if (isCapital(c)){
         if (storage.empty()) {
            storage.push(c);
            break;
         }
         if (storage.top() == toLower(c)) storage.pop();
         else break;
      } 
      else break;
   }

   if (storage.empty()) cout << 1;
   else cout << 0;

   return 0;
}