/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer 
*
* Copyright (C) 2012 Renesas Electronics Corporation. All rights reserved.    
*******************************************************************************/
/******************************************************************************
* File Name    : r_flash_rx62n.h
* Description  : This file has specific information about the ROM and DF on 
*                RX62N/RX621 Group MCUs.
*******************************************************************************
* History : DD.MM.YYYY Version Description
*         : 11.09.2012 1.00    First Release
*         : 10.10.2012 1.10    Added FCU_RAM_INIT_REQUIRED macro.
*         : 01.12.2015 1.20    Fixed incorrect FLASH_CF_BLOCK_INVALID values
*         : 10.08.2016 2.00    Modified for BSPless operations.
*         : 17.11.2016 2.10    Added FLASH_xxx size and num block defines
*         : 02.08.2017 2.20    Replaced #include "r_mcu_config.h" with "r_flash_targets.h"
******************************************************************************/

#ifndef _FLASH_API_RX62N_H
#define _FLASH_API_RX62N_H

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>
#include "r_flash_targets.h"


/******************************************************************************
Macro definitions
******************************************************************************/
/* Defines the number of flash areas */
#define NUM_ROM_AREAS           1
/* Defines the start program/erase address for the different flash areas */
#define ROM_AREA_0              (0x00F80000)        

/* Defines whether this MCU requires the FCU RAM be enabled and initialized.
   If uncommented, then MCU is required to init FCU RAM.
   If commented out, then MCU is not required. */
#define FCU_RAM_INIT_REQUIRED   (1)

/*  Bottom of DF Area */
#define DF_ADDRESS              0x00100000
/* Used for getting DF block */
#define DF_MASK                 0xFFFFF800
/* Used for getting erase boundary in DF block when doing blank checking */
#define DF_ERASE_BLOCK_SIZE     0x00000800
/* Defines how many DF blocks are on this part */
#define DF_NUM_BLOCKS           16      // 16 blocks of 2K == 32K
/* THis is the last address in the last block, not the starting address */
#define FLASH_DF_LAST_BLOCK        ((FLASH_DF_BLOCK_INVALID) - (DF_ERASE_BLOCK_SIZE))

/* Defines how many ROM blocks are on this part */
#if MCU_ROM_SIZE_BYTES == 524288
    #define ROM_NUM_BLOCKS      38    //512KB part
#elif MCU_ROM_SIZE_BYTES == 393216
    #define ROM_NUM_BLOCKS      30    //384KB part
#elif MCU_ROM_SIZE_BYTES == 262144
    #define ROM_NUM_BLOCKS      22    //256KB part
#endif

/* Programming size for ROM in bytes */
#define ROM_PROGRAM_SIZE        256
/* Programming size for data flash in bytes */
#define DF_PROGRAM_SIZE_LARGE   128
#define DF_PROGRAM_SIZE_SMALL   8

#define FLASH_CF_SMALL_BLOCK_SIZE       (4096)
#define FLASH_CF_MEDIUM_BLOCK_SIZE      (16384)
#define FLASH_NUM_BLOCKS_CF             ROM_NUM_BLOCKS
#define FLASH_CF_MIN_PGM_SIZE           ROM_PROGRAM_SIZE
#define FLASH_DF_BLOCK_SIZE             DF_ERASE_BLOCK_SIZE
#define FLASH_NUM_BLOCKS_DF             DF_NUM_BLOCKS
#define FLASH_DF_MIN_PGM_SIZE           DF_PROGRAM_SIZE_SMALL
#define FLASH_DF_HIGHEST_VALID_BLOCK    FLASH_DF_LAST_BLOCK


