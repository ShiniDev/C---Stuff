#include "headers/Room.hpp"
#include "headers/GameLoop.hpp"
GameLoop::GameLoop(int n)
    :gmap(n),checker(0){}

void GameLoop::init_gmap(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> gen(0,gmap.size()-1);
    for(int i = 0; i < gmap.size(); i++){
        gmap[i].id = i+1;
    }
    bool success = false;
    while(true){
        success = true;
        for(int i = 0; i < gmap.size();i++){
            for(int j = 0; j < gmap[i].rooms.size(); j++){
                if(gmap[i].rooms[j]==-1){
                    success = false;
                    randomize_map(i);
                }
                if(checker==-1){
                    init_gmap();
                    return;
                }
            }
        }
        if(success)break;
    }
}

void GameLoop::randomize_map(int index){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> gen(0,gmap.size()-1);
    int key = 0;
    while(true){
        checker++;
        if(checker>gmap.size()*gmap.size()){
            std::vector<Room> nmap(gmap.size());
            gmap = nmap;
            checker = -1;
            return;
        }
        key = gen(rng);
        if(already_connected(gmap,index,key))continue;
        if(key==index)continue;
        for(int i = 0; i < gmap[key].rooms.size(); i++){
            if(gmap[key].rooms[i]==-1&&gmap[index].rooms[2]==-1){
                gmap[key].rooms[i]=index+1;
                connect_room(gmap,index,key);
                break;
            }
        }
        if(gmap[index].rooms[2]!=-1)break;
    }
    key=gen(rng);
    while(true){
        if(key!=index)break;
        else key=gen(rng);
    }
    for(int i = 0; i < gmap[key].rooms.size(); i++){
        if(gmap[key].rooms[i]==-1){
            randomize_map(key);
            break;
        }
    }
}

void GameLoop::print_gmap(){
    for(int i = 0; i < gmap.size(); i++){
        std::cout << "Room: " << gmap[i].id << " is connected to the ff. rooms: ";
        for(int j = 0; j < gmap[i].rooms.size(); j++){
            std::cout << gmap[i].rooms[j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "Loop iteration count: " << checker << '\n';
}
inline bool already_connected(std::vector<Room>& r,int ind,int key){
    for(int i = 0; i <r[ind].rooms.size();i++){
        if(r[ind].rooms[i]==key+1)return true;
    }
    return false;
}

inline void connect_room(std::vector<Room>& r,int ind,int key){
    for(int i = 0 ; i < r[ind].rooms.size(); i++){
        if(r[ind].rooms[i]==-1){
            r[ind].rooms[i]=key+1;
            break;
        }
    }
}


