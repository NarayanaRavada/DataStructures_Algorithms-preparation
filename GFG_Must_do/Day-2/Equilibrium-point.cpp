/**
.* 	  author: narayana_r
.* 	  created: 23.06.2022 07:15:46
**/

#include <bits/stdc++.h>
using namespace std;

int equilibrium(long long arr[], int n) {
	long long sum = 0;
	for(int i = 0; i < n; i++) {
    	sum += arr[i];
	}

	int curr_sum = 0, idx = -1;
	for(int i = 0; i < n; i++) {
    	if(curr_sum == sum - curr_sum - arr[i]) {
			idx = i + 1;
			break;
		}
		curr_sum += arr[i];
	}

	return idx;
}

int main() {
	int n;
	cin >> n;
	long long arr[n];
	for(auto &x: arr) {
    	cin >> x;
	}

	cout << equilibrium(arr, n);
	
	return 0;
}
