#include <iostream>


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}

};

class Solution
{
public:
	ListNode* reverseList1(ListNode* head)
	{
		ListNode* previous = new ListNode(head->val);
		
		while(head)
		{
			ListNode* next = head->next;
			head->next = previous;
			previous = head;
			head = next;
		}
		
		return previous;
		
	}
	ListNode* reverseList2(ListNode* head)
	{
		if (head->next == nullptr) return head;
		ListNode* previous = reverseList2(head->next);
		head->next->next = head;
		head->next = nullptr;
		return previous;
		
	}
};


int main()
{
	ListNode* p5 = new ListNode(5);
	ListNode* p4 = new ListNode(4);
	ListNode* p3 = new ListNode(3);
	ListNode* p2 = new ListNode(2);
	ListNode* p1 = new ListNode(1);
	ListNode* cur;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	cur = p1;
	for (int i = 0; i<5; i++)
	{
		std::cout << cur->val;
		cur = cur->next;
	}
	std::cout << std::endl;
	Solution s;
	p1 = s.reverseList2(p1);

	cur = p1;
	for (int i = 0; i < 5; i++)
	{
		std::cout << cur->val;
		cur = cur->next;
	}
	
	
}