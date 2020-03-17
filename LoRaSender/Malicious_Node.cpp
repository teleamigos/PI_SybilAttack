//
//  Malicious_Node.cpp
//  Detecting_SA
//
//  Created by Jorge Orlando Gonzalez  on 2/19/20.
//  Copyright © 2020 Jorge Orlando Gonzalez . All rights reserved.
//

#include "Malicious_Node.hpp"

/*-----------------------------------------------------------------------------------------------------
                                     class Node implementation
-----------------------------------------------------------------------------------------------------*/

/*Constructors*/
Malicious_Node::Malicious_Node(size_t N,vector<uint8_t> fake_i):N_identities(N),fake_identities(fake_i)
{
    //
}
/*Getters*/
size_t Malicious_Node::GetNID()const
{
    return this->N_identities;
}
vector<uint8_t> Malicious_Node::GetFakeID()const
{
    return this->fake_identities;
}
/*Setters*/
void Malicious_Node::SetNID(size_t N_ID)
{
    this->N_identities=N_ID;
}
void Malicious_Node::SetFakeID(vector<uint8_t> fake_ID)
{
    this->fake_identities=fake_ID;
}
/*Methods*/
void Malicious_Node::AddFakeID(uint8_t id)
{
    this->fake_identities.insert(this->fake_identities.begin(), id);
}

vector<vector<uint8_t>> Malicious_Node::Create_pack()
{
    int i;
    vector<uint8_t> packet;
    vector<vector<uint8_t>> fake_packet;
    for (i=0;i<this->fake_identities.size();i++)
    {
        SetID(this->fake_identities.at(i));
        Pack();
        packet=GetPack();
        fake_packet.push_back(packet);
        Clear_pack();
    }
    return fake_packet;
}

