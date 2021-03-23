/* =====================================================================================================================
 * data.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines data structure
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef data_h_INCLUDED
#define data_h_INCLUDED

struct Data {
	volatile unsigned int nLoops;
	volatile double counter;
	int schedPolicy;
		
};

#endif
