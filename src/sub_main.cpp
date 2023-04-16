#include "../include/sub.hpp"
int main() {
    mosquitto_lib_init();
    char* yolo = "/ynov/bordeau/";
    Sub mysub(yolo);
    return 0;
}
