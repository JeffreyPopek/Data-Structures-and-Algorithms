/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned:
Due Date:

Description: Stub driver tests all functions required for PA6.
				- Adds elements to tree
				- Shows pre, in, and post order
				- Shows tree in hierarchical order
				- Shows Node count, leaf count, and tree height
				- Shows paths to elements that exists and don't in tree
				- Uses BFS and DFS to find elements that exists and don't in the tree

			 Stub Driver is mostly from the BST template 


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#include <iostream>
#include "BST.h"


int main()
{
	BST<int> tree;

	//Insert elements
	cout << "Inserting:  5\n";
	tree.insert(5);

	cout << "Inserting:  8\n";
	tree.insert(8);

	cout << "Inserting:  3\n";
	tree.insert(3);

	cout << "Inserting:  12\n";
	tree.insert(12);

	cout << "Inserting:  9\n";
	tree.insert(9);

	cout << "Inserting:  2\n";
	tree.insert(2);

	cout << "Inserting:  13\n";
	tree.insert(13);

	cout << "Inserting:  0\n";
	tree.insert(0);

	cout << "Inserting:  -1\n";
	tree.insert(-1);


	//Show orders
	cout << "Inorder:  ";
	tree.showInOrder();
	cout << endl;

	cout << "Preorder:  ";
	tree.showPreOrder();
	cout << endl;

	cout << "Postorder:  ";
	tree.showPostOrder();
	cout << endl;


	//Show Tree
	cout << "The tree looks like:\n";
	tree.showTree();


	//Show tree info
	cout << "Node Count = " << tree.nodesCount() << endl;
	cout << "Leaves Count = " << tree.leavesCount() << endl;
	cout << "Height = " << tree.getHeight() << endl;


	//Print tree paths
	cout << "Printing Path for 1:  ";
	tree.printPath(1);
	cout << endl;
	cout << "Printing Path for 9:  ";
	tree.printPath(9);
	cout << endl;


	//Tree searches
	cout << "\n\nDFS:  1\n";
	cout << (tree.dfs(1) ? "Found" : "Not Found") << endl;

	cout << "\n\nDFS:  9\n";
	cout << (tree.dfs(9) ? "Found" : "Not Found") << endl;

	cout << "\n\nBFS:  1\n";
	cout << (tree.bfs(1) ? "Found" : "Not Found") << endl;

	cout << "\n\nBFS:  9\n";
	cout << (tree.bfs(9) ? "Found" : "Not Found") << endl;


	system("pause");

	return 0;
}
