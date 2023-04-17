#include "../include/sub.hpp"

int port = 1883;
int timeout = 5;

void Sub::connect_mqtt()
{
    this->st_client = mosquitto_new(this->s_id_for_mqtt, true, NULL);
    mosquitto_connect(this->st_client,this->s_host, port, timeout);

    mosquitto_message_callback_set(this->st_client, message);
    mosquitto_subscribe(this->st_client, NULL, this->s_topic, 0);
    mosquitto_loop_forever(this->st_client, -1, 1);

    mosquitto_destroy(this->st_client);
    mosquitto_lib_cleanup();
}

Sub::Sub(char* s_host,char*  s_id_for_mqtt,char*  s_topic)
{
    this->s_host=s_host;
    this->s_id_for_mqtt=s_id_for_mqtt;
    this->s_topic=s_topic;
    this->connect_mqtt();
}

void Sub::set_topic(char* s_topic)
{
    this->s_topic=s_topic;
}

void message(struct mosquitto *st_client, void *userdata, const struct mosquitto_message *st_message)
{
    cout << "message du topic " << st_message->topic << ": " << (char*) st_message->payload << endl;
}