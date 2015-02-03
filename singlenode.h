/*******************************************************************************
Title: singlenode.h
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Header file of a single node for a program which outputs names 
of species based on their score. Purpose of this program is to demonstrate 
usage of tree.
Usage: ./a.out input_file
Build with: g++ -std=c++0x hwk4_frabbi.cpp
Dependencies: One input file that should be in the same directory. 
Modifications: Comments were added on 12/14/2014
*******************************************************************************/
#ifndef SINGLENODE_H
#define SINGLENODE_H
#include <string>
using namespace std;

class single_node{
	public:
		// default constructor
		single_node();
		/* default constructor which also sets score= g
		pre-condition: g has valid value of type double
		post-condition: score is set equal to g*/
		single_node(double g);
		/* returns score
		pre-condition: score has valid value of type double
		post-condition: score is returned*/
		double getScore();
		/* returns name
		pre-condition: name has valid value of type string
		post-condition: name is returned*/
		string getName();
		/*sets score equal to s
		pre-condition: s has valid value of type double
		post-condition: score is set equal to s*/
		void setScore(double s);
		/*sets name equal to n
		pre-condition: n has valid value of type name
		post-condition: name is set equal to n*/
		void setName(string n);
		/*returns pointer to single_node of left
		pre-condition: left has allocted memory of type single_node
		post-condition:  pointer to single_node of left is returned*/
		single_node* getLeft();
		/*returns pointer to single_node of right
		pre-condition: right has allocted memory of type single_node
		post-condition:  pointer to single_node of right is returned*/
		single_node* getRight();
		/*sets left equal to node
		pre-condition: node is pointing to a single_node in allocated 
		memeory
		post-condition:  left is set to node*/
		void setLeft(single_node* node);
		/*sets right equal to node
		pre-condition: node is pointing to a single_node in allocated 
		memeory
		post-condition:  right is set to node*/
		void setRight(single_node* node);
	private:
		double score;// score of the species
		string name;// name of the species
		single_node* left;// left node of the tree
		single_node* right;// right node of the tree
};
#endif