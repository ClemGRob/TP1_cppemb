#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <mosquitto.h>

typedef char        char_t;
typedef float       float32_t; /*!< float32_t: float. Ex: f32_var*/
typedef double      float64_t; /*!< float64_t: double. Ex: f64_var*/
typedef long double float92_t; /*!< float92_t: long double. Ex: f92_var*/
typedef int			int32_t;   
typedef unsigned int uint32_t;   
using namespace std;
void on_message(struct mosquitto *st_client, void *userdata, const struct mosquitto_message *st_message);
void connect_mqtt(struct mosquitto *st_client);
#endif