/*******************************************************************************
Title: tree.h
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Header file of tree for a program which outputs names 
of species based on their score. Purpose of this program is to demonstrate 
usage of tree.
Usage: ./a.out input_file
Build with: g++ -std=c++0x hwk4_frabbi.cpp
Dependencies: One input file that should be in the same directory. 
Modifications: Comments were added on 12/14/2014
*******************************************************************************/
#ifndef TREE_H
#define TREE_H
#include <string>
#include "singlenode.h"
using namespace std;

class tree{
	public:
		//default constructor for a binary tree which sets root equal to NULL
		tree();
		/*deletes all nodes of the tree, including the root by recursively 
		calling removeSubtree(single_node* ptr).
		pre-condition: allocated memory of type single_node exists for node
		post-condition: all nodes are deleted*/
		void deleteTree();
		/*adds leaves to the tree by calling 
		addLeafPrivate(double s, string n, single_node* ptr), 
		setting score=s and n= name.
		pre-condition: s is a valid value of type s and n is a valid value of type n
		post-condition: new leaf is added*/
		void addLeaf(double s, string n);
		/*prints names of leaves in inorder method by recursively calling
		printPrivate(ostream& out, single_node* ptr). 
		pre-condition: leaves of tree has proper name (either species or ,)
		post-condition: names are outputted with balanced parenthesis*/
		void print(ostream& out);
	private:
		// root of the tree 
		single_node* root;
		/*Allocates memory for type single_node for a new leaf
		pre-conditon: s is a valid value of type s and n is a valid value of type n
		post-condition: new single_node is allocated for which score=s and name= n. 
		Returns pointer to that single_node */
		single_node* createLeaf(double s, string n);
		/*adds leaves to the tree by calling createLeaf(double s, string n), 
		setting score=s and n= name. If the root is empty, then the root gets these values. 
		pre-condition: s is a valid value of type s and n is a valid value of type n
		post-condition: new leaf is added*/
		void addLeafPrivate(double s, string n, single_node* ptr);
		/*Outputs name with balanced paranthesis and comma in between.
		pre-condition: name of ptr is not NULL.
		post-condition: name is outputted with balanced paranthesis*/
		void printPrivate(ostream& out, single_node* ptr);
		/*if ptr is not null, reursively deletes left, right and root of the node.
		pre-condition: ptr belongs to the tree
		post-condition: all nodes are deleted*/
		void removeSubtree(single_node* ptr);
};
#endif