/* ***       Author:  Wei Kian Chen
     *  Last Update:  November 11, 2022
     *        Class:  CSI-281
     *     Filename:  bst.h
     *
     *  Description:
     *      This is the template binary search tree definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/


#ifndef _BST_H
#define _BST_H
#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;
template <typename T>
class BST
{
private:
    template <typename R>
    struct Node
    {
        R       mData;
        Node<R>* mLeft, * mRight;
        /*      Pre:  None
         *     Post:  This object is initialized using default
         *            values
         *  Purpose:  To initialize date object
         *****************************************************/
        Node()
        {
            mData = R();
            mLeft = NULL;
            mRight = NULL;
        }
        /*      Pre:  None
         *     Post:  This object is initialized using specified
         *            data
         *  Purpose:  To initialize date object
         *****************************************************/
        Node(R data)
        {
            mData = data;
            mLeft = NULL;
            mRight = NULL;
        }
        /*      Pre:  None
         *     Post:  This object is initialized using specified
         *            data with the specified children attached
         *  Purpose:  To initialize date object
         *****************************************************/
        Node(R data, Node<R>* left, Node<R>* right)
        {
            mData = data;
            mLeft = left;
            mRight = right;
        }
    };
    Node<T>* mRootNode;
    BST(T data, Node<T>* left, Node<T>* right);
    void destroySubtree(Node<T>*& node);
    void displayInOrder(Node<T>* node);
    void displayPreOrder(Node<T>* node);
    void displayPostOrder(Node<T>* node);
    void displayTree(Node<T>* node, int tab);
    void insert(Node<T>*& node, const T& data);
    void makeDeletion(Node<T>*& node);
    void remove(Node<T>*& node, const T& searchKey);

    //Extra Functions
    bool hasPath(vector<T>& list, Node<T>* node, T searchKey);
public:
    BST();
    ~BST();
    bool bfs(T searchKey);
    void clear();
    bool dfs(T searchKey);
    int  getHeight();
    void insert(T data);
    bool isEmpty();
    bool isExists(T searchKey);
    int  leavesCount();
    int  nodesCount();
    void remove(T searchKey);
    void printPath(T searchKey);
    void showInOrder();
    void showPreOrder();
    void showPostOrder();
    void showTree();
};


/*      Pre:  None
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::BST()
{
    mRootNode = NULL;
}


/*      Pre:  data, left pointer and right pointer
 *     Post:  The root node of the BST is initialized to the
 *            new root node with both left and right child
 *  Purpose:  Constructor
 **************************************************************/
template <typename T>
BST<T>::BST(T data, Node<T>* left, Node<T>* right)
{
    Node<T>* newNode;
    newNode = new Node<T>(data, left, right);
    if (newNode != NULL)
        mRootNode = newNode;
}


/*      Pre:  The BST is instantiated
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::~BST()
{
}


/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using breadth-first search
 **************************************************************/
template <typename T>
bool BST<T>::bfs(T searchKey)
{
    Queue<Node<T>*> queue;
    if (mRootNode == NULL) 
    {
        return false;
    }

    //print root
    queue.enqueue(mRootNode);
    cout << mRootNode->mData << "  ";
    

    while (!queue.isEmpty()) {
        Node<T>* temp = queue.dequeue();


        if (temp->mLeft) 
        {
            queue.enqueue(temp->mLeft);
            cout << temp->mLeft->mData << "  ";

            if (temp->mLeft->mData == searchKey)
            {
                return true;
            }
        }

        if (temp->mRight) 
        {
            queue.enqueue(temp->mRight);
            cout << temp->mRight->mData << "  ";

            if (temp->mRight->mData == searchKey)
            {
                return true;
            }
        }
    }

    return false;
}



/*      Pre:  The BST is instantiated
 *     Post:  The entire BST is deleted
 *  Purpose:  To clear the entire BST
 **************************************************************/
template <typename T>
void BST<T>::clear()
{
    destroySubtree(mRootNode);
}




/*      Pre:  A node within the BST
 *     Post:  All the subtree branching from the node (including
 *            the node) is deleted
 *  Purpose:  To delete a subtree
 **************************************************************/
template <typename T>
void BST<T>::destroySubtree(Node<T>*& node)
{
    if (node == NULL)
        return;
    // explore left
    destroySubtree(node->mLeft);
    // explore right   
    destroySubtree(node->mRight);
    // deleting the node
    delete node;
    node = NULL;
}



/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using depth-first search
 **************************************************************/
template <typename T>
bool BST<T>::dfs(T searchKey)
{
    Stack<Node<T>*> stack;

    if (mRootNode == NULL)
    {
        return false;
    }

    stack.push(mRootNode);

    while (!stack.isEmpty()) 
    {
        Node<T>* temp = stack.pop();
        if (temp->mRight)
        {
            stack.push(temp->mRight);
        }

        if (temp->mLeft)
        {
            stack.push(temp->mLeft);

        }

        cout << temp->mData << "  ";

        if (temp->mData == searchKey)
        {
            return true;
        }
    }

    return false;
}



