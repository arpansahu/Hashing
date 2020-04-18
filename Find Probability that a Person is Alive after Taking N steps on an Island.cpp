#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
float aliveProbability(int x,int y,int n,map<string, float> &dp){

    if (n == 0) return 1.0;

    string key = to_string(x) + "|" +  to_string(y)  +  "|"  + to_string(n);

    if(dp.find(key) == dp.end()){

        float p = 0.0;
        if(x > 0) p += 0.25 * aliveProbability(x-1,y,n-1,dp);
        if(x < n-1) p += 0.25 * aliveProbability(x+1,y,n-1,dp);
        if(y > 0) p += 0.25 * aliveProbability(x,y-1,n-1,dp);
        if(y < n - 1) p+= 0.25 * aliveProbability(x,y+1,n-1,dp);

        dp[key] = p;
    }
    return dp[key];
}

int main()
{
    int n = 3;        // number of steps to be taken
    int x = 0, y = 0; // starting coordinates

    // map to store solution to already computed sub-problems
    map<string, float> dp;


    cout << "Alive probability is " << aliveProbability(x, y, n, dp);

    return 0;
}