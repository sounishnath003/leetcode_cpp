#include <bits/stdc++.h>

using namespace std ;
typedef long long ll  ;
const int inf = 2e9+18;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> A(n), B(m);
	fo(i, n){
		cin >> A[i];
	}
	fo(i, m){
		cin >> B[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	// using forward DP / Push DP intution
	fo(i, n){
		for(int j = 0; j < m; j++){
			if(A[i] == B[j]){
				dp[i + 1][j + 1] = 1 + dp[i][j];
			}else{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
		debug() << imie(dp);
	}
	cout << "maximum uncrossed lines: " << dp[n][m];
}

