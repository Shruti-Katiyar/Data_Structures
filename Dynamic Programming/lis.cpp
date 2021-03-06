#include <iostream>
#include <vector>
using namespace std;

int lis(int *a, int n) {
	// Calculate the length of LIS
	int dp[1000];
	for (int i = 0 ; i < n ; i++) {
		dp[i] = 1;
	}

	for (int i = 1 ; i < n ; i++) {
		for (int j = 0 ; j < i ; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 1;
	int i = 0;
	for (int j = 0 ; j < n ; j++) {
		if (ans < dp[j]) {
			ans = dp[j];
			i = j;
		}
	}


	// Printing the LIS
	vector<int> v;
	v.push_back(a[i]);
	int len = ans;
	len--;
	for (int j = i - 1; j >= 0 ; j--) {
		if (dp[j] == len and v[v.size() - 1] > a[j]) {
			v.push_back(a[j]);
			len--;
			if (len == 0) {
				break;
			}
		}
	}

	for (int i = v.size() - 1 ; i >= 0 ; i--) {
		cout << v[i] << " ";
	}
	cout << endl;

	return ans;
}

int main() {



	int a[] = {1,3,2,6,4,7,3,0};
	int n = sizeof(a) / sizeof(int);


	cout << "LIS: " << lis(a, n) << endl;
	return 0;
}


