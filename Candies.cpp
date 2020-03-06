/*
Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.

Function Description

Complete the candies function in the editor below. It must return the minimum number of candies Alice must buy.

candies has the following parameter(s):

n: an integer, the number of children in the class
arr: an array of integers representing the ratings of each student
Input Format

The first line contains an integer ,n , the size of arr.
Each of the next n lines contains an integer arr[i] indicating the rating of the student at position i.
Constraints
1 <= n <= 10^5
1 <= arr[i] <= 10^5
Output Format

Output a single line containing the minimum number of candies Alice must buy.

Sample Input 0

3
1
2
2
Sample Output 0

4
Explanation 0

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.

Sample Input 1

10
2
4
2
6
1
7
8
9
2
1
Sample Output 1

19
Explanation 1

Optimal distribution will be 1,2,1,2,1,2,3,4,2,1
*/
// Complete the candies function below.
long candies(int n, vector<int> arr) {
    int len = arr.size();
    long long int total = 0;
    vector<long> candies(len);
    candies[0] = 1;
    for(int i = 1; i < len; i++){
        if(arr[i] > arr[i-1]){
            candies[i] = candies[i-1]+1;
        } else {
            candies[i] = 1;
        }
    }

    for(int i = len - 2; i >= 0; i--){
        if(arr[i] > arr[i+1] && candies[i] < candies[i+1]+1){
            candies[i] = candies[i+1]+1;
        }
    }

    for(int i = 0; i < len; i++){
        total += candies[i];
    }

    return total;
}
