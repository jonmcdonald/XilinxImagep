//v2: comments beginning with v2 are generated and used by V2
//v2: please don't remove or modify these comments

//v2: begin of includes section
#include "zynqIP.h"
//v2: end of includes section

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_handler(int s){
    cout << endl << "*** Caught signal " << s << endl;
    cout << "*** Stopping Simulation " << endl;
    sc_stop();
    exit(0); 
}

extern "C" void Papoulis_SetTclVariable(const char* name, const char* value);

int sc_main(int argc, char *argv[]) {

  Papoulis_SetTclVariable("::env(VISTA_PLATFORM_NAME)", "zynq");

 struct sigaction sigIntHandler;
 sigIntHandler.sa_handler = my_handler;
 sigemptyset(&sigIntHandler.sa_mask);
 sigIntHandler.sa_flags = 0;
 sigaction(SIGINT, &sigIntHandler, NULL);

//v2: begin of channel declarations section
//v2: end of channel declarations section


printf("going to instantiate top\n");

//v2: begin of instantiations section
//v2: instance inst_zynqIP - instance number 0 of module zynqIP
zynqIP *inst_zynqIP = new zynqIP("top");
//v2: end of instantiations section

printf("going to start sim\n");


//v2: begin of ports assignment section
//v2: ports assignment for instance inst_zynqIP
//v2: end of ports assignment section

 sc_start();

//v2: begin of instantiations section
delete inst_zynqIP;
//v2: end of instantiations section

 return 0;
}
