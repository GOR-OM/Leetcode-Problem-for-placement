// there are repeated number in array in rotated sorted array 

#include<bits/stdc++.h>
using namespace  std; 


#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}