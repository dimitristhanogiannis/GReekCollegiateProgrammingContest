#include <bits/stdc++.h>
using namespace std;

long long int cost(char a, char b){
    if (a == b) return 0;
    else return 1; 
}

long long int edit_distance(string a, string b){
    long long int A = a.length() + 1;
    long long int B = b.length() + 1;

    vector<vector<long long int>> distance(A, vector<long long> (B));
    distance[0][0] = 0;
    
    for(int i = 1; i < A; i++){
        distance[i][0] = i;
    }

    for(int j = 1; j < B; j++){
        distance[0][j] = j;
    }

    for(int i = 1; i < A; i++){
        for(int j = 1; j < B; j++){
            distance[i][j] = min({distance[i-1][j] + 1, distance[i][j-1] + 1, distance[i-1][j-1] + cost(a[i-1],b[j-1])});
        }
    }

    return distance[A-1][B-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int N;
    vector<long long int> positions;
    vector<string> secwords, parwords;

    cin >> N;

    for(int i = 0; i < 10; i++){
        long long int pos;
        cin >> pos;
        positions.push_back(pos);
    }

    for(int i = 0; i < 10; i++){
        string s;
        cin >> s;
        secwords.push_back(s);
    }

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        parwords.push_back(s);
    }

    for(int i = 0; i < 10; i++){
        cout << edit_distance(secwords[i], parwords[positions[i]-1]) << " "; 
    }

   return 0;
}