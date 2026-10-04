#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cost of k single tickets
ll singleCost(ll k, ll a, ll b) {
    return b * k + a * k * (k + 1) / 2;
}

// Cost of m double tickets
ll doubleCost(ll m, ll c, ll d) {
    return d * m + c * m * (m + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        ll bestK = 0, bestM = 0;
        ll bestCost = LLONG_MAX;

        // Continuous candidate
        double denom = 4.0 * a + c;
        double numer = 2.0 * a * n + 2.0 * b + a - d - 0.5 * c;
        double mstar = denom > 0 ? numer / denom : 0.0;

        // Helper to consider a candidate m
        auto consider = [&](ll m) {
            if (m < 0) return;
            ll mcap = (n + 1) / 2; // max needed doubles
            if (m > mcap) m = mcap;
            ll k = max(0LL, n - 2 * m);
            ll cost = singleCost(k, a, b) + doubleCost(m, c, d);
            if (cost < bestCost) {
                bestCost = cost;
                bestK = k;
                bestM = m;
            }
        };

        // Check neighborhood around continuous candidate
        ll base = ll(floor(mstar));
        for (ll m = base - 2; m <= base + 2; ++m) consider(m);

        // Always check the boundaries
        consider(0);
        consider((n + 1) / 2);
        consider(n / 2); // also check floor(n/2)

        cout << bestK << " " << bestM << "\n";
    }

    return 0;
}