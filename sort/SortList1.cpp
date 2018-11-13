#include <iostream>
// https://blog.csdn.net/wumuzi520/article/details/8078322
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// swap node's value
// two pointer: p q
// begin+1...p: <= pivot 
// p+1...q: > pivot
ListNode* Partition(ListNode* begin, ListNode* end) {
    int val = begin->val;
    ListNode* p = begin;
    ListNode* q = p->next;
    while (q != end) {
        if (q->val < val) {
            p = p->next;
            swap(p->val, q->val);
        }
        q = q->next;
    }
    swap(p->val, begin->val);
    return p;
}

// range is [begin, end) to avoid adding one traversal 
void QuickSort(ListNode* begin, ListNode* end) {
    if (begin != end) {
        ListNode* position = Partition(begin, end);
        QuickSort(begin, position);
        QuickSort(position->next, end);
    }
}

ListNode* SortList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *begin = head, *end = NULL;
    QuickSort(begin, end);
    return begin;
}

int main(void) {
    ListNode* node1 = new ListNode(30);
    ListNode* node2 = new ListNode(50);
    ListNode* node3 = new ListNode(10);
    node1->next = node2;
    node2->next = node3;
    SortList(node1);
    ListNode *cur = node1;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    delete node1;
    delete node2;
    delete node3;
    return 0;
}
