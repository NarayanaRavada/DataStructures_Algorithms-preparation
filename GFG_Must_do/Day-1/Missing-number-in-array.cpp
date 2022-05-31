/**
.* 	  author: narayana_r
.* 	  created: 31.05.2022 18:02:04
**/

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n) {

	int missing = 0;
	sort(array.begin(), array.end());
	for(int i = 0; i < n; i++) {
		if(array[i] != i + 1) {
			missing = i + 1;
			break;
		}
	}

	if(missing == 0) {
		missing = n;
	}
	return missing;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(auto &num: arr) {
			cin >> num;
		}
		
		cout << MissingNumber(arr, n);
		cout << "\n";
	}
	return 0;
}

