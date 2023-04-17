#include "../include/sub.hpp"

char const id_for_mqtt[] = "clem_sub";

void Sub::connect_mqtt()
{
    this->st_client = mosquitto_new(id_for_mqtt, true, NULL);
    mosquitto_connect(this->st_client, "broker.emqx.io", 1883, 20);
    
    mosquitto_message_callback_set(this->st_client, message);

    mosquitto_subscribe(this->st_client, NULL, this->s_topic, 0);
    mosquitto_loop_forever(this->st_client, -1, 1);
    mosquitto_destroy(this->st_client);
    mosquitto_lib_cleanup();
}

Sub::Sub(char* s_topic)
{
    this->s_topic=s_topic;
    this->connect_mqtt();
}

void Sub::sets_topic(char* s_topic)
{
    this->s_topic=s_topic;
}

void message(struct mosquitto *st_client, void *userdata, const struct mosquitto_message *st_message)
{
    cout << "message du topic " << st_message->topic << ": " << (char*) st_message->payload << endl;
}