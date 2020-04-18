#include <iostream>
#include "algorithm"
#include <unordered_set>

using namespace std;

template<size_t  n>
void tripletExists(int (&arr)[n], int Capacity)  //here time cpmplexity is O(N2) and auxillary space required is : O(N)
{

    for (int j = 0; j < n- 1 ; ++j) {
        unordered_set<int> set1;
        for (int i = j; i < n; ++i) {
            if(set1.find(Capacity - arr[j] - arr[i]) != set1.end()) {cout << "Triplet Exists\n"; return;}
            else set1.insert(arr[i]);
        }
    }
}

template<size_t  n>
void tripletPrint(int (&arr)[n], int Capacity) // Here time complexity is O(N2) But Space complexity is O(1)
{

    sort(arr, arr + n);

    for (int i = 0; i <n - 1 ; ++i) {
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            if(Capacity == arr[left] + arr[right] + arr[i]) {cout <<arr[left] <<" " <<arr[right] <<" "<<arr[i]<<"\n";   left++;     right--;}
            else if (Capacity > arr[left] + arr[right] + arr[i]) left++;
            else right--;
        }
    }
}

// main function
int main()
{
    int arr[] = { 0, -1, 2, -3, 1 };
    int sum = -2;
    tripletExists(arr,sum);
    tripletPrint(arr,sum);
    return 0;
}
