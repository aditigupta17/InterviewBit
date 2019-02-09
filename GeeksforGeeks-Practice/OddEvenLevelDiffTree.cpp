/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*Iterative approach*/
int getLevelDiff(Node *root)
{
   if(root == NULL) return 0;
   queue<Node*> Q;
   Q.push(root);
   int level = 0, evenSum = 0, oddSum = 0;
   while(!Q.empty())
   {
       int queueLength = Q.size();
       level++;
       while(queueLength > 0)
       {
           Node *temp = Q.front();
           Q.pop();
           if(level % 2 == 0) evenSum += temp->data;
           else oddSum += temp->data;
           if(temp->left != NULL) Q.push(temp->left);
           if(temp->right != NULL) Q.push(temp->right);
           queueLength--;
       }
   }
   return oddSum - evenSum;
}
/*Recursive approach*/
int getLevelDiff(Node *root)
{
    if(root == NULL) return 0;
    return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
}
