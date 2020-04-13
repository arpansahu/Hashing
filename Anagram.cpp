#include <iostream>
#include "algorithm"
#include <map>
#include "vector"
using namespace std;



int isAnagram(string X,string Y){
    map <int,int> map1;
    map <int,int> map2;
    for (int i = 0; i < Y.length(); ++i) {
        map1[X[i]]++;
        map2[Y[i]]++;
    }
    return map1 == map2;

}//another option is two use one map and use two loops to first enter all the elemnts of string 1 and subtracct the elemetys from map1 in another round of loop for string 2



// main function
int main()
{
    string X = "tommarvoloriddle";    // Tom Marvolo Riddle
    string Y = "iamlordvoldemort";    // I am Lord Voldemort

    if (isAnagram(X, Y))
        cout << "Anagram";
    else
        cout << "Not a Anagram";

    return 0;
}


