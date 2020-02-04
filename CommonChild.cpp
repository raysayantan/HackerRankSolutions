/*
A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. 
Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

For example, ABCD and ABDC have two children with maximum length 3, ABC and ABD. They can be formed by eliminating either 
the D or C from both strings. Note that we will not consider ABCD as a common child because we can't rearrange characters and ABCD != ABDC.

Function Description

Complete the commonChild function in the editor below. It should return the longest string which is a common child of the input strings.

commonChild has the following parameter(s):

s1, s2: two equal length strings
Input Format

There is one line with two space-separated strings, s1 and s2.
Constraints
1 <= |s1|, |s2| <= 5000
All characters are upper case in the range ascii[A-Z].
Output Format

Print the length of the longest string s, such that s is a child of both s1 and s2.

Sample Input

HARRY
SALLY
Sample Output

 2
Explanation

The longest string that can be formed by deleting zero or more characters from HARRY and SALLY is AY, whose length is 2.
*/

int maxVal(int a, int b){
    return (a > b) ? a : b;
}
// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> v(l1 + 1);
    for(int i = 0; i <= l1; i++){
        v[i] = vector<int>(l2 + 1);
    }

    for(int i = 0; i <= l1; i++){
        v[i][0] = 0;
        v[0][i] = 0;
    }

    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i-1] == s2[j-1]){
                v[i][j] = v[i-1][j-1] + 1;
            } else {
                v[i][j] = maxVal(maxVal(v[i-1][j-1],v[i-1][j]), v[i][j-1]);
            }
        }
    }

    return v[l1][l2];
}
