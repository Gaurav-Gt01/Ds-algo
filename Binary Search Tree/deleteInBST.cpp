// Delete a node in BST 

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = NULL;
        TreeNode* curr = root;

        if (root == NULL) return NULL;

        // root is the node to delete
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            TreeNode* rightSub = root->right;
            TreeNode* leftSub = root->left;
            delete root;

            if (rightSub == NULL) return leftSub;
            TreeNode* leftmost = leftmostNode(rightSub);
            leftmost->left = leftSub;
            return rightSub;
        }

        while (curr) {
            if (curr->val == key) {
                TreeNode* rightSub = curr->right;
                TreeNode* leftSub = curr->left;
                if (prev->left == curr) {
                    if (rightSub == NULL) {
                        prev->left = leftSub;
                    } else {
                        TreeNode* leftmost = leftmostNode(rightSub);
                        leftmost->left = leftSub;
                        prev->left = rightSub;
                    }
                } else {
                    if (rightSub == NULL) {
                        prev->right = leftSub;
                    } else {
                        TreeNode* leftmost = leftmostNode(rightSub);
                        leftmost->left = leftSub;
                        prev->right = rightSub;
                    }
                }
                delete curr;
                break;
            } else if (curr->val > key) {
                prev = curr;
                curr = curr->left;
            } else {
                prev = curr;
                curr = curr->right;
            }
        }

        return root;
    }

    TreeNode* leftmostNode(TreeNode* root) {
        if (root == NULL) return NULL;
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
};