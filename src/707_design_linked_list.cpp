//707. Design Linked List 设计链表
//作者: yuelilily
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class MyLinkedList {
private:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr) {}
    };
    ListNode* head;

public:
    MyLinkedList(): head(nullptr) {   
    }
    
    int get(int index) {
        if (head == nullptr)
            return -1;
        ListNode* node = head;
        while (index > 0 && node->next != nullptr)
        {
            node = node->next;
            --index;
        }
        return (index > 0) ? -1 : node->val;
    }
    
    void addAtHead(int val) {
        ListNode* newnode = new ListNode(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    
    void addAtTail(int val) {
        if (head == nullptr)
        {
            addAtHead(val);
            return;
        }
        ListNode* newnode = new ListNode(val);
        ListNode* node = head;
        while (node->next != nullptr)
            node = node->next;
        node->next = newnode;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0)
        {
            addAtHead(val);
            return;
        }
        ListNode* newnode = new ListNode(val);
        ListNode* node = head;
        ListNode* prev = head;
        while (index > 0 && node != nullptr)
        {
            prev = node;
            node = node->next;
            --index;
        }
        if (index == 0)
        {
            newnode->next = node;
            prev->next = newnode;
        }
        else (index > 0)
        ;
    }
    
    void deleteAtIndex(int index) {
        if (head != nullptr && index >= 0)
        {
            if (index == 0)
            {
                if (head->next != nullptr)
                    head = head->next;
                else
                    head = nullptr;
                return;
            }
            ListNode* node = head;
            ListNode* prev = head;
            while (index > 0 && node->next != nullptr)
            {
                prev = node;
                node = node->next;
                --index;
            }
            if (index == 0)
                prev->next = node->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
