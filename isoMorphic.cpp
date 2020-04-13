#include <iostream>
#include "algorithm"
#include <unordered_map>
#include "unordered_set"
using namespace std;



int isoMorphic(string X,string Y){
    if (X.length() != Y.length())
        return 0;
    unordered_map <char,char> map1;
    unordered_set<char> set1;
    for (int i = 0; i < X.length() ; ++i) {
        if(map1.find(X[i]) != map1.end())   if(X[i] != Y[i]) return 0;
        else{
            if(set1.find(Y[i]) != set1.end()) return 0;
            map1[X[i]] = Y[i];
            set1.insert(Y[i]);
        }
    }


    return 1;

}//another option is two use one map and use two loops to first enter all the elemnts of string 1 and subtracct the elemetys from map1 in another round of loop for string 2



// main function
int main()
{
    string X = "ACAB";
    string Y = "XCXY";

    if (isoMorphic(X, Y))
        cout << "isoMorphic";
    else
        cout << "Not a isoMorphic";

    return 0;
}


