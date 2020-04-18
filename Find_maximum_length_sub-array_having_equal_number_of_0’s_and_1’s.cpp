#include <iostream>
#include <unordered_map>
using namespace std;

template<size_t  n>
int maxLengthSubArrayWithEqual0_1(int (&arr)[n])
{
    unordered_map <int , int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;
    int ending_index = -1;

    for (int i = 0; i < n ; i++) {

        sum += (arr[i] == 0) ? -1 : 1;
        if(map.find(sum) != map.end()){

            if(len <  i -  map[sum]){
                ending_index = i;
                len = i - map[sum] ;
            }

        }else  map[sum] = i;


    }
    if(ending_index != -1)cout << "[" << (ending_index - len + 1) << "," << ending_index << "]";
    else cout << "No Subarrays with equal no of 1 and 0  : ";

}

// main function
int main()
{
    int arr[] = { 0, 0, 1, 0, 1, 0, 0 };
    maxLengthSubArrayWithEqual0_1(arr);
    return 0;
}