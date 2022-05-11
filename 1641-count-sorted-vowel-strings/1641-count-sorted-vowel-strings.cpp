/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

	      a  e  i  o  u
    n=1   1  1  1  1  1  /a, e, i, o, u
    n=2   5  4  3  2  1  /a-> aa,ae,ai,ao,au | e-> ee,ei,eo,eu | i-> ii,io,iu | o-> oo,ou | u-> uu
    n=3   15 10 6  3  1

dp table of size n*5 or space optimize using dp table of size 5
*/
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        for(int j = 2;j<=n;j++)
        {    
            for(int i=3;i>=0;i--){
                dp[i] = dp[i] + dp[i+1];
            }
        }
        int nuString = 0;
        for(int i=0;i<5;i++){
            nuString +=dp[i];
        }
        return nuString;
    }
};
