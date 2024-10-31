#include "includes.h"
#include <ucos_ii.h>
#include <stdio.h>
#include <altera_avalon_pio_regs.h>
#include <system.h>
#include <alt_types.h>
#include <altera_avalon_jtag_uart_regs.h>

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];
OS_STK    task3_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */
#define TASK1_PRIORITY      1
#define TASK2_PRIORITY      2
#define TASK3_PRIORITY      3

/* Function Prototypes */
void displayHEX(const char* letter);
void jtag_uart(const char *message);
int count = 0;


void task1(void* pdata)
{
  while (1)
  { 
    jtag_uart("Executing. . .\n");
    jtag_uart("TASK 1\n\n");

    const char TEXT[8] = {'T', 'I', 'F', 'F', 'A', 'N', 'Y', ' '};
    displayHEX(TEXT);
    IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE, 1);
    OSTimeDlyHMSM(0, 0, 2, 0);
  }
}

void task2(void* pdata)
{
  while (1){
	    jtag_uart("Executing. . .\n");
	    jtag_uart("TASK 2\n\n");

	    IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE, 2);
	    const char TEXT1[8] = {'A', 'N', 'I', 'R', 'U', 'D', 'H', ' '};
	    displayHEX(TEXT1);

	  OSTimeDlyHMSM(0, 0, 3, 0);
  }
}

void task3(void* pdata)
{
  while (1)
  {
    jtag_uart("Executing. . .\n");
    jtag_uart("TASK 3\n\n");

	IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE, 6);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, count);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, count);
	count++;

    OSTimeDlyHMSM(0, 0, 4, 0);
  }
}

//Code to display Letters with corresponding HEX values from a string array.
void displayHEX(const char* letter){
     const char lookUpLetterTable[128] = {
             ['0'] = 0x40, ['1'] = 0x79, ['2'] = 0x24, ['3'] = 0x30, //0-9
             ['4'] = 0x19, ['5'] = 0x12, ['6'] = 0x02, ['7'] = 0xF8,
             ['8'] = 0x00, ['9'] = 0x10,
             [' '] = 0xFF, ['A'] = 0x88, ['B'] = 0x83, ['C'] = 0xC6, //A-Z w/space
             ['D'] = 0xA1, ['E'] = 0x86, ['F'] = 0x8E, ['G'] = 0xC2,
             ['H'] = 0x89, ['I'] = 0xCF, ['J'] = 0xE1, ['K'] = 0x8A,
             ['L'] = 0xC7, ['M'] = 0xAA, ['N'] = 0xC8, ['O'] = 0xA3,
             ['P'] = 0x8C, ['Q'] = 0x98, ['R'] = 0xAF, ['S'] = 0x92,
             ['T'] = 0x87, ['U'] = 0xC1, ['V'] = 0xE3, ['W'] = 0xE2,
             ['X'] = 0x9B, ['Y'] = 0x91, ['Z'] = 0xA4
     };

     IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE, lookUpLetterTable[(int)letter[0]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE, lookUpLetterTable[(int)letter[1]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE, lookUpLetterTable[(int)letter[2]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE, lookUpLetterTable[(int)letter[3]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE, lookUpLetterTable[(int)letter[4]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE, lookUpLetterTable[(int)letter[5]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE, lookUpLetterTable[(int)letter[6]]);
     IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE, lookUpLetterTable[(int)letter[7]]);
}

/*Allows for communication between the terminal and the DE2-115 Board*/
void jtag_uart(const char *message)
{
    while (*message)
    {
        IOWR_ALTERA_AVALON_JTAG_UART_DATA(JTAG_UART_0_BASE, *message++);
    }
}

/* The main function creates three task and starts multi-tasking */
int main(void)
{
  OSTaskCreateExt(task1,
                  NULL,
                  (void *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
              
               
  OSTaskCreateExt(task2,
                  NULL,
                  (void *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);

  OSTaskCreateExt(task3,
                  NULL,
                  (void *)&task3_stk[TASK_STACKSIZE-1],
                  TASK3_PRIORITY,
                  TASK3_PRIORITY,
                  task3_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
  OSStart();
  return 0;
}
