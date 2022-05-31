/**
.* 	  author: narayana_r
.* 	  created: 31.05.2022 17:41:31
**/

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {

	long long sum = arr[0], best = arr[0];
	for(int i = 1; i < n; i++) {
		sum = sum < 0 ? arr[i] : sum + arr[i];
		best = best > sum ? best : sum;
	}

	return best;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		int arr[n];
		for(auto &num: arr) {
			cin >> num;
		}
		
		cout << maxSubarraySum(arr, n);
		cout << "\n";
	}
	return 0;
}
