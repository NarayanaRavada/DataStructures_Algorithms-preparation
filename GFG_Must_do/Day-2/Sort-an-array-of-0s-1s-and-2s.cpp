/**
.* 	  author: narayana_r
.* 	  created: 22.06.2022 18:55:20
**/

#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n) {
    int zeros = 0, ones = 0;
 	for(int i = 0;i < n; i++) {
		if(arr[i] == 0) zeros++;
		else if(arr[i] == 1) ones++;
	}

	for(int i = 0; i < n; i++) {
    	if(i < zeros) arr[i] = 0;
		else if(i < zeros + ones) arr[i] = 1;
		else arr[i] = 2;
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(auto &x: arr) {
    	cin >> x;
	}

	sort012(arr, n);
	
	for(auto n: arr) {
    	cout << n << " ";
	}
	return 0;
}
