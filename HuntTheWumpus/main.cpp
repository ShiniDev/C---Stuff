#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include "src/headers/Room.hpp"
#include "src/headers/GameLoop.hpp"

int main(){
    GameLoop g(20);
    g.init_gmap();
    g.print_gmap();
    return 0;
}
