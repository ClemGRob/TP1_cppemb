#include "../include/pub.hpp"
char s_id_for_mqtt[] = "clem_pub";
char topic[] = "/ynov/bordeau/";

int main() {
    mosquitto_lib_init();
    
    Pub myPub(topic);
    return 0;
}
