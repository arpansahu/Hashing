#include <iostream>
#include <set>
using namespace std;

int minimum(int a ,int b) {return (a<b)? a:b;}
int maximum(int a ,int b) {return (a>b)? a:b;}
template<size_t  n>
void lengthOfLargestSubArrayWithContiguosElements(int (&arr)[n])
{
    int max_len = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i] ;int max = arr[n-1];
        for (int j = i + 1; j < n; ++j) {
            min = minimum(min,arr[j]);
            max = maximum(max,arr[j]);
            if(max-min == j - i){max_len = maximum(max_len ,(j-i +1));}
        }
    }
    cout <<"Length of largest contiguos sub array is : " <<max_len << "  ";

}
template<size_t  n>
void lengthOfLargestSubArrayWithContiguosElementsWithRepeatedElements(int (&arr)[n])
{
    int max_len = 0;
    for (int i = 0; i < n - 1; i++)
    {
        set <int> set;
        set.insert(arr[i]);

        int min = arr[i] ;int max = arr[n-1];

        for (int j = i + 1; j < n; ++j) {

            if(set.find(arr[j]) != set.end()) break;

            min = minimum(min,arr[j]);
            max = maximum(max,arr[j]);

            set.insert(arr[j]);

            if(max-min == j - i){max_len = maximum(max_len ,(j-i +1));}
        }
    }
    cout <<"Length of largest contiguos sub array is : " <<max_len << "  ";

}
template <size_t n>
void lengthOfLargestSubArrayWithContiguosElementsUsingHasing(int (&arr)[n]){

    set<int> set;
    int max_len;
    for (int i = 0; i < n; ++i) {
        set.insert(arr[i]);
    }
    for (int i = 0; i < n; ++i) {

        if(set.find(arr[i] - 1) == set.end()){
            int j = arr[i];
            while(set.find(j) != set.end()) j++;

            max_len = maximum(max_len,j - arr[i]);
        }

    }
    cout <<"Length of largest contiguos sub array is : " <<max_len << "  ";
}

template<size_t  n>
void printLargestSubArrayWithContiguosElements(int (&arr)[n])
{
    int max_len = 0;int end = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i] ;int max = arr[n-1];
        for (int j = i + 1; j < n; ++j) {
            end = i;
            min = minimum(min,arr[j]);
            max = maximum(max,arr[j]);
            if(max-min == j - i){ max_len = maximum(max_len ,(j-i +1));  end = j; }
        }
    }

    for (int k = end - max_len + 1 ; k <= end; ++k)     cout <<arr[k] <<" ";
    cout << "\n";

}
template<size_t  n>
void printLargestSubArrayWithContiguosElementsWithRepeatedElements(int (&arr)[n])
{
    int max_len = 0;int end = 0;
    for (int i = 0; i < n - 1; i++)
    {
        set <int> set;
        set.insert(arr[i]);

        int min = arr[i] ;int max = arr[n-1];

        for (int j = i + 1; j < n; ++j) {

            if(set.find(arr[j]) != set.end()) break;

            min = minimum(min,arr[j]);
            max = maximum(max,arr[j]);

            set.insert(arr[j]);

            if(max-min == j - i){max_len = maximum(max_len ,(j-i +1));   end = j; }
        }
    }
    for (int k = end - max_len + 1 ; k <= end; ++k)     cout <<arr[k] <<" ";
    cout << "\n";


}

template <size_t n>
void printLargestSubArrayWithContiguosElementsUsingHasing(int (&arr)[n]){

    set<int> set;
    int max_len;
    for (int i = 0; i < n; ++i) {
        set.insert(arr[i]);
    }
    int start = 0;
    for (int i = 0; i < n; ++i) {

        if(set.find(arr[i] - 1) == set.end()){

            int j = arr[i];
            while(set.find(j) != set.end()) j++;


            max_len = maximum(max_len,j - arr[i]);
            if(max_len == j - arr[i]) start = i;
        }

    }

    for (int k = start  ; k <= start + max_len - 1; ++k)     cout <<arr[k] <<" ";
    cout << "\n";

}

// main function
int main()
{
    int arr[] =  {1, 56, 58, 57, 90, 92, 94, 93, 91, 45}; //90, 92, 94, 93, 91, is the answer
    int arr2[] = {10, 12, 12, 10, 10, 11, 10};

    lengthOfLargestSubArrayWithContiguosElements(arr);//this is only applicable when no repeated no occur in the array
    printLargestSubArrayWithContiguosElements(arr);
    lengthOfLargestSubArrayWithContiguosElementsWithRepeatedElements(arr2);//this can be applied in both repeated and non repeated
    printLargestSubArrayWithContiguosElementsWithRepeatedElements(arr2);
    lengthOfLargestSubArrayWithContiguosElementsUsingHasing(arr);// this can be ap[plied only on non repeating array
    printLargestSubArrayWithContiguosElementsUsingHasing(arr);

    return 0;
}
