#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) { }
};

ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* fake = new ListNode(0);
	ListNode* move = fake, *cur = NULL;
	int carry = 0;
	int sum = 0;

	while (l1 && l2) {
		sum = l1->val + l2->val + carry;
		carry = sum / 10;
		cur = new ListNode(sum % 10);
		move->next = cur;
		move = move->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1) {
		while (carry && l1) {
			sum = l1->val + carry;
			carry = sum / 10;
			cur = new ListNode(sum % 10);
			move->next = cur;
			move = move->next;
			l1 = l1->next;
		}
		move->next = l1;
	}
	if (l2) {
		while (carry && l2) {
			sum = l2->val + carry;
			carry = sum / 10;
			cur = new ListNode(sum % 10);
			move->next = cur;
			move = move->next;
			l2 = l2->next;
		}
		move->next = l2;
	}
	if (carry) {
		cur = new ListNode(carry);
		move->next = cur;
	}
	ListNode* ret = fake->next;
	delete fake;
	return ret;
}
int main() {
	ListNode* l11 = new ListNode(2);
	ListNode* l12 = new ListNode(4);
	ListNode* l13 = new ListNode(3);
	l11->next = l12;
	l12->next = l13;
	ListNode* l21 = new ListNode(5);
	ListNode* l22 = new ListNode(6);
	ListNode* l23 = new ListNode(4);
	l21->next = l22;
	l22->next = l23;
	ListNode* ret = AddTwoNumbers(l11, l21);
	while (ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}
}
