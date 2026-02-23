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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        bool ltor = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>zlevel(size);
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // take a temp vector and put numbers on index based upon the direction of toggle
                int index = ltor ? i: size -1-i;
                zlevel[index] = node -> val;

                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }
            ltor = !ltor;
            ans.push_back(zlevel);
        }
        return ans;
    }
};