/**
.* 	  author: narayana_r
.* 	  created: 23.06.2022 07:27:42
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n){
	vector<int> leadrs;
	int max = arr[n - 1];
	for(int i = n - 1; i >= 0; i-) {
    	if(arr[i] >= max) {        
        	leadrs.push_back(arr[i]);
			max = arr[i];
		}
	}
	reverse(leadrs.begin(), leadrs.end());

	return leadrs;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &x: arr) {
    	cin >> x;
	}

	return 0;
}
