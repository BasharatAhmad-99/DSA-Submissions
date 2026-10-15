/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(root->val==key){
        
        if(!root->left)  return root->right;   
        if(!root->right) return root->left;    

        // two children: use inorder successor
        TreeNode* succ = root->right;
        while(succ->left) succ = succ->left;

        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
        return root;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};