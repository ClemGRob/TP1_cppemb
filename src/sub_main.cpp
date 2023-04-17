#include "../include/sub.hpp"
char s_id_for_mqtt[] = "clem_sub";
char s_topic[] = "/ynov/bordeaux/";
char s_host[] = "broker.emqx.io";

int main() 
{
    mosquitto_lib_init();
    Sub mysub(s_host,s_id_for_mqtt,s_topic);
    return 0;
}
