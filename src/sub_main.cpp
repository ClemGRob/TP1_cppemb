#include "../include/sub.hpp"
int main() {
    mosquitto_lib_init();
    char topic[] = "/ynov/bordeau/";
    Sub mysub(topic);
    return 0;
}
