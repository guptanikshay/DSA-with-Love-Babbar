#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// TWO SUM IN A BST: You are given a BST and a target value and you need to check if two such numbers exist in that BST whose sum is equal to the target value.
void inorderTrav(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorderTrav(root->left, in);
    in.push_back(root->data);
    inorderTrav(root->right, in);
}
bool findTarget(Node *root, int k)
{
    vector<int> inorder;
    inorderTrav(root, inorder);
    int i = 0, j = inorder.size() - 1;
    while (i < j)
    {
        if (inorder[i] + inorder[j] == k)
            return true;
        else if (inorder[i] + inorder[j] > k)
            j--;
        else
            i++;
    }
    return false;
}

// FLATTEN A BST TO A SORTED LIST
// void inorder(TreeNode<int> * root, vector<int> &in){
//     if(!root)
//     return;
//     inorder(root->left, in);
//     in.push_back(root->data);
//     inorder(root->right, in);
// }
// TreeNode<int>* flatten(TreeNode<int>* root)
// {
//     // Write your code here
//     if(!root)
//     return NULL;
//     vector <int> in;
//     inorder(root, in);
//     int n = in.size();
//     TreeNode<int>* ans = new TreeNode<int>(in[0]);
//     TreeNode<int> * curr = ans;
//     for(int i=1; i<n; i++){
//         TreeNode<int> * temp = new TreeNode<int>(in[i]);
//         curr->left = NULL;
//         curr->right = temp;
//         curr = temp;
//     }
//     curr->left = NULL;
//     curr->right = NULL;
//     return ans;
// }

// CONVERT A NORMAL BST TO A BALANCED BST
// A BST in which the height of the two subtrees of every node differs no more than one.
// void inorder(TreeNode *root, vector<int> &in)
// {
//     if (!root)
//         return;
//     inorder(root->left, in);
//     in.push_back(root->val);
//     inorder(root->right, in);
// }
// TreeNode *makeTree(vector<int> &in, int s, int e) // Passing the vector here by reference consumes much less time and memory
// {
//     if (s > e)
//     {
//         return NULL;
//     }
//     int m = (s + e) / 2;
//     TreeNode *root = new TreeNode(in[m]);
//     root->left = makeTree(in, s, m - 1);
//     root->right = makeTree(in, m + 1, e);
//     return root;
// }
// TreeNode *balanceBST(TreeNode *root)
// {
//     vector<int> in;
//     inorder(root, in);
//     int s = 0, e = in.size() - 1;
//     return makeTree(in, s, e);
// }

// CREATE A BST USING ITS PREORDER TRAVERSAL
// TreeNode *solve(vector<int> &preorder, int &i, int maxi)
// {
//     if (i >= preorder.size() || preorder[i] > maxi)
//         return NULL;
//     TreeNode *root = new TreeNode(preorder[i++]);
//     root->left = solve(preorder, i, root->val);
//     root->right = solve(preorder, i, maxi);
//     return root;
// }
// TreeNode *bstFromPreorder(vector<int> &preorder)
// {
//     int maxi = INT_MAX, i = 0;
//     return solve(preorder, i, maxi);
// }

