
/**
  ******************************************************************************
  * @file    rfal_nfcf.h
  * @author  MMY Application Team
  * @brief   Implementation of NFC-F Poller (FeliCa PCD) device
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


#ifndef RFAL_NFCF_H
#define RFAL_NFCF_H

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include "rfal_platform.h"
#include "rfal_utils.h"
#include "rfal_rf.h"

/*
 ******************************************************************************
 * GLOBAL DEFINES
 ******************************************************************************
 */

#define RFAL_NFCF_NFCID2_LEN                    8U       /*!< NFCID2 (FeliCa IDm) length                        */
#define RFAL_NFCF_SENSF_RES_LEN_MIN             16U      /*!< SENSF_RES minimum length                          */
#define RFAL_NFCF_SENSF_RES_LEN_MAX             18U      /*!< SENSF_RES maximum length                          */
#define RFAL_NFCF_SENSF_RES_PAD0_LEN            2U       /*!< SENSF_RES PAD0 length                             */
#define RFAL_NFCF_SENSF_RES_PAD1_LEN            3U       /*!< SENSF_RES PAD1 length                             */
#define RFAL_NFCF_SENSF_RES_RD_LEN              2U       /*!< SENSF_RES Request Data length                     */
#define RFAL_NFCF_SENSF_RES_BYTE1               1U       /*!< SENSF_RES first byte value                        */
#define RFAL_NFCF_SENSF_SC_LEN                  2U       /*!< Felica SENSF_REQ System Code length               */
#define RFAL_NFCF_SENSF_PARAMS_SC1_POS          0U       /*!< System Code byte1 position in the SENSF_REQ       */
#define RFAL_NFCF_SENSF_PARAMS_SC2_POS          1U       /*!< System Code byte2 position in the SENSF_REQ       */
#define RFAL_NFCF_SENSF_PARAMS_RC_POS           2U       /*!< Request Code position in the SENSF_REQ            */
#define RFAL_NFCF_SENSF_PARAMS_TSN_POS          3U       /*!< Time Slot Number position in the SENSF_REQ        */
#define RFAL_NFCF_POLL_MAXCARDS                 16U      /*!< Max number slots/cards 16                         */


#define RFAL_NFCF_CMD_POS                        0U      /*!< Command/Responce code length                      */
#define RFAL_NFCF_CMD_LEN                        1U      /*!< Command/Responce code length                      */
#define RFAL_NFCF_LENGTH_LEN                     1U      /*!< LEN field length                                  */
#define RFAL_NFCF_HEADER_LEN                     (RFAL_NFCF_LENGTH_LEN + RFAL_NFCF_CMD_LEN) /*!< Header length  */

#define RFAL_NFCF_NOS_LEN                        1U      /*!< Number of Services length                         */
#define RFAL_NFCF_NOB_LEN                        1U      /*!< Number of Blocks length                           */


#define RFAL_NFCF_SENSF_NFCID2_BYTE1_POS         0U      /*!< NFCID2 byte1 position                             */
#define RFAL_NFCF_SENSF_NFCID2_BYTE2_POS         1U      /*!< NFCID2 byte2 position                             */

#define RFAL_NFCF_SENSF_NFCID2_PROT_TYPE_LEN     2U      /*!< NFCID2 length for byte 1 and byte 2 indicating NFC-DEP or T3T support */
#define RFAL_NFCF_SENSF_NFCID2_BYTE1_NFCDEP      0x01U   /*!< NFCID2 byte1 NFC-DEP support            Digital 1.0 Table 44 */
#define RFAL_NFCF_SENSF_NFCID2_BYTE2_NFCDEP      0xFEU   /*!< NFCID2 byte2 NFC-DEP support            Digital 1.0 Table 44 */

#define RFAL_NFCF_SYSTEMCODE                     0xFFFFU /*!< SENSF_RES Default System Code            Digital 2.3 8.6.1.5 */
#define RFAL_NFCF_SYSTEMCODE_LEN                 2U      /*!< SENSF_RES System Code length             Digital 2.3 8.6.1   */

#define RFAL_NFCF_BLOCK_LEN                      16U     /*!< NFCF T3T Block size                        T3T 1.0  4.1      */
#define RFAL_NFCF_CHECKUPDATE_RES_ST1_POS        9U      /*!< Check|Update Res Status Flag 1 position    T3T 1.0  Table 8  */
#define RFAL_NFCF_CHECKUPDATE_RES_ST2_POS        10U     /*!< Check|Update Res Status Flag 2 position    T3T 1.0  Table 8  */
#define RFAL_NFCF_CHECKUPDATE_RES_NOB_POS        11U     /*!< Check|Update Res Number of Blocks position T3T 1.0  Table 8  */

