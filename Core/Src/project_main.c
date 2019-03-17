/* ==========================================================
 * project_main.c - 
 * Project : Disk91 SDK
 * ----------------------------------------------------------
 * Created on: 6 sept. 2018
 *     Author: Paul Pinault aka Disk91
 * ----------------------------------------------------------
 * Copyright (C) 2018 Disk91
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU LESSER General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * ----------------------------------------------------------
 * 
 * Add a such file in the main Src directory for executing
 * you own workload.
 *
 * ==========================================================
 */
#include <it_sdk/config.h>
#include <it_sdk/itsdk.h>
#include <it_sdk/time/time.h>
#include <it_sdk/logger/logger.h>
#include <it_sdk/lorawan/lorawan.h>
#include <it_sdk/encrypt/encrypt.h>
#include <it_sdk/sched/scheduler.h>


void taskLed() {
	gpio_toggle(__BANK_H,__LP_GPIO_1);
}

void taskLora() {
	if ( !itsdk_lorawan_hasjoined() ) {
		log_info("Connecting\r\n");
		itsdk_lorawan_join_sync();
	} else {
		log_info("Firing message\r\n");
		uint8_t frBuffer[10] = { 0,1,2,3,4,5,6,7,8,9 };
		uint8_t rPort;
		uint8_t rSize;
		uint8_t rData[16];
		itsdk_lorawan_send_sync(
					frBuffer,			// payload buffer
					10,					// payload size
					1,					// Port
					__LORAWAN_DR_5,		// speed
					LORAWAN_SEND_UNCONFIRMED,
					1,					// retry (not applicable for unconfirmed communications)
					&rPort,				// downlink port
					&rSize,				// downlink size
					rData,				// downlink data
					/*PAYLOAD_ENCRYPT_AESCTR | PAYLOAD_ENCRYPT_SPECK |*/ PAYLOAD_ENCRYPT_NONE
		);
	}
}


void project_setup() {
	log_info("Booting \r\n");

	static itsdk_lorawan_channelInit_t channels= ITSDK_LORAWAN_CHANNEL;
	#ifdef ITSDK_LORAWAN_CHANNEL
		itsdk_lorawan_setup(__LORAWAN_REGION_EU868,&channels);
	#else
		itsdk_lorawan_setup(__LORAWAN_REGION_EU868,NULL);
	#endif

	itdt_sched_registerSched(30000,ITSDK_SCHED_CONF_IMMEDIATE, &taskLora);
	itdt_sched_registerSched(1000,ITSDK_SCHED_CONF_IMMEDIATE, &taskLed);

}

void project_loop() {
	itsdk_lorawan_loop();
}

