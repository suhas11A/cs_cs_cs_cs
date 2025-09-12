#include "tree.h"

/**
 * @brief Check if a binary tree is a valid binary search tree
 *
 * @param root The root of the binary tree
 * @return true If the binary tree is a valid binary search tree
 * @return false If the binary tree is not a valid binary search tree
 *
 * Your task is to check if the tree indexing all the values of type T is a
 * valid binary search tree, which implies that for each node in the tree,
 * all the values in its left_child subtree are less than the value of that node, and
 * all the values in its right_child subtree are greater than the value of that node.
 *
 * You can add helper functions or data structures, but you should not modify
 * the existing function signature. Note that this requiress knowledge about
 * the concpet of smart pointers in C++.
 *
 * Lastly, do not add `using namespace std;` as it is a bad practice.
 * The full problem involves the above task AND the task in the file
 * "employee.h". You should complete both tasks.
 */



// TODO: Write any helper functions you want here

template <std::totally_ordered T>
T my_min(std::shared_ptr<struct node_t<T>> root) {
    if (!root->left_child && !root->right_child) return root->value;
    if (!root->left_child) return std::min(root->value, my_min(root->right_child));
    if (!root->right_child) return std::min(root->value, my_min(root->left_child));
    return std::min(std::min(root->value, my_min(root->left_child)), my_min(root->right_child));
}

template <std::totally_ordered T>
T my_max(std::shared_ptr<struct node_t<T>> root) {
    if (!root->left_child && !root->right_child) return root->value;
    if (!root->left_child) return std::max(root->value, my_max(root->right_child));
    if (!root->right_child) return std::max(root->value, my_max(root->left_child));
    return std::max(std::max(root->value, my_max(root->left_child)), my_max(root->right_child));
}


// End TODO



template <std::totally_ordered T>
bool is_valid_bst(std::shared_ptr<struct node_t<T>> root) {
    if (!root) return true;
    if (!root->left_child && !root->right_child) return true;
    if (!root->left_child && root->right_child) return (root->value <= my_min(root->right_child) && is_valid_bst(root->right_child));
    if (root->left_child && !root->right_child) return (root->value >= my_max(root->left_child) && is_valid_bst(root->left_child));
    if (root->left_child && root->right_child) return (root->value <= my_min(root->right_child) && is_valid_bst(root->right_child) && root->value >= my_max(root->left_child) && is_valid_bst(root->left_child));
    return false;
}