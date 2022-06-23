/**
.* 	  author: narayana_r
.* 	  created: 23.06.2022 07:39:55
**/

#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) { 
	sort(arr, arr + n);
	sort(dep, dep + n);
	int i = 1, j = 0, count = 1, res = 1;
	while(i < n && j < n) {
		if(arr[i] <= dep[j]) {
			i++;
			count++;
		} else {
			count--;
			j++;
		}

		res = max(res, count);
	}

	return res;
}

int main() {
	int n;
	cin >> n;
	int dep[n], arr[n];
	for(auto &t: arr) {
    	cin >> t;
	}
	for(auto &t: dep) {
    	cin >> t;
	}
	
	cout << findPlatform(arr, dep, n);
	return 0;
}