typedef enum _flash_block_address
{
FLASH_CF_BLOCK_0       = 0x00FFF000,    /*   4KB: 0xFFFFF000 - 0xFFFFFFFF */
FLASH_CF_BLOCK_1       = 0x00FFE000,    /*   4KB: 0xFFFFE000 - 0xFFFFEFFF */
FLASH_CF_BLOCK_2       = 0x00FFD000,    /*   4KB: 0xFFFFD000 - 0xFFFFDFFF */
FLASH_CF_BLOCK_3       = 0x00FFC000,    /*   4KB: 0xFFFFC000 - 0xFFFFCFFF */
FLASH_CF_BLOCK_4       = 0x00FFB000,    /*   4KB: 0xFFFFB000 - 0xFFFFBFFF */
FLASH_CF_BLOCK_5       = 0x00FFA000,    /*   4KB: 0xFFFFA000 - 0xFFFFAFFF */
FLASH_CF_BLOCK_6       = 0x00FF9000,    /*   4KB: 0xFFFF9000 - 0xFFFF9FFF */
FLASH_CF_BLOCK_7       = 0x00FF8000,    /*   4KB: 0xFFFF8000 - 0xFFFF8FFF */
FLASH_CF_BLOCK_8       = 0x00FF4000,    /*  16KB: 0xFFFF4000 - 0xFFFF7FFF */
FLASH_CF_BLOCK_9       = 0x00FF0000,    /*  16KB: 0xFFFF0000 - 0xFFFF3FFF */
FLASH_CF_BLOCK_10      = 0x00FEC000,    /*  16KB: 0xFFFEC000 - 0xFFFEFFFF */
FLASH_CF_BLOCK_11      = 0x00FE8000,    /*  16KB: 0xFFFE8000 - 0xFFFEBFFF */
FLASH_CF_BLOCK_12      = 0x00FE4000,    /*  16KB: 0xFFFE4000 - 0xFFFE7FFF */
FLASH_CF_BLOCK_13      = 0x00FE0000,    /*  16KB: 0xFFFE0000 - 0xFFFE3FFF */
FLASH_CF_BLOCK_14      = 0x00FDC000,    /*  16KB: 0xFFFDC000 - 0xFFFDFFFF */
FLASH_CF_BLOCK_15      = 0x00FD8000,    /*  16KB: 0xFFFD8000 - 0xFFFDBFFF */
FLASH_CF_BLOCK_16      = 0x00FD4000,    /*  16KB: 0xFFFD4000 - 0xFFFD7FFF */
FLASH_CF_BLOCK_17      = 0x00FD0000,    /*  16KB: 0xFFFD0000 - 0xFFFD3FFF */
FLASH_CF_BLOCK_18      = 0x00FCC000,    /*  16KB: 0xFFFCC000 - 0xFFFCFFFF */
FLASH_CF_BLOCK_19      = 0x00FC8000,    /*  16KB: 0xFFFC8000 - 0xFFFCBFFF */
FLASH_CF_BLOCK_20      = 0x00FC4000,    /*  16KB: 0xFFFC4000 - 0xFFFC7FFF */
FLASH_CF_BLOCK_21      = 0x00FC0000,    /*  16KB: 0xFFFC0000 - 0xFFFC3FFF */
#if   MCU_CFG_PART_MEMORY_SIZE == 0x6   //   256KB ROM
    FLASH_CF_BLOCK_INVALID = 0x00FBFFFF,
#else
FLASH_CF_BLOCK_22      = 0x00FBC000,    /*  16KB: 0xFFFBC000 - 0xFFFBFFFF */
FLASH_CF_BLOCK_23      = 0x00FB8000,    /*  16KB: 0xFFFB8000 - 0xFFFBBFFF */
FLASH_CF_BLOCK_24      = 0x00FB4000,    /*  16KB: 0xFFFB4000 - 0xFFFB7FFF */
FLASH_CF_BLOCK_25      = 0x00FB0000,    /*  16KB: 0xFFFB0000 - 0xFFFB3FFF */
FLASH_CF_BLOCK_26      = 0x00FAC000,    /*  16KB: 0xFFFAC000 - 0xFFFAFFFF */
FLASH_CF_BLOCK_27      = 0x00FA8000,    /*  16KB: 0xFFFA8000 - 0xFFFABFFF */
FLASH_CF_BLOCK_28      = 0x00FA4000,    /*  16KB: 0xFFFA4000 - 0xFFFA7FFF */
FLASH_CF_BLOCK_29      = 0x00FA0000,    /*  16KB: 0xFFFA0000 - 0xFFFA3FFF */
#if   MCU_CFG_PART_MEMORY_SIZE == 0x7   //   384KB ROM
    FLASH_CF_BLOCK_INVALID = 0x00F9FFFF,
#else
FLASH_CF_BLOCK_30      = 0x00F9C000,    /*  16KB: 0xFFF9C000 - 0xFFF9FFFF */
FLASH_CF_BLOCK_31      = 0x00F98000,    /*  16KB: 0xFFF98000 - 0xFFF9BFFF */
FLASH_CF_BLOCK_32      = 0x00F94000,    /*  16KB: 0xFFF94000 - 0xFFF97FFF */
FLASH_CF_BLOCK_33      = 0x00F90000,    /*  16KB: 0xFFF90000 - 0xFFF93FFF */
FLASH_CF_BLOCK_34      = 0x00F8C000,    /*  16KB: 0xFFF8C000 - 0xFFF8FFFF */
FLASH_CF_BLOCK_35      = 0x00F88000,    /*  16KB: 0xFFF88000 - 0xFFF8BFFF */
FLASH_CF_BLOCK_36      = 0x00F84000,    /*  16KB: 0xFFF84000 - 0xFFF87FFF */
FLASH_CF_BLOCK_37      = 0x00F80000,    /*  16KB: 0xFFF80000 - 0xFFF83FFF */
#if   MCU_CFG_PART_MEMORY_SIZE == 0x8   //   512KB ROM
    FLASH_CF_BLOCK_INVALID = 0x00F7FFFF,
#endif
#endif
#endif
     FLASH_DF_BLOCK_0       = 0x00100000,    /*    2K: 0x00100000 - 0x001007FF */
     FLASH_DF_BLOCK_1       = 0x00100800,    /*    2K: 0x00100800 - 0x00100FFF */
     FLASH_DF_BLOCK_2       = 0x00101000,    /*    2K: 0x00101000 - 0x001017FF */
     FLASH_DF_BLOCK_3       = 0x00101800,    /*    2K: 0x00101800 - 0x00101FFF */
     FLASH_DF_BLOCK_4       = 0x00102000,    /*    2K: 0x00102000 - 0x001027FF */
     FLASH_DF_BLOCK_5       = 0x00102800,    /*    2K: 0x00102800 - 0x00102FFF */
     FLASH_DF_BLOCK_6       = 0x00103000,    /*    2K: 0x00103000 - 0x001037FF */
     FLASH_DF_BLOCK_7       = 0x00103800,    /*    2K: 0x00103800 - 0x00103FFF */
     FLASH_DF_BLOCK_8       = 0x00104000,    /*    2K: 0x00104000 - 0x001047FF */
     FLASH_DF_BLOCK_9       = 0x00104800,    /*    2K: 0x00104800 - 0x00104FFF */
     FLASH_DF_BLOCK_10      = 0x00105000,    /*    2K: 0x00105000 - 0x001057FF */
     FLASH_DF_BLOCK_11      = 0x00105800,    /*    2K: 0x00105800 - 0x00105FFF */
     FLASH_DF_BLOCK_12      = 0x00106000,    /*    2K: 0x00106000 - 0x001067FF */
     FLASH_DF_BLOCK_13      = 0x00106800,    /*    2K: 0x00106800 - 0x00106FFF */
     FLASH_DF_BLOCK_14      = 0x00107000,    /*    2K: 0x00107000 - 0x001077FF */
     FLASH_DF_BLOCK_15      = 0x00107800,    /*    2K: 0x00107800 - 0x00107FFF */
     FLASH_DF_BLOCK_INVALID = 0x00108000     /*    Can't write beyond 0x00107FFF */

} flash_block_address_t;

