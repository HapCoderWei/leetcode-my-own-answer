/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *add1 = l1;
    struct ListNode *add2 = l2;
    struct ListNode *sum  = l1;
    int temp = 0, t = 0;
    
    while( add1->next != NULL && add2->next != NULL) {
        t = add1->val + add2->val + temp;
        sum->val = t % 10;
        temp     = t / 10;
        
        add1 = add1->next;
        add2 = add2->next;
        sum  = sum->next;
    }
    t = add1->val + add2->val + temp;
    sum->val = t % 10;
    temp     = t / 10;
    
    
    if( add1->next != NULL ) { // l1 longer than l2
        add1 = add1->next;
        sum  = sum->next;
        
        while( add1->next != NULL ) {
            t = add1->val + temp;
            temp     = t / 10;
            sum->val = t % 10;
            
            add1 = add1->next;
            sum = sum->next;
        }
        t = add1->val + temp;
        temp     = t / 10;
        sum->val = t % 10;
    }
    if( add2->next != NULL ) {
        add2 = add2->next;
        sum->next = add2;
        sum = sum->next;
        
        while( add2->next != NULL) {
            t = add2->val + temp;
            temp     = t / 10;
            sum->val = t % 10;
            
            add2 = add2->next;
            sum = sum->next;
        }
        t = add2->val + temp;
        temp     = t / 10;
        sum->val = t % 10;
    }
    if( temp > 0 ) {
        sum->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum->next->val = temp;
        sum->next->next = NULL;
    }
    
    return l1;
}
