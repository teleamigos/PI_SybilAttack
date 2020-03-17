//
//  Node.cpp
//  Detecting_SA
//
//  Created by Jorge Orlando Gonzalez  on 2/16/20.
//  Copyright © 2020 Jorge Orlando Gonzalez . All rights reserved.
//
/*-----------------------------------------------------------------------------------------------------
                                     class Node implementation
-----------------------------------------------------------------------------------------------------*/
#include "Node.hpp"
#include <vector>
/*Constructors*/
Node::Node(unsigned char id,unsigned char type): ID(id),type_m(type)
{
        //Exceptions
}
Node::Node(const Node &nodo)
{
    this->ID=nodo.ID;
    this->type_m=nodo.type_m;
}
/*Get*/
uint8_t Node::GetID()const
{
    return this->ID;
}
uint8_t Node::GetTypeM()const
{
    return this->type_m;
}
vector<uint8_t> Node::GetPack()const
{
    return this->pack;
}
/*Set*/
void Node::SetID(uint8_t id)
{
    this->ID=id;
}
void Node::SetTypeM(uint8_t type)
{
    this->type_m=type;
}
void Node::SetPack(vector<uint8_t> p)
{
    this->pack=p;
}
/*Methods*/
void Node::Pack()
{
    this->pack.push_back(this->type_m);
    this->pack.push_back(this->ID);
}

void Node::Clear_pack()
{
    this->pack.clear();
}
