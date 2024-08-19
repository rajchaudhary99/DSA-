#include <iostream>

using namespace std;


struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};


ListNode* reverseList(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    int count = 0;

 
    ListNode* temp = head;
    for (int i = 0; i < k; ++i) {
        if (temp == nullptr) return head; 
        temp = temp->next;
    }

   
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        ++count;
    }

   
    return prev;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prevGroupEnd = dummy;
    ListNode* groupStart = head;
    ListNode* groupEnd = nullptr;

    while (groupStart != nullptr) {
        ListNode* temp = groupStart;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            ++count;
        }

        if (count == k) {
            groupEnd = temp;
            ListNode* newGroupStart = reverseList(groupStart, k);
            prevGroupEnd->next = newGroupStart;
            groupStart->next = groupEnd;
            prevGroupEnd = groupStart;
            groupStart = groupEnd;
        } else {
            prevGroupEnd->next = groupStart;
        }
    }

    ListNode* newHead = dummy->next;
    delete dummy; 
    return newHead;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
   
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);

    int k = 3;
    cout << "Original List: ";
    printList(head);

    
    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

 
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
