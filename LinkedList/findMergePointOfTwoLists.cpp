/*
Given pointers to the head nodes of  linked lists that merge together at some point, find the Node where the two lists merge. 
It is guaranteed that the two head Nodes will be different, and neither will be NULL.
In the diagram below, the two lists converge at Node x:
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
Complete the int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) method so that it finds and returns 
the data value of the Node where the two lists merge.
Test Case 0

 1
  \
   2--->3--->NULL
  /
 1
Test Case 1

1--->2
      \
       3--->Null
      /
     1
Sample Output

2
3
Explanation

Test Case 0: As demonstrated in the diagram above, the merge Node's data field contains the integer 2.
Test Case 1: As demonstrated in the diagram above, the merge Node's data field contains the integer 3.
*/
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int nodeCount1 = 0;
    int nodeCount2 = 0;
    SinglyLinkedListNode* p = head1;
    SinglyLinkedListNode* q = head2;
    //get number of nodes in List one
    while(p){
        nodeCount1++;
        p = p->next;
    }
    //get number of nodes in list two
    while(q){
        nodeCount2++;
        q = q->next;
    }
    int diff = 0;
    //Bigger one is p and the other is q
    if(nodeCount1 > nodeCount2){
        p = head1;
        q = head2;
        diff = nodeCount1 - nodeCount2;
    } else{
        p = head2;
        q = head1;
        diff = nodeCount2 - nodeCount1;
    }

    //Diff of the node count and move p till that point 
    //where both having same number of node to traverse
    while(diff > 0){
        diff--;
        p = p->next;
    } 

    while(p != q){
        p = p->next;
        q = q->next;
    }

    return (p) ? p->data : -1;

}
