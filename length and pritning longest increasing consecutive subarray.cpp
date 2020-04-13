#include <iostream>
#include <unordered_map>
#include <cstring>
#include <limits.h>
#include<set>
using namespace std;

template<size_t  n>
void lengthOfLargestIncreasingConsecutiveSubArray(int (&arr)[n])
{
    unordered_map <int,int> mp;

    int dp[n];
    memset(dp, 0, sizeof(dp));

    int maximum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if(mp.find(arr[i]-1) != mp.end())       dp[i] = 1 + dp[mp[arr[i] - 1] - 1];
        else dp[i] = 1;

        mp[arr[i]] = i+1;
        maximum = (maximum < dp[i])? dp[i] : maximum;

    }
    cout << maximum <<"\n";

}

template<size_t  n>
void printingLargestIncreasingConsecutiveSubArray(int (&arr)[n])
{
    unordered_map <int,int> mp;
    unordered_multimap<int,int> final;

    int dp[n];
    memset(dp, 0, sizeof(dp));

    int maximum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if(mp.find(arr[i]-1) != mp.end())     dp[i] = 1 + dp[mp[arr[i] - 1] - 1];
        else dp[i] = 1;

        mp[arr[i]] = i+1;
        if (maximum < dp[i]) maximum = dp[i];
        final.insert(make_pair(dp[i],i));
    }




    set <int> setfinal;
    int last = INT_MAX;
    while(maximum){
        auto result = final.equal_range(maximum);
        int x = INT_MIN;
        for(auto it = result.first; it != result.second ; it++) {
            if(arr[it->second] < last) {
                x = max(arr[it->second],x);
            }
        }
        setfinal.insert(x);
        last = x;
        maximum--;
    }
    for(auto i :setfinal) cout <<i <<"  ";

}
// main function
int main()
{
    int arr[] = {10 , 22 , 9 , 33,  21  ,50 , 41,  60,  80};
    lengthOfLargestIncreasingConsecutiveSubArray(arr);
    printingLargestIncreasingConsecutiveSubArray(arr);
    return 0;
}
/*
 * {3, 10, 3, 11, 4, 5, 6, 7, 8, 12}; 3,4,5,6,7,8
 * {6, 7, 8, 3, 4, 5, 9, 10};  6,7,8,9,10
 * {10  22  9  33  21  50  41  60  80};  10,22,33,50,60,80
 *
 */