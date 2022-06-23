/**
.* 	  author: narayana_r
.* 	  created: 05.06.2022 09:03:25
**/

#include <bits/stdc++.h>
using namespace std;

 /*
  * By this method we can store two elements is the same index
  * the added value and present value just by multiplying with some 
  * greater constant.
  * a = a + (b%k)*k;
  * -> a = a%k;
  * -> b = b/k
  */
void rearrange(long long *arr, int n) { 

	int max_idx = n - 1, min_idx = 0, max = arr[n-1] + 1;
	for(int i = 0; i < n; i++) {
		if(i%2 == 0) {
			arr[i] = (arr[max_idx--]%max)*max + arr[i];
		} else {
			arr[i] = (arr[min_idx++]%max)*max + arr[i];
		}
	}

	for(int i = 0; i < n; i++) {
		arr[i] = arr[i]/max;
	}
}

int main() {
	int n;
	cin >> n;
	long long arr[n];
	for(auto &num: arr) {
    	cin >> num;
	}

	rearrange(arr, n);

	for(auto &num: arr) {
    	cout << num << " ";
	}
	return 0;
}
