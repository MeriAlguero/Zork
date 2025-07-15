#include "Game.h"
#include "Item.h"
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

Game::Game() {
    //Create rooms
    livingRoom = new Room("\nLIVING ROOM\n\nYou are in the living room. A table stands in the center. A door to the north.");
    kitchen = new Room("\nKITCHEN\n\nYou are in the kitchen. It smells like fresh bread. You see a door in the south wall and a door in the east");
    bedroom = new Room("\nBEDROOM\n\nYou are in the bedroom. There is a cozy bed with white beding and an auxiliar table. \n There is a door that goes west and another one north.");
    secretRoom = new Room("\nTRESURE ROOM\n\nYou are in the secret room. It's full of tresures!", true);

    //Link rooms
    livingRoom->setExit("north", kitchen);
    kitchen->setExit("south", livingRoom);
    kitchen->setExit("east", bedroom);
    bedroom->setExit("west", kitchen);
    bedroom->setExit("north", secretRoom);
    secretRoom->setExit("south", bedroom);

    //Add items
    livingRoom->addItem(new Item("key"));
    kitchen->addItem(new Item("sandwich"));
    kitchen->addItem(new Item("bottle of water"));
    bedroom->addItem(new Item("book"));
    secretRoom->addItem(new Item("money"));

    player.setCurrentRoom(livingRoom);
}

Game::~Game() {
    delete livingRoom;
    delete kitchen;
    delete bedroom;
    delete secretRoom;
}

void Game::start() {
    string command;
    Room* lastRoom = player.getCurrentRoom();  //Track last room

   //Print initial room description once
    cout << "\n" << lastRoom->getDescription() << "\n";
    for (Item* item : lastRoom->getItems()) {
        cout << "You see a " << item->getName() << ".\n";
    }

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "quit" || command == "exit" || command == "Quit" || command == "Exit") { 
            cout << "\n\nSee you later!!\n\n" << endl;
            Sleep(600);
            break;
        }

        else if (command.find("go ") == 0 || command.find("walk ") == 0 || command.find("move ") == 0 || command.find("Move ") == 0 || command.find("Walk ") == 0 || command.find("Go ") == 0)  {
            player.move(command.substr(3));

            Room* currentRoom = player.getCurrentRoom();
            if (currentRoom != lastRoom) {
                cout << "\n" << currentRoom->getDescription() << "\n";
                for (Item* item : currentRoom->getItems()) {
                    cout << "You see a " << item->getName() << ".\n";
                }
                lastRoom = currentRoom;  // Update lastRoom
            }
        }
        else if (command.find("take ") == 0 || command.find("Take ") == 0 || command.find("Grab ") == 0 || command.find("grab ") == 0) {
            player.takeItem(command.substr(5));
            
        }
        else if (command.find("drop ") == 0 || command.find("Drop ") == 0) {
            player.dropItem(command.substr(5));
            
        }
        else if (command == "inventory" || command =="Inventory") {
            player.showInventory();
        }
        else if(command.find("put ") == 0 && command.find(" in bag") != string::npos){
            string itemName = command.substr(4, command.find(" in bag") - 4);
            player.putInBag(itemName);
        }
        else if (command.find("take ") == 0 && command.find(" from bag") != string::npos) {
            string itemName = command.substr(15);
            player.removeFromBag(itemName);
        }
        else if (command == "open bag" || command == "check bag") {
            player.showBag();
        }
        else if (command == "dictionary" || "Dictionary" || "Help" || "help")
        {
            player.showDictionary();
        }
        else {
            cout << "Unknown command.\n";
        }
    }
}