#define RFAL_NFCF_STATUS_FLAG_SUCCESS            0x00U   /*!< Check response Number of Blocks position   T3T 1.0  Table 11 */
#define RFAL_NFCF_STATUS_FLAG_ERROR              0xFFU   /*!< Check response Number of Blocks position   T3T 1.0  Table 11 */

#define RFAL_NFCF_BLOCKLISTELEM_MAX_LEN          3U      /*!< Block List Element max Length (3 bytes)        T3T 1.0 5.6.1 */
#define RFAL_NFCF_BLOCKLISTELEM_LEN_BIT          0x80U   /*!< Block List Element Length bit (2|3 bytes)      T3T 1.0 5.6.1 */

#define RFAL_NFCF_SERVICECODE_RDONLY             0x000BU /*!< NDEF Service Code as Read-Only                 T3T 1.0 7.2.1 */
#define RFAL_NFCF_SERVICECODE_RDWR               0x0009U /*!< NDEF Service Code as Read and Write            T3T 1.0 7.2.1 */

#define RFAL_NFCF_TEST_LB_CMD0                   0xD8U /*!< T3T loopback CMD0                 ETSI TS 102 695-1  5.6.4.4.2 */
#define RFAL_NFCF_TEST_LB_CMD1                   0x00U /*!< T3T loopback CMD1                 ETSI TS 102 695-1  5.6.4.4.2 */


/*! NFC-F Felica command set   JIS X6319-4  9.1 */
enum 
{
    RFAL_NFCF_CMD_POLLING                      = 0x00, /*!< SENSF_REQ (Felica Poll/REQC command to identify a card )       */
    RFAL_NFCF_CMD_POLLING_RES                  = 0x01, /*!< SENSF_RES (Felica Poll/REQC command response )                 */
    RFAL_NFCF_CMD_REQUEST_SERVICE              = 0x02, /*!< verify the existence of Area and Service                       */
    RFAL_NFCF_CMD_REQUEST_RESPONSE             = 0x04, /*!< verify the existence of a card                                 */
    RFAL_NFCF_CMD_READ_WITHOUT_ENCRYPTION      = 0x06, /*!< read Block Data from a Service that requires no authentication */
    RFAL_NFCF_CMD_READ_WITHOUT_ENCRYPTION_RES  = 0x07, /*!< read Block Data response from a Service with no authentication */
    RFAL_NFCF_CMD_WRITE_WITHOUT_ENCRYPTION     = 0x08, /*!< write Block Data to a Service that requires no authentication  */
    RFAL_NFCF_CMD_WRITE_WITHOUT_ENCRYPTION_RES = 0x09, /*!< write Block Data response to a Service with no authentication  */
    RFAL_NFCF_CMD_REQUEST_SYSTEM_CODE          = 0x0c, /*!< acquire the System Code registered to a card                   */
    RFAL_NFCF_CMD_AUTHENTICATION1              = 0x10, /*!< authenticate a card                                            */
    RFAL_NFCF_CMD_AUTHENTICATION2              = 0x12, /*!< allow a card to authenticate a Reader/Writer                   */
    RFAL_NFCF_CMD_READ                         = 0x14, /*!< read Block Data from a Service that requires authentication    */
    RFAL_NFCF_CMD_WRITE                        = 0x16, /*!< write Block Data to a Service that requires authentication     */
};

/*
 ******************************************************************************
 * GLOBAL MACROS
 ******************************************************************************
 */

/*! Checks if the given NFC-F device indicates NFC-DEP support */
#define rfalNfcfIsNfcDepSupported( dev )  ( (((rfalNfcfListenDevice*)(dev))->sensfRes.NFCID2[RFAL_NFCF_SENSF_NFCID2_BYTE1_POS] == RFAL_NFCF_SENSF_NFCID2_BYTE1_NFCDEP) && \
                                            (((rfalNfcfListenDevice*)(dev))->sensfRes.NFCID2[RFAL_NFCF_SENSF_NFCID2_BYTE2_POS] == RFAL_NFCF_SENSF_NFCID2_BYTE2_NFCDEP)    )


/*
******************************************************************************
* GLOBAL TYPES
******************************************************************************
*/


/*! NFC-F SENSF_RES format  Digital 1.1  8.6.2 */
typedef struct 
{
    uint8_t CMD;                                /*!< Command Code: 01h  */
    uint8_t NFCID2[RFAL_NFCF_NFCID2_LEN];       /*!< NFCID2             */
    uint8_t PAD0[RFAL_NFCF_SENSF_RES_PAD0_LEN]; /*!< PAD0               */
    uint8_t PAD1[RFAL_NFCF_SENSF_RES_PAD1_LEN]; /*!< PAD1               */
    uint8_t MRTIcheck;                          /*!< MRTIcheck          */
    uint8_t MRTIupdate;                         /*!< MRTIupdate         */
    uint8_t PAD2;                               /*!< PAD2               */
    uint8_t RD[RFAL_NFCF_SENSF_RES_RD_LEN];     /*!< Request Data       */
} rfalNfcfSensfRes;


