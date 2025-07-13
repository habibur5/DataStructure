/* 

Binary Search Tree is a special types of tree

timeComplexity: 
  search : 0(log (N))


* properties: left subtree < Root
            * Right Subtree> root 
            * 
            *
todo: important inorder traversal of BST gives Sorted Sequnces
  * inorder Traversal: left->root->right

*/

#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node* left;
    Node* right;
    int data;
    Node(int data){
      this->data = data;
      left = right = NULL;
    }
    Node* insert(Node* root, int data){
      if(root == NULL){
        return new Node(data);
      }
      if(data < root->data){
        root->left = insert(root->left, data);
      } else {
        root->right = insert(root->right, data);
      }
      return root;

    }

  Node* buildTree(vector<int> arr, int n){
    Node* root = NULL;
    for(int i = 0; i < n; i++){
      root = insert(root, arr[i]);
    }
    return root;
  }
};

bool search(Node* root, int k){
  if( root == NULL) return false;
  if(root->data == k)return true;

  if(k < root->data){
    return search(root->left, k);
  } else {
    return search(root->right, k);
  }
  
}


// inorder traversal of BST
// prints the elements in sorted order
void inorder(Node* root){
  if(root==NULL) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);

}

// delete a node from BST
// three cases
//    1. nochildren
//    2. one child
//    3. two children
// for two children, we can replace the node with the inorder successor or inorder predecessor


Node* deleteNode(Node* root, int k){
  if(root == NULL) return NULL;

  if(k<root->data){
    root->left = deleteNode(root->left,k);
  } else if(k > root->data){
    root->right = deleteNode(root->right,k);
  } else {
    // case 1: no children
    if(root->left == NULL && root->right == NULL){
      delete root;
      return NULL;
    }
    // case 2: one child
    if(root->left == NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }


    // case 3: two children
    // find inorder successor (smallest in right subtree)

    Node* successor = root->right;
    while(successor && successor->left != NULL){
      successor = successor->left;
    }
    root->data = successor->data;
    root->right = deleteNode(root->right,successor->data);
  }
  return root;
}

// print in range

void printeInRange(Node* root, int low, int high){
  if(root == NULL) return;

  if(root->data >= low && root->data <= high){
    cout<<root->data<<" ";
  }
  
  if(low < root->data){
    printeInRange(root->left, low, high);
  }
  
  if(high > root->data){
    printeInRange(root->right, low, high);
  }
}

// root to leaf path

void printPath(vector<int> &path){
  for(auto it:path) cout<<it<<" ";
  cout<<endl;
}

void helperPath(Node* root, vector<int> &path){
  if(root == NULL) return;
  path.push_back(root->data);

  if(root->left == NULL && root->right == NULL){
    printPath(path);
    path.pop_back();
    return;
  }
  helperPath(root->left, path);
  helperPath(root->right, path);
  path.pop_back();

}

void pathToLeaf(Node* root){
  vector<int> path;
  helperPath(root, path);
}

// valided BST




int main(){
  
  return 0;
}