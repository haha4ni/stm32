
/**
  ******************************************************************************
  * @file    rfal_st25xv.h
  * @author  MMY Application Team
  * @brief   NFC-V ST25 NFC-V Tag specific features
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

#ifndef RFAL_ST25xV_H
#define RFAL_ST25xV_H

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include "rfal_platform.h"
#include "rfal_utils.h"
#include "rfal_nfc.h"
#include "rfal_rf.h"

/*
 ******************************************************************************
 * GLOBAL DEFINES
 ******************************************************************************
 */

 
#define RFAL_NFCV_BLOCKNUM_M24LR_LEN                     2U      /*!< Block Number length of MR24LR tags: 16 bits                */
#define RFAL_NFCV_ST_IC_MFG_CODE                         0x02    /*!< ST IC Mfg code (used for custom commands)                  */

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Read Single Block (M24LR)
 *  
 * Reads a Single Block from a M24LR tag which has the number of blocks 
 * bigger than 256 (M24LR16 ; M24LR64)
 *
 * \param[in]  flags        : Flags to be used: Sub-carrier; Data_rate; Option
 *                            default: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid          : UID of the device to be put to be read
 *                             if not provided Select mode will be used 
 * \param[in]  blockNum     : Number of the block to read (16 bits)
 * \param[out] rxBuf        : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen     : length of rxBuf
 * \param[out] rcvLen       : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerM24LRReadSingleBlock( uint8_t flags, const uint8_t* uid, uint16_t blockNum, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Single Block (M24LR)
 *  
 * Reads a Single Block from a M24LR tag which has the number of blocks 
 * bigger than 256 (M24LR16 ; M24LR64) using ST Fast mode
 *
 * \param[in]  flags        : Flags to be used: Sub-carrier; Data_rate; Option
 *                            default: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid          : UID of the device to be put to be read
 *                             if not provided Select mode will be used 
 * \param[in]  blockNum     : Number of the block to read (16 bits)
 * \param[out] rxBuf        : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen     : length of rxBuf
 * \param[out] rcvLen       : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerM24LRFastReadSingleBlock( uint8_t flags, const uint8_t* uid, uint16_t blockNum, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Write Single Block (M24LR)
 *  
 * Writes a Single Block from a M24LR tag which has the number of blocks 
 * bigger than 256 (M24LR16 ; M24LR64)
 *
 * \param[in]  flags        : Flags to be used: Sub-carrier; Data_rate; Option
 *                            for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid          : UID of the device to be put to be written
 *                             if not provided Select mode will be used 
 * \param[in]  blockNum     : Number of the block to write (16 bits)
 * \param[in]  wrData       : data to be written on the given block
 * \param[in]  blockLen     : number of bytes of a block
 *  
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerM24LRWriteSingleBlock( uint8_t flags, const uint8_t* uid, uint16_t blockNum, const uint8_t* wrData, uint8_t blockLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Read Multiple Blocks (M24LR)
 *  
 * Reads Multiple Blocks from a device from a M24LR tag which has the number of blocks 
 * bigger than 256 (M24LR16 ; M24LR64)  
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  firstBlockNum  : first block to be read (16 bits)
 * \param[in]  numOfBlocks    : number of block to read
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerM24LRReadMultipleBlocks( uint8_t flags, const uint8_t* uid, uint16_t firstBlockNum, uint8_t numOfBlocks, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );


/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Multiple Blocks (M24LR)
 *  
 * Reads Multiple Blocks from a device from a M24LR tag which has the number of blocks 
 * bigger than 256 (M24LR16 ; M24LR64) using ST Fast mode
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  firstBlockNum  : first block to be read (16 bits)
 * \param[in]  numOfBlocks    : number of block to read
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerM24LRFastReadMultipleBlocks( uint8_t flags, const uint8_t* uid, uint16_t firstBlockNum, uint8_t numOfBlocks, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Single Block
 *  
 * Reads a Single Block from a device (VICC) using ST Fast mode
 *
 * \param[in]  flags        : Flags to be used: Sub-carrier; Data_rate; Option
 *                            for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid          : UID of the device to be put to be read
 *                             if not provided Select mode will be used 
 * \param[in]  blockNum     : Number of the block to read
 * \param[out] rxBuf        : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen     : length of rxBuf
 * \param[out] rcvLen       : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastReadSingleBlock( uint8_t flags, const uint8_t* uid, uint8_t blockNum, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Multiple Blocks
 *  
 * Reads Multiple Blocks from a device (VICC) using ST Fast mode
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  firstBlockNum  : first block to be read
 * \param[in]  numOfBlocks    : number of block to read
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastReadMultipleBlocks( uint8_t flags, const uint8_t* uid, uint8_t firstBlockNum, uint8_t numOfBlocks, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Extended Read Single Block
 *  
 * Reads a Single Block from a device (VICC) supporting extended commands using ST Fast mode
 *
 * \param[in]  flags        : Flags to be used: Sub-carrier; Data_rate; Option
 *                            for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid          : UID of the device to be put to be read
 *                             if not provided Select mode will be used 
 * \param[in]  blockNum     : Number of the block to read (16 bits)
 * \param[out] rxBuf        : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen     : length of rxBuf
 * \param[out] rcvLen       : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastExtendedReadSingleBlock( uint8_t flags, const uint8_t* uid, uint16_t blockNum, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Extended Read Multiple Blocks
 *  
 * Reads Multiple Blocks from a device (VICC) supporting extended commands using ST Fast mode
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  firstBlockNum  : first block to be read (16 bits)
 * \param[in]  numOfBlocks    : number of consecutive blocks to read (16 bits)
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastExtReadMultipleBlocks( uint8_t flags, const uint8_t* uid, uint16_t firstBlockNum, uint16_t numOfBlocks, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Read Configuration
 *  
 * Reads static configuration registers at the Pointer address
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pointer        : Pointer address
 * \param[out] regValue       : Register value
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerReadConfiguration( uint8_t flags, const uint8_t* uid, uint8_t pointer, uint8_t* regValue );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Write Configuration
 *  
 * Writes static configuration registers at the Pointer address
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pointer        : Pointer address
 * \param[in]  regValue       : Register value
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerWriteConfiguration( uint8_t flags, const uint8_t* uid, uint8_t pointer, uint8_t regValue );


/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Read Dynamic Configuration
 *  
 * Reads dynamic registers at the Pointer address
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pointer        : Pointer address
 * \param[out] regValue       : Register value
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerReadDynamicConfiguration( uint8_t flags, const uint8_t* uid, uint8_t pointer, uint8_t* regValue );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Write Dynamic Configuration
 *  
 * Writes dynamic registers at the Pointer address
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pointer        : Pointer address
 * \param[in]  regValue       : Register value
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerWriteDynamicConfiguration( uint8_t flags, const uint8_t* uid, uint8_t pointer, uint8_t regValue );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Dynamic Configuration
 *  
 * Reads dynamic registers at the Pointer address using ST Fast mode
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pointer        : Pointer address
 * \param[out] regValue       : Register value
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastReadDynamicConfiguration( uint8_t flags, const uint8_t* uid, uint8_t pointer, uint8_t* regValue );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Write Dynamic Configuration
 *  
 * Writes dynamic registers at the Pointer address using ST Fast mode
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pointer        : Pointer address
 * \param[in]  regValue       : Register value
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastWriteDynamicConfiguration( uint8_t flags, const uint8_t* uid, uint8_t pointer, uint8_t regValue );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Present Password
 *  
 * Sends the Present Password command
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pwdNum         : Password number
 * \param[in]  pwd            : Password
 * \param[in]  pwdLen         : Password length
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerPresentPassword( uint8_t flags, const uint8_t* uid, uint8_t pwdNum, const uint8_t* pwd, uint8_t pwdLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Write Password
 *  
 * Sends the Write Password command
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  pwdNum         : Password number
 * \param[in]  pwd            : Password
 * \param[in]  pwdLen         : Password length
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerWritePassword( uint8_t flags, const uint8_t* uid, uint8_t pwdNum, const uint8_t *pwd,  uint8_t pwdLen);

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Get Random Number
 *  
 *  Returns a 16 bit random number
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerGetRandomNumber( uint8_t flags, const uint8_t* uid, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Read Message length
 *  
 * Sends a Read Message Length message to retrieve the value of MB_LEN_Dyn 
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[out] msgLen         : Message Length
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerReadMessageLength( uint8_t flags, const uint8_t* uid, uint8_t* msgLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Message length
 *  
 * Sends a Fast Read Message Length message to retrieve the value of MB_LEN_Dyn using ST Fast mode.
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[out] msgLen         : Message Length
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastReadMsgLength( uint8_t flags, const uint8_t* uid, uint8_t* msgLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Read Message
 *  
 * Reads up to 256 bytes in the Mailbox from the location
 * specified by MBpointer and sends back their value in the rxBuf response.
 * First MailBox location is '00'. When Number of bytes is set to 00h 
 * and MBPointer is equals to 00h, the MB_LEN bytes of the full message 
 * are returned. Otherwise, Read Message command returns (Number of Bytes + 1) bytes 
 * (i.e. 01h returns 2 bytes, FFh returns 256 bytes).
 * An error is reported if (Pointer + Nb of bytes + 1) is greater than the message length. 
 * RF Reading of the last byte of the mailbox message automatically clears b1 
 * of MB_CTRL_Dyn HOST_PUT_MSG, and allows RF to put a new message.
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  mbPointer      : MPpointer
 * \param[in]  numBytes       : number of bytes
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerReadMessage( uint8_t flags, const uint8_t* uid, uint8_t mbPointer, uint8_t numBytes, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Read Message
 *  
 * Reads up to 256 bytes in the Mailbox from the location
 * specified by MBpointer and sends back their value in the rxBuf response using ST Fast mode.
 * First MailBox location is '00'. When Number of bytes is set to 00h 
 * and MBPointer is equals to 00h, the MB_LEN bytes of the full message 
 * are returned. Otherwise, Read Message command returns (Number of Bytes + 1) bytes 
 * (i.e. 01h returns 2 bytes, FFh returns 256 bytes).
 * An error is reported if (Pointer + Nb of bytes + 1) is greater than the message length. 
 * RF Reading of the last byte of the mailbox message automatically clears b1 
 * of MB_CTRL_Dyn  HOST_PUT_MSG, and allows RF to put a new message.
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  mbPointer      : MPpointer
 * \param[in]  numBytes       : number of bytes
 * \param[out] rxBuf          : buffer to store response (also with RES_FLAGS)
 * \param[in]  rxBufLen       : length of rxBuf
 * \param[out] rcvLen         : number of bytes received
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastReadMessage( uint8_t flags, const uint8_t* uid, uint8_t mbPointer, uint8_t numBytes, uint8_t* rxBuf, uint16_t rxBufLen, uint16_t *rcvLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Write Message
 *  
 * Sends Write message Command
 *
 * On receiving the Write Message command, the ST25DVxxx puts the data contained 
 * in the request into the Mailbox buffer, update the MB_LEN_Dyn register, and 
 * set bit RF_PUT_MSG in MB_CTRL_Dyn register. It then reports if the write operation was successful 
 * in the response. The ST25DVxxx Mailbox contains up to 256 data bytes which are filled from the
 *  first location '00'. MSGlength parameter of the command is the number of 
 * Data bytes minus 1 (00 for 1 byte of data, FFh for 256 bytes of data). 
 * Write Message could be executed only when Mailbox is accessible by RF.
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  msgLen         : MSGLen  number of Data bytes minus 1
 * \param[in]  msgData        : Message Data
 * \param[out] txBuf          : buffer to used to build the Write Message command 
 * \param[in]  txBufLen       : length of txBuf
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerWriteMessage( uint8_t flags, const uint8_t* uid, uint8_t msgLen, const uint8_t* msgData, uint8_t* txBuf, uint16_t txBufLen );

/*! 
 *****************************************************************************
 * \brief  NFC-V Poller Fast Write Message
 *  
 * Sends Fast Write message Command using ST Fast mode
 * 
 * On receiving the Write Message command, the ST25DVxxx puts the data contained 
 * in the request into the Mailbox buffer, update the MB_LEN_Dyn register, and 
 * set bit RF_PUT_MSG in MB_CTRL_Dyn register. It then reports if the write operation was successful 
 * in the response. The ST25DVxxx Mailbox contains up to 256 data bytes which are filled from the
 *  first location '00'. MSGlength parameter of the command is the number of 
 * Data bytes minus 1 (00 for 1 byte of data, FFh for 256 bytes of data). 
 * Write Message could be executed only when Mailbox is accessible by RF.
 *
 * \param[in]  flags          : Flags to be used: Sub-carrier; Data_rate; Option
 *                              for NFC-Forum use: RFAL_NFCV_REQ_FLAG_DEFAULT
 * \param[in]  uid            : UID of the device to be put to be read
 *                               if not provided Select mode will be used 
 * \param[in]  msgLen         : MSGLen  number of Data bytes minus 1
 * \param[in]  msgData        : Message Data
 * \param[out] txBuf          : buffer to used to build the Write Message command 
 * \param[in]  txBufLen       : length of txBuf
 *  
 * \return RFAL_ERR_WRONG_STATE    : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM          : Invalid parameters
 * \return RFAL_ERR_IO             : Generic internal error 
 * \return RFAL_ERR_CRC            : CRC error detected
 * \return RFAL_ERR_FRAMING        : Framing error detected
 * \return RFAL_ERR_PROTO          : Protocol error detected
 * \return RFAL_ERR_TIMEOUT        : Timeout error
 * \return RFAL_ERR_NONE           : No error
 *****************************************************************************
 */
ReturnCode rfalST25xVPollerFastWriteMessage( uint8_t flags, const uint8_t* uid, uint8_t msgLen, const uint8_t* msgData, uint8_t* txBuf, uint16_t txBufLen );

#endif /* RFAL_ST25xV_H */

/**
  * @}
  *
  * @}
  *
  * @}
  */

