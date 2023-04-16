#include "../include/pub.hpp"
int main() {
    mosquitto_lib_init();
    char* yolo = "/ynov/bordeau/";
    Pub myPub(yolo);
    return 0;
}
