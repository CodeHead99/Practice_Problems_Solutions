You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:

Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8
Output: 2 3 4 5 6 7 8
Explanation: 
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.
Example 2:

Input:
       5
        \
         8
       /   \
      7     9  
Output: 5 7 8 9
Explanation:
After flattening, the tree looks like this:
   5
    \
     7
      \
       8
        \
         9
Your Task:
You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST as input parameter and returns the root node after transforming the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 103
1 <= Data of a node <= 105




class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        function<pair<Node*, Node*> (Node *, Node *, bool)> dfs = [&](Node * node, Node * prev, bool isLeft) -> pair<Node*, Node*> {
            if(!node)
                return {nullptr, nullptr};
                
            pair<Node *, Node *> left = dfs(node -> left, node, 1);
            pair<Node *, Node *> right = dfs(node -> right, node, 0);
                
            node -> left = left.first;
            node -> right = right.first;
            
            Node * MIN = left.first ? left.first : node;
            Node * MAX = right.second ? right.second : node;
            
            if(isLeft)
                MAX -> right = prev;
            
            node -> left = nullptr;
            return {MIN, MAX};
        };
        
        return dfs(root, nullptr, 0).first;
    }
};
