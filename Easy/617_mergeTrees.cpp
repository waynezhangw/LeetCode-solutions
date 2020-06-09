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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL){
        	t1 = NULL;
        	return t1;
        }
        else if (t1 == NULL && t2 != NULL){
        	t1 = t2;
        	return t1;
        }
        else if (t1 != NULL && t2 == NULL){
        	return t1;
        }
        else {
        	t1->val = t1->val + t2->val;
        	merge(t1, t2);
        }
        return t1;
    }

    void merge(TreeNode* t1, TreeNode* t2){
    	if (t1->left == NULL && t2->left == NULL){
        	t1->left = NULL;
        }
        else if (t1->left == NULL && t2->left != NULL){
        	t1->left = t2->left;
        }
        else if (t1->left != NULL && t2->left == NULL){
        	//
        }
        else {
        	(t1->left)->val = (t1->left)->val + (t2->left)->val;
        	merge(t1->left, t2->left);
        }
        if (t1->right == NULL && t2->right == NULL){
        	t1->right = NULL;
        }
        else if (t1->right == NULL && t2->right != NULL){
        	t1->right = t2->right;
        }
        else if (t1->right != NULL && t2->right == NULL){
        	//
        }
        else {
        	(t1->right)->val = (t1->right)->val + (t2->right)->val;
        	merge(t1->right, t2->right);
        }
    }
};