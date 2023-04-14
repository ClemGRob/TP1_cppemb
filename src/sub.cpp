#include <iostream>
#include <cstring>
#include <mosquitto.h>
#include "../include/sub.h"

using namespace std;

void message(struct mosquitto *st_client, void *userdata, const struct mosquitto_message *st_message)
{
    cout << "message du topic " << st_message->topic << ": " << (char*) st_message->payload << endl;
}

void connect_mqtt(struct mosquitto *client)
{
    mosquitto_connect(client, "broker.emqx.io", 1883, 60);
    mosquitto_message_callback_set(client, message);
    mosquitto_subscribe(client, NULL, "/ynov/bordeau/", 0);
    mosquitto_loop_forever(client, -1, 1);
    mosquitto_destroy(client);
    mosquitto_lib_cleanup();
}


