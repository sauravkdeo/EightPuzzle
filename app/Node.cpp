/**
 * @file      include/Node.cpp
 * @brief     Header file for declaring the class SteeringControl,its attributes and its methods
 *            along with class SteeringControlOutput, class Point and their data members
 * @author    Saurav Kumar
 * @copyright 2019
 *
 **BSD 3-Clause License
 *
 *Copyright (c) 2018, Saurav Kumar
 *All rights reserved.
 *
 *Redistribution and use in source and binary forms, with or without
 *modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holder nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *  this software without specific prior written permission.
 *
 *THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include<../include/Node.h>
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::swap;
using std::ofstream;
using std::priority_queue;

Node::~Node() {
}
bool Node::moveup(Node* current) {
  if (current->x > 0) {
    return true;
  }
  else{
    return false;
  }
}

bool Node::movedown(Node* current) {
  if (current->x < 2){
    return true;
  }
  else {
    return false;
  }
}
bool Node::moveleft(Node* current) {
  if (current->y > 0) {
    return true;
  }
  else {
    return false;
  }
}
bool Node::moveright(Node* current) {
  if (current->y < 2) {
    return true;
  }
  else {
    return false;
  }
}
void Node::printMatrix(int mat[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++){
      cout << mat[i][j] << "\t";
    }
    cout << "\n";
  }
  cout << "\n";

}



void Node::solve(int initial[3][3], int x, int y,
                 int final[3][3]) {

  Node* root = newnode(initial, x, y, x, y, 0, NULL);
  root->nodenumber = 1;
  explorechild(root,final);
  setnextnode(root,final);


}

void Node::printpath(Node* solution) {
  if (solution == NULL)
    return;
  printpath(solution->parent);
  printMatrix(solution->mat);
}


bool Node::norepetition(Node* node, int x, int y, int newX,int newY){
  int checkmatrix[3][3];

  /*  checkmatrix = node.mat;*/
  matrixcopy(checkmatrix,node->mat);
  swapposition(checkmatrix,x,y,newX,newY);
  if (node->parent == NULL){
    return true;
  }
  else if (ismatrixequal(checkmatrix, node->parent->mat)){
    return false;
  }
  else {
    return true;
  }
}

Node* Node::newnode(int mat[3][3], int x, int y, int newX,int newY, int level, Node* parent) {
  Node* node = new Node;

  // set pointer for path to root
  node->parent = parent;

  // copy data from parent node to current node
  matrixcopy(node->mat, mat);

  // move tile by 1 postion
  swapposition(node->mat,x,y,newX,newY);

  // set number of moves so far
  node->level = level;

  // update new blank tile cordinates
  node->x = newX;
  node->y = newY;

  return node;
}


void Node::explorechild(Node* root,int final[3][3]) {

  cout << root->level<< "\n";
  if (moveleft(root) && norepetition(root, root->x,root->y, root->x, root->y-1 )){
    root->childleft = newnode(root->mat, root->x,
                              root->y, root->x,
                              root->y-1 ,
                              root->level + 1, root);

  }
  if (!moveleft(root) || !norepetition(root, root->x,root->y, root->x, root->y-1 )){

    root->childleft = NULL;
  }
  if (moveup(root) && norepetition(root, root->x,root->y, root->x-1, root->y )){
    root->childup = newnode(root->mat, root->x,
                            root->y, root->x-1,
                            root->y,
                            root->level + 1, root);


  }
  if (!moveup(root) || !norepetition(root, root->x,root->y, root->x-1, root->y )){
    root->childup =NULL;
  }
  if (moveright(root)&& norepetition(root, root->x,root->y, root->x, root->y+1 )){
    root->childright = newnode(root->mat, root->x,
                               root->y, root->x,
                               root->y+1 ,
                               root->level + 1, root);
  }
  if (!moveright(root) || !norepetition(root, root->x,root->y, root->x, root->y+1 )){
    root->childright = NULL;
  }
  if (movedown(root) && norepetition(root, root->x,root->y, root->x+1, root->y)){
    root->childdown = newnode(root->mat, root->x,
                              root->y, root->x+1,
                              root->y,
                              root->level + 1, root);
  }
  if (!movedown(root) || !norepetition(root, root->x,root->y, root->x+1, root->y)){
    if(root->childdown != NULL){
      root->childdown = NULL;
    }
  }

}


void Node::setnextnode(Node * root,int final[3][3]) {
  if (ismatrixequal(root->mat,final)){
      std::cout << "Solved: \n";
      printpath(root);
      return;
    }
  else {

  if (root->parent == NULL) {

    if (root->childleft != NULL) {
      root->nextnode = root->childleft;
    }
    else if (root->childup != NULL) {
      root->nextnode = root->childup;
    }
    else if (root->childright != NULL) {
      root->nextnode = root->childright;
    }
    else if (root->childdown != NULL) {
      root->nextnode = root->childdown;
    }
  }


  else if (root != NULL) {
    if(root == root->parent->childleft) {

      if (root->parent->childup != NULL) {
        root->nextnode = root->parent->childup;

      }
      else if (root->parent->childright != NULL) {
        root->nextnode = root->parent->childright;
      }
      else if (root->parent->childdown != NULL) {
        root->nextnode = root->parent->childdown;
      }

      else shift_to_uncle_childnode(root);
    }

    else if(root == root->parent->childup) {
      if (root->parent->childright != NULL) {
        root->nextnode = root->parent->childright;

      }
      else if (root->parent->childdown != NULL) {
        root->nextnode = root->parent->childdown;
      }
      else shift_to_uncle_childnode(root);

    }

    else if(root == root->parent->childright) {
      if (root->parent->childdown != NULL) {
        root->nextnode = root->parent->childdown;

      }
      else shift_to_uncle_childnode(root);
    }
    else if (root == root->parent->childdown) {
      shift_to_uncle_childnode(root);
    }
  }
  root->nextnode->nodenumber = root->nodenumber+1;
  explorechild(root->nextnode,final);
  setnextnode(root->nextnode,final);
}
}

void Node::shift_to_uncle_childnode(Node* root) {
  {
    if (root->parent->nextnode->childleft !=NULL){
      root->nextnode =root->parent->nextnode->childleft;
    }
    else if (root->parent->nextnode->childup !=NULL){
      root->nextnode =root->parent->nextnode->childup;
    }
    else if (root->parent->nextnode->childright !=NULL){
      root->nextnode =root->parent->nextnode->childright;
    }
    else if (root->parent->nextnode->childdown !=NULL){
      root->nextnode =root->parent->nextnode->childdown;
    }
  }
}


void Node::swapposition(int matrix[3][3],int x,int y,int newx,int newy) {

  matrix[x][y]=matrix[newx][newy];
  matrix[newx][newy] = 0;

}
void Node::matrixcopy(int into[3][3],int from[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++){
      into[i][j] = from[i][j];
    }
  }
}

bool Node::ismatrixequal(int matrix[3][3],int expected[3][3]){
  if (matrix[0][0] == expected[0][0] && matrix[0][1] == expected[0][1] && matrix[0][2] == expected[0][2] &&
      matrix[1][0] == expected[1][0] && matrix[1][1] == expected[1][1] && matrix[1][2] == expected[1][2] &&
      matrix[2][0] == expected[2][0] && matrix[2][1] == expected[2][1] && matrix[2][2] == expected[2][2]){
    return true;
  }
  else {
    return false;
  }
}
