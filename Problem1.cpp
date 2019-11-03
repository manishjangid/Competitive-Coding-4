/* Problem Statement:

VERIFIED ON LEETCODE PLATFORM 
110. Balanced Binary Tree
Easy

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Return false.

 * Solution 1: using recursive approach
   Time Complexity : O(n^2) 
 * Space complexity :O(1) 
 * Solution 2: using recursive approach but not calculating height every time for each level
   Time Complexity : O(n) 
 * Space complexity :O(1) 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        /* Is tree balaced on left side and right side, if yes then check for absolute value difference between heights of
         2 subtrees. if it is less than 1 then all conditions are satisfied hence we can return true else return false */
        return isBalanced(root->left) && isBalanced(root->right) && (abs(height_of_tree(root->left) - height_of_tree(root->right)) <= 1);
    }
    
    int height_of_tree(TreeNode *root) {
        /* return 0 if root is NULL */
        if (root == NULL) {
            return 0;
        }
        /* Get the max of heights for two subtree as we are looking for the longest subtree not the shortest one. add 1 to it for the height*/
        return max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
    }

    /* solution 2: O(n) solution */
    const int not_valid = -1;
    int height_of_tree(TreeNode* root) {
        
        if (root == NULL) {
            return 0;
        }
        int left_h = height_of_tree(root->left);
        int right_h = height_of_tree(root->right);
        
        if (left_h == not_valid || right_h == not_valid) {
            return not_valid;
        }
        
        if (abs(left_h - right_h) > 1) {
            return not_valid;
        }
        
        return max(left_h,right_h) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return height_of_tree(root) != not_valid;

    }
};/* Execute on leetcode platform */


