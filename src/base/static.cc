#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
        return nullptr;

    ListNode *pointerA = headA;
    ListNode *pointerB = headB;

    while (pointerA != pointerB) {
        pointerA = pointerA ? pointerA->next : headB;
        pointerB = pointerB ? pointerB->next : headA;
    }

    return pointerA;
}

// Utility function to print the linked list starting from the given node
void printLinkedList(ListNode *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test()
{
    // Example usage
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = new ListNode(8);
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(5);

    // Make them intersect at node with value 6
    ListNode *intersectionNode = new ListNode(8);
    headA->next->next = intersectionNode;
    headB->next->next->next = intersectionNode;

    // Print the linked lists
    cout << "Linked List A: ";
    printLinkedList(headA);

    cout << "Linked List B: ";
    printLinkedList(headB);

    // Find the intersection node
    ListNode *intersection = getIntersectionNode(headA, headB);
    if (intersection)
        cout << "Intersection node value: " << intersection->val << endl;
    else
        cout << "No intersection node found" << endl;

    // Free memory
    delete headA;
    delete headB;
    // delete intersectionNode;
}