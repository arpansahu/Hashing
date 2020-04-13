#include <iostream>
#include <unordered_map>
using namespace std;

template<size_t  n>
int maxLengthSubArray(int (&arr)[n],int S)
{
    unordered_map <int , int> map;
    map[0] = -1;

    int sum = 0;
    int len = 0;
    int ending_index = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (map.find(sum) == map.end()) map[sum] = i;

        if (map.find(sum - S) != map.end())
        {
            len =  i - map[sum - S];
            ending_index = i;
            break;
        }
    }
    cout << "[";
    for (int j = ending_index - len + 1; j <= ending_index; ++j) {
        cout << " "<<arr[j] ;
        if(j != ending_index)  cout<<",";
    }
     cout <<  " ]";

}

// main function
int main()
{
    int arr[] =  {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10};
    int sum = -3;
    maxLengthSubArray(arr,sum);
    return 0;
}
/*
 * Input:   {2, 6, 0, 9, 7, 3, 1, 4, 1, 10}, sum 15
Output: Subarray {6, 0, 9} exists with sum 15


Input:   {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10}, sum 15
Output:




Input:   {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10}, sum -3
Output: Subarray {1, -4} exists with sum -3
 *
 *
 *
 */