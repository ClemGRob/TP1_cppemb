#include "../include/pub.hpp"

static char* id_for_mqtt = "clem2";

void Pub::connect_mqtt()
{
    this->st_client = mosquitto_new(id_for_mqtt, true, NULL);
    //mosquitto_connect(this->st_client, "broker.emqx.io", 1883, 20);
    int rc = mosquitto_connect(this->st_client, "broker.emqx.io", 1883, 20);
    if (rc != MOSQ_ERR_SUCCESS) {
        cerr << "Erreur : impossible de se connecter au broker MQTT." << endl;
        mosquitto_destroy(this->st_client);
        mosquitto_lib_cleanup();
    }
    else
    {
        mosquitto_publish(this->st_client, NULL, this->s_topic, 3, "lalala", 0, false);
        mosquitto_destroy(this->st_client);
        mosquitto_lib_cleanup();
    }
}

Pub::Pub(char* s_topic)
{
    this->s_topic=s_topic;
    this->connect_mqtt();
}

void Pub::sets_topic(char* s_topic)
{
    this->s_topic=s_topic;
}