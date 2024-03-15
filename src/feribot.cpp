#include <bits/stdc++.h>
using namespace std;

int feribot(long long N, long long K, const vector<int>& G) {
    long long left = *max_element(G.begin(), G.end());
    long long right = accumulate(G.begin(), G.end(), 0);
    int64_t ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        int64_t sum = 0;
        int cnt = 1;
        for (int i = 0; i < N + 1; i++) {
            sum += G[i];
            if (sum > mid) {
                cnt++;
                sum = G[i];
            }
        }
        if (cnt <= K) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");
    long long N, K;
    fin >> N >> K;

    vector<int> G(N+1);
    for (int i = 1; i <= N; i++) {
        fin >> G[i];
    }

    long long solutie = feribot(N, K, G);

    fout << solutie << endl;
    fin.close();
    fout.close();

    return 0;
}
