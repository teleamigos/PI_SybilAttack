//
//  Receiver_Node.hpp
//  Detecting_SA
//
//  Created by Jorge Orlando Gonzalez  on 2/29/20.
//  Copyright © 2020 Jorge Orlando Gonzalez . All rights reserved.
//

#ifndef Receiver_Node_hpp
#define Receiver_Node_hpp
/*-----------------------------------------------------------------------------------------------------
                                class Receiver_Node definition
-----------------------------------------------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>
#include "Node.hpp"

using namespace std;
class Receiver_Node
{
private:
    Node ThisNode;
    const vector<float> range_tol{0.1182,0.155,0.1593,0.0882,0.1265,0.1003,0.1511,0.0471};
    /*Range of tol                0.20    0.40    1      2      4     8       16     32*/
    vector<uint8_t> ID_List;
    vector<float> RSSI_list;
    vector<float> NSR;
    vector<vector<uint8_t>> ID_detected;
public:
    /*Constructors*/
    Receiver_Node()=default;
    Receiver_Node (Node nodo);
    Receiver_Node(Node nodo,vector<uint8_t> ids,vector<float> rssi);
    /*Getters*/
    Node GetThisNode()const;
    vector<uint8_t> GetIDList()const;
    vector<float> GetRSSIList()const;
    vector<vector<uint8_t>> GetID_detected()const;
    /*Setters*/
    //void SetThisNode(Node nodo);
    void SetIDList(vector<uint8_t> ids);
    void SetRSSIList(vector<float> rssi);
    /*Methods*/
    void Unpack(uint8_t ID,uint8_t type, float RSSI,float NSR);//Unpack information
    void Print_List();//print the list of messages with RSSI
    void Discard();//Algortihm to disrcard bad nodes...
    void Print_ID_detected()const;
    void Clear_lists();
};

#endif /* Receiver_Node_hpp */