/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A private function that display the entire BST
 *            using in-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayInOrder(Node<T>* node)
{
    //Check if node is valid
    if (node == NULL)
    {
        return;
    }

    displayInOrder(node->mLeft);

    cout << node->mData << "  ";

    displayInOrder(node->mRight);
}




/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A private function that display the entire BST
 *            using pre-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPreOrder(Node<T>* node)
{
    //Check if node is valid
    if (node == NULL)
    {
        return;
    }

    cout << node->mData << "  ";

    displayPreOrder(node->mLeft);

    displayPreOrder(node->mRight);
}




/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A private function that display the entire BST
 *            using post-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPostOrder(Node<T>* node)
{   
    //Check if node is valid
    if (node == NULL)
    {
        return;
    }

    displayPostOrder(node->mLeft);

    displayPostOrder(node->mRight);

    cout << node->mData << "  ";
}




/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed
 *  Purpose:  A private function that display the entire BST
 **************************************************************/
template <typename T>
void BST<T>::displayTree(Node<T>* node, int tab)
{
    int space = 5;

    if (node == NULL)
    {
        return;
    }

    tab += space;

    displayTree(node->mRight, tab);

    cout << endl;
    for (int i = space; i < tab; i++)
    {
        cout << " ";
    }
    cout << node->mData << endl;


    displayTree(node->mLeft, tab);
}




/*      Pre:  None
 *     Post:  The height of a tree is returned
 *  Purpose:  To compute the longest branch within the BST
 **************************************************************/
template <typename T>
int BST<T>::getHeight()
{
    if (mRootNode == NULL)
    {
        return 0;
    }

    Queue <Node<T>*> queue;
    int height = 0;
    int nodeCount = 0;
    Node<T>* temp; 

    queue.enqueue(mRootNode);

    while (!queue.isEmpty()) 
    {
        height++;
        nodeCount = queue.getCount();

        while (nodeCount--) 
        {
            temp = queue.dequeue();

            if (temp->mLeft != NULL) {
                queue.enqueue(temp->mLeft);
            }

            if (temp->mRight != NULL)
            {
                queue.enqueue(temp->mRight);
            }
        }
    }

    return (height - 1);
}





/*      Pre:  None
 *     Post:  returns bool based on if the node has path to searchkey 
 *  Purpose:  to check if searchkey is valid
 **************************************************************/
template <typename T>
bool BST<T>::hasPath(vector<T>& list, Node<T>* node, T searchKey)
{
    if (node == NULL)
    {
        return false;
    }

    list.push_back(node->mData);

    if (node->mData == searchKey)
    {
        return true;
    }

    if (hasPath(list, node->mLeft, searchKey) || hasPath(list, node->mRight, searchKey))
    {
        return true;
    }

    list.pop_back();
    return false;
}





/*      Pre:  A data to insert into a BST
 *     Post:  A new data is inserted into a BST
 *  Purpose:  To insert a new value into a BST
 **************************************************************/
template <typename T>
void BST<T>::insert(T data)
{
    insert(mRootNode, data);
}




/*      Pre:  A node within a tree and the value to insert
 *     Post:  The new value is inserted into the BST
 *  Purpose:  A private function that insert a new data into a
 *            BST.  BST does not allow duplication of value.
 *            Hence, a duplicated value will not be inserted
 **************************************************************/
template <typename T>
void BST<T>::insert(Node<T>*& node, const T& data)
{
    if (node == NULL)
    {
        node = new Node<T>(data);
        return;
    }
    if (node->mData == data);
    else if (node->mData > data)
        insert(node->mLeft, data);
    else
        insert(node->mRight, data);
}




/*      Pre:  None
 *     Post:  True if the BST is empty, otherwise false
 *  Purpose:  To determine if the BST is empty
 **************************************************************/
template <typename T>
bool BST<T>::isEmpty()
{
    return (mRootNode == NULL);
}




/*      Pre:  A search key
 *     Post:  True is return if the search key existed in the
 *            BST, otherwise false
 *  Purpose:  To search if a search key exists in the BST using
 *            the typical binary tree search
 **************************************************************/
template <typename T>
bool BST<T>::isExists(T searchKey)
{
    Node<T>* tmp;
    bool    found = false;
    tmp = mRootNode;
    while (tmp != NULL && !found)
    {
        if (tmp->mData == searchKey)
            found = true;
        else if (tmp->mData > searchKey)
            tmp = tmp->mLeft;
        else
            tmp = tmp->mRight;
    }
    return found;
}




