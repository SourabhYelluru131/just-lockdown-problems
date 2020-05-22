// Tree Implementation
// Functions - 
// (1) Insert
// (2) Breadth First Search
// (3) Depth First Search
// 	a. Preorder DFS
//	b. Inorder DFS
//	c. Postorder DFS


#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* parent;
void Insert(TreeNode* root,int value,char lastmove)
{
    if(!root)
    {
        TreeNode* temp = new TreeNode();
        temp->val = value;
        temp->left = nullptr;
        temp->right = nullptr;
        if(lastmove=='l') parent->left = temp;
        else parent->right = temp;
        parent = nullptr;
    }
    else
    {
        char pos;
        parent = root;
        cout << "\nInsert to the left or right of " << root->val << " : ";
        cin >> pos;
        if(pos=='r') Insert(root->right, value,pos);
        else
        {
            if(pos == 'l') Insert(root->left,value,pos);
        }
    }
}

void BFS(TreeNode* root)
{
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        TreeNode* current = que.front();
        if(current->left) que.push(current->left);
        if(current->right) que.push(current->right);
        cout << current->val << "  ";
        que.pop();
    }
}

void PreOrder(TreeNode* root)
{
    if(!root) return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode* root)
{
    if(!root) return;
    PreOrder(root->left);
    cout << root->val << " ";
    PreOrder(root->right);
}

void PostOrder(TreeNode* root)
{
    if(!root) return;
    PreOrder(root->left);
    PreOrder(root->right);
    cout << root->val << " ";
}

int main()
{
    int option,inp;
    TreeNode* head;
    cout << "Enter the value of root node: ";
    cin >> inp;
    TreeNode* root = new TreeNode();
    root->left = nullptr;
    root->right = nullptr;
    root->val = inp;
    head = root;
    do
    {
        cout << "\n";
        cout << "1: Insert\n";
        cout << "2: Search Breadth First\n";
        cout << "3: Search PreOrder\n";
        cout << "4: Search InOrder\n";
        cout << "5: Search PostOrder\n";
        cout << "Enter option ((1-5), 0 for exit): ";
        cin >> option;
        switch(option)
        {
            case 1:
                int value;
                char pos;
                cout << "\nEnter value to be inserted: ";
                cin >> value;
                cout << "\nEnter to the left or right of root? ( Enter l or r ): ";
                cin >> pos;
                parent = root;
                if(pos=='l') Insert(root->left,value,pos);
                else
                {
                    if(pos=='r') Insert(root->right,value,pos);
                    else break;
                }
                break;
            case 2:
                BFS(head);
                break;
                
            case 3:
                PreOrder(head);
                break;
                
            case 4:
                InOrder(head);
                break;
                
            case 5:
                PostOrder(head);
                break;
        }       
    }while(option!=0);
}
