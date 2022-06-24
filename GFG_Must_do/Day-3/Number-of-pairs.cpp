/**
.* 	  author: narayana_r
.* 	  created: 24.06.2022 13:33:38
**/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long long countPairs(int X[], int Y[], int M, int N) {
	sort(X, X + M);
	sort(Y, Y + N);

	long long count = 0;  
	
	int ones = upper_bound(Y, Y + N, 1) - lower_bound(Y, Y + N, 1);
	int twos = upper_bound(Y, Y + N, 2) - lower_bound(Y, Y + N, 2);
	int threes = upper_bound(Y, Y + N, 3) - lower_bound(Y, Y + N, 3);
	int fours = upper_bound(Y, Y + N, 4) - lower_bound(Y, Y + N, 4);

	for(int i = 0; i < M; i++) {
    	if(X[i] != 1) {
			count += ones;
			count += N - (upper_bound(Y, Y + N, X[i]) - Y);

			if(X[i] == 2) {
            	count -= threes;
            	count -= fours;
			} else if(X[i] == 3) {
            	count += twos;
			}
		}
     }

	return count;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(auto &x: arr) {
    	cin >> x;
	}
	return 0;
}
