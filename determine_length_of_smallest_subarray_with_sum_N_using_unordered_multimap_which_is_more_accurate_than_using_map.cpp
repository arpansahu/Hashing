#include <iostream>
#include <unordered_map>
using namespace std;

template<size_t  n>
int maxLengthSubArray(int (&arr)[n],int S)
{
    unordered_multimap <int , int> map;
    map.insert(pair<int,int>(0,-1));
    int sum = 0;
    int len = 0;
    int ending_index = -1;

    for (int i = 0; i < n ; i++) {

        sum += arr[i];
        if(S != 0)  map.insert(pair<int, int>(sum, i));
        if(map.find(sum - S) != map.end()){

            auto it = map.find(sum - S);
            while(it != map.end() && it->first == sum - S){
                if(len >= i -  it->second || (len == 0)){len =  it->second + 1 - i ; ending_index = i;}
                it++;
            }

        }
        if(S == 0)  map.insert(pair<int, int>(sum, i));


    }
    if(ending_index != -1)cout << "[" << (ending_index - len + 1) << "," << ending_index << "]";
    else cout << "No Subarrays with sum : "<<S;

}

// main function
int main()
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int sum = 0;
    maxLengthSubArray(arr,sum);
    return 0;
}