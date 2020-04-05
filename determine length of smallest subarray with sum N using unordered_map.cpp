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

        if (map.find(sum - S) != map.end() && (len >= i - map[sum - S] || (len == 0)))
        {
            len =  i - map[sum - S];
            ending_index = i;
        }
    }

    if(ending_index != -1)cout << "[" << (ending_index - len + 1) << "," << ending_index << "]";
    else cout << "No Subarrays with sum : "<<S;
}

// main function
int main()
{
    int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
    int sum = 8;
    maxLengthSubArray(arr,sum);
    return 0;
}