/*! NFC-F poller device (PCD) struct  */
typedef struct
{
    uint8_t NFCID2[RFAL_NFCF_NFCID2_LEN];       /*!< NFCID2             */
} rfalNfcfPollDevice;

/*! NFC-F listener device (PICC) struct  */
typedef struct
{
    uint8_t           sensfResLen;              /*!< SENF_RES length    */
    rfalNfcfSensfRes  sensfRes;                 /*!< SENF_RES           */
} rfalNfcfListenDevice;

typedef  uint16_t rfalNfcfServ;                 /*!< NFC-F Service Code */

/*! NFC-F Block List Element (2 or 3 bytes element)       T3T 1.0 5.6.1 */
typedef struct 
{
    uint8_t  conf;             /*!<  Access Mode | Serv Code List Order */
    uint16_t blockNum;         /*!<  Block Number                       */
}rfalNfcfBlockListElem;

/*! Check Update Service list and Block list parameter */
typedef struct 
{
    uint8_t               numServ;              /*!< Number of Services */
    rfalNfcfServ          *servList;            /*!< Service Code List  */
    uint8_t               numBlock;             /*!< Number of Blocks   */
    rfalNfcfBlockListElem *blockList;           /*!< Block Number List  */
}rfalNfcfServBlockListParam;


/*
******************************************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************************************
*/

