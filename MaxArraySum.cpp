/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array arr=[]-2,1,3,-4,5  we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is 8.
Function Description

Complete the maxSubsetSum function in the editor below. It should return an integer representing the maximum subset sum for the given array.

maxSubsetSum has the following parameter(s):

arr: an array of integers
Input Format

The first line contains an integer n, .
The second line contains n space-separated integers arr[i].

Constraints
1 <= n <= 100000
1/10000 <= arr[i] <= 10000
Output Format

Return the maximum sum described in the statement.

Sample Input 0

5
3 7 4 6 5
Sample Output 0

13
Explanation 0

Our possible subsets are [3,4,5], [3,4], [3,6], [3,5], [7,6], [7,5] and [4,5]. The largest subset sum is 13 from subset [7,6] 
*/

int maxElement(int a, int b){
    return ((a > b) ? a : b);
}
// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int l = arr.size();

    int maxVal = INT_MIN;
    int currIncluding = 0;
    int currExcluding = 0;
    int temp = 0;

    for(int i = 0; i < l; i++){
        maxVal =maxElement(maxElement(arr[i] + currExcluding, currIncluding), arr[i]);
        currExcluding = currIncluding;
        currIncluding = maxVal;
    }

    return maxVal;
}
