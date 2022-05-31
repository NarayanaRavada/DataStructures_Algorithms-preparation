/**
.* 	  author: LakshmiNarayana {narayana_r}
.* 	  created: 31.05.2022 17:10:07
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s) {

	long long sum = 0;
	int r = 0, l = 0;
	while(r <= n && l <= n ) {

		if(sum == s) {
			return {l+1, r};
		} 
		else if(sum < s){
			sum += arr[r];
			r++;
		} else {
			sum -= arr[l];
			l++;
		}
	}
	return {-1};
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		long long s;
		cin >> n >> s;
		int arr[n];
		for(auto &num: arr) {
			cin >> num;
		}
		
		vector<int> indx = subarraySum(arr, n, s);
		if(indx.size() == 1) {
        	cout << -1;
		} else {
        	cout << indx[0] << " " << indx[1];
		}
		cout << "\n";
	}
	return 0;
}
