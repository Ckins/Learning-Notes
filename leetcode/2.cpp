/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* p1, struct ListNode* p2) {
    
    struct ListNode * l1 = p1;
    struct ListNode * l2 = p2;

    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = 0;
    l3->next= NULL;
    struct ListNode *l4 = l3;
    int sum = 0;
    int inc = 0;
    while (l1 != NULL && l2!= NULL) {
        sum = l1->val + l2->val + inc;
        if (sum >= 10) {
            inc = 1;
            sum -= 10;
        } else {
            inc = 0;
        }
        l3->val = sum;
        l1 = l1->next;
        l2 = l2->next;
        if (l1 != NULL || l2 != NULL) {
            l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3 = l3->next;
            l3->next = NULL;
        }
    }
    if(l1 == NULL) l1 = l2;
    while(l1 != NULL) {
        sum = l1->val + inc;
         if (sum >= 10) {
            inc = 1;
            sum -= 10;
        } else {
            inc = 0;
        }
        l3->val = sum;
        l1 = l1->next;
        if (l1 != NULL) {
            l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3 = l3->next;
            l3->next = NULL;
        }
    }
    if (l1 == NULL && inc != 0) {
        l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->next = NULL;
        l3->val = 1;    
    }
    return l4;
}
