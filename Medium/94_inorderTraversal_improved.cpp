#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(){
        val=0;
        left=NULL;
        right=NULL;
    }
	//TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	Solution(){
	    root = new TreeNode();
        L2_1 = new TreeNode();
        R2_1 = new TreeNode();
        L3_1 = new TreeNode();
        L3_2 = new TreeNode();
        R3_1 = new TreeNode();
        R3_2 = new TreeNode();
        L4_4 = new TreeNode();
        R4_4 = new TreeNode();
	}

	virtual ~Solution(void){
        delete root;
        root = NULL;
        delete L2_1;
        L2_1 = NULL;
        delete R2_1;
        R2_1 = NULL;
        delete L3_1;
        L3_1 = NULL;
        delete L3_2;
        L3_2 = NULL;
        delete R3_1;
        R3_1 = NULL;
        delete R3_2;
        R3_2 = NULL;
        delete L4_4;
        L4_4 = NULL;
        delete R4_4;
        R4_4 = NULL;
    }

    void initialization(){
        vector<int> A = {3,9,20,5,6,15,7,NULL,NULL,NULL,NULL,NULL,NULL,1,2};
        root->val = A[0];                       
        root->left = L2_1;
        root->right = R2_1;

        L2_1->val = A[1];
        L2_1->left = L3_1;
        L2_1->right = R3_1;
        R2_1->val = A[2];
        R2_1->left = L3_2;
        R2_1->right = R3_2;

        L3_1->val = A[3];
        R3_1->val = A[4];
        L3_2->val = A[5];
        R3_2->val = A[6];
        R3_2->left = L4_4;
        R3_2->right = R4_4;

        L4_4->val = A[13];
        R4_4->val = A[14];
        seeTree(root);
        cout<<endl;
        seeVector(inorderTraversal(root));
    }

    void seeTree(TreeNode* root){
        if(root){
            seeTree(root->left);
            seeTree(root->right);
            cout<<root->val<<",";
        }
        else{
            //cout<<"NULL"<<",";
        }
    }

    void seeVector(vector<int> vec) {
    	for (unsigned int i=0;i<vec.size();i++) {
    		cout<<vec[i]<<","<<endl;
    	}
    	cout<<endl;
    }

    vector<int> inorderTraversal(TreeNode* root) {  //中根遍历，非递归版
        if (root == NULL) {
            return {};
        }
        else {
            vector<int> T;
            stack<TreeNode*> tree;
            tree.push(root);
            TreeNode* currentRoot = root->left;            //一定是下一个左节点
            while (!tree.empty() || currentRoot != NULL) { //当tree空了且当前节点为NULL的时候，while就不能执行了
                while (currentRoot) {
                    tree.push(currentRoot);
                    currentRoot = currentRoot->left;
                }
                currentRoot = tree.top();            //第二层while会走到死，这里要回退一步就到左下角了
                tree.pop();
                T.push_back(currentRoot->val);
                currentRoot = currentRoot->right;
            }
            return T;
        }
    }
    
private:
	TreeNode* root;
    TreeNode* L2_1;
    TreeNode* R2_1;
    TreeNode* L3_1;
    TreeNode* L3_2;
    TreeNode* R3_1;
    TreeNode* R3_2;
    TreeNode* L4_4;
    TreeNode* R4_4;
};

int main(){
	Solution test;
    test.initialization();
    return 0;
}
