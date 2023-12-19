/*
 * spi_master_controls.c
 *
 *  Created on: Dec 15, 2023
 *      Author: zhmis
 */

#include "spi_master_controls.h"

void servo_enable_system(mosi_packet_t *packet_to_slave) {
	packet_to_slave->mode |= 0x4;
}
void servo_disable_system(mosi_packet_t *packet_to_slave) {
	packet_to_slave->mode &= 0xFB;
}

void servo_enable(mosi_packet_t *packet_to_slave, uint8_t num_of_servo) {
	switch (num_of_servo) {
	case 1:
		packet_to_slave->mode |= 0x2;
		break;
	case 2:
		packet_to_slave->mode |= 0x1;
	default:
		break;
	}
}
void servo_disable(mosi_packet_t *packet_to_slave, uint8_t num_of_servo) {
	switch (num_of_servo) {
	case 1:
		packet_to_slave->mode &= 0xFD;
		break;
	case 2:
		packet_to_slave->mode &= 0xFE;
	default:
		break;
	}
}

void servo_set_timeout(mosi_packet_t *packet_to_slave, uint8_t timeout_ms) {
	packet_to_slave->valid_packet_timeout = timeout_ms;
}

void servo_set_angle(mosi_packet_t *packet_to_slave, uint8_t num_of_servo,
		float angle, float speed_cap) {
	switch (num_of_servo) {
	case 1:
		packet_to_slave->angle_reference1 = angle;
		packet_to_slave->velocity_cap1 = speed_cap;
		break;
	case 2:
		packet_to_slave->angle_reference2 = angle;
		packet_to_slave->velocity_cap2 = speed_cap;
		break;
	default:
		break;
	}
}
