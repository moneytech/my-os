#include <assemblyFunctions.h>
#include <rpiGpio.h>
#include <interrupt.h>
#include <intTypes.h>
#include <timer.h>
#include <stdOutput.h>
#include <intTypes.h>
 
 
void frameBufferSetup(int width, int height, int bitDepth){
    int error = frameBufferInit(width, height, bitDepth);

    if (error == 0){
        return 0;
    }

    else {
        // error handler
    }
}


void kernel_main() {

	setLEDasOutput();
	
	_enable_interrupts();
	// volatile int toggledOnce =1;

	timerInit(LOAD_VALUE_1S_1_PRESCALLAR, Bit23, TIMER_CONTROL_PRESCALLAR_1);

	while(1){

	}

	
    // while(1){
	// 		if (ARMrpiTimer -> count < 100 && toggledOnce == 0 ) {
	// 			gpioToggle();
	// 			toggledOnce = 1;
	// 		}
	// 		if(ARMrpiTimer ->count >= 100 && toggledOnce==1) {
	// 			toggledOnce = 0;
	// 		}
	// }

}
