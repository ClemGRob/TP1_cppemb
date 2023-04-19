#include "../include/pub.hpp"
char s_id_for_mqtt[] = "clem_pub";
char s_topic[] = "/ynov/bordeaux/";
char s_host[] = "broker.emqx.io";
char s_msg[]="clement";

int main() {
    mosquitto_lib_init();
    Pub myPub(s_host,s_id_for_mqtt, s_topic);
    myPub.publish(s_msg);
    return 0;
}
