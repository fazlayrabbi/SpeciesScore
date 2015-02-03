/*******************************************************************************
Title: tree.cpp
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Implementation file of tree.h for a program which outputs names 
of species based on their score. Purpose of this program is to demonstrate 
usage of tree.
Usage: ./a.out input_file
Build with: g++ -std=c++0x hwk4_frabbi.cpp
Dependencies: One input file that should be in the same directory. 
Modifications: Comments were added on 12/14/2014
*******************************************************************************/
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include "tree.h"
#include "singlenode.h"
using namespace std;

tree::tree(){ 
	root=NULL;
}


void tree::print(ostream& out){
	printPrivate( out, root);//prints leaves of the tree
	out<<endl;
}

void tree::printPrivate(ostream& out, single_node* ptr){
	if(root!= NULL){//if root is NULL, there is no name
		
		if(ptr->getLeft() != NULL){ //prints left first (inorder)
			out<<"(";
			printPrivate(out, ptr->getLeft());			
		}

		out<<ptr->getName();
		
		if(ptr->getRight() != NULL){		
			printPrivate(out, ptr->getRight());
			out<<")";
		}	
	}
	
}

single_node* tree::createLeaf(double s, string n){
	single_node* node= new single_node(s);
	node->setName(n);
	return node;
}

void tree::addLeaf(double s, string n){
	addLeafPrivate(s, n, root);
}

void tree::addLeafPrivate(double s, string n, single_node* ptr){
	if(root==NULL)//  tree is emplty
		root= createLeaf(s, n);
	else if(s< ptr->getScore()){// since it is a binary tree, left gets assigned
		if(ptr->getLeft() != NULL)/* recursively calls itself unless it finds 
								a single_node which is NULL*/
			addLeafPrivate(s, n, ptr->getLeft());
		else// left is NULL
			ptr->setLeft(createLeaf(s, n));
	}
	else if(s> ptr->getScore()){// since it is a binary tree, right gets assigned
		if(ptr->getRight() != NULL)/* recursively calls itself unless it finds 
								a single_node which is NULL*/
			addLeafPrivate(s, n, ptr->getRight());
		else// right is NULL
			ptr->setRight(createLeaf(s, n));
	}
}

void tree::deleteTree(){
	removeSubtree(root);// removes all nodes, including root
}

void tree::removeSubtree(single_node* ptr){
	if(ptr != NULL){
		if(ptr-> getLeft() != NULL)// deletes all left nodes first
			removeSubtree(ptr->getLeft());
		if(ptr->getRight() != NULL)
			removeSubtree(ptr->getRight());

		delete ptr;
	}
}

