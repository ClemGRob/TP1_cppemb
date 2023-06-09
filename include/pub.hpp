#include <cstring>
#include <mosquitto.h>
#include <iostream>


typedef char        char_t;
typedef float       float32_t; /*!< float32_t: float. Ex: f32_var*/
typedef double      float64_t; /*!< float64_t: double. Ex: f64_var*/
typedef long double float92_t; /*!< float92_t: long double. Ex: f92_var*/
typedef int			int32_t;   
typedef unsigned int uint32_t;

using namespace std;

class Pub
{
private:
    struct mosquitto *st_client;
    char* s_host;
    char* s_id_for_mqtt;
    char* s_topic;
    void connect_mqtt();
public:
    void publish(char* msg);
    Pub(char* s_host,char* s_id_for_mqtt, char* s_topic);
    void sets_topic(char* s_topic);
    
};
