
/**
  ******************************************************************************
  * @file    rfal_chip.h
  * @author  MMY Application Team
  * @brief   RFAL Hardware Abstraction Layer
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


#ifndef RFAL_CHIP_H
#define RFAL_CHIP_H

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "rfal_platform.h"
#include "rfal_utils.h"
#include "rfal_rf.h"


/*****************************************************************************
 *  RF Chip                                                                  *  
 *****************************************************************************/

/*!
 *****************************************************************************
 * \brief Writes a register on the RF Chip
 *
 * Checks if the given register is valid and if so, writes the value(s)
 * on the RF Chip register
 * 
 * \param[in] reg    : register address to be written, or the first if len > 1
 * \param[in] values : pointer with content to be written on the register(s)
 * \param[in] len    : number of consecutive registers to be written
 *  
 * 
 * \return RFAL_ERR_PARAM    : Invalid register or bad request
 * \return RFAL_ERR_NOTSUPP  : Feature not supported
 * \return RFAL_ERR_NONE     : Write done with no error
 *****************************************************************************
 */
ReturnCode rfalChipWriteReg( uint16_t reg, const uint8_t* values, uint8_t len );

/*!
 *****************************************************************************
 * \brief Reads a register on the RF Chip
 *
 * Checks if the given register is valid and if so, reads the value(s)
 * of the RF Chip register(s)
 * 
 * \param[in]  reg    : register address to be read, or the first if len > 1
 * \param[out] values : pointer where the register(s) read content will be placed 
 * \param[in]  len    : number of consecutive registers to be read  
 * 
 * \return RFAL_ERR_PARAM    : Invalid register or bad request
 * \return RFAL_ERR_NOTSUPP  : Feature not supported
 * \return RFAL_ERR_NONE     : Read done with no error
 *****************************************************************************
 */
ReturnCode rfalChipReadReg( uint16_t reg, uint8_t* values, uint8_t len );

/*!
 *****************************************************************************
 * \brief Change a register on the RF Chip
 *
 * Change the value of the register bits on the RF Chip Test set in the valueMask. 
 * 
 * \param[in] reg       : register address to be modified
 * \param[in] valueMask : mask value of the register bits to be changed
 * \param[in] value     : register value to be set
 * 
 * \return RFAL_ERR_PARAM    : Invalid register or bad request
 * \return RFAL_ERR_NOTSUPP  : Feature not supported
 * \return RFAL_ERR_OK       : Change done with no error
 *****************************************************************************
 */
ReturnCode rfalChipChangeRegBits( uint16_t reg, uint8_t valueMask, uint8_t value );

/*!
 *****************************************************************************
 * \brief Writes a Test register on the RF Chip
 *
 * Writes the value on the RF Chip Test register
 * 
 * \param[in] reg   : register address to be written
 * \param[in] value : value to be written on the register
 *  
 * 
 * \return RFAL_ERR_PARAM    : Invalid register or bad request
 * \return RFAL_ERR_NOTSUPP  : Feature not supported
 * \return RFAL_ERR_NONE     : Write done with no error
 *****************************************************************************
 */
ReturnCode rfalChipWriteTestReg( uint16_t reg, uint8_t value );

/*!
 *****************************************************************************
 * \brief Reads a Test register on the RF Chip
 *
 * Reads the value of the RF Chip Test register
 * 
 * \param[in]  reg   : register address to be read
 * \param[out] value : pointer where the register content will be placed  
 * 
 * \return RFAL_ERR_PARAM    :Invalid register or bad request
 * \return RFAL_ERR_NOTSUPP  : Feature not supported
 * \return RFAL_ERR_NONE     : Read done with no error
 *****************************************************************************
 */
ReturnCode rfalChipReadTestReg( uint16_t reg, uint8_t* value );

/*!
 *****************************************************************************
 * \brief Change a Test register on the RF Chip
 *
 * Change the value of the register bits on the RF Chip Test set in the valueMask. 
 * 
 * \param[in] reg       : test register address to be modified
 * \param[in] valueMask : mask value of the register bits to be changed
 * \param[in] value     : register value to be set
 * 
 * \return RFAL_ERR_PARAM     : Invalid register or bad request
 * \return RFAL_ERR_NOTSUPP   : Feature not supported
 * \return RFAL_ERR_OK        : Change done with no error
 *****************************************************************************
 */
ReturnCode rfalChipChangeTestRegBits( uint16_t reg, uint8_t valueMask, uint8_t value );

/*!
 *****************************************************************************
 * \brief Execute command on the RF Chip
 *
 * Checks if the given command is valid and if so, executes it on 
 * the RF Chip
 * 
 * \param[in] cmd : direct command to be executed
 * 
 * \return RFAL_ERR_PARAM     : Invalid command or bad request
 * \return RFAL_ERR_NOTSUPP   : Feature not supported
 * \return RFAL_ERR_NONE      : Direct command executed with no error
 *****************************************************************************
 */
