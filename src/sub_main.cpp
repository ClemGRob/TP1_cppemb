#include <iostream>
#include <cstring>
#include <mosquitto.h>
#include "../include/sub.h"


int main() {
    mosquitto_lib_init();
    struct mosquitto *client = mosquitto_new("clem", true, NULL);
    connect_mqtt(client);

    return 0;
}
