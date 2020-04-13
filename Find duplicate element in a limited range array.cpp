#include <iostream>
#include <unordered_map>
using namespace std;

template<size_t  n>
void findDuplicateUsingHasing(int (&arr)[n])
{
    unordered_map < int,int > map;

    for (int i = 0; i < n; i++)
    {

        if (map.find(arr[i]) == map.end()) map[arr[i]] = i;
        else {
            cout<<"Duplicate element is : " << arr[i]; return;
        }
    }

}
template<size_t  n>
void findDuplicateWithoutHashing(int (&arr)[n]){
    for (int i = 0; i < n; i++)
    {
        int val = abs(arr[i]);
        if (arr[val-1] >= 0) {
            arr[val-1] = -arr[val-1];
        } else {cout << "Duplicate Element is : " <<val;
            break;}

    }

}

// main function
int main()
{   
    int arr[] =  { 4,3,2,1,3 };
    findDuplicateUsingHasing(arr);
    findDuplicateWithoutHashing(arr);    //this is only for arrays of positive intergers
    
    return 0;
}
