#include <iostream>
#include <unordered_map>
using namespace std;
template <size_t  n>
void  findPair(int (&arr)[n], int sum){
    unordered_map <int,int> map;
    for (int i = 0; i < n; ++i) {
        if(map.find(sum - arr[i]) != map.end()){ cout << "Pairs Found They are at index: " << map[sum-arr[i]]  <<" and " << i <<" ( " << arr[map[sum-arr[i]]] <<" , " << arr[i] <<" )" <<"\n"; return;}

        map[arr[i]] = i;
    }
    cout << "Not found";
}
int main(){
    int arr[] = { 8, 7, 2, 5, 3, 1};
    int sum = 10;
    findPair(arr, sum);
    return 0;
}