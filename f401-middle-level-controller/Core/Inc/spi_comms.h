/*
 * master_comms.h
 *
 *  Created on: Dec 14, 2023
 *      Author: zhmis
 */

#ifndef INC_SPI_COMMS_H_
#define INC_SPI_COMMS_H_

#include "main.h"
#include <stdlib.h>
#include <string.h>
#include "crc.h"

/* MOSI packet struct ---------------------------------------------------------*/
typedef struct {
	// Dummy bytes in order to match slave packet length
	uint8_t dummy[10];

	// MODE register bytes
	uint8_t mode;
	uint8_t valid_packet_timeout;

	// Position references
	float angle_reference1;
	float angle_reference2;

	// Angular velocity cap
	float velocity_cap1;
	float velocity_cap2;

	// CRC
	uint32_t crc_res;

// Add packed attribute to ensure no padding included in a structure data representation
} __attribute__((packed)) mosi_packet_t;

/* MISO packet struct ---------------------------------------------------------*/
typedef struct {
	// Dummy bytes in order to match a word length (needed for crc)
	uint8_t dummy[3];

	// STATUS register bytes
	uint8_t status;

	// Position feedbacks
	float angle_feedback1;
	float angle_feedback2;

	// Angular velocity feedbacks
	float velocity_feedback1;
	float velocity_feedback2;

	// Current feedbacks
	float current_feedback1;
	float current_feedback2;

	// CRC
	uint32_t crc_res;

// Add packed attribute to ensure no padding included in a structure data representation
} __attribute__((packed)) miso_packet_t;

/* Master methods ---------------------------------------------------------*/
void master_reset_miso_packet(miso_packet_t*);
void master_crc_packet(mosi_packet_t*);
uint8_t master_verify_miso_packet(miso_packet_t*);

/* Slave methods ---------------------------------------------------------*/
void slave_reset_mosi_packet(mosi_packet_t*);
void slave_crc_packet(miso_packet_t*);
uint8_t slave_verify_mosi_packet(mosi_packet_t*);

#endif /* INC_SPI_COMMS_H_ */
