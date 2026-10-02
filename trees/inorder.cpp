void inorder(treenode *root,vector<int>&ans){
    if(root==null){
        return;
    }

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}