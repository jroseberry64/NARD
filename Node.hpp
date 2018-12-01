//
//  Node.hpp
//  Rogue_Dun_Gen
//
//  Created by Jonathan Roseberry on 8/22/18.
//  Copyright © 2018 Jonathan Roseberry. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include "Room.hpp"
#include "Sector.hpp"
#include <vector>

class Node {
public:
    Node();
    ~Node();
    
    //Test Functions
    void printNodeData(void) const;
    
    //Recursive function that calls itself until all branches are complete
    Node* create(Sector sector, Node* parentNode, int partnDir, int partnIter);
    
    //Generates a random number between 1 and 5
    static const int genRandPartnNum(int coordMin, int roomParentMaxCoord);
    
    //Generates a random number between 1 and 2
    static const int genRandPartnDirect(void);
    
    static const int genRandPartnStart(int min, int max);
    
    const bool equals(Node* node);
    
    Room getRoomPartn(void);
    
    static std::vector<Sector>& getFinalBranches(void);
    
    static Sector returnBlankSector(void);
    
private:
    Sector sector;
    Room room;
    Node *left;
    Node *right;
    static std::vector<Sector> finalBranches;
    
    //static std::vector<Sector> finalBranches;
    
    
};

#endif /* Node_hpp */
