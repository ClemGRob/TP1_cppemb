#include "../include/pub.hpp"


int port = 1883;
int timeout = 5;


void Pub::publish(char* msg)
{
        mosquitto_publish(this->st_client, NULL, this->s_topic, strlen(msg), msg, 0, false);
        mosquitto_destroy(this->st_client);
        mosquitto_lib_cleanup();
    }
void Pub::connect_mqtt()
{
    this->st_client = mosquitto_new(this->s_id_for_mqtt, true, NULL);
    // mosquitto_connect(this->st_client,this->s_host, port, timeout);
    mosquitto_connect(this->st_client, "broker.emqx.io", 1883, 20);
    
}
    

Pub::Pub(char* s_host,char* s_id_for_mqtt, char* s_topic)
{
    this->s_host=s_host;
    this->s_id_for_mqtt=s_id_for_mqtt;
    this->s_topic=s_topic;
    this->connect_mqtt();
}

void Pub::sets_topic(char* s_topic)
{
    this->s_topic=s_topic;
}