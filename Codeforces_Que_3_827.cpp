#include <bits/stdc++.h>

using namespace std;

int count_col(int i, int j , vector<vector<char>>&vec) {
	int count = 0;

	if (i == 0) {
		int temp = 1;
		for (int k = 1; k < 8; k++) {
			if (vec[k][j] == vec[k - 1][j])temp++;
		}
		count = max(count, temp);
	}
	if (j == 0) {
		int temp = 1;
		for (int k = 1; k < 8; k++) {
			if (vec[i][k] == vec[i][k - 1])temp++;
		}
		count = max(count, temp);
	}
	// else if (j < 8) {
	// 	int temp = 0;
	// 	for (int k = j; k < 8; k++) {
	// 		if (vec[i][k] == vec[i][j])temp++;
	// 	}
	// 	count = max(count, temp);
	// }
	// else if (j >= 0) {
	// 	int temp = 0;
	// 	for (int k = j; k >= 0; k++) {
	// 		if (vec[i][k] == vec[i][j])temp++;
	// 	}
	// 	count = max(count, temp);
	// }
	return count;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {
		vector<vector<char>>vec(8, vector<char>(8));

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> vec[i][j];
			}
		}

		string res = "";

		for (int i = 0; i < 8; i++) {
			int ans = 0;
			if ((vec[0][i] == 'R' || vec[0][i] == 'B'))ans = count_col(0, i, vec);
			if (ans == 8) {
				res = vec[0][i];
				break;
			}
		}

		if (res.size() == 0) {
			for (int i = 0; i < 8; i++) {
				int ans = 0;
				if ((vec[i][0] == 'R' || vec[i][0] == 'B'))ans = count_col(i, 0, vec);
				if (ans == 8) {
					res = vec[i][0];
					break;
				}
			}
		}
		cout << res << endl;

	}
	return 0;
}
