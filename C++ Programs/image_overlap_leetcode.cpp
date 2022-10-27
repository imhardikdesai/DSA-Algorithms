/* Problem statement */
/* 
You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.

 
*/

/*
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3

*/






#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>v1,v2;   // to store the index(x_coordi,y_coordi)nin a vector v1 and v2
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img2.size();j++){
                if(img1[i][j]==1){
                    v1.push_back({i,j});  // psuhing int the vector v1
                }
                if(img2[i][j]==1){
                    v2.push_back({i,j});  // pushing in the vector v2 
                }
            }
        }
        map<pair<int,int>,int>umap;   // creating the map data structure
        int res=0;
        for(auto it:v1){
            for(auto ix:v2){
                umap[{it.first-ix.first,it.second-ix.second}]++;
                res=max(res, umap[{it.first-ix.first,it.second-ix.second}]);
            }
        }
        return res;
    }
};