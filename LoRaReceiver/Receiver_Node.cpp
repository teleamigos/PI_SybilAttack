//
//  Receiver_Node.cpp
//  Detecting_SA
//
//  Created by Jorge Orlando Gonzalez  on 2/29/20.
//  Copyright © 2020 Jorge Orlando Gonzalez . All rights reserved.
//

#include "Receiver_Node.hpp"
/*Constructors*/
Receiver_Node::Receiver_Node(Node nodo):ThisNode(nodo)
{
    //Exceptions
}
Receiver_Node::Receiver_Node(Node nodo,vector<uint8_t> ids,vector<float> rssi): ThisNode(nodo),ID_List(ids),RSSI_list(rssi)
{
    //Exceptions
}
/*Getters*/
Node Receiver_Node::GetThisNode()const
{
    return this->ThisNode;
}
vector<uint8_t> Receiver_Node::GetIDList()const
{
    return this->ID_List;
}
vector<float> Receiver_Node::GetRSSIList()const
{
    return this->RSSI_list;
}
vector<uint8_t> Receiver_Node::GetID_detected()const
{
    return this->detected;
}
/*Setters*/
void Receiver_Node::SetIDList(vector<uint8_t> ids)
{
    this->ID_List=ids;
}
void Receiver_Node::SetRSSIList(vector<float> rssi)
{
    this->RSSI_list=rssi;
}
/*Methods*/
void Receiver_Node::Unpack(uint8_t ID,uint8_t type, float RSSI,float NSR)
{
    //No implementado aun...
    /*
    String con formato :
     1 .- ID 1 byte
     2 .- Tipo de mensaje 1 byte
     3.-  RSSI recibido 4 bytes
    */
    this->ID_List.push_back(ID);
    this->RSSI_list.push_back(RSSI);
    this->NSR.push_back(NSR);
}

void Receiver_Node::Print_List()
{
    /*print method*/
    int i;
    for (i=0;i<this->ID_List.size();i++)
    {
    cout<<i+1<<"ID :"<<this->ID_List.at(i)<<"RSSI : "<<this->RSSI_list.at(i)<<endl;
    }
}

void Receiver_Node::Discard()
{
  /*Discard algorithm */
    int i,j;
    size_t tam;
    vector<uint8_t> ids;//it storages only IDs who sent Hello message
    vector<float> rssi_prom; //It storages rssi averages for each ID
    bool aux;
    float rssi_aux,c,r_error;


     for (i=0;i<this->ID_List.size();i++)
    {
        /*Resume ID list*/
        aux=false;
        if(ids.size()==0)
        {
            /*If is empty, add the first id*/
            ids.push_back(this->ID_List.at(i));

         }
        else
        {
            /*In other way, find the currently ID in the list and only add it if it is not yet*/
            tam=ids.size();
            for(j=0;j<tam;j++)
            {
                if(this->ID_List.at(i)==ids.at(j))
                {
                    aux=true;
                }
            }
            if(aux==false)
            {
                ids.push_back(this->ID_List.at(i));
            }
        }
    }

     for(i=0;i<ids.size();i++)
    {
        /*This section computes rssi average*/
        rssi_aux=0;
        c=0;
        for(j=0;j<this->ID_List.size();j++)
        {
            if(ids.at(i)==this->ID_List.at(j))
            {
                rssi_aux+=this->RSSI_list.at(j);
                c++;
            }
        }
        rssi_prom.push_back(rssi_aux/c);
    }
    /*Version for 2 nodes of sybil attack*/
    r_error=rssi_prom.at(0)-rssi_prom.at(1);
    //define distance
    if (r_error>this->range_tol.at(0))
    {
            this->detected=ids;
    }

}

void Receiver_Node::Clear_lists()
{
  this->ID_List.clear();
  this->RSSI_list.clear();
}
/*
void Receiver_Node::GenerateDoc(vector<uint8_t> id)
{
    string *detected;
    string iden;
    int i;
    for (i=0;i<id.size();i++)
    {
        detected =(string*)id.at(i);
    }
    
}
*/
