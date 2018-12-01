//
//  Node.cpp
//  Rogue_Dun_Gen
//
//  Created by Jonathan Roseberry on 8/22/18.
//  Copyright © 2018 Jonathan Roseberry. All rights reserved.
//

#include "Node.hpp"
#include <random>

#include <cstdlib>
#include <cstdio>

#define ROOT  0
#define LEFT  2
#define RIGHT 1

//Exists solely because we have to have some way of making a blank sector
//for the static vector final branches
Sector Node::returnBlankSector(void) {
    Sector sector;
    sector._x1 = 0;
    sector._x2 = 0;
    sector._y1 = 0;
    sector._y2 = 0;
    
    sector._dx = 0;
    sector._dy = 0;
    
    sector._p1.x = 0;
    sector._p1.y = 0;
    sector._p2.x = 0;
    sector._p2.y = 0;
    sector._p3.x = 0;
    sector._p3.y = 0;
    sector._p4.x = 0;
    sector._p4.y = 0;

    
    return sector;
}


std::vector<Sector> Node::finalBranches = {Node::returnBlankSector()};

Node::Node() {
    this->left = NULL;
    this->right = NULL;
}

Node::~Node() {
    if(this->left != NULL) {
        delete this->left;
        this->left = NULL;
    }
    
    if(this->right != NULL) {
        delete this->left;
        this->left = NULL;
    }
}

//Generates a random number between the coordinate minimum value and the parent room max coordinate for whatever
//direction we're splitting the room by.
const int Node::genRandPartnNum(int coordMin, int roomParentMaxCoord) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> rand_num(coordMin, roomParentMaxCoord);
    
    return rand_num(gen);
}

//Generates a random number between 1 and 2
const int Node::genRandPartnDirect(void) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> rand_num(1,2);
    
    return rand_num(gen);
}

const int Node::genRandPartnStart(int min, int max) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> rand_num(min, max);
    
    return rand_num(gen);
}

Room Node::getRoomPartn(void) {
    return this->room;
}

std::vector<Sector>& Node::getFinalBranches(void) {
    return finalBranches;
}

//End Test Functions

