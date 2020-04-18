#include <iostream>
#include <unordered_set>
using namespace std;

template<size_t  n>
int findAnySubArrayWithSum0(int (&arr)[n])
{
    unordered_set<int> sumSet;
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())   return 1;
        sumSet.insert(sum);
    }
    return 0;
}

// main function
int main()
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    if(findAnySubArrayWithSum0(arr)) cout << "Yes";
    else cout << "No";
    return 0;
}