#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
    // Vectorul dp[i][j] reprezintă suma maximă a notelor primite de N prieteni
    // pentru primele i platouri, având un buget total de j lei.
    vector<vector<long long >> dp(m + 1, vector<long long>(n * x + 1, 0));

    // Inițializăm cazul de bază: nu comandăm niciun platou.
    for (int j = 0; j <= n * x; j++) {
        dp[0][j] = 0;
    }

    // Cazul general.
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n * x; j++) {
            // Nu comandăm platoul i.
            dp[i][j] = dp[i - 1][j];

            // Comandăm platoul i, dacă avem suficient buget.
            if (j - p[i - 1] >= 0) {
                long long sum = dp[i-1][j - p[i - 1]];
                for (int k = 1; k <= n; k++) {
                    sum += g[k - 1][i - 1];
                }
                dp[i][j] = max(dp[i][j], sum);
            }
        }
    }

    return dp[m][n * x];
}
int task2(int n, int m, int x, vector<int>& p, vector<vector<int>>& g) {
    // Vectorul dp[i][j] reprezintă suma maximă a notelor primite de N prieteni
    // pentru primele i platouri, având un buget total de j lei.
    vector<vector<int>> dp(m + 1, vector<int>(n * x + 1, 0));

    // Inițializăm cazul de bază: nu comandăm niciun platou.
    for (int j = 0; j <= n * x; j++) {
        dp[0][j] = 0;
    }

    // Cazul general.
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n * x; j++) {
            // Nu comandăm platoul i.
            dp[i][j] = dp[i - 1][j];
// Calculăm toate combinațiile posibile de platouri comandate de fiecare tip.
            for (int k = 1; k <= min(2, j / p[i-1]); k++) {
                int sum = 0;
                for (int l = 1; l <= n; l++) {
                    sum += k * g[l-1][i-1];
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j - k * p[i-1]] + sum);
            }
        }
    }

    // Returnăm rezultatul maxim pentru bugetul total n * x.
    return dp[m][n * x];
}

int task3(int n, int m, int x, vector<int>& p, vector<vector<int>>& g) {
    // Vectorul dp[i][j][k] reprezintă suma maximă a notelor primite
    // de fiecare dintre cei N prieteni
    // pentru primele i platouri, având un buget total de j lei
    // și comandând cel mult k platouri în total.
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>
    (n * x + 1, vector<int>(n + 1, 0)));

    // Inițializăm cazul de bază: nu comandăm niciun platou.
    for (int j = 0; j <= n * x; j++) {
        for (int k = 0; k <= n; k++) {
            dp[0][j][k] = 0;
        }
    }

    // Cazul general.
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n * x; j++) {
            for (int k = 0; k <= n; k++) {
                // Nu comandăm platoul i.
                dp[i][j][k] = dp[i - 1][j][k];
                // Calculăm toate combinațiile posibile de 0, 1
                // sau 2 platouri comandate de fiecare tip.
                for (int l = 1; l <= min(2, k); l++) {
                    int sum = 0;
                    for (int pIdx = 0; pIdx < n; pIdx++) {
                        sum += l * g[pIdx][i-1];
                    }
                    if (j >= l * p[i-1]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j - l *
                        p[i-1]][k - l] + sum);
                    }
                }
            }
        }
    }

    // Returnăm suma maximă a notelor primite de fiecare dintre cei N prieteni.
    return dp[m][n * x][n];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