//Recursive function that calls itself until all branches are complete
//
//Partition iterations determines the size of the rooms and how many
//room splits there are.
Node* Node::create(Sector parentSector, Node* parentNode, int partnIter, int partnDir) {
    
if(partnIter != 0) {
        
    
    Node *node = new Node;
    
    //Determines the size of the rooms
    int random;
    
    Sector newSector[2];
    
    if(partnDir == 1) {
        
        random = genRandPartnStart(3 * partnIter, 5 * partnIter);
        
        /* Split the Partition Horizontally */
        
        //The only change should be in the Y coordinates for both partitions.
        //The X coordinates will remain the same;
        
        //Y coordinates
        int left_y1 = parentSector._y2 - random;
        int left_y2 = parentSector._y2;
        
        int right_y1 = parentSector._y1;
        int right_y2 = left_y1;
        
        //X coordinates
        int left_x1 = parentSector._x1;
        int left_x2 = parentSector._x2;
        
        int right_x1 = parentSector._x1;
        int right_x2 = parentSector._x2;
        
        /* --Define the Left Sector-- */
        
        //Define the Start and End for X and Y
        newSector[0]._x1 = left_x1;
        newSector[0]._x2 = left_x2;
        newSector[0]._y1 = left_y1;
        newSector[0]._y2 = left_y2;
        
        //Define the Coordinate Pairs for the points of the corners
        //
        //Top Left
        newSector[0]._p1.x = left_x1;
        newSector[0]._p1.y = left_y1;
        
        //Top Right
        newSector[0]._p2.x = left_x2;
        newSector[0]._p2.y = left_y1;
        
        //Bottom Left
        newSector[0]._p3.x = left_x1;
        newSector[0]._p3.y = left_y2;
        
        //Bottom Right
        newSector[0]._p4.x = left_x2;
        newSector[0]._p4.y = left_y2;
        
        //Define the distances of the line segments, defined by y2 - y1 and x2 - x1
        newSector[0]._dx = left_x2 - left_x1;
        newSector[0]._dy = left_y2 - left_y1;
        
        /* --Repeat the above to define the Right Sector-- */
        
        //Define the Start and End for X and Y
        newSector[1]._x1 = right_x1;
        newSector[1]._x2 = right_x2;
        newSector[1]._y1 = right_y1;
        newSector[1]._y2 = right_y2;
        
        //Define the Coordinate Pairs for the points of the corners
        //
        //Top Left
        newSector[1]._p1.x = right_x1;
        newSector[1]._p1.y = right_y1;
        
        //Top Right
        newSector[1]._p2.x = right_x2;
        newSector[1]._p2.y = right_y1;
        
        //Bottom Left
        newSector[1]._p3.x = right_x1;
        newSector[1]._p3.y = right_y2;
        
        //Bottom Right
        newSector[1]._p4.x = right_x2;
        newSector[1]._p4.y = right_y2;
        
        //Define the distances of the line segments, defined by y2 - y1 and x2 - x1
        newSector[1]._dx = right_x2 - right_x1;
        newSector[1]._dy = right_y2 - right_y1;
        
    } else if(partnDir == -1) {
        
        random = genRandPartnStart(3 * partnIter, 6 * partnIter);
        
        /* Split the Partition Vertically */
        
        //The only change should be in the X coordinates for both partitions.
        //The Y coordinates will remain the same;
        
        //Y coordinates
        int left_y1 = parentSector._y1;
        int left_y2 = parentSector._y2;
        
        int right_y1 = parentSector._y1;
        int right_y2 = parentSector._y2;
        
        //X coordinates
        int left_x1 = parentSector._x2 - random;
        int left_x2 = parentSector._x2;
        
        int right_x1 = parentSector._x1;
        int right_x2 = left_x1;
        
        /* --Define the Left Sector-- */
        
        //Define the Start and End for X and Y
        newSector[0]._x1 = left_x1;
        newSector[0]._x2 = left_x2;
        newSector[0]._y1 = left_y1;
        newSector[0]._y2 = left_y2;
        
        //Define the Coordinate Pairs for the points of the corners
        //
        //Top Left
        newSector[0]._p1.x = left_x1;
        newSector[0]._p1.y = left_y1;
        
        //Top Right
        newSector[0]._p2.x = left_x2;
        newSector[0]._p2.y = left_y1;
        
        //Bottom Left
        newSector[0]._p3.x = left_x1;
        newSector[0]._p3.y = left_y2;
        
        //Bottom Right
        newSector[0]._p4.x = left_x2;
        newSector[0]._p4.y = left_y2;
        
        //Define the distances of the line segments, defined by y2 - y1 and x2 - x1
        newSector[0]._dx = left_x2 - left_x1;
        newSector[0]._dy = left_y2 - left_y1;
        
        /* --Repeat the above to define the Right Sector-- */
        
        //Define the Start and End for X and Y
        newSector[1]._x1 = right_x1;
        newSector[1]._x2 = right_x2;
        newSector[1]._y1 = right_y1;
        newSector[1]._y2 = right_y2;
        
        //Define the Coordinate Pairs for the points of the corners
        //
        //Top Left
        newSector[1]._p1.x = right_x1;
        newSector[1]._p1.y = right_y1;
        
        //Top Right
        newSector[1]._p2.x = right_x2;
        newSector[1]._p2.y = right_y1;
        
        //Bottom Left
        newSector[1]._p3.x = right_x1;
        newSector[1]._p3.y = right_y2;
        
        //Bottom Right
        newSector[1]._p4.x = right_x2;
        newSector[1]._p4.y = right_y2;
        
        //Define the distances of the line segments, defined by y2 - y1 and x2 - x1
        newSector[1]._dx = right_x2 - right_x1;
        newSector[1]._dy = right_y2 - right_y1;

    }
    
    node->sector = parentSector;
    node->room = Room(node->sector);
    
    
    //This is the partition direction for the left and right child
    partnDir *= -1;
    
    /* Possible fix to overflow error */
    if(newSector[0]._dx > parentSector._dx || newSector[0]._dy > parentSector._dy)
        return NULL;
    else if(newSector[1]._dx > parentSector._dx || newSector[1]._dy > parentSector._dy)
        return NULL;
    else if(newSector[1]._dx <= 1 || newSector[1]._dy <= 1)
        return NULL;
    else if(newSector[0]._dx <= 1 || newSector[0]._dy <= 1)
        return NULL;
    
    //Create the left and right child nodes
    node->left->create(newSector[0], node, partnIter - 1, partnDir);
    node->right->create(newSector[1], node, partnIter - 1, partnDir);
    
    if(partnIter == 1) {
            finalBranches.push_back(newSector[0]);
            finalBranches.push_back(newSector[1]);
    }
    
    return node;
} else {
    return NULL;
}
    
}

const bool Node::equals(Node* node) {
    Node *node_ptr = this;
    if(node_ptr == node)
        return true;
    else
        return false;
}


