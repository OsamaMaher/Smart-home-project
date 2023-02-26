/*
 * LCD_tet.h
 *
 * Created: 11/21/2022 8:46:54 PM
 *  Author: osama
 */ 


#ifndef LCD_TET_H_
#define LCD_TET_H_
#define four_bit
#define LCD_CONN_PORT1 'A'
#define LCD_CONN_PORT2 'A'
#define CLEAR_SCREEN 0x01
#define CURSOR_ON_DESPLAY_ON 0x0C
#define RETURN_HOME 0x02
#define ENTERY_MODE 0x06
#define EN 0
#define RS 1
#define RW 2
#if defined four_bit
#define FOUR_BIT_MODE 0x28
#elif defined eight_bit
#define EIGHT_BIT_MODE 0x38
#endif



void LCD_init(void);
static void send_falling_edge(void);
void LCD_send_cmd(char cmd);
void LCD_send_char(char data);
void LCD_send_string(char* data);
void LCD_clear_screen(void);
void LCD_move_cursor(char row, char column);

#endif /* LCD_TET_H_ */