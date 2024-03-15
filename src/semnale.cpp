#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i=2; i <= n; i++) {
        result = (result % mod * i % mod) % mod;
    }
    return result;
}
long long inverse(long long x, long long mod) {
    long long y = mod - 2;
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}
long long combinari(int n, int k) {
    if (k > n) {
        return 0;
    }
    long long numarator = 1;
    for (int i = n; i > n-k; i--) {
        numarator = (numarator * i) % mod;
    }
    long long numitor = 1;
    for (int i = 2; i <= k; i++) {
        numitor = (numitor * i) % mod;
    }
    return (numarator * inverse(numitor, mod)) % mod;
}

int type1(int x, int y) {
    long long ans = combinari(x+1, y) % mod;
    return ans;
}

int type2(int x, int y) {
    // int i;
    long long ans = combinari(x+1, 2) * combinari(x+y-3, y-2);
    return ans;
}

int main() {
    freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

    switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << endl;
	}

    return 0;
}
