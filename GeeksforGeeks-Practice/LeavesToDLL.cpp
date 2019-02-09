#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/

Node *convertToDLL(Node *root,Node **head_ref)
{
    if(root == NULL) return NULL;
    // if it is a leaf
    if(root->left == NULL && root->right == NULL)
    {
        root->right = *head_ref;
        if(*head_ref != NULL) (*head_ref)->left = root;
        *head_ref = root;
        return NULL;
    }
    root->right = convertToDLL(root->right, head_ref);
    root->left = convertToDLL(root->left, head_ref);
    return root;
}

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
Node *convertToDLL(Node *root,Node **head_ref);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2;
			scanf(" %c",&lr);
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
					break;
					case 'R':root->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		Node *head=NULL;
		root=convertToDLL(root,&head);
		while(head->right!=NULL){
			cout<<head->data<<" ";
			head=head->right;
		}
		cout<<head->data<<endl;
		while(head!=NULL){
			cout<<head->data<<" ";
			head=head->left;
		}
		cout<<endl;
	}
}

