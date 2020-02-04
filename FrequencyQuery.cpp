/*
You are given  queries. Each query is of the form two integers described below:
-1 x  : Insert x in your data structure.
-2 y  : Delete one occurence of y from your data structure, if present.
-3 z  : Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.

The queries are given in the form of a 2-D array queries of q size  where queries[i][0] contains the operation, and queries[i][1]
contains the data element. 
For example, you are given array queries = [(1,1),(2,2),(3,2),(1,1),(1,1),(2,1),(3,2)]. The results of each operation are:
Operation   Array   Output
(1,1)       [1]
(2,2)       [1]
(3,2)                   0
(1,1)       [1,1]
(1,1)       [1,1,1]
(2,1)       [1,1]
(3,2)                   1

Return an array with the output:[0,1] .

Function Description

Complete the freqQuery function in the editor below. It must return an array of integers where each element is a 1 
if there is at least one element value with the queried number of occurrences in the current array, or 0 if there is not.

freqQuery has the following parameter(s):

queries: a 2-d array of integers

Input Format

The first line contains of an integer q, the number of queries.
Each of the next q lines contains two integers denoting the 2-d array queries.

Constraints
1<= q <= 1000000
1<= x,y,z <= 1000000000
queries[i][0] belogs to {1,2,3}
1 <= queries[i][1] <= 1000000000
All 
Output Format

Return an integer array consisting of all the outputs of queries of type 3.
Sample Input 0

8
1 5
1 6
3 2
1 10
1 10
1 6
2 5
3 2
Sample Output 0

0
1
Explanation 0

For the first query of type 3, there is no integer whose frequency is 2 (array = [5,6]). So answer is 0.
For the second query of type 3, there are two integers in array = [6,10,10,6] 
whose frequency is 2 (integers = 6 and 10). So, the answer is 1.

Sample Input 2

10
1 3
2 3
3 2
1 4
1 5
1 5
1 4
3 2
2 4
3 2
Sample Output 2

0
1
1
Explanation 2

When the first output query is run, the array is empty. We insert two 4's and two 5's before the second output query,  
so there are two instances of elements occurring twice. We delete a 4 and run the same query. Now only the instances of  
5 satisfy the query.
*/

// Only the Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int,int> dict;
    multiset<int> freq;
    vector<int> result;

    int numOfQueries = queries.size();
    for(int i = 0; i < numOfQueries; i++){
        if(queries[i][0] == 1){
            int val = 0;
            map<int,int>::iterator it1 = dict.find(queries[i][1]);
            if(it1 != dict.end() && it1->second != 0){
                val = it1->second;
                multiset<int>::iterator it = freq.find(val);
                if(it != freq.end()){
                    freq.erase(it);
                }
            }

            dict[queries[i][1]] = val+1;
            freq.insert(val+1);
        } else if(queries[i][0] == 2){
            int val = 0;
            map<int,int>::iterator it = dict.find(queries[i][1]);
            if( it != dict.end() || it->second != 0){
                val = it->second;
                multiset<int>::iterator it1 = freq.find(val);
                if(it1 != freq.end()){
                    freq.erase(it1);
                }
                val--; 
                  
                if(val != 0) {
                    dict[queries[i][1]] = val;
                    freq.insert(val);
                } else {
                    dict.erase(it);
                }
            }
        } else {     
            int present = 0; 
            int val = queries[i][1];
            
            multiset<int>::iterator it = freq.find(val);
            if(it != freq.end()){
                present = 1;
            }

            result.push_back(present);
        }
    }

    return result;
}
