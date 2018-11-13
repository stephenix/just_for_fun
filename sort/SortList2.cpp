#include <iostream>
// https://blog.csdn.net/wumuzi520/article/details/8078322
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Merge(ListNode* head1, ListNode* head2) {
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	ListNode* head3 = NULL;
	ListNode* head = NULL;
	if (head1->val < head2->val) {
		head3 = head1;
		head1 = head1->next;
	} else {
		head3 = head2;
		head2 = head2->next;
	}
	head = head3;
	while (head1 && head2) {
		if (head1->val < head2->val) {
			head3->next = head1;
			head1 = head1->next;
		} else {
			head3->next = head2;
			head2 = head2->next;
		}
		head3 = head3->next;
	}
	if (head1)
		head3->next = head1;
	if (head2)
		head3->next = head2;
	return head;
}

ListNode* SortList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
	ListNode* fast = head->next, *slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* head1 = SortList(slow->next);
	slow->next = NULL;
	ListNode* head2 = SortList(head);
    return Merge(head1, head2);
}

int main(void) {
    ListNode* node1 = new ListNode(30);
    ListNode* node2 = new ListNode(50);
    ListNode* node3 = new ListNode(10);
    node1->next = node2;
    node2->next = node3;
    ListNode* cur = SortList(node1);
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
