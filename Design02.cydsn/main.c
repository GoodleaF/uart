/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    /* Start UART operation */
    UART_Start();
    
    /* Transmit header to the terminal */
   // UART_UartPutString("\r\n**********************************************************************************\r\n");
   // UART_UartPutString("This example uses polling to demonstrate UART operation\r\n");
   // UART_UartPutString("If you see this text the terminal connection is configured correctly.\r\n");
    //UART_UartPutString("Start typing to see an echo in the terminal.\r\n");
   // UART_UartPutString("\r\n");
    int txdata[14];
    int rxdata[7];
    int d=0;
    for(;;)
    {
        //if(UART_SpiUartGetRxBufferSize() != 0ul) {
        //uint32 data= UART_SpiUartReadRxData();
              uint32 data = UART_SpiUartReadRxData();
          if(data==0x32 && d==0){
            txdata[0]=0x32;
            rxdata[0]=0x32;
            UART_SpiUartWriteTxData(0x32);
            
            d++;
        }
        
           // uint32 data_0 = UART_SpiUartReadRxData();
           else if(data==0xBB && d==1 ){
                txdata[1]=0xAA;
                 rxdata[1]=0xBB;
                UART_SpiUartWriteTxData(0xAA);
               // break;
                d++;
            }
           else if(data==0x00 && d==2  ){
                txdata[2]=0x00;
                 rxdata[2]=0x00;
                UART_SpiUartWriteTxData(0x00);
               // break;
                d++;
            }
        else if(data==0x0B && d==3  ){
                txdata[3]=0x0A;
                 rxdata[3]=0x0B;
                UART_SpiUartWriteTxData(0x0A);
               // break;
                d++;
            }
       else if(data==0x00 && d==4  ){
                txdata[4]=0x07;
        rxdata[4]=0x00;
                UART_SpiUartWriteTxData(0x00);
               // break;
                d++;
            }
        else if(data==0x00 && d==5 ){
                txdata[5]=0xE5;
        rxdata[5]=0x00;
                UART_SpiUartWriteTxData(0xE5);
               // break;
                d++;
            }
        else if(data==0x00 && d==6 ){
                txdata[6]=0x07;
        rxdata[6]=0x00;
                UART_SpiUartWriteTxData(0x07);
                
               // break;
                d++;
            }
        else if(data ==(rxdata[1]^rxdata[2]^rxdata[3]^rxdata[4]^rxdata[5]^rxdata[6]) && d==7  ){
              txdata[7]=0x06;
                  UART_SpiUartWriteTxData(0x06);
               // break;
                d++;
            }
         else if(data==0x34 && d==8 ){
                txdata[8]=0x00;
                txdata[9]=0x00;
                txdata[10]=0x00;
               txdata[11]=0x00;
               
                UART_SpiUartWriteTxData(0x00);
                UART_SpiUartWriteTxData(0x00);
                UART_SpiUartWriteTxData(0x00);
                UART_SpiUartWriteTxData(0x00);
                UART_SpiUartWriteTxData(txdata[1]^ txdata[2]^ txdata[3]^ txdata[4]^ txdata[5]^ txdata[6]^ txdata[7]^ txdata[8]^ txdata[9]^ txdata[10]^ txdata[11]);
                 UART_SpiUartWriteTxData(0x34);
                // break;
                d=0;
            }
        
        
       }
   // if(rxdata=[0x32,0xAA, 0x00,0x0A,0x07,0xE5,0x07,0x00,0x00,0x00]){
   //}
    /*for(int i=0;i<10;i++){
        UART_SpiUartWriteTxData(rxdata[i]);
       
       }*/
   
   //}
    
           // UART_SpiUartWriteTxData(rxdata);
            /*if(data==0x0B){
            UART_SpiUartWriteTxData(0x0B);
            }
        }*/
    
    //if(data=UART_SpiUartReadRxData()){}
        
        /* Below is an alternative that is simpler, but function used blocks until character is received */
        /* Characters typed on console are transmitted via UART using a low level API function*/
        //uint32 read_character = UART_UartGetChar(); 
        //UART_UartPutChar(read_character);
  //  }
}
//}

/* [] END OF FILE */
