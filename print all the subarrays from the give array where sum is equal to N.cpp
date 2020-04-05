#include <iostream>
#include <unordered_map>
using namespace std;

template<size_t  n>
int printallSubarrays(int (&A)[n],int S)
{
    unordered_multimap <int , int> map;
    map.insert(pair<int,int>(0,-1));
    int sum = 0;
    for (int i = 0; i < n ; i++) {

        sum += A[i];
        if(S != 0)  map.insert(pair<int, int>(sum, i));
        if(map.find(sum - S) != map.end()){

            auto it = map.find(sum - S);
            while(it != map.end() && it->first == sum - S){
                cout << "Subarray [" << it->second + 1 << ".." << i << "]\n";
                it++;
            }

        }
        if(S == 0)  map.insert(pair<int, int>(sum, i));


    }



}

// main function
int main()
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    printallSubarrays(arr,0);
    return 0;
}