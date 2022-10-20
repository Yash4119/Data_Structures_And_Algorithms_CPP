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
		int n;
		cin >> n;

		vector<int>str(n), hel(n);

		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> hel[i];
		}

		long long int time = 0;

		int s = 0;
		int e = n - 1;

		while (s < e) {
			time += str[s];
			if (s + 1 < e) {
				str[s + 1] += hel[s];
			}
			time += str[e];
			if (e - 1 > s) {
				str[e - 1] += hel[e];
			}
			if (s + 1 >= e) {

				time += (min(hel[s], hel[e]));
			}
			s++;
			e--;
		}

		if (s == e) {
			time += str[s];
		}

		cout << time << endl;

	}

	return 0;
}
