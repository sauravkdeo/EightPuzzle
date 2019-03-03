/**
 * @file      include/Node.h
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
#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Node {
 private:
  Node* parent;
  Node* childup;
  Node* childdown;
  Node* childright;
  Node* childleft;
  Node* nextnode;
  int mat[3][3];

  // stores blank tile coordinates
  int x, y;

  // stores the number of moves so far
  int level;
  int nodenumber;



 public:
  ~Node();

  bool moveleft(Node*);
  bool moveright(Node*);
  bool moveup(Node*);
  bool movedown(Node*);

  void swapposition(int[3][3],int,int,int,int);
  void matrixcopy(int[3][3],int[3][3]);


  void printMatrix(int [3][3]);

  void solve(int[3][3], int, int,int[3][3]);

  void printpath(Node*);


  Node* newnode(int[3][3], int, int , int ,int, int,Node*);

  bool norepetition(Node*, int , int , int ,int );

  void explorechild(Node*);
  bool ismatrixequal(int[3][3],int[3][3]);
  void explorebreadth(Node* ,int[3][3]);
  void setnextnode(Node* ,int[3][3]);
  void shift_to_uncle_childnode(Node *);
};
#endif  // INCLUDE_NODE_H_



















