/**
.* 	  author: narayana_r
.* 	  created: 22.06.2022 17:05:03
**/

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long l, long long mid, long long r) {

	long long count = 0;

	long long i = l;
	long long j = mid + 1;
	long long temp[r-l+1];
	long long k = 0;

	while(i <= mid && j <= r) {
		if(arr[i] > arr[j]) {
			count += mid - i + 1;
			temp[k++] = arr[j++];
		} else {
			temp[k++] = arr[i++];
		}
	}

	while(i <= mid) {
		temp[k++] = arr[i++];
	}
	while(j <= r) {
		temp[k++] = arr[j++];
	}

	for(long long i = l; i <= r; i++) {
		arr[i] = temp[i - l];
	}

	return count;
}

long long mergeSort(long long arr[],long long l,long long r){

	long long inv_count = 0;

	if(l < r) {
		long long mid=(l+r)/2;
		inv_count += mergeSort(arr,l,mid);
		inv_count += mergeSort(arr,mid+1,r);
		inv_count += merge(arr,l,mid,r);
	}

	return inv_count;
}

long long int inversionCount(long long arr[], long long N) {
	return mergeSort(arr, 0, N - 1);
}

int main() {
	long long N;
	cin >> N;
    long long arr[N];
    for(int i = 0; i < N - 1; i++) {
    	cin >> arr[i];
	}
	cout << inversionCount(arr, N);
	return 0;
}
