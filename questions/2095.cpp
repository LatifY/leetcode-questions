/*
 * Problem: 2095. Delete the Middle Node of a Linked List
 * Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
 * Author: LatifY
 * Date: 15 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        
        ListNode* turtle = head;
        ListNode* rabbit = head->next->next;
        
        while(rabbit && rabbit->next){
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }
        ListNode* tmp = turtle->next->next;
        delete turtle->next;
        turtle->next = tmp;
        
        return head;
        
    }
};