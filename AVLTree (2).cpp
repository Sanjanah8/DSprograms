#include<iostream>
#define SPACE 10
#include<stdlib.h>
using namespace std;
class TreeNode
{
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode()
  {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v)
  {
    value = v;
    left = NULL;
    right = NULL;
  }
};
class AVLTree
{
  public:
    TreeNode * root;
  AVLTree()
  {
    root = NULL;
  }
  bool isTreeEmpty()
  {
    if (root == NULL)
        return true;
     else
      return false;

  }
int height(TreeNode * r)
{
    if (r == NULL)
      return -1;
    else
    {
      int lheight = height(r -> left);
      int rheight = height(r -> right);
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }
int getBalanceFactor(TreeNode * n)
{
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
}
TreeNode * rightRotate(TreeNode * y)
  {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    return x;
  }
TreeNode * leftRotate(TreeNode * x)
  {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left;
    y -> left = x;
    x -> right = T2;

    return y;
  }
TreeNode * insert(TreeNode * r, TreeNode * new_node)
{
    if (r == NULL)
    {
      r = new_node;
      cout << "Value inserted successfully" << endl;
      return r;
    }

    if (new_node -> value < r -> value)
    {
      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value)
    {
      r -> right = insert(r -> right, new_node);
    }
    else
    {
      cout << "No duplicate values allowed!" << endl;
      return r;
    }
int bf = getBalanceFactor(r);
if (bf > 1 && new_node -> value < r -> left -> value)
      return rightRotate(r);
if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);
if (bf > 1 && new_node -> value > r -> left -> value)
    {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
if (bf < -1 && new_node -> value < r -> right -> value)
    {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }
    return r;
}
TreeNode * minValueNode(TreeNode * node)
{
    TreeNode * current = node;
    while (current -> left != NULL)
    {
      current = current -> left;
    }
    return current;
}
TreeNode * deleteNode(TreeNode * r, int v)
{
    if (r == NULL)
    {
      return NULL;
    }
    else if (v < r -> value)
    {
      r -> left = deleteNode(r -> left, v);
    }
    else if (v > r -> value)
    {
      r -> right = deleteNode(r -> right, v);
    }
    else
    {
      if (r -> left == NULL)
      {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      }
      else if (r -> right == NULL)
      {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      }
      else
        {
        TreeNode * temp = minValueNode(r -> right);
        r -> value = temp -> value;
        r -> right = deleteNode(r -> right, temp -> value);
      }
    }
    int bf = getBalanceFactor(r);
    if (bf == 2 && getBalanceFactor(r -> left) >= 0)
      return rightRotate(r);
    else if (bf == 2 && getBalanceFactor(r -> left) == -1)
    {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    else if (bf == -2 && getBalanceFactor(r -> right) <= -0)
      return leftRotate(r);
    else if (bf == -2 && getBalanceFactor(r -> right) == 1)
    {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    return r;
  }
void print2D(TreeNode * r, int space)
{
    if (r == NULL)
      return;
    space += SPACE;
    print2D(r -> right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
      cout << " "; // 5.1
    cout << r -> value << "\n";
    print2D(r -> left, space);
}
void printInorder(TreeNode * r)
  {
    if (r == NULL)
      return;
    printInorder(r -> left);
    cout << r -> value << " ";
    printInorder(r -> right);
  }


  TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }

};

int main() {
  AVLTree obj;
  int option, val;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal AVL Tree values" << endl;
    cout << "5. Exit Program" << endl;
    do{
    cout << "Enter an option(1 to 5):";
    cin >> option;
    TreeNode * new_node = new TreeNode();
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
      cin >> val;
      new_node -> value = val;
      obj.root = obj.insert(obj.root, new_node);
      break;
    case 2:
      cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
      cin >> val;
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL)
      {
        cout << "Value found" << endl;
      }
      else
      {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
      cin >> val;
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL)
      {
        obj.root = obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      }
      else
      {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout <<"IN-ORDER: ";
      obj.printInorder(obj.root);
      cout<<endl;
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 5);
  return 0;
}
