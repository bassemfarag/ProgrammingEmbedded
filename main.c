//Course: Programming embedded systems.
//Assignment number: One.
//Part number: One.
//Name: Bassem Farag.
// Personal Number : 199110167153.
//Date: 30/10/2016.

// include the standard I/O header file needed for using printf.
#include <stdio.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "stm32f10x_conf.h"
#include "task.h"
#include "setup.h"

/*-----------------------------------------------------------*/


unsigned int Time;
 void periodictask( void * timing )
 {
  unsigned long xLastWakeTime;
 const int period = 100;
	 float printtime;
	 
     // Initialise the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();
     for( ;; )
     {
			 printtime= (float)Time;
			   printf("%f s \n", printtime/1000);
         // Wait for the next cycle.
         vTaskDelayUntil( &xLastWakeTime, period );
				 Time = xTaskGetTickCount();
			 }
		   assert(0);
 }
unsigned int *t= &Time;

/*
 * Entry point of program execution
 */
int main( void )
{
  prvSetupHardware();
	 xTaskCreate(periodictask,   // pointer to task function
              "periodictask",	// name of task
			  100,      // size of stack: 100 words = 400 byte
			            // should be at least configMINIMAL_STACK_SIZE
			  t,     // task parameters
			  1,        // priority: number between
			            // 0 and (configMAX_PRIORITIES - 1)
			  NULL      // handle to the task
			  );
	
	
  vTaskStartScheduler();
  assert(0);
  return 0;                 // not reachable
}
/*-----------------------------------------------------------*/


