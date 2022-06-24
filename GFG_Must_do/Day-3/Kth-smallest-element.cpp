/**
.* 	  author: narayana_r
.* 	  created: 24.06.2022 18:02:32
**/

#include <bits/stdc++.h>
using namespace std;

// median of array by sorting 
// limited to size of 5 here
int findMedian(int arr[], int n) {
	sort(arr, arr + n);
	return arr[n/2];
}

// paritions around x
// move x to last
// follow standard paritioning
int partition(int arr[], int l, int r, int x) {
	for(int i = l; i <= r; i++) {
    	if(arr[i] == x) {
			swap(arr[i], arr[r]);
			break;
		}
	} 

    int j = l;
    for(int i = l; i < r; i++) {
    	if(arr[i] <= x) {
        	swap(arr[i], arr[j]);
			j++;
		}
	}

	swap(arr[j], arr[r]);
	return j;
}

// find median of every n/5 elements
// find median of left over elements
// find median of medians using kthSmallest
// partition around median of medians and get pivot idx
// if pi < k => kthSmallest(pi + 1, r)
// if pi > k => kthSmallest(l, pos - 1)
// if pi == k return arr[pos]
int kthSmallest(int arr[], int l, int r,  int k) {
	
	int n = r - l + 1;

	int i, medians[(n + 4)/5];
	for(i = 0; i < n/5; i++) {
    	medians[i] = findMedian(arr + l + i*5, 5);
	}

	if(i*5 < n) {
    	medians[i] = findMedian(arr + l + i*5, n%5);
		i++;
	}

	int medianOfMedians = medians[i - 1];
	if(i != 1) {
		medianOfMedians = kthSmallest(medians, 0, i - 1, i/2);
	}

	int pos = partition(arr, l, r, medianOfMedians);

	if(pos < k - 1) {
        return kthSmallest(arr, pos + 1, r, k);
	} 
	else if (pos > k - 1) {
    	return kthSmallest(arr, l, pos - 1, k);
	}

	return arr[pos];
}


int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(auto &x:arr) {
		cin >> x;
	}

	cout << kthSmallest(arr, 0, n - 1, k);

	return 0;
}
