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

    bool checkMirror(TreeNode *node1, TreeNode *root2){
        if(node1 ==NULL && root2 ==NULL)
        {
            return true;
        }
        if(node1 !=NULL && root2 ==NULL)
        {
            return false;
        }
        if(node1 ==NULL && root2 !=NULL)
        {
            return false;
        }
        if(node1 -> val != root2 -> val)
        {
            return false;
        }

        bool option1 = checkMirror(node1 -> left, root2 -> right);
        bool option2 = checkMirror(node1 -> right , root2 -> left);
        bool finalAns = option1 && option2;

        return finalAns;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        return    checkMirror(root -> left, root -> right);
    
        
    }
};