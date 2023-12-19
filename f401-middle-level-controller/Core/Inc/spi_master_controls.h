/*
 * spi_master_controls.h
 *
 *  Created on: Dec 15, 2023
 *      Author: zhmis
 */

#ifndef INC_SPI_MASTER_CONTROLS_H_
#define INC_SPI_MASTER_CONTROLS_H_

#include "spi_comms.h"

void servo_enable_system(mosi_packet_t *packet_to_slave);
void servo_disable_system(mosi_packet_t *packet_to_slave);

void servo_enable(mosi_packet_t *packet_to_slave, uint8_t num_of_servo);
void servo_disable(mosi_packet_t *packet_to_slave, uint8_t num_of_servo);
void servo_set_timeout(mosi_packet_t *packet_to_slave, uint8_t timeout_ms);

void servo_set_angle(mosi_packet_t *packet_to_slave, uint8_t num_of_servo,
		float angle, float speed_cap);

#endif /* INC_SPI_MASTER_CONTROLS_H_ */
