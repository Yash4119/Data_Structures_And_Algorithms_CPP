#include <bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>>arr(m, vector<int>(2));
		vector<int>vis(n, -1);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> arr[i][j];

			}
			vis[arr[i][0] - 1] = 0;
		}

		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (vis[i] == -1) {
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}

	return 0;
}
