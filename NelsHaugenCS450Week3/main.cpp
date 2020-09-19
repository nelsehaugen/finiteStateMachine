#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <ctime>

int main()
{
enum state { ST_WAITFORZERO, ST_ACKZERO, ST_WAITFORONE, ST_ACKONE };

enum state current_state = ST_WAITFORZERO;
int packetCall = -1;

while (packetCall != 2)
{

    switch (current_state)
    {
        case ST_WAITFORZERO:
            std::cout << "Sending State Machine is in state CALL 0" << std::endl;
            std::cout << "Please input a 0 to request a send packet or 1 to send a packet (or 2 to end program)" << std::endl;
            std::cin >> packetCall;
            while (current_state != ST_ACKZERO) {
                if (packetCall == 1) {
                    std::cout << "Cannot send a packet in state CALL 0" << std::endl;
                    std::cin >> packetCall;
                } else if (packetCall == 0) {
                    std::cout << "Sending packet..." << std::endl;
                    current_state = ST_ACKZERO;
                    packetCall = -1;
                } else if (packetCall == 2) {
                    std::cout << "Have a nice day!" << std::endl;
                    return 0;
                } else {
                    std::cout << "Sorry, that is not a valid input" << std::endl;
                    std::cin >> packetCall;
                }
            }

        break;

        case ST_ACKZERO:
            std::cout << "Sending State Machine is in state WAIT 0" << std::endl;
            std::cout << "Please enter 1 for a corrupt packet or 0 for a good packet and a zero acknowledge (or 2 to end program)" << std::endl;

            //start timer

            std::cin >> packetCall;
            while (current_state != ST_WAITFORONE) {
                    //timeout function goes here
                    //reset timer
                if (packetCall == 1) {
                    std::cout << "Receipt package was corrupt, Sending State Machine is still in state WAIT 0" << std::endl;
                    std::cin >> packetCall;
                } else if (packetCall == 0) {
                    std::cout << "Acknowledge zero received..." << std::endl;
                    current_state = ST_WAITFORONE;
                    //stop timer
                } else if (packetCall == 2) {
                    std::cout << "Have a nice day!";
                    return 0;
                } else {
                    std::cout << "Sorry, that is not a valid input" << std::endl;
                    std::cin >> packetCall;
                }
            }

        break;

        case ST_WAITFORONE:
            std::cout << "Sending State Machine is in state CALL 1" << std::endl;
            std::cout << "Please input a 1 to request a send packet or 0 to send a packet (or 2 to end program)" << std::endl;
            std::cin >> packetCall;
            while (current_state != ST_ACKONE) {
                if (packetCall == 0) {
                    std::cout << "Cannot send a packet in state CALL 1" << std::endl;
                    std::cin >> packetCall;
                } else if (packetCall == 1) {
                    std::cout << "Sending packet..." << std::endl;
                    current_state = ST_ACKONE;
                    packetCall = -1;
                } else if (packetCall == 2) {
                    std::cout << "Have a nice day!";
                    return 0;
                } else {
                    std::cout << "Sorry, that is not a valid input" << std::endl;
                    std::cin >> packetCall;
                }
            }

        break;

        case ST_ACKONE:
            std::cout << "Sending State Machine is in state WAIT 1" << std::endl;
            std::cout << "Please enter 0 for a corrupt packet or 1 for a good packet and a zero acknowledge (or 2 to end program)" << std::endl;

            //start timer

            std::cin >> packetCall;
            while (current_state != ST_WAITFORZERO) {
                    //timeout function goes here
                    //reset timer
                if (packetCall == 0) {
                    std::cout << "Receipt package was corrupt, Sending State Machine is still in state WAIT 1" << std::endl;
                    std::cin >> packetCall;
                } else if (packetCall == 1) {
                    std::cout << "Acknowledge zero received..." << std::endl;
                    current_state = ST_WAITFORZERO;
                    //stop timer
                } else if (packetCall == 2) {
                    std::cout << "Have a nice day!";
                    return 0;
                } else {
                    std::cout << "Sorry, that is not a valid input" << std::endl;
                    std::cin >> packetCall;
                }
            }

        break;


    }
}
};

