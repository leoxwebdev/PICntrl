// Copyright 2014-2015 the project authors as listed in the AUTHORS file.
// All rights reserved. Use of this source code is governed by the
// license that can be found in the LICENSE file.

#include "PICNTRL.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   if(wiringPiSetup() == -1) {
      return 0;
   }

   // validate we got the required parameters 
   if (2 > argc) {
      printf("Missing mqttBroker parameter - exiting\n");
      return -1;
   }
   
   PICNTRL transmitter = PICNTRL(argv[1]);

   transmitter.listenForMessages((char*)"house/cntrl/+/+");
}

