void lcd_init();                //LCD initialization function
void lcd_data(unsigned char);   //Function to send DATA into the LCD
void lcd_cmd(unsigned char);    //Function to send COMMAND into the LCD
void lcd_dis(unsigned char *);  //LCD string display function
void delay();                   //Function to generate a delay
void init_pll();
void init_uart0();               //initialize uart0
void displayString(char *);
char recieve_char_uart0();       //recieve character on UART0
//void transmit_char_uart0(unsigned char); //transmit character on UART0