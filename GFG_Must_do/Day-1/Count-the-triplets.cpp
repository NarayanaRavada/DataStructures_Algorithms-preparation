/**
.* 	  author: LakshmiNarayana {narayana_r}
.* 	  created: 31.05.2022 17:36:07
**/

#include <bits/stdc++.h>
using namespace std;

int countTriplet(int arr[], int n) {
	sort(arr, arr + n);
	int count = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			if(binary_search(arr + j + 1 , arr + n, sum)) {
				count++;
			}
		}
	}

	return count;
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
		
		cout << countTriplet(arr, n);
		cout << "\n";
	}
	return 0;
}
