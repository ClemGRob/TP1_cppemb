#include "../include/pub.hpp"
int main() {
    mosquitto_lib_init();
    char topic[] = "/ynov/bordeau/";
    Pub myPub(topic);
    return 0;
}