ReturnCode rfalChipExecCmd( uint16_t cmd );

/*! 
 *****************************************************************************
 * \brief  Set RFO
 *
 * Sets the RFO value to be used when the field is on (unmodulated/active)
 * 
 * \param[in] rfo : the RFO value to be used
 *
 * \return  RFAL_ERR_IO           : Internal error
 * \return  RFAL_ERR_NOTSUPP      : Feature not supported
 * \return  RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalChipSetRFO( uint8_t rfo );


/*! 
 *****************************************************************************
 * \brief  Get RFO
 *
 * Gets the RFO value used used when the field is on (unmodulated/active)
 *
 * \param[out] result : the current RFO value 
 *
 * \return  RFAL_ERR_IO           : Internal error
 * \return  RFAL_ERR_NOTSUPP      : Feature not supported
 * \return  RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalChipGetRFO( uint8_t* result );


/*! 
 *****************************************************************************
 * \brief  Measure Amplitude
 *
 * Measures the RF Amplitude
 *
 * \param[out] result : result of RF measurement
 *
 * \return  RFAL_ERR_IO           : Internal error
 * \return  RFAL_ERR_NOTSUPP      : Feature not supported
 * \return  RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalChipMeasureAmplitude( uint8_t* result );


/*! 
 *****************************************************************************
 * \brief  Measure Phase
 *
 * Measures the Phase
 *
 * \param[out] result : result of Phase measurement
 *
 * \return  RFAL_ERR_IO           : Internal error
 * \return  RFAL_ERR_NOTSUPP      : Feature not supported
 * \return  RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalChipMeasurePhase( uint8_t* result );


/*! 
 *****************************************************************************
 * \brief  Measure Capacitance
 *
 * Measures the Capacitance
 *
 * \param[out] result : result of Capacitance measurement
 *
 * \return  RFAL_ERR_IO      : Internal error
 * \return  RFAL_ERR_NOTSUPP : Feature not supported
 * \return  RFAL_ERR_NONE    : No error
 *****************************************************************************
 */
ReturnCode rfalChipMeasureCapacitance( uint8_t* result );


/*! 
 *****************************************************************************
 * \brief  Measure Power Supply
 *
 * Measures the Power Supply
 *
 * \param[in]  param  : measurement parameter (chip specific)
 * \param[out] result : result of the measurement
 *
 * \return  RFAL_ERR_IO      : Internal error
 * \return  RFAL_ERR_NOTSUPP : Feature not supported
 * \return  RFAL_ERR_NONE    : No error
 *****************************************************************************
 */
ReturnCode rfalChipMeasurePowerSupply( uint8_t param, uint8_t* result );


/*! 
 *****************************************************************************
 * \brief  Measure I and Q
 *
 * Measures I and Q channels
 *
 *  \param[out] resI : 8 bit long result of the I channel (signed)
 *  \param[out] resQ : 8 bit long result of the Q channel (signed)
 *
 * \return  RFAL_ERR_IO      : Internal error
 * \return  RFAL_ERR_NOTSUPP : Feature not supported
 * \return  RFAL_ERR_NONE    : No error
 *****************************************************************************
 */
ReturnCode rfalChipMeasureIQ( int8_t* resI, int8_t* resQ );


/*! 
 *****************************************************************************
 * \brief  Measure combined I and Q
 *
 * Measures I and Q channels and combines them
 *
 *  \param[out] result : I and Q combined
 *
 * \return  RFAL_ERR_IO      : Internal error
 * \return  RFAL_ERR_NOTSUPP : Feature not supported
 * \return  RFAL_ERR_NONE    : No error
 *****************************************************************************
 */
ReturnCode rfalChipMeasureCombinedIQ( uint8_t* result );


/*! 
 *****************************************************************************
 * \brief  Set Antenna mode
 *
 * Sets the antenna mode. 
 * Differential or single ended antenna mode (RFO1 or RFO2)
 *
 *  \param[in]   single : FALSE differential ; single ended mode
 *  \param[in]    rfiox : FALSE   RFI1/RFO1  ; TRUE   RFI2/RFO2
 *
 * \return  RFAL_ERR_IO      : Internal error
 * \return  RFAL_ERR_NOTSUPP : Feature not supported
 * \return  RFAL_ERR_NONE    : No error
 *****************************************************************************
 */
ReturnCode rfalChipSetAntennaMode( bool single, bool rfiox );

#endif /* RFAL_CHIP_H */

/**
  * @}
  *
  * @}
  *
  * @}
  */
