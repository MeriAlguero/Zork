#include "Game.h"
#include "Item.h"
#include "Player.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

Game::Game() {
    //Create rooms
    livingRoom = new Room("\nLIVING ROOM\n\nYou are in the living room. A table stands in the center. A door to the north.", false);
    kitchen = new Room("\nKITCHEN\n\nYou are in the kitchen. It smells like fresh bread and butter. You see a door leading to the south wall and a door in the east", false);
    bedroom = new Room("\nBEDROOM\n\nYou are in the bedroom. There is a cozy bed with white beding and an auxiliar table. \n There is a door that goes west, another to the south and a closed one at the north wall.", false);
    secretRoom = new Room("\nTRESURE ROOM\n\nYou are in the secret room. It's full of tresures!", true);
    bathroom = new Room("\nBATHROOM\n\n You are in the bathroom. Entering through the door is an empty bath with a full laundry bag. \n At the left side a toliet with a cabinet on top, in front a wash basin \n To the north you see a door.", false);

    //Link rooms
    livingRoom->setExit("north", kitchen);
    kitchen->setExit("south", livingRoom);
    kitchen->setExit("east", bedroom);
    bedroom->setExit("west", kitchen);
    bedroom->setExit("north", secretRoom);
    secretRoom->setExit("south", bedroom);
    bedroom->setExit("south", bathroom);
    bathroom->setExit("north", bedroom);

    //Add items
    livingRoom->addItem(new Item("key"));
    kitchen->addItem(new Item("sandwich"));
    kitchen->addItem(new Item("bottle of water"));
    bedroom->addItem(new Item("book"));
    secretRoom->addItem(new Item("money"));
    bathroom->addItem(new Item("bandages"));

    player.setCurrentRoom(livingRoom);
}

Game::~Game() {
    delete livingRoom;
    delete kitchen;
    delete bedroom;
    delete secretRoom;
    delete bathroom;
}
void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
        setConsoleColor(11); //Chenging color
        cout << "> ";
        getline(cin, command);
        setConsoleColor(7);  // Reset to default
        

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
        else if (command.find("take ") == 0 || command.find("Take ") == 0 || command.find("Grab ") == 0 || command.find("grab ") == 0 || command.find("Get ") == 0 || command.find("get ") == 0) {
            player.takeItem(command.substr(5));
            
        }
        else if (command.find("drop ") == 0 || command.find("Drop ") == 0) {
            player.dropItem(command.substr(5));
            
        }
        else if (command == "inventory" || command == "Inventory") {
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
        else if (command.find("check ") == 0 || command.find("inspect ") == 0 || command.find("examine ") == 0 || command.find("Check ") == 0 || command.find("Inspect ") == 0 || command.find("Examine ") == 0) {
            string itemName = command.substr(command.find(" ") + 1);
            player.checkItem(itemName);
        }
        else if (command == "dictionary" || command == "Dictionary" || command == "Help" || command == "help")
        {
            player.showDictionary();
        }
        else {
            setConsoleColor(12);
            cout << "\nUnknown command.\nIf you need some aid type -> dictionary or help\n";
            setConsoleColor(7);
        }
    }
}