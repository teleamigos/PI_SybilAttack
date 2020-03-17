//
//  Malicious_Node.hpp
//  Detecting_SA
//
//  Created by Jorge Orlando Gonzalez  on 2/19/20.
//  Copyright © 2020 Jorge Orlando Gonzalez . All rights reserved.
//

#ifndef Malicious_Node_hpp
#define Malicious_Node_hpp
/*-----------------------------------------------------------------------------------------------------
                                class Malicious_Node definition
-----------------------------------------------------------------------------------------------------*/
#include "Node.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Malicious_Node: public Node
{
private:
    size_t N_identities;
    vector<uint8_t> fake_identities;
public:
    /*Constructors*/
    Malicious_Node()=default;
    Malicious_Node(size_t N,vector<uint8_t> fake_i);
    /*Getters*/
    size_t GetNID()const;
    vector<uint8_t> GetFakeID()const;
    /*Setters*/
    void SetNID(size_t N_ID);
    void SetFakeID(vector<uint8_t> fake_ID);
    /*Methods*/
    void AddFakeID(uint8_t id);
    vector<vector<uint8_t>> Create_pack();//No sé como vergas lo vamos a usar pero aqui ta
};
#endif /* Malicious_Node_hpp */