/*      Pre:  None
 *     Post:  The number of leave nodes is returned
 *  Purpose:  To determine the number of leave nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::leavesCount()
{
    if (mRootNode == NULL)
    {
        return 0;
    }

    Queue <Node<T>*> queue;
    int leaves = 0;

    queue.enqueue(mRootNode);

    while (!queue.isEmpty())
    {
        Node<T>* temp = queue.dequeue();

        if (temp->mLeft != NULL)
        {
            queue.enqueue(temp->mLeft);
        }

        if (temp->mRight != NULL)
        {
            queue.enqueue(temp->mRight);
        }

        if (temp->mLeft == NULL && temp->mRight == NULL)
        {
            leaves++;
        }
    }

    return leaves;
}




/*      Pre:  A node within the BST
 *     Post:  The node is deleted from the BST
 *  Purpose:  A private function that delete the node from the
 *            BST.  If the node has only one child, then the
 *            child will serve as the new root node for that
 *            branch.  However, if the node has two children,
 *            then the right child will serve as the new root
 *            node for the branch.
 **************************************************************/
template <typename T>
void BST<T>::makeDeletion(Node<T>*& node)
{
    Node<T>* nodeToDelete, * attachPoint;
    nodeToDelete = node;
    // case 1: only 1 child, left
    if (node->mRight == NULL)
        node = node->mLeft;
    // case 2: only 1 child, right
    else if (node->mLeft == NULL)
        node = node->mRight;
    // case 3: 2 children
    else
    {
        // find the left most node from the right child
        attachPoint = node->mRight;
        while (attachPoint->mLeft != NULL)
            attachPoint = attachPoint->mLeft;
        // making the attchment
        attachPoint->mLeft = node->mLeft;
        node = node->mRight;
    }
    delete nodeToDelete;
}




/*      Pre:  None
 *     Post:  The number of nodes is returned
 *  Purpose:  To determine the number of nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::nodesCount()
{
    if (mRootNode == NULL)
    {
        return 0;
    }

    Queue <Node<T>*> queue;
    int count = 0; 

    queue.enqueue(mRootNode);

    while (!queue.isEmpty())
    {
        Node<T>* temp = queue.dequeue(); 
        count++;

        if (temp->mLeft != NULL)
        {
            queue.enqueue(temp->mLeft);
        }

        if (temp->mRight != NULL)
        {
            queue.enqueue(temp->mRight);
        }
    }

    return count;
}







/*      Pre:  None
 *     Post:  The path from the root node to the search key is
 *            displayed on the screen or an error message
 *            indicating the search key does not exist
 *  Purpose:  To display the path from the root node to the
 *            search key is displayed on the screen.  If the
 *            search key does not exist in the BST, a message
 *            indicating the search key does not exist in the
 *            BST
 **************************************************************/
template <typename T>
void BST<T>::printPath(T searchKey)
{
    vector<T> list;

    if (hasPath(list, mRootNode, searchKey))
    {
        for (int i = 0; i < list.size() - 1; i++)
        {
            cout << list[i] << "  ";
        }
        cout << list[list.size() - 1];
    }
    else
    {
        cout << "No path, doesn't exist in tree";
    }
}





/*      Pre:  A search key
 *     Post:  The search key is removed from the BST
 *  Purpose:  To remove a value from a BST
 **************************************************************/
template <typename T>
void BST<T>::remove(T searchKey)
{
    remove(mRootNode, searchKey);
}




/*      Pre:  A node within the BST and a search key
 *     Post:  The search key is removed from the BST if the
 *            value exists
 *  Purpose:  A private function that to remove a value from a
 *            BST recursively.  This function will find the node
 *            where the value occur.  Once the node is found,
 *            call makeDeletion to complete the process.
 **************************************************************/
template <typename T>
void BST<T>::remove(Node<T>*& node, const T& searchKey)
{
    //Node<T>* tmp;
    //bool    found = false;
    //tmp = mRootNode;
    //while (tmp != NULL && !found)
    //{
    //   if (tmp->mData == searchKey)
    //      found = true;
    //   else if (tmp->mData > searchKey)
    //      tmp = tmp->mLeft;
    //   else
    //      tmp = tmp->mRight;
    //}
    //if (found)
    //   makeDeletion(tmp);
    if (node == NULL)
        return;
    if (node->mData == searchKey)
        makeDeletion(node);
    else if (node->mData > searchKey)
        remove(node->mLeft, searchKey);
    else
        remove(node->mRight, searchKey);
}





/*      Pre:  None
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A function that display the entire BST using
 *            in-order format.  This function will call
 *            displayInOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showInOrder()
{
    displayInOrder(mRootNode);
}





/*      Pre:  None
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A function that display the entire BST using
 *            pre-order format.  This function will call
 *            displayPreOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPreOrder()
{
    displayPreOrder(mRootNode);
}





/*      Pre:  None
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A function that display the entire BST using
 *            post-order format.  This function will call
 *            displayPostOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPostOrder()
{
    displayPostOrder(mRootNode);
}





/*      Pre:  None
 *     Post:  The entire BST is displayed
 *  Purpose:  A function that display the entire BST.  This
 *            function will call displayTree to complete the
 *            process
 **************************************************************/
template <typename T>
void BST<T>::showTree()
{
    displayTree(mRootNode, 0);
    cout << "\n\n";
}




#endif