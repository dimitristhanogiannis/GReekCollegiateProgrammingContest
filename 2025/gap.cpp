#include <bits/stdc++.h>
using namespace std;

bool canAchieve(string s, int k, int maxGap) {
    int roads_used = 0;
    int curr_gap = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#') {
            curr_gap = 0;
        } else {
            curr_gap++;
            if (curr_gap > maxGap) {
                // Need to place a road here
                roads_used++;
                curr_gap = 0;
            }
        }
    }
    
    return roads_used <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    
    cin >> n >> k >> s;
    
    // Binary search on the answer
    int left = 0, right = n;
    int answer = n;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAchieve(s, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    // Reconstruct the solution
    string result = s;
    int curr_gap = 0;
    
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == '#') {
            curr_gap = 0;
        } else {
            curr_gap++;
            if (curr_gap > answer) {
                result[i] = '#';
                curr_gap = 0;
            }
        }
    }
    
    cout << answer << "\n";
    cout << result << "\n";
    
    return 0;
}