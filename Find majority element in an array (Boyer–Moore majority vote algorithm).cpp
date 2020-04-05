#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template<size_t  n>
int majorityElement(int (&A)[n])
{
    unordered_map<int, int> map;
    int max = 0;
    int element ;
    for (int i = 0; i < n; i++) {
        map[A[i]]++;
        if (max < map[A[i]]){max = map[A[i]];element = A[i];}
    }
    if(max > n / 2)     cout << "Majority is present and its held by : " << element;
    else cout <<" No majority";

}

// main function
int main()
{
    int A[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };

    majorityElement(A);

    return 0;
}