// Copyright 2014-2015 the project authors as listed in the AUTHORS file.
// All rights reserved. Use of this source code is governed by the
// license that can be found in the LICENSE file.

#ifndef _PICNTRL
#define _PICNTRL

#include <wiringPi.h>
#include <time.h>

extern "C" {
    #include "MQTTClient.h"
    #include "MQTTClientPersistence.h"
}

class PICNTRL {
   public:
      PICNTRL(char* mqttBroker);
      void listenForMessages(char* topic);

   private:
      int _lightPin;
      char* _topic;
      char* _mqttBroker;
      MQTTClient _myClient;
      MQTTClient_connectOptions _mqttOptions;

      static int messageArrived(void *context, char* topicName, int topicLen, MQTTClient_message *message);
      static void connectionLost(void *context, char *cause);
};

#endif
