/*
You will be given a list of integers, arr, and a single integer . You must create an array of length k from elements of arr such that 
its unfairness is minimized. Call that array subarr. Unfairness of an array is calculated as
              max(subarr) - min(subarr)
As an example, consider the array [1,4,7,2] with a k of 2. Pick any two elements, test subarr=[4,7].
unfairness = max([4,7]) - min([4,7]) = 7 - 3 = 4
Testing for all pairs, the solution [1,2] provides the minimum unfairness.

Note: Integers in arr may not be unique.
*/

// Only Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int unfairValue = INT_MAX;
    sort(arr.begin(), arr.end());
    int l = arr.size();
    int minDiff = INT_MAX;
    for(int i = 0; i <= l - k; i++){
        minDiff = arr[i+k -1] - arr[i];
        if(minDiff < unfairValue) unfairValue = minDiff;
    }

    return unfairValue;
}
