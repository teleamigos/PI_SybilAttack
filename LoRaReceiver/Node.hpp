//
//  Node.hpp
//  Detecting_SA
//
//  Created by Jorge Orlando Gonzalez  on 2/16/20.
//  Copyright © 2020 Jorge Orlando Gonzalez . All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
/*-----------------------------------------------------------------------------------------------------
                                     class Node definition
-----------------------------------------------------------------------------------------------------*/
#include <vector>
using namespace std;
class Node{
private:
    uint8_t ID; //1 byte para el 1d
    uint8_t type_m='0'; //Mesnaje hello (1 byte)
    vector<uint8_t> pack; // guarda en 2 bytes
public:
    /*Constructors
     Construyen la clase de 3 diferentes formas:
     1.- por defecto (como se inicilizan los miembros de la clase)
     2.- Pasando dos argumentos ID y el tipo de mensaje
     3.- Pasando otro objecto de la clase Node*/
    Node()=default;
    Node(uint8_t id,uint8_t type);
    Node(const Node &nodo);
    /*Destructor
     Destruye la clase*/
    ~Node()=default;
    /*Get
     Nos permite obtener datos los miembros de la clase*/
    uint8_t GetID()const;
    uint8_t GetTypeM()const;
    vector<uint8_t> GetPack()const;
    /*Set
     Nos permite modificar el contenido de los datos miembro*/
    void SetID(uint8_t id);
    void SetTypeM(uint8_t type);
    void SetPack(vector<uint8_t> p);
    /*Methods
     Empaqueta ID y tipo en una variable*/
    void Pack();// Pack information...
    void Clear_pack();
};

#endif /* Node_hpp */
