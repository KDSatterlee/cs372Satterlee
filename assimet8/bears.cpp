

//References: https://cplusplus.com/forum/general/16473/
//https://stackoverflow.com/questions/40454622/reaching-the-number-42-by-recursion

#include <iostream>
using namespace std;
const int MXN = 1e6 + 5;
int goal[MXN];
int bears(int initial) {
    if (initial <= 41) { // base case
        return 0;
    }
    if (goal[initial] != -1) { // if already solved for n
        return goal[initial]; // return dp[n]
    }
    goal[initial] = 0; // let dp[n]=0
    // |(OR) all cases
    if (initial % 2 == 0) {
        goal[initial] |= bears(initial / 2); // if divisible by two return n/2 bears
    }
    if (initial % 5 == 0) {
        goal[initial] |= bears(initial - 42); // if divisible by 5 return 42 bears
    }
    if (initial % 4 == 0 || initial % 3 == 0) {
        int a = initial % 10;
        int b = initial % 100 / 10;
        goal[initial] |= bears(initial - a * b); // if divisible by 3 or 4 return product of last 2 digits
    }
    return goal[initial]; //return dp[n] whether 1 or 0
}
int main() {
    int initial;
    cout << "Enter number of bears:";
    cin >> initial; // input n
    memset(goal, -1, sizeof(goal)); // initialise all elements of dp to -1;
    goal[42] = 1; // base case dp[42]=1
    string ans;// store ans
    if (bears(initial)) { // call bears
        ans = "true";
    }
    else {
        ans = "false";
    }
    cout << "bear(" << initial << ") is " << ans << endl; // print ans
    return 0;

}
