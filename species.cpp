/*******************************************************************************
Title: species.cpp
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Implementation file of main program which outputs names 
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
#include <cmath>
#include <cstdlib>
#include "tree.h"
#include "singlenode.h"
using namespace std;

bool sortDescending(single_node& lhs, single_node& rhs){
	return lhs.getScore() > rhs.getScore();
}

void generateNodes(list<single_node>& database, tree& mytree){
	list<single_node> nodes;// nodes of mytree
	list<single_node> temp;// used to create nodes of mytree
	temp= database;

	/*this while loop generates the nodes of mytree by comparing two 
	single_node which has the lowest difference*/

	while(temp.size()>2){/* if it is equal to 2, those two single_node are left 
								and right of the root of mytree*/

		list<single_node>::iterator it1,it2;
		it1=it2=temp.begin();

		int minIndex1;/* index # of single_node within temp whose 
					difference is the lowest*/ 
		int minIndex2;/* index # of single_node within temp whose 
					difference is the lowest*/

		int index1= 0;// index# to parse through temp
		int index2=0;// index# to parse through temp

		double min;// minimum difference between two indexes

		for(it1; it1!= temp.end(); it1++){
			it2= it1;
			it2++;
			index2= index1 +1;
			for(it2; it2!= temp.end(); it2++){
				double difference= fabs(it1->getScore()- it2->getScore());
				if (index1==0 &&index2==1){/* at the start, first two 
							indexes have the minimum difference*/
					minIndex1= 0;	
					minIndex2= 1;			
					min= difference;
				}
				else{
					if(difference< min){
						minIndex1= index1;
						minIndex2= index2;
						min= difference;
					}
				}
				index2++;
			}
			index1++;
		}
		it2= temp.begin();
		advance (it2, minIndex2);// iterator advances to the minindex
		it1= temp.begin();
		advance (it1, minIndex1);// iterator advances to the minindex
		nodes.push_back((it1->getScore()+it2->getScore())/2);/*average 
								between two gets pushed_back*/
		temp.push_back((it1->getScore()+it2->getScore())/2);/*average 
								between two gets pushed_back*/
		/*minIndex1 and 2 gets erased from temp*/
		temp.erase(it2);
		temp.erase(it1);
	}
	if( temp.size()==2){
		list<single_node>::iterator it1,it2;
		it1=it2=temp.begin();
		it2++;
		mytree.addLeaf((it1->getScore()+it2->getScore())/2, ","); /*the 
		   root gets set. For printing purpose, we added ',' for the name*/

		/* found1 and found2 determines whether left and right of the 
		root is included in the database. If any od them is included it 
		deletes them from database*/
		int found1=0;
		int found2= 0;
		for (list<single_node>::iterator it_i = database.begin(); 
								it_i != database.end(); ++it_i){
			if (it_i->getScore()== it1->getScore()){// found in database
				database.erase(it_i);
				found1= 1;
				break;
			}
		}
		for (list<single_node>::iterator it_i = database.begin(); 
								it_i != database.end(); ++it_i){
			if (it_i->getScore()== it2->getScore()){// found in database
				database.erase(it_i);
				found2= 1;
				break;
			}
		}
		if (found1==0)
			mytree.addLeaf( it1->getScore(), ",");
		else if (found1==1)// found in database, has a species name
			mytree.addLeaf( it1->getScore(), it1->getName());
		if (found2==0)
			mytree.addLeaf( it2->getScore(), ",");
		else if (found2==1)// found in database, has a species name
			mytree.addLeaf( it2->getScore(), it2->getName());
	}
	if( nodes.size()>0){// all nodes of trees gets added
		for (list<single_node>::reverse_iterator it1 = nodes.rbegin(); 
									it1 != nodes.rend(); ++it1)
			mytree.addLeaf( it1->getScore(), ",");		
	}
	database.sort(sortDescending);/* leaves of mytree are sorted for 
										accuracy purpose*/
	for (list<single_node>::iterator it_i = database.begin(); 
								it_i != database.end(); ++it_i)
	/*all leaves are added*/
			mytree.addLeaf( it_i->getScore(), it_i->getName());
}