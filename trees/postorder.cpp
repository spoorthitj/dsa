void postorder(treenode *root,vector<int>&ans){
    if(root==null){
        return;
    }

    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
}