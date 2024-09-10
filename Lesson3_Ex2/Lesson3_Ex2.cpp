#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum RoomType {
    Bedroom,
    Kitchen,
    Bathroom,
    ChildrenRoom,
    LivingRoom
};

struct Room {
    int type;
    float area;
};

struct Floor {
    int numRooms;
    float ceilingHeight;
    vector<Room> rooms;
};

struct Building {
    string type;
    float area;
    int numFloors;
    vector<Floor> floors;
    bool hasStove;
};

struct Plot {
    int plotNumber;
    vector<Building> buildings;
};

struct Village {
    vector<Plot> plots;
    float totalArea;
};

Room inputRoom() {
    Room room;
    cout << "Enter room type (0 - Bedroom, 1 - Kitchen, 2 - Bathroom, 3 - ChildrenRoom, 4 - LivingRoom): ";
    cin >> room.type;
    cout << "Enter room area: ";
    cin >> room.area;
    return room;
}

Floor inputFloor() {
    Floor floor;
    cout << "Enter the number of rooms on the floor: ";
    cin >> floor.numRooms;
    cout << "Enter ceiling height: ";
    cin >> floor.ceilingHeight;
    for (int i = 0; i < floor.numRooms; ++i) {
        cout << "Enter details for room " << i + 1 << endl;
        floor.rooms.push_back(inputRoom());
    }
    return floor;
}

Building inputBuilding() {
    Building building;
    cout << "Enter building type (House, Garage, Shed, Bath): ";
    cin >> building.type;
    cout << "Enter building area: ";
    cin >> building.area;
    if (building.type == "House") {
        cout << "Enter the number of floors: ";
        cin >> building.numFloors;
        for (int i = 0; i < building.numFloors; ++i) {
            cout << "Enter details for floor " << i + 1 << endl;
            building.floors.push_back(inputFloor());
        }
    }
    else {
        building.numFloors = 1;
    }
    cout << "Does the building have a stove? (1 for Yes, 0 for No): ";
    cin >> building.hasStove;
    return building;
}

Plot inputPlot(int plotNumber) {
    Plot plot;
    plot.plotNumber = plotNumber;
    int numBuildings;
    cout << "Enter the number of buildings on plot " << plotNumber << ": ";
    cin >> numBuildings;
    for (int i = 0; i < numBuildings; ++i) {
        cout << "Enter details for building " << i + 1 << endl;
        plot.buildings.push_back(inputBuilding());
    }
    return plot;
}

int main() {
    Village village;
    cout << "Enter the total area of the village: ";
    cin >> village.totalArea;
    int numPlots;
    cout << "Enter the number of plots in the village: ";
    cin >> numPlots;
    for (int i = 0; i < numPlots; ++i) {
        cout << "Enter details for plot " << i + 1 << endl;
        village.plots.push_back(inputPlot(i + 1));
    }

    cout << "Village data entered successfully!" << endl;

    return 0;
}
