/**
.* 	  author: narayana_r
.* 	  created: 24.06.2022 20:36:39
**/

#include <bits/stdc++.h>
using namespace std;

bool checkTriplet(int arr[], int n) {
	unordered_map<int, int> squares;
	for(int i = 0;i < n; i++) {
		squares[arr[i] * arr[i]]++;
	}

	int triplets = 0;
	for(int i = 0; i < n; i++) {
		for(int j= i + 1; j < n; j++) {
			if(squares[arr[i]*arr[i] + arr[j]*arr[j]] != 0) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(auto &x: arr) {
    	cin >> x;
	}
	
	cout << (checkTriplet(arr, n) ? "YES" : "NO");
	return 0;
}