// MERGE TWO BST
// Approach 1: It has time complexity of O(m+n) and space complexity of  O(m+n)
void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void mergeArr(vector<int> &in1, vector<int> &in2, vector<int> &ans)
{
    int n = in1.size(), m = in2.size();
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (in1[i] <= in2[j])
        {
            ans.push_back(in1[i]);
            i++;
        }
        else
        {
            ans.push_back(in2[j]);
            j++;
        }
    }
    while (i < n)
    {
        ans.push_back(in1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(in2[j]);
        j++;
    }
}
Node *makeTree(vector<int> &in, int s, int e) // Passing the vector here by reference consumes much less time and memory
{
    if (s > e)
    {
        return NULL;
    }
    int m = (s + e) / 2;
    Node *root = new Node(in[m]);
    root->left = makeTree(in, s, m - 1);
    root->right = makeTree(in, m + 1, e);
    return root;
}
Node *merge(Node *root1, Node *root2)
{
    // Your code here
    vector<int> in1, in2, ans;
    inorder(root1, in1);
    inorder(root2, in2);
    mergeArr(in1, in2, ans);
    return makeTree(ans, 0, ans.size());
}
// Approach 2: Here we optimize space complexity by using linked lists to O(h1 + h2)
// Converting a BST into DoublyLL
void convertToDLL(Node *root, Node *&head)
{
    if (!root)
        return;
    convertToDLL(root->right, head);
    root->right = head;
    if (head)
        head->left = root;
    head = root;
    convertToDLL(root->left, head);
}
// Merge two sorted LL into one
Node *merge2LL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
}
// Converting the created sorted linked list to BST
int countNodes(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
// Understand this function in simple recursive turns, first we define the base condition, then we create the left subtree using first n/2 nodes and we define the next node as root and then we create the right subtree using the remaining n-n/2-1 nodes. This function is returning the root of the formed BST and in the end the head will point to NULL after last node.
Node *sortedLLtoBST(Node *head, int n)
{ // 2nd parameter is no of nodes
    if (n <= 0 || !head)
        return NULL;
    Node *left = sortedLLtoBST(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLtoBST(head, n - n / 2 - 1);
    return root;
}
// Final Function
Node *mergeBST(Node *root1, Node *root2)
{
    // Convert BST into sorted LL inplace
    Node *head1 = NULL;
    convertToDLL(root1, head1);
    head1->left = NULL;
    Node *head2 = NULL;
    convertToDLL(root2, head2);
    head2->left = NULL;

    // Merge the two so formed LL
    Node *head = merge2LL(head1, head2);

    // Convert sorted LL to BST
    return sortedLLtoBST(head, countNodes(head));
}

// SIZE OF A LARGEST BST IN A BINARY TREE
// Approach 1: In this approach we visit every node and check whether the tree below it is a BST or not and if it is BST we store its size and return the maxSize found. Checking BST for a node takes O(n) time and as we'll do this for n nodes, we end up having a time complexity of O(n^2), which gets optimized in the next approach
// Approach 2: Here we create a class containing some information and we update that info as we visit every node and this way we only traverse the tree once and hence solving the problem with O(n) TC
// class info{
//     public:
//     int maxi;
//     int mini;
//     bool isBST;
//     int size; // Here size represents the total number of nodes in that tree.
// };

// info solve(TreeNode <int> *root, int &ans){
//     if(!root) return {INT_MIN, INT_MAX, true, 0};

//     info left = solve(root->left, ans);
//     info right = solve(root->right, ans);

//     info Curr;
//     Curr.size = left.size + right.size + 1;
//     Curr.maxi = max(right.maxi, root->data);
//     Curr.mini = min(left.mini, root->data);

//     if(left.isBST && right.isBST && root->data>left.maxi && root->data<right.mini)
//     Curr.isBST = true;
//     else
//     Curr.isBST = false;

//     if(Curr.isBST)
//     ans = max(ans, Curr.size);

//     return Curr;
// }
// int largestBST(TreeNode<int>* root)
// {
//     // Write your code here.
//     int maxSize=0;
//     info temp = solve(root, maxSize);
//     return maxSize;
// }

// Maximum sum BST in Binary Tree: Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).
// bool solve(TreeNode *root, int min, int max, int &sum) // This function checks for BST and calculates the total sum of nodes in the checked tree.
// {
//     if (!root)
//         return true;
//     sum+=root->val;
//     if (root->val <= min || root->val >= max)
//         return false;
//     else
//         return (solve(root->left, min, root->val, sum) && solve(root->right, root->val, max, sum));
// }
// bool isValidBST(TreeNode *root, int &sum)
// {
//     int min = 0, max = INT_MAX;
//     return solve(root, min, max, sum);
// }
// void helper(TreeNode *root, int &ans){ // This function checks for valid BST and stores the maximum sum found in the entire tree.
//     if(!root)
//     return;
//     int sum=0;
//     if(isValidBST(root, sum)){
//         ans = max(ans, sum);
//         return;
//     }
//     helper(root->left, ans);
//     helper(root->right, ans);
// }
// int maxSumBST(TreeNode* root) {
//     int ans = 0;
//     helper(root, ans);
//     return ans;
// }
int main()
{

    return 0;
}