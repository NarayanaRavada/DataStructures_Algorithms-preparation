/**
.* 	  author: narayana_r
.* 	  created: 23.06.2022 08:03:38
**/

#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(vector<long long>& arr, int n, int k) {
	vector<long long> res;

	for(int i = 0; i < n; i += k) {
    	for(int j = i + k - 1; j >= i; j--) {
        	if(j < n) res.push_back(arr[j]);
		}
	}

	for(int i = 0; i < n; i++) {
    	arr[i] = res[i];
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> arr(n);
	for(auto &x: arr) {
    	cin >> x;
	}

	reverseInGroups(arr, n, k);

	for(auto x: arr) {
    	cout <<  x << " ";
	}
	return 0;
}
