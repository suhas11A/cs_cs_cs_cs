#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree(){}

const ptr RedBlackTree::getRoot() const { 
	return root; 
}

ptr RedBlackTree::insert(int data) {
	ptr newnodePtr = new node(data);
	if (!root) {
		root = newnodePtr;
		root->is_red = 0; // set root color as black
		return newnodePtr;
	}
	insert(root, newnodePtr);
	fixup(newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr) {
	int n = newnodePtr->data;
	auto temp = start; node* x = nullptr;
	while(temp) {
		x = temp;
		temp = (n>= temp->data)? temp->right : temp->left;
	}
	((n>= x->data)? x->right : x->left) = newnodePtr;
	newnodePtr->parent = x;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const {
	if (!start) return;

	std::cout << prefix;
	std::cout << (isLeftChild ? "|--" : "|__" );
	// print the value of the node
	std::cout << start->data << "(" << start->is_red << ")" << std::endl;
	// enter the next tree level - left and right branch
	printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
	printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr a) {
	if (!a) return;
	auto my_parent = a->parent;
	auto b = a->right;
	if (!b) return;
	a->right = b->left;
	if (a->right) a->right->parent = a;
	a->parent = b;
	b->left = a;
	b->parent = my_parent;
	if (!my_parent) {
		root = b; return;
	}
	(my_parent->right==a ? my_parent->right : my_parent->left) = b;
	return;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr b)  {
	if (!b) return;
	auto my_parent = b->parent;
	auto a = b->left;
	if (!a) return;
	b->left = a->right;
	if (b->left) b->left->parent=b;
	b->parent = a;
	a->right = b;
	a->parent = my_parent;
	if (!my_parent) {
		root = a; return;
	}
	(my_parent->right==b ? my_parent->right : my_parent->left) = a;
	return;
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc) {
	if (!loc) return;
	if (!loc->parent) {loc->is_red=0; return;}
	if (!loc->parent->parent) {loc->parent->is_red=0; return;}
	auto my_parent = loc->parent;
	if (!my_parent->is_red) return;
	auto my_gp = loc->parent->parent;
	auto my_unc = (my_gp->left==my_parent)? my_gp->right : my_gp->left;
	if (my_unc && my_unc->is_red) {
		my_parent->is_red = 0;
		my_unc->is_red = 0;
		my_gp->is_red = 1;
		fixup(my_gp);
		return;
	}
	bool me_is_left_child = (my_parent->left==loc);
	bool parent_is_left_child = (my_gp->left==my_parent);
	if (me_is_left_child!=parent_is_left_child) {
		if (me_is_left_child) leftrotate(my_parent);
		else rightrotate(my_parent);
		std::swap(loc, my_parent);
	}
	if (parent_is_left_child) leftrotate(my_gp);
	else rightrotate(my_gp);
	my_parent->is_red = 0;
	my_gp->is_red = 1;
	return;
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const {
	if (!start)
		return;
	
	inorder(start->left);
	std::cout << start->data << " ";
	inorder(start->right);
}


