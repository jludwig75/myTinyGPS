/*
 * TinyGPS_test.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: jludwig
 */
#include "TinyGPS.h"
#include <stdio.h>


void dump_gps_data(TinyGPS &gps)
{
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    printf("LAT=");
    printf("%0.6f", flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat);
    printf(" LON=");
    printf("%0.6f", flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon);
    printf(" SAT=");
    printf("%u", gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
    printf(" PREC=");
    printf("%lu", gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
    printf("\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "You must specify an NMEA log file\n");
		return -1;
	}
	TinyGPS gps;

	FILE *fp = fopen(argv[1], "r");
	while (!feof(fp))
	{
		char c = fgetc(fp);
		//printf("%c", c); fflush(stdout);
		if (gps.encode(c))
		{
			dump_gps_data(gps);
		}
	}
	fclose(fp);

	return 0;
}
