/*
We define the distance between two array values as the number of indices between the two values. Given , find the minimum distance between any pair of equal elements in the array. If no such value exists, print .

For example, if , there are two matching pairs of values: . The indices of the 's are  and , so their distance is . The indices of the 's are  and , so their distance is .

Function Description

Complete the minimumDistances function in the editor below. It should return the minimum distance between any two matching elements.

minimumDistances has the following parameter(s):

a: an array of integers
Input Format

The first line contains an integer , the size of array .
The second line contains  space-separated integers .

Constraints
1 <= n <= 10^3
1 <= a[i] <= 10^5
Output Format

Print a single integer denoting the minimum  in . If no such value exists, print .

Sample Input

6
7 1 3 4 1 7
Sample Output

3
*/
int minimumDistances(vector<int> a) {
    map<int, int> indexer;
    int minDist = INT_MAX;
    for(int i = 0; i < a.size(); i++){
        if(indexer.find(a[i]) != indexer.end()){
            if(minDist > (i - indexer[a[i]])){
                minDist = i - indexer[a[i]];
            }
        }
        indexer[a[i]] = i;
    }

    if(minDist > a.size()) return -1;
    return minDist;
}
