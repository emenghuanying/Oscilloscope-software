#ifndef _MYIIC_H
#define _MYIIC_H

#define SDA_IN()  {GPIOB->MODER&=~(3<<(11*2));GPIOB->MODER|=0<<11*2;}
#define SDA_OUT() {GPIOB->MODER&=~(3<<(11*2));GPIOB->MODER|=1<<11*2;}

#define IIC_SCL   PBout(10) //SCL
#define IIC_SDA   PBout(11) //SDA
#define READ_SDA  PBin(11)  //

void IIC_Init(void);             				 
void IIC_Start(void);
void IIC_Stop(void);	 
void IIC_Send_Byte(unsigned char txd);			
unsigned char IIC_Read_Byte(unsigned char ack);
unsigned char IIC_Wait_Ack(void); 
void IIC_Ack(void);
void IIC_NAck(void);

void IIC_Write_One_Byte(unsigned char daddr,unsigned char addr,unsigned char data);
unsigned char IIC_Read_One_Byte(unsigned char daddr,unsigned char addr);	 
#endif

