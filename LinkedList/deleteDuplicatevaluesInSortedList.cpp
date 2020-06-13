/*
You're given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending order. 
Delete as few nodes as possible so that the list does not contain any value more than once. The given head pointer may 
be null indicating that the list is empty.
The initial linked list is: 1 -> 2 -> 2 -> 3 -> 4 -> NULL

The final linked list is: 1 -> 2 -> 3 -> 4 -> NULL
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
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* p = NULL;
    SinglyLinkedListNode* q = NULL;
    //List is empty
    if(head == NULL){
        return head;
    }

    p = head;
    q = head->next;
    bool isDuplicate = false;
    while(q){
        //if data in consecutive nodes are same delete the successor and move
        //successor one node ahead and continue the loop
        if(p->data == q->data){
            SinglyLinkedListNode* t = q;
            p->next = q->next;
            q = q->next;
            delete(t);
        } else {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}