typedef struct _rom_block_sizes
{
 uint32_t num_blocks;                     // number of blocks at this size
 uint32_t block_size;                     // Size of each block
}rom_block_sizes_t;

typedef struct _rom_block_info
{
 uint32_t start_addr;                   // starting address for this block section
 uint32_t end_addr;                     // ending (up to and including this) address
 uint16_t block_number;                 // the rom block number for this address queried
 uint32_t thisblock_stAddr;             // the starting address for the above block #
 uint32_t block_size;                   // Size of this block

}rom_block_info_t;


#define NUM_BLOCK_TABLE_ENTRIES 3
static rom_block_sizes_t g_flash_RomBlockSizes[NUM_BLOCK_TABLE_ENTRIES] = {
         8,  4096,    /* 8 blocks of 4K   */
        30, 16384,    /* 30 blocks of 16K */
        0,  0
};


/*  According to HW Manual the Max Programming Time for 256 bytes (ROM)
    is 12ms.  This is with a PCLK of 50MHz. The calculation below
    calculates the number of ICLK ticks needed for the timeout delay.
    The 12ms number is adjusted linearly depending on the PCLK frequency.
*/
#define WAIT_MAX_ROM_WRITE \
        ((int32_t)(12000 * (50.0/(MCU_CFG_FCLK_HZ/1000000)))*(MCU_CFG_ICLK_HZ/1000000))

