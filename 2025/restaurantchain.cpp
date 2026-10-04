#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;

void solve() {
    // Read N, D, K
    int n;
    long long d;
    int k;
    if (!(cin >> n >> d >> k)) return;

    // Read x and c
    vector<long long> x(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    // 1. Find the earliest potentially conflicting position for each location i.
    // conflict_start_idx[i] is the index 'j' such that x[i] - x[j] < D, and 
    // x[i] - x[j-1] >= D (or j=0). All positions from j to i-1 are potential conflicts.
    vector<int> conflict_start_idx(n, 0);
    int current_j = 0;
    for (int i = 0; i < n; i++) {
        // Find the smallest j such that x[i] - x[j] < D is FALSE, i.e., x[i] - x[j] >= D
        // Note: x is sorted, so we can use a two-pointer approach (monotonic j).
        while (current_j < i && x[i] - x[current_j] >= d) {
            current_j++;
        }
        // Now, current_j is the first index such that x[i] - x[current_j] < D is false (or current_j == i)
        // The first conflicting index is current_j (if current_j < i).
        conflict_start_idx[i] = current_j; 
    }
    
    // 2. Determine the maximum window size needed for the mask
    int maxWindow = 0;
    for (int i = 0; i < n; i++) {
        // The conflict window is from conflict_start_idx[i] to i-1.
        int first_conflict = conflict_start_idx[i];
        if (first_conflict < i) {
            // Window size is i - first_conflict (from first_conflict up to i-1) + 1 (for current i)
            maxWindow = max(maxWindow, i - first_conflict + 1);
        }
    }

    // Heuristic Cap (maxWindow must be small enough for 2^maxWindow to pass)
    // A value around 18-20 is often used, relying on sparse DP states.
    // We will use 20 as in the original code.
    maxWindow = min(maxWindow, 20); 

    // 3. Dynamic Programming (Profile DP)
    // dp[{violations, mask}] = max_profit
    // The mask size is maxWindow. The LSB (bit 0) is the selection status of the last processed position.
    // The state transition implicitly handles the step 'i'
    map<pair<int, int>, long long> dp;
    
    // Initial state: before position 0, 0 violations, empty mask (0)
    dp[{0, 0}] = 0;

    for (int i = 0; i < n; i++) {
        map<pair<int, int>, long long> ndp;
        
        // The conflict window is from first_conflict up to i-1
        int first_conflict = conflict_start_idx[i];
        int window_size = i - first_conflict; // The number of locations in [first_conflict, i-1]

        for (auto& [state, profit] : dp) {
            int viol = state.first;
            int mask = state.second;
            
            // --- Option 1: Don't select location i ---
            // Shift mask left, new LSB is 0 (not selected)
            int newMask_skip = (mask << 1) & ((1 << maxWindow) - 1);
            pair<int, int> key_skip = {viol, newMask_skip};
            ndp[key_skip] = max(ndp[key_skip], profit);
            
            // --- Option 2: Select location i ---
            int addViol = 0;
            
            // The locations in the current mask are i-1, i-2, ..., i-maxWindow.
            // The conflicting locations are in the index range [first_conflict, i-1].
            // We only need to check the conflicts that fall within the mask's range.
            
            // Location j is a conflict if j >= first_conflict.
            // The position 'j' relative to the *current* mask is at offset:
            // offset_in_mask = (i-1) - j. 
            // The oldest element in the mask is at bit (maxWindow - 1).
            
            // We check the 'window_size' bits corresponding to the locations [first_conflict, i-1].
            // These locations are at mask offsets from maxWindow - 1 down to maxWindow - window_size.
            
            // The conflict window [first_conflict, i-1] corresponds to the part of the mask:
            // mask bits from [maxWindow - window_size] up to [maxWindow - 1]
            
            for (int bit = maxWindow - window_size; bit < maxWindow; bit++) {
                if (bit >= 0) { // Should always be true since maxWindow is min(N, 20)
                    if (mask & (1 << bit)) {
                        addViol++;
                    }
                }
            }
            
            if (viol + addViol <= k) {
                // Shift mask left, new LSB is 1 (selected)
                int newMask_select = ((mask << 1) | 1) & ((1 << maxWindow) - 1);
                pair<int, int> key_select = {viol + addViol, newMask_select};
                ndp[key_select] = max(ndp[key_select], profit + c[i]);
            }
        }
        
        dp = move(ndp); // Move states for the next iteration
    }

    // 4. Final Answer
    long long ans = 0;
    for (auto& [state, profit] : dp) {
        ans = max(ans, profit);
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}