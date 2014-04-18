/*
 * gps.h
 *
 *  Created on: Apr 16, 2014
 *      Author: Hans
 */

#ifndef GPS_H_
#define GPS_H_

//*****************************************************************************
//
// Globally defined constants
//
//*****************************************************************************
#define NMEA_MSG_GGA 0
#define NMEA_MSG_GLL 1
#define NMEA_MSG_GSA 2
#define NMEA_MSG_GSV 3
#define NMEA_MSG_RMC 4

//*****************************************************************************
//
// Structure typedef to make storing application state data simpler.
//
//*****************************************************************************
typedef struct
{
	uint8_t ui8CharRcvCnt;  // Counter for received chars

	uint8_t ui8IntervalSec; // Timer loop for querying GPS

	uint8_t ui8InitState;  // Has GPS been initialized?
	int8_t i8OnOff; // On = 1; Off = 0; Unknown = -1
	uint8_t i8SatelliteFix; // Does GPS has satellite fix?

}tGpsState;

//*****************************************************************************
//
// Global variables originally defined in gps.c that are made available to
// functions in other files.
//
//*****************************************************************************
extern tGpsState g_sGpsState;

//*****************************************************************************
//
// Functions defined in gps.c that are made available to other files.
//
//*****************************************************************************
extern void InitGPS(void);
extern void ToggleGPS(void);
extern void ProcessReceivedNMEA(char *nmeaSentence);
extern void QueryGPS(uint8_t ui8MsgSelect);

#endif /* GPS_H_ */
