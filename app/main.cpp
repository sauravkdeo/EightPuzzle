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
#include <../include/Node.h>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ofstream;

// Driver code
int main() {
  ofstream nodePath;
  nodePath.open("nodePath.txt", std::ofstream::out | std::ofstream::trunc);
  ofstream Nodes;
  Nodes.open("Nodes.txt", std::ofstream::out | std::ofstream::trunc);
  ofstream NodeInfo;
  NodeInfo.open("NodeInfo.txt", std::ofstream::out | std::ofstream::trunc);

  int final[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
  int x, y;
  // Initial configuration
  // Value 0 is used for empty space
  int initial[3][3];
  int value;
  cout << "please feed the initial configutaion of the puzzles : \n \n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[" << i+1 << "] " << "[" <<
          j+1 << "]" << " element of the puzzle :";
      cin >> value;
      initial[i][j] = value;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      if (initial[i][j] == 0) {
        x = i;
        y = j;
      }
  }
  cout << "\n";
  Node puzzle;
  puzzle.solve(initial,x,y,final);



  return 0;
}
