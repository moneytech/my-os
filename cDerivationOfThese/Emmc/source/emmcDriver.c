#include <assemblyFunctions.h>
#include <rpiGpio.h>
#include <interrupt.h>
#include <intTypes.h>
#include <timer.h>
#include <emmc.h>
#include <jtag.h>
#include <stdOutput.h>

void frameBufferSetup(int width, int height, int bitDepth){
    uint32_t error = frameBufferInit(width, height, bitDepth);

    if (error == 0){
        return 0;
    }

    else {
        // error handler
        // gpioBlink(200, 10);
		delay(1000);
    }
}

void kernel_main2() {
	// setLEDasOutput();

	while(1) {	
		gpioBlink(200, 10);
	}
}

void kernel_main() {

	// jtagInit();
	// setLEDasOutput();
// gpioBlink(200, 10);

	// gpioBlink(50, 100);
	
	_enable_interrupts();
	// volatile int toggledOnce =1;
	frameBufferSetup(1024, 768, 16);
	setStartPosition(0,0);
	setCursor(0);
	// timerInit(LOAD_VALUE_1S_1_PRESCALLAR, Bit23, TIMER_CONTROL_PRESCALLAR_1);

	emmcInit();
	printf("Emmc Init Done\n");
	delay(1000);

	volatile uint32_t dataBlockBuffer[64];
	emmcSendData(READ_SINGLE, 0, &dataBlockBuffer);
	for (uint8_t i=58; i < 64; i++) {
		uint32_t print_data = dataBlockBuffer[i];
		printf("Number %i is = %x\n", i, print_data);
		// if (i%20 == 0){
		// 	delay(1000*10);
		// 	clearScreen();
		// 	setStartPosition(0,0);
		// 	setCursor(0);
		// }
	}
	while(1){
		// volatile uint32_t data = emmcControllerBasicStruct1_t -> data;
	}

}
