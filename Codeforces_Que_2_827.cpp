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
    int n; cin >> n;

    unordered_map<int, int>mp;

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      mp[temp]++;
    }

    bool flag = false;
    for (auto it : mp) {
      if (it.second > 1) {
        flag = true;
        break;
      }
    }

    if (flag) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }
  }

  return 0;
}
