/*
 * pwm.h
 *
 *  Created on: 11 Haz 2021
 *      Author: Abdullah
 */
#ifndef PWM
#define PWM
#include "stm32f10x.h" 				// Device header

typedef struct MotorStruct{		// DC Motor structure

 GPIO_TypeDef* pwm_port;			// Port and pin assignments for pwm
 uint16_t 		 pwm_pin;				// If pwm not used, pwm_port and pwm_pin assignments are unnecessary

 GPIO_TypeDef* forward_port;	// Port and pin assignments for forward direction
 uint16_t 		 forward_pin;

 GPIO_TypeDef* backward_port; // Port and pin assignments for backward direction
 uint16_t 		 backward_pin;

}Motor;

void MotorConfig(Motor Port_Pin);																	// DC Motor configuration including pwm settings
void MotorRun(Motor Port_Pin, uint16_t speed, char direction);		// Running function with pwm
void Basic_MotorConfig(Motor Port_Pin);														// DC Motor configuration without pwm settings
void Basic_MotorRun(Motor Port_Pin,char direction);								// Running function without pwm, just for full speed of backward or forward
void Motor_Stop(Motor Port_Pin);																	// Stop function for selected motor
void Motor_Delay(uint32_t time);																	// Real time delay function
void systemClockEnable(void);
void SysTick_Handler(void);
#endif