/*! 
 *****************************************************************************
 * \brief  Initialize NFC-F Poller mode
 *  
 * This methods configures RFAL RF layer to perform as a 
 * NFC-F Poller/RW (FeliCa PCD) including all default timings
 * 
 * \param[in]  bitRate      : NFC-F bitrate to be initialize (212 or 424)
 *
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or mode not set
 * \return RFAL_ERR_PARAM        : Incorrect bitrate
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerInitialize( rfalBitRate bitRate );


/*! 
 *****************************************************************************
 *  \brief NFC-F Poller Check Presence
 *  
 *  This function sends a Poll/SENSF command according to NFC Activity spec
 *  It detects if a NCF-F device is within range
 * 
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error, no listener device detected
 * \return RFAL_ERR_NONE         : No error and some NFC-F device was detected
 *
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerCheckPresence( void );


/*! 
 *****************************************************************************
 *  \brief NFC-F Poller Start Check Presence
 *  
 *  This function triggers a Poll/SENSF command according to NFC Activity spec
 *  It detects if a NCF-F device is within range
 * 
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_NONE         : No error and some NFC-F device was detected
 *
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerStartCheckPresence( void );


/*! 
 *****************************************************************************
 *  \brief NFC-F Poller Get Check Presence Status
 *  
 *  This function gets the status of the Check Presense operation
 *  triggered by rfalNfcfPollerStartCheckPresence()
 * 
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error, no listener device detected
 * \return RFAL_ERR_NONE         : No error and some NFC-F device was detected
 *
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerGetCheckPresenceStatus( void );


/*! 
 *****************************************************************************
 * \brief NFC-F Poller Poll
 * 
 * This function sends to all PICCs in field the POLL command with the given
 * number of slots.
 *
 * \param[in]  slots      : the number of slots to be performed
 * \param[in]  sysCode    : as given in FeliCa poll command  
 * \param[in]  reqCode    : FeliCa communication parameters
 * \param[out] cardList   : Parameter of type rfalFeliCaPollRes which will hold the cards found
 * \param[out] devCnt     : actual number of cards found
 * \param[out] collisions : number of collisions encountered
 *
 * \warning the list cardList has to be as big as the number of slots for the Poll
 *
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or incorrect mode
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error, no listener device detected
 * \return RFAL_ERR_NONE         : No error and some NFC-F device was detected
 *
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerPoll( rfalFeliCaPollSlots slots, uint16_t sysCode, uint8_t reqCode, rfalFeliCaPollRes *cardList, uint8_t *devCnt, uint8_t *collisions );


/*! 
 *****************************************************************************
 * \brief  NFC-F Poller Full Collision Resolution
 *  
 * Performs a full Collision resolution as defined in Activity 1.1  9.3.4
 *
 * \param[in]  compMode    : compliance mode to be performed
 * \param[in]  devLimit    : device limit value, and size nfcaDevList
 * \param[out] nfcfDevList : NFC-F listener devices list
 * \param[out] devCnt      : Devices found counter
 *
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or mode not set
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerCollisionResolution( rfalComplianceMode compMode, uint8_t devLimit, rfalNfcfListenDevice *nfcfDevList, uint8_t *devCnt );


/*! 
 *****************************************************************************
 * \brief  NFC-F Start Poller Collision Resolution
 *  
 * Triggers a Collision Resolution as defined in Activity 2.1  9.3.6
 *
 * \param[in]  compMode    : compliance mode to be performed
 * \param[in]  devLimit    : device limit value, and size nfcaDevList
 * \param[out] nfcfDevList : NFC-F listener devices list
 * \param[out] devCnt      : Devices found counter
 *
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or mode not set
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerStartCollisionResolution( rfalComplianceMode compMode, uint8_t devLimit, rfalNfcfListenDevice *nfcfDevList, uint8_t *devCnt );


/*! 
 *****************************************************************************
 *  \brief NFC-F Poller Get Collision Resolution Status
 *  
 *  This function gets the status of the Collision Resolution operation
 *  triggered by rfalNfcfPollerStartCollisionResolution()
 * 
 * \return RFAL_ERR_IO           : Generic internal error 
 * \return RFAL_ERR_CRC          : CRC error detected
 * \return RFAL_ERR_FRAMING      : Framing error detected
 * \return RFAL_ERR_PROTO        : Protocol error detected
 * \return RFAL_ERR_TIMEOUT      : Timeout error, no listener device detected
 * \return RFAL_ERR_NONE         : No error and some NFC-F device was detected
 *
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerGetCollisionResolutionStatus( void );


/*! 
 *****************************************************************************
 * \brief  NFC-F Poller Check/Read
 *  
 * It computes a Check / Read command accoring to T3T 1.0 and JIS X6319-4 and 
 * sends it to PICC. If sucessfully, the rxBuf will contain the the number of 
 * blocks in the first byte followed by the blocks data.
 *
 * \param[in]  nfcid2      : nfcid2 of the device
 * \param[in]  servBlock   : parameter containing the list of Services and
 *                           Blocks to be addressed by this command
 * \param[out] rxBuf       : buffer to place check/read data 
 * \param[in]  rxBufLen    : size of the rxBuf
 * \param[out] rcvdLen     : length of data placed in rxBuf
 *
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or mode not set
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error
 * \return RFAL_ERR_REQUEST      : The request was executed with error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerCheck( const uint8_t* nfcid2, const rfalNfcfServBlockListParam *servBlock, uint8_t *rxBuf, uint16_t rxBufLen, uint16_t *rcvdLen );


/*! 
 *****************************************************************************
 * \brief  NFC-F Poller Update/Write
 *  
 * It computes a Update / Write command accoring to T3T 1.0 and JIS X6319-4 and 
 * sends it to PICC.
 *
 * \param[in]  nfcid2      : nfcid2 of the device
 * \param[in]  servBlock   : parameter containing the list of Services and
 *                           Blocks to be addressed by this command
 * \param[in]  txBuf       : buffer where the request will be composed
 * \param[in]  txBufLen    : size of txBuf
 * \param[in]  blockData   : data to written on the given block(s)
 * \param[out] rxBuf       : buffer to place check/read data 
 * \param[in]  rxBufLen    : size of the rxBuf
 *
 * \return RFAL_ERR_WRONG_STATE  : RFAL not initialized or mode not set
 * \return RFAL_ERR_PARAM        : Invalid parameters
 * \return RFAL_ERR_IO           : Generic internal error
 * \return RFAL_ERR_REQUEST      : The request was executed with error
 * \return RFAL_ERR_NONE         : No error
 *****************************************************************************
 */
ReturnCode rfalNfcfPollerUpdate( const uint8_t* nfcid2, const rfalNfcfServBlockListParam *servBlock, uint8_t *txBuf, uint16_t txBufLen, const uint8_t *blockData, uint8_t *rxBuf, uint16_t rxBufLen);

/*!
 *****************************************************************************
 * \brief NFC-F Listener is T3T Request  
 * 
 * This method checks if the given data is a valid T3T command (Read or Write) 
 * and in case a valid request has been received it may output the request's NFCID2
 * 
 * \param[in]   buf : buffer holding Initiator's received command
 * \param[in]   bufLen : length of received command in bytes
 * \param[out]  nfcid2 : pointer to where the NFCID2 may be outputed, 
 *                       nfcid2 has NFCF_SENSF_NFCID2_LEN as length
 *                       Pass NULL if output parameter not desired 
 * 
 * \return true  : Valid T3T command (Read or Write) received
 * \return false : Invalid protocol request
 * 
 *****************************************************************************
 */
bool rfalNfcfListenerIsT3TReq( const uint8_t* buf, uint16_t bufLen, uint8_t* nfcid2 );


#endif /* RFAL_NFCF_H */

/**
  * @}
  *
  * @}
  *
  * @}
  */
