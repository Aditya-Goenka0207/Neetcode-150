class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        vector<vector<int>> ans;
        vector<int> level;

        if(root == NULL) return ans;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            level.clear();

            for(int i = 0;i<size;i++){
                TreeNode *top = q.front();
                q.pop();

                level.push_back(top->val);

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};