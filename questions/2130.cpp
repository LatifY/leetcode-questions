/*
 * Problem: 2130. Maximum Twin Sum of a Linked List
 * Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
 * Author: LatifY
 * Date: 14 June 2026
 * Time Complexity: O(N)
 * Space Complexity: O(N)
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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            n++;
            curr = curr->next;
        }

        stack<int> st;
        curr = head;
        for(int i = 0; i < n / 2; i++){
            st.push(curr->val);
            curr = curr->next;
        }

        int sum = 0, maxSum = 0;
        while(curr != nullptr){
            sum = curr->val + st.top();
            st.pop();
            maxSum = max(maxSum, sum);
            curr = curr->next;
        }
        return maxSum;
    }
};

