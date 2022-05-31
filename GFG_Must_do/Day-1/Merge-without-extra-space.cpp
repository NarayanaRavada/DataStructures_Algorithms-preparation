/**
.* 	  author: narayana_r
.* 	  created: 31.05.2022 18:12:04
**/

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) { 
	int i = n - 1, j = 0;
	while(i >= 0 && j < m) {
		if(arr1[i] > arr2[j]) {
			long long temp = arr1[i];
			arr1[i] = arr2[j];
			arr2[j] = temp;
			i--;
			j++;
		} else {
			j++;
		}
	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, m;
		cin >> n >> m;
		long long arr1[n], arr2[m];
		for(auto &num: arr1) {
			cin >> num;
		}
		for(auto &num: arr2) {
			cin >> num;
		}

		merge(arr1, arr2, n, m);

		for(auto &num: arr1) {
			cout << num << " ";
		}
		for(auto &num: arr2) {
			cout << num << " ";
		}
		
		cout << "\n";
	}
	return 0;
}

