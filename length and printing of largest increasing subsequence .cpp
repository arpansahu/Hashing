#include <iostream>
#include<vector>


using namespace std;

template<size_t  n>
void lengthOfLargestIncreasingSubArray(int (&arr)[n])
{
    vector <int> vect;

    for (int i = 0; i < n; ++i) {
        if(vect.size() == 0)    vect.push_back(arr[i]);
        else if(vect[vect.size() - 1] < arr[i])  vect.push_back(arr[i]);
        else if(vect[vect.size() - 1] > arr[i] && vect[vect.size() - 2] < arr[i]){   vect.pop_back();    vect.push_back(arr[i]);      }
    }
    cout << vect.size(); cout <<"\n";

}

template<size_t  n>
void printingLargestIncreasingSubArray(int (&arr)[n])
{
    vector <int> vect;

    for (int i = 0; i < n; ++i) {
        if(vect.size() == 0)    vect.push_back(arr[i]);
        else if(vect[vect.size() - 1] < arr[i])  vect.push_back(arr[i]);
        else if(vect[vect.size() - 1] > arr[i] && vect[vect.size() - 2] < arr[i]){   vect.pop_back();    vect.push_back(arr[i]);      }
    }
    for(auto i :vect) cout << i<<" "; cout <<"\n";
}
// main function
int main()
{
    int arr[] =  { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    lengthOfLargestIncreasingSubArray(arr);
    printingLargestIncreasingSubArray(arr);
    return 0;
}
