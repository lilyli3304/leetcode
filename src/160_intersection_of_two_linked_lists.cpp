//160. Intersection of Two Linked Lists 相交链表
//作者：yuelilily
//链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/solution/by-yuelilily-za67/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        if (headA == headB)
            return headA;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        ListNode* tail = nullptr;
        ListNode* fast = nullptr;
        ListNode* slow = nullptr;
        ListNode* ptr = nullptr;
        //同速指针寻找交叉点，如无法找到，遍历到“链较短的那条”的结尾
        //将短链结尾连接到链头形成环
        while (ptrA != ptrB)
        {
            if (ptrA->next == nullptr)
            {
                tail = ptrA;
                tail->next = headA;
                fast = headB;
                slow = headB;
                ptr = headB;
                break;
            }
            if (ptrB->next == nullptr)
            {
                tail = ptrB;
                tail->next = headB;
                fast = headA;
                slow = headA;
                ptr = headA;
                break;
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        //同速指针找到交点
        if (ptrA == ptrB)
            return ptrA;
        
        //用快慢指针，找到交叉点(见142题)
        do
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                //若根本不交叉，则解环返回null
                tail->next = nullptr;
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        while (fast != slow);

        while (ptr != slow)
        {
            ptr = ptr->next;
            slow = slow->next;
        }
        //找到交叉点，解环返回交叉点
        tail->next = nullptr;
        return ptr;
    }
};

