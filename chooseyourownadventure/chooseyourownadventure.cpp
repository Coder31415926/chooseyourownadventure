//Framework for a choose your own adventure game

#include <iostream>
using namespace std;
//Create a location structure
//This will house the information about each room including pointers to the rooms it leads to.
struct location
{
    int idNumber = 0;
    char desc[300] = "";
    char descInside[1000] = "";
    int itemId = 0;
    struct location* doorOne = nullptr;
    struct location* doorTwo = nullptr;
    struct location* doorThree = nullptr;
    struct location* doorFour = nullptr;
    struct location* secretOne = nullptr;
    struct location* startLocation = nullptr;


    location(int id)
    {
        idNumber = id;

    }
};

//Create the level class. This will hold your current location
//And your starting location
//Plus functions to move and get the descriptions of the room and hallways
class level
{
public:
    location* start = nullptr;
    location* current = nullptr;
    void move(int locationNum);
    void printDesc();
    void printHallDesc();

};

//Change the current location pointer to the pointer of one of the rooms it connects to when moving
void level::move(int locationNum)
{
    switch (locationNum)
    {
    case(1):
        current = current->doorOne;
        break;
    case(2):
        current = current->doorTwo;
        break;
    case(3):
        current = current->doorThree;
        break;
    case(4):
        current = current->doorFour;
        break;
    }
};

//Print the description of the current location
void level::printDesc()
{
    std::cout << current->descInside << '\n';
};

//Print the short desc of each connecting room.
void level::printHallDesc()
{
    std::cout << "1. " << current->doorOne->desc << '\n';
    std::cout << "2. " << current->doorTwo->desc << '\n';
    std::cout << "3. " << current->doorThree->desc << '\n';
    std::cout << "4. " << current->doorFour->desc << '\n';
};

//Main function
int main()
{
    //Have we lost?
    int lost = 1;

    //Create and populate the level
    level lvl;
    location* loc0 = new location(0);
    location* loc1 = new location(1);
    location* loc2 = new location(2);
    location* loc3 = new location(3);
    location* loc4 = new location(4);
    location* loc5 = new location(5);
    location* loc6 = new location(6);
    location* loc7 = new location(7);
    lvl.start = loc0;
    lvl.current = lvl.start;
    loc0->doorOne = loc1;
    loc0->doorTwo = loc2;
    loc0->doorThree = loc3;
    loc0->doorFour = loc4;
    strcpy_s(loc0->desc, "The room you started in. With 4 hallways leading to rooms");
    strcpy_s(loc1->desc, "A room with a small box ");

    while (lost)
    {
        int choice = 0;
        int move = 0;
        std::cout << "What do you do?\n1. Look around\n2. Inspect current room\n3. Move to a new location\n:";
        std::cin >> choice;

        switch (choice)
        {
            case(1):
                lvl.printHallDesc();
                break;
            case(2):
                lvl.printDesc();
                break;
            case(3):
                std::cout << "Where do you move? (1-4)";
                std::cin >> move;

                if (move > 4 || move < 1)
                    std::cout << "Invalid option: " << move;
                else
                    lvl.move(move);
                break;
            
            default:
                cout << "Bad choice of: " << choice;
                lost = 0;
                break;
        }
        /* std::cout << loc0->doorOne << "\n";
         std::cout << loc0->desc;*/
    }
}

