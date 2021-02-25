#include "headers/Room.hpp"
Room::Room()
    :bat(false),pit(false),wump(false),player(false),id(-1)
{
    for(int i = 0; i < 3; i++){
        rooms.push_back(-1);
    }
}

inline bool already_connected(std::vector<Room>& r,int ind,int key){
    for(int i = 0; i <r[ind].rooms.size();i++){
        if(r[ind].rooms[i]==key+1)return true;
    }
    return false;
}

inline void connect_room(std::vector<Room>& r,int ind,int key){
    if(r[ind].rooms[0]==-1)r[ind].rooms[0]=key+1;
    else if(r[ind].rooms[1]==-1)r[ind].rooms[1]=key+1;
    else if(r[ind].rooms[2]==-2)r[ind].rooms[2]=key+1;
}
