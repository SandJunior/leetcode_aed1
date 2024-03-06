bool isPalindrome(struct ListNode* head) {
    if (head == NULL){
        return true;
    } else { 
    struct ListNode *firstPart = head;
    struct ListNode *secondPart = head;
    struct ListNode *prev = NULL;

    while (firstPart != NULL && firstPart->next != NULL) {
        firstPart = firstPart->next->next;
        struct ListNode *nextNode = secondPart->next;
        secondPart->next = prev;
        prev = secondPart;
        secondPart = nextNode;
    }
    
    if (firstPart != NULL) {
        secondPart = secondPart->next;
    }
    
    while (prev != NULL && secondPart != NULL) {
        if (prev->val != secondPart->val) {
            return false;
        }
        prev = prev->next;
        secondPart = secondPart->next;
    }
    return true;
    }
}