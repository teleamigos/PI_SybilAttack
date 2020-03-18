# PI_SybilAttack
Mechanism that detect a Sybil Attack using blockchain.
# Version 1.0
This repository has two modes, sender and receiver. Sender is a file written in
arduino, this one implement Node.hpp and Maliciouss_Node.hpp classes. Reciever is
designed to receive messages of type "Hello", read them and compute a RSSI of those
messages.
Both codes are using this headers in c++.
\1.- Node.hpp : Class node represents a basic node in the network.
\2.- Malicious_Node.hpp : This class is only used in the Sybil node.
\3.- Receiver_Node.hpp : This class is used only to receive and detect sybil nodes.
