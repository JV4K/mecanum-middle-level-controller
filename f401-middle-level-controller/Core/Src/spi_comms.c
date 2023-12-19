/*
 * spi_comms.c
 *
 *  Created on: Dec 15, 2023
 *      Author: zhmis
 */

#include "spi_comms.h"

/* Master methods ---------------------------------------------------------*/
void master_reset_miso_packet(miso_packet_t *packet) {
	miso_packet_t empty_packet = { { 0, 0, 0 }, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
			0 };
	memcpy(packet, &empty_packet, 32);
}

void master_crc_packet(mosi_packet_t *packet) {
	uint32_t crc_check = HAL_CRC_Calculate(&hcrc, (uint32_t*) packet, 7);
	packet->crc_res = crc_check;
}

uint8_t master_verify_miso_packet(miso_packet_t *packet) {
	uint32_t crc_check = HAL_CRC_Calculate(&hcrc, (uint32_t*) packet, 7);
	if (packet->crc_res == crc_check) {
		return 1;
	} else {
		return 0;
	}
}

/* Slave methods ---------------------------------------------------------*/
void slave_reset_mosi_packet(mosi_packet_t *packet) {
	mosi_packet_t empty_packet = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0, 0, 0.0,
			0.0, 0.0, 0.0, 0 };
	memcpy(packet, &empty_packet, 32);
}
void slave_crc_packet(miso_packet_t *packet) {
	uint32_t crc_check = HAL_CRC_Calculate(&hcrc, (uint32_t*) packet, 7);
	packet->crc_res = crc_check;
}
uint8_t slave_verify_mosi_packet(mosi_packet_t *packet) {
	uint32_t crc_check = HAL_CRC_Calculate(&hcrc, (uint32_t*) packet, 7);
	if (packet->crc_res == crc_check) {
		return 1;
	} else {
		return 0;
	}
}
