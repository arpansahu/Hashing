#include <iostream>
#include "algorithm"
#include <map>
#include "unordered_map"
using namespace std;


template <size_t n>
void sortByFrequencyAndIndex(int(&a)[n]){
    map<int ,int>map1;
    multimap<int ,int ,greater<>> map2;
    for (int i = 0; i < n; ++i) {
        map1[a[i]]++;
    }
    for(auto i:map1) map2.insert(pair<int,int>(i.second,i.first));
    int index = 0;
    for(auto i :map2) {
        int j = i.first;
        while(j--) a[index++] = i.second ;
    }

}

// main function
int main()
{
    int a[] = { 3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8 };
    sortByFrequencyAndIndex(a);

    for (int i = 0; i < (*(&a + 1) - a); i++)
        cout << a[i] << " ";

    return 0;
}


