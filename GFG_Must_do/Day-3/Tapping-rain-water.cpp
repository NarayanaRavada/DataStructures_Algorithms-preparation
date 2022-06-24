/**
.* 	  author: narayana_r
.* 	  created: 24.06.2022 18:41:34
**/

#include <bits/stdc++.h>
using namespace std;

long long tappingWater(int arr[], int n) {
	int next_max[n];
	next_max[n - 1] = arr[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if(next_max[i + 1] >= arr[i]) {
			next_max[i] = next_max[i + 1];
		} else {
        	next_max[i] = arr[i];
		}
	}

	long long water = 0;
	int prev_max = arr[0];
	for(int i = 1; i < n; i++) {
		prev_max = prev_max > arr[i] ? prev_max : arr[i];
		water += min(prev_max, next_max[i]) - arr[i];
	}

	return water;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(auto &x: arr) {
    	cin >> x;
	}

	cout << tappingWater(arr, n);
	return 0;
}
