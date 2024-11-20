#include <vector>
using namespace std;

int find_lis(const vector<int> &a) {
	int lis = 0;
	vector<int> dp(a.size(), 1);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) { dp[i] = max(dp[i], dp[j] + 1); }
		}
		lis = max(lis, dp[i]);
	}
	return lis;
}