/*  According to HW Manual the Max Programming Time for 128 bytes
    (Data Flash) is 5ms.  This is with a PCLK of 50MHz. The calculation
    below calculates the number of ICLK ticks needed for the timeout delay.
    The 5ms number is adjusted linearly depending on the PCLK frequency.
*/
#define WAIT_MAX_DF_WRITE \
        ((int32_t)(5000 * (50.0/(MCU_CFG_FCLK_HZ/1000000)))*(MCU_CFG_ICLK_HZ/1000000))

/*  According to HW Manual the Max Blank Check time for 2k bytes
    (Data Flash) is 0.7ms.  This is with a PCLK of 50MHz. The calculation
    below calculates the number of ICLK ticks needed for the timeout delay.
    The 0.7ms number is adjusted linearly depending on the PCLK frequency.
*/
#define WAIT_MAX_BLANK_CHECK \
        ((int32_t)(700 * (50.0/(MCU_CFG_FCLK_HZ/1000000)))*(MCU_CFG_ICLK_HZ/1000000))
        
/*  According to HW Manual the max timeout value when using the peripheral
    clock notification command is 60us. This is with a PCLK of 50MHz. The 
    calculation below calculates the number of ICLK ticks needed for the 
    timeout delay. The 10us number is adjusted linearly depending on 
    the PCLK frequency.
*/
#define WAIT_MAX_NOTIFY_FCU_CLOCK \
        ((int32_t)(60 * (50.0/(MCU_CFG_FCLK_HZ/1000000)))*(MCU_CFG_ICLK_HZ/1000000))

/*  According to HW Manual the Max Erasure Time for a 16kB block is
    around 300ms.  This is with a PCLK of 50MHz. The calculation below
    calculates the number of ICLK ticks needed for the timeout delay.
    The 300ms number is adjusted linearly depending on the PCLK frequency.
*/
#define WAIT_MAX_ERASE \
        ((int32_t)(300000 * (50.0/(MCU_CFG_FCLK_HZ/1000000)))*(MCU_CFG_ICLK_HZ/1000000))

/******************************************************************************
Error checking
******************************************************************************/
/* FCLK must be between 8MHz and 50MHz. */
#if (MCU_CFG_FCLK_HZ > 50000000) || (MCU_CFG_FCLK_HZ < 8000000)
    #error "ERROR - Flash API - FCLK on RX62N must be between 8MHz and 50MHz!"
#endif

#endif /* _FLASH_API_RX62N_H */
