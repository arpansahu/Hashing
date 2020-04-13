#include <iostream>
#include "algorithm"
#include <unordered_map>
#include "vector"
using namespace std;
typedef pair<int,int> Pair;
template<size_t  n>
void quadTuple(int (&arr)[n], int Capacity)  //here time cpmplexity is O(N2) and auxillary space required is : O(N)
{
    unordered_map<int , vector<Pair>> map1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int val = Capacity - (arr[i] + arr[j]);
            if (map1.find(val) != map1.end())
            {
                for (auto pair : map1.find(val)->second)
                {
                    int x = pair.first;
                    int y = pair.second;
                    if ((x != i && x != j) && (y != i && y != j))   { cout << "Quadruplet Found ("<< arr[i] << ", " << arr[j] << ", " << arr[x]<< ", " << arr[y] << ")";return;}
                }
            }map1[arr[i] + arr[j]].push_back({i, j});
        }
    }
}



// main function
int main()
{
    int arr[]  = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int sum = 20;

    quadTuple(arr,sum);
    return 0;
}
