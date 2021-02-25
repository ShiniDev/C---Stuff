#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP
#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include "Room.hpp"
class GameLoop{
    public:
        GameLoop(int n);

        void init_gmap();
        void print_gmap();
    private:
        void randomize_map(int);
        std::vector<Room> gmap;
        int checker;
};

inline void connect_room(std::vector<Room>&,int,int);
inline bool already_connected(std::vector<Room>&,int,int);

#endif
