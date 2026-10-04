#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

    int N, M, K;

    cin >> N >> M >> K;

    vector<int> influences(N, -1);
    vector<bitset<20>> eggsday1, eggsday2(N);

    string s;
    cin >> s;

    int L = s.length();

    bitset<20> b(s);
    eggsday1.push_back((b));

    for(int i = 1; i < N; i++){
        string s;
        cin >> s;
        bitset<20> b(s);
        eggsday1.push_back(b);
    }

    for(int i = 0; i < M; i++){
        pair<int, int> p;
        cin >> p.first >> p.second;
        influences[p.second - 1] = p.first - 1;
    }

    for(int i = 1; i < K; i++){
        for(int j = 0; j < N; j++){
            if (influences[j] == -1) eggsday2[j] = eggsday1[j];
            else {
                eggsday2[j] = (eggsday1[j]) ^ (eggsday1[influences[j]]);
            } 
        }
        eggsday1 = eggsday2;
    }

    for(int i = 0; i < N; i++){
        for(int j = L - 1; j >= 0; j--){
            cout << eggsday1[i][j];
        }
        cout << " ";
    }

   return 0;
}