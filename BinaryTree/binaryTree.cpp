#include <bits/stdc++.h>
using namespace std;

class Node{
  
  public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
      this->data = data;
      left = right= NULL;
    }

};
// build tree
Node* buildTree(vector<int>& nodes, int& idx){
    if (nodes[idx] == -1) {
        idx++;
        return NULL;
    }
    Node* currNode = new Node(nodes[idx++]);
    currNode->left = buildTree(nodes, idx);
    currNode->right = buildTree(nodes, idx);
    return currNode;
}

// tree traversal
// preorder, postorder, inorder, level order
// problem links:
// leetcode 144, https://leetcode.com/problems/binary-tree-preorder-traversal/
// leetcode 145, https://leetcode.com/problems/binary-tree-postorder-traversal/
// leetcode 94, https://leetcode.com/problems/binary-tree-inorder-traversal/
// leetcode 102, https://leetcode.com/problems/binary-tree-level-order-traversal/
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

void preorder(Node * root){
  if(root == NULL) return;
  cout<< root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(Node * root){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}
void inorder(Node* root){
  if(root == NULL) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void levelOrder(Node* root){
  if(root == NULL) return;
  queue<Node*>q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    Node* curren = q.front();
    q.pop();
    if(curren == NULL){
      cout<<endl;
      if(q.empty()) break;
      else q.push(NULL);
    }else{
      cout<<curren->data<<" ";
      if(curren->left !=NULL) q.push(curren->left);
      if(curren->right !=NULL) q.push(curren->right);
    }
  }

}

// height of a tree
// leetcode 104, https://leetcode.com/problems/maximum-depth-of-binary-tree/
// leetcode 111, https://leetcode.com/problems/minimum-depth-of-binary-tree/
// https://www.geeksforgeeks.org/find-height-of-binary-tree/

int height(Node* root){
  if(root == NULL) return 0;

  int left = height(root->left);
  int right = height(root->right);
  return max(left, right)+1;
}

// count number of nodes in a tree
// leetcode 222,  https://leetcode.com/problems/count-complete-tree-nodes/
// https://www.geeksforgeeks.org/count-nodes-in-binary-tree/

int countNode(Node* root){
  if(root == NULL) return 0;
  int left = countNode(root->left);
  int right = countNode(root->right);
  return left+right+1;
}

// sum of nodes
// problem links:
// leetcode 112, https://leetcode.com/problems/path-sum/
// leetcode 113, https://leetcode.com/problems/path-sum-ii/
// https://www.geeksforgeeks.org/sum-of-nodes-in-binary-tree/

int sumOfNodes(Node* root){
  if(root == NULL) return 0;
  int left = sumOfNodes(root->left);
  int right = sumOfNodes(root->right);
  return left+right+root->data;
}

// longest path  of tree
/*!  Approch1: O(n^2) */
// problem links:
// leetcode 543, https://leetcode.com/problems/diameter-of-binary-tree/
// https://www.geeksforgeeks.org/diameter-of-binary-tree/

int diameter1(Node*root){
  if(root ==NULL) return 0;
  int diam1 = diameter1(root->left);
  int diam2 = diameter1(root->right);
  int diam3 = height(root->left)+ height(root->right) +1;
  return max(diam3, max(diam1,diam2));
}

/*!  Approch2: O(n) */
// pair <diameter, height>
pair<int,int> diameter2(Node* root){
  if(root == NULL) return make_pair(0,0);
  pair<int, int> left = diameter2(root->left);
  pair<int, int> right = diameter2(root->right);

  int currentDiam = left.second + right.second+1; // calculate diameter though root node
  int finalDiam = max(currentDiam, max(left.first , right.second));
  int height = max(left.second,right.second)+1;
  return make_pair(finalDiam,height);
  
}


/* Find subtree of another tree */
// problem links:
// leetcode 572, https://leetcode.com/problems/subtree-of-another-tree/
// https://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

bool isIdentical(Node* root1, Node*root2){

  if(root1==NULL && root2==NULL) return true;
  else if(root1==NULL|| root2==NULL)return false;

  if(root1->data!=root2->data) return false;
  return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

// subtreee of another tree
bool isSubTree(Node* root, Node*subRoot){
  if(root==NULL && subRoot==NULL) return true;
  else if(root==NULL) return false;

  if(root->data == subRoot->data){
    if(isIdentical(root, subRoot)) return true;
  }

  bool left = isSubTree(root->left, subRoot);

  if(!left){
    return isSubTree(root->right, subRoot);
  }
  return true;
}


// top view of a tree
// problem links:
//* leetcode 102, https://leetcode.com/problems/binary-tree-level-order-traversal/
//* https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// leetcode 199, https://leetcode.com/problems/binary-tree-right-side-view/

void topView(Node* root){
  // unique number consider as a non visited distance
  // root HD = 0;
  // level order traversal
  // queue<pair<Node*, Horozontal Distance(HD)>> q;

  queue<pair<Node*, int>> q;
  q.push({root, 0});
  map<int, Node*> mp;  // node, HD   :  track unique value of HD

  while(!q.empty()){

    pair<Node*, int> curr = q.front();
    q.pop();
    Node* currNode = curr.first;
    int currHD = curr.second;
    
    if(mp.count(currHD) == 0 ){
      mp.insert({currHD, currNode});
    }

    if(currNode->left !=NULL)
        q.push({currNode->left, currHD-1 });
    if(currNode->right !=NULL)
      q.push({currNode->right, currHD+1});

  }

  for(auto it:mp) cout<<it.second->data<<" ";
}

// bottom view of a tree
// problem links:
// https://www.geeksforgeeks.org/bottom-view-binary-tree/

void bottomView(Node* root){
  // unique number consider as a non visited distance
  // root HD = 0;
  // level order traversal
  // queue<pair<Node*, Horozontal Distance(HD)>> q;

queue<pair<int, Node*>>q;
q.push({0, root});

map<int, Node*> mp; // track distance and node

while (!q.empty())
{
  pair<int, Node*> curr = q.front();
  q.pop();
  Node* currNode = curr.second;
  int currHD = curr.first;
  mp[currHD] = currNode;
  if(currNode->left !=NULL)
    q.push({currHD-1, currNode->left});
  if(currNode->right !=NULL)
    q.push({currHD+1, currNode-> right});
}
  for(auto it:mp) cout<<it.second->data<<" ";
}


// Left side view
// problem links:
// leetcode 199, https://leetcode.com/problems/binary-tree-right-side-view/

void leftSideView(Node* root){
  if(root == NULL) return;
  queue<pair<Node*, int>> q;
  q.push({root, 1});
  map<int, Node*> mp; // track level and node

  while(!q.empty()){
    pair<Node*, int> curr = q.front();
    q.pop();
    Node* currNode = curr.first;
    int currLevel = curr.second;

    if(mp.count(currLevel) == 0){
      mp.insert({currLevel, currNode});
    }

    if(currNode->left !=NULL)
      q.push({currNode->left, currLevel+1});
    if(currNode->right !=NULL)
      q.push({currNode->right, currLevel+1});
  }

  for(auto it:mp) cout<<it.second->data<<" ";
}

// right side view
// problem links:
// leetcode 199, https://leetcode.com/problems/binary-tree-right-side-view/

void rightSideView(Node* root){
  if(root== NULL) return;
  queue<pair<Node*, int>>q;
  q.push({root,0});
  unordered_map<int,Node*> mp;
  while(!q.empty()){
    Node* currNode = q.front().first;
    int currHD = q.front().second;
    q.pop();
    if(mp.count(currHD)==0){
      mp[currHD] = currNode;
    }

    if(currNode->right !=NULL){
      q.push({currNode->right, currHD+1});
    }
    if(currNode->left){
      q.push({currNode->left, currHD+1});
    }
  }
  for(auto it:mp) cout<<it.second->data<<" ";
}
// kth level of a tree
// my logic for print kth lelev
void kthLevel2(Node* root,int level){
  if( root==NULL) return;
  queue<pair<Node*, int>> q;
  q.push({root,1});
  while(!q.empty()&& q.front().second<=level){
    Node* currNode = q.front().first;
    int l = q.front().second;
    q.pop();

    if( l == level){
      cout<<currNode->data<<" ";
    }
    if(l<=level){
      if(currNode->left) {          
        q.push({currNode->left, l+1});
      };
      if(currNode->right ) {
        q.push({currNode->right, l+1});
      };
    }
  }
}

// apna college level : recursive method
void kthLevelHelper(Node* root, int k, int currentLevel){
  if( root==NULL) return;

  if(currentLevel == k){
    cout<<root->data<<" ";
    return;
  }
  kthLevelHelper(root->left, k, currentLevel+1);
  kthLevelHelper(root->right, k, currentLevel+1);
}
void kthLevel(Node* root, int level){
  kthLevelHelper(root, level, 1);
}

// lowest common ansistor
// problem links:
// leetcode 236, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// leetcode 1644, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
// https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree/

// time complexity: O(N), Space Complexity: O(N)
// Approch 1
// find path to node
// Time Complexity: O(N), Space Complexity: O(N)
bool rootToPath(Node* root, int n, vector<int>&path){
  if(root == NULL) return false;
  path.push_back(root->data);
  if(root->data == n) return true;
  int l = rootToPath(root->left, n, path);
  int r = rootToPath(root->right, n, path);
  if(l||r) return true;
  path.pop_back();
  return false;
}
int LCA1(Node* root,int n1, int n2){
  vector<int> path1, path2;

  rootToPath(root, n1, path1);
  rootToPath(root, n2, path2);
  int lca = -1;
  for(int i =0, j=0; i<path1.size() && j<path2.size(); i++, j++){
    if(path1[i] !=path2[j]) return lca;
    lca = path1[i];
  }

  return lca;
}

// lowest Common ansistor
// Approch 2
// Time Complexity:O(N), Space Complexity: O(N)

Node* LCA2(Node* root,int n1, int n2){
  if(root==NULL) return NULL;
  if(root->data == n1|| root->data == n2) return root;

  Node* leftLCA = LCA2(root->left, n1, n2);
  Node* rightLCA = LCA2(root->right, n1, n2);
  if(leftLCA && rightLCA) return root;
  return leftLCA ==NULL? rightLCA:leftLCA;

}

// Minimum distance between two nodes
// problem links:
// leetcode 236, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
// Time Complexity: O(N), Space Complexity: O(N)

void rootToPath2(Node* root, int n, vector<int>&path){
  if(root == NULL) return;
  path.push_back(root->data);
  if(root->data == n) return;
  rootToPath2(root->left, n, path);
  if(path.back() != n) path.pop_back();
  if(path.back() != n) rootToPath2(root->right, n, path);
  
}


// find distance between two nodes
// Time Complexity: O(N), Space Complexity: O(N)

int findDistance(Node* root, int n1, int n2){
  Node* lca = LCA2(root, n1, n2);
  vector<int> path1, path2;
  rootToPath2(lca, n1, path1);
  rootToPath2(lca, n2, path2);
  return path1.size() + path2.size() - 2; // -2 for lca node
}


// kth ancestor of a node
// problem links:
// leetcode 236, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-1/


int kthAncestor(Node* root, int node, int k){
  if(root == NULL || k<0) return -1;
  if(root->data == node) return 0;
  int left = kthAncestor(root->left, node, k);
  int right = kthAncestor(root->right, node, k);

  if(left == -1 && right == -1) return -1;
  int valid = left ==-1 ? right : left;
  if(valid + 1 == k) {
    cout<<root->data<<" ";
  
  }
  return valid + 1;
}

// transform tree into sum  tree

int transformtree(Node* root){
  if(root==NULL) return 0;
  
  int leftOld =  transformtree(root->left);
  int rightOld = transformtree(root->right);
  int currentOld = root->data;

  root->data = leftOld+ rightOld;

  if(root->left != NULL) root->data += root->left->data;
  if(root->right != NULL) root->data += root->right->data;

  return currentOld;
}



int main(){
  vector<int> nodes = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  int idx = 0;
  Node* root = buildTree(nodes, idx);
  vector<int> path;
  rootToPath2(root, 6, path);
  cout<<"Path to 6: ";
  for(int i: path) cout<<i<<" ";

  return 0;
}