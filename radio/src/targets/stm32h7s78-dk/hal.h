/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#define CPU_FREQ                        480000000
#define PERI1_FREQUENCY                 120000000
#define PERI2_FREQUENCY                 120000000
#define TIMER_MULT_APB1                 2
#define TIMER_MULT_APB2                 2

#define LED_GPIO                      GPIO_PIN(GPIOC, 13) // PI.05

#define TELEMETRY_EXTI_PRIO             0 // required for soft serial

#define BOOTLOADER_ADDRESS              0x08000000
#define LANDSCAPE_LCD true
#define PORTRAIT_LCD false
  
// Power
#if defined(RADIO_T18)
  #define PWR_ON_GPIO                   GPIO_PIN(GPIOJ, 1) // PJ.01
  #define PWR_SWITCH_GPIO               GPIO_PIN(GPIOJ, 0) // PJ.00
  #define PWR_EXTRA_SWITCH_GPIO         GPIO_PIN(GPIOB, 0) // PB.00
#elif defined(RADIO_V16)
  #define PWR_ON_GPIO                   GPIO_PIN(GPIOB, 2) // PB.02
  #define PWR_SWITCH_GPIO               GPIO_PIN(GPIOJ, 0) // PJ.00
#else
  #define PWR_ON_GPIO                   GPIO_PIN(GPIOJ, 1) // PJ.01
  #define PWR_SWITCH_GPIO               GPIO_PIN(GPIOJ, 0) // PJ.00
#endif

// QSPI
#define QSPI_CLK_GPIO   GPIO_PIN(GPIOF, 10)  
#define QSPI_CS_GPIO    GPIO_PIN(GPIOG, 6)  
#define QSPI_MISO_GPIO    GPIO_PIN(GPIOF, 9)  
#define QSPI_MOSI_GPIO    GPIO_PIN(GPIOF, 8)  
#define QSPI_WP_GPIO    GPIO_PIN(GPIOF, 7)  
#define QSPI_HOLD_GPIO    GPIO_PIN(GPIOF, 6)  

#define QSPI_CLK_GPIO_AF  GPIO_AF9
#define QSPI_CS_GPIO_AF GPIO_AF9
#define QSPI_MISO_GPIO_AF GPIO_AF9
#define QSPI_MOSI_GPIO_AF GPIO_AF9
#define QSPI_WP_GPIO_AF GPIO_AF9
#define QSPI_HOLD_GPIO_AF GPIO_AF9

// SDRAM
#define SDRAM_BANK1

// USB
#define USB_GPIO_VBUS                   GPIO_PIN(GPIOA, 9)  // PA.09
#define USB_GPIO_DM                     GPIO_PIN(GPIOA, 11) // PA.11
#define USB_GPIO_DP                     GPIO_PIN(GPIOA, 12) // PA.12
#define USB_GPIO_AF                     GPIO_AF10

// LCD
#if defined(RADIO_T15)
  #define LCD_NRST_GPIO                   GPIOG
  #define LCD_NRST_GPIO_PIN               LL_GPIO_PIN_10 // PG.10
  #define LCD_SPI_GPIO                    GPIOE
  #define LCD_SPI_CS_GPIO_PIN             LL_GPIO_PIN_4  // PE.04
  #define LCD_SPI_SCK_GPIO_PIN            LL_GPIO_PIN_2  // PE.02
  #define LCD_SPI_MISO_GPIO_PIN           LL_GPIO_PIN_5  // PE.05
  #define LCD_SPI_MOSI_GPIO_PIN           LL_GPIO_PIN_6  // PE.06
  #define LTDC_IRQ_PRIO                   4
  #define DMA_SCREEN_IRQ_PRIO             6
#else
#if defined(PCBX12S)
  // #define LCD_GPIO_NRST                 GPIO_PIN(GPIOF, 10) // PF.10
#elif defined(PCBX10)
  // #define LCD_GPIO_NRST                 GPIO_PIN(GPIOI, 10) // PI.10
#endif
#if defined(PCBX10) && !defined(RADIO_T18) && !defined(RADIO_V16)
  #define LCD_VERTICAL_INVERT
#endif
#define LTDC_IRQ_PRIO                   4
#define DMA_SCREEN_IRQ_PRIO             6
#endif

#define SD_SDIO SDMMC1
#define SD_SDIO_TRANSFER_CLK_DIV SDMMC_NSPEED_CLK_DIV
// #define SD_SDIO_DMA                       DMA2
// #define SD_SDIO_DMA_STREAM                DMA2_Stream3 // or Stream6
// #define SD_SDIO_DMA_CHANNEL               LL_DMA_CHANNEL_4
// #define SD_SDIO_DMA_IRQn                  DMA2_Stream3_IRQn
// #define SD_SDIO_DMA_IRQHANDLER            DMA2_Stream3_IRQHandler
// #define SD_SDIO_CLK_DIV(fq)               ((48000000 / (fq)) - 2)
// #define SD_SDIO_INIT_CLK_DIV              SD_SDIO_CLK_DIV(400000)
// #define SD_SDIO_TRANSFER_CLK_DIV          SD_SDIO_CLK_DIV(24000000)

// Uncomment only one line below to select which storage to use
#define STORAGE_USE_SDIO      // Use SD card for storage with SDIO driver
//#define STORAGE_USE_SPI_FLASH // Use SPI flash for storage instead of SD card

// SPI NOR Flash 
#if defined(PCBX12S) && PCBREV >= 13
  #define FLASH_SPI                      SPI1
  #define FLASH_SPI_CS_GPIO              GPIO_PIN(GPIOA, 15) // PA.15
  #define FLASH_SPI_GPIO                 GPIOA
  #define FLASH_SPI_SCK_GPIO             GPIO_PIN(GPIOA, 5) // PA.05
  #define FLASH_SPI_MISO_GPIO            GPIO_PIN(GPIOA, 6) // PA.06
  #define FLASH_SPI_MOSI_GPIO            GPIO_PIN(GPIOA, 7) // PA.07
  #define FLASH_SPI_DMA                  DMA2
  #define FLASH_SPI_DMA_CHANNEL          LL_DMA_CHANNEL_3
  #define FLASH_SPI_DMA_TX_STREAM        LL_DMA_STREAM_3
  #define FLASH_SPI_DMA_RX_STREAM        LL_DMA_STREAM_5
  // SPI1_TX: DMA2 Stream 3 (SDIO) / Stream 5 (Ext. module timer)
  // #define FLASH_SPI_TX_DMA_CHANNEL       DMA_Channel_3
  // #define FLASH_SPI_TX_DMA_STREAM        DMA2_Stream3
  // #define FLASH_SPI_TX_DMA_IRQn          DMA2_Stream3_IRQn
  // #define FLASH_SPI_TX_DMA_IRQHandler    DMA2_Stream3_IRQHandler
  // #define FLASH_SPI_TX_DMA_FLAG_TC       DMA_IT_TCIF3
  // #define FLASH_SPI_TX_DMA_STATUS_REG    HISR
  // SPI1_RX: DMA2 Stream 0 / Stream 2 
  // #define FLASH_SPI_RX_DMA_CHANNEL       DMA_Channel_3
  // #define FLASH_SPI_RX_DMA_STREAM        DMA2_Stream5
  // #define FLASH_SPI_RX_DMA_IRQn          DMA2_Stream5_IRQn
  // #define FLASH_SPI_RX_DMA_IRQHandler    DMA2_Stream5_IRQHandler
  // #define FLASH_SPI_RX_DMA_STATUS_REG    HISR
  // #define FLASH_SPI_RX_DMA_FLAG_TC       DMA_IT_TCIF5
#elif defined(PCBX10)
  #define FLASH_SPI                      SPI2
  #define FLASH_SPI_CS_GPIO              GPIO_PIN(GPIOI, 0)  // PI.00
  #define FLASH_SPI_GPIO                 GPIOI
  #define FLASH_SPI_SCK_GPIO             GPIO_PIN(GPIOI, 1)  // PI.01
  #define FLASH_SPI_MISO_GPIO            GPIO_PIN(GPIOI, 2)  // PI.02
  #define FLASH_SPI_MOSI_GPIO            GPIO_PIN(GPIOI, 3)  // PI.03
  #define FLASH_SPI_DMA                  DMA1
  #define FLASH_SPI_DMA_CHANNEL          LL_DMA_CHANNEL_0
  #define FLASH_SPI_DMA_TX_STREAM        LL_DMA_STREAM_4
  #define FLASH_SPI_DMA_RX_STREAM        LL_DMA_STREAM_3
  // #define FLASH_SPI_TX_DMA_CHANNEL       DMA_Channel_0
  // #define FLASH_SPI_TX_DMA_STREAM        DMA1_Stream4
  // #define FLASH_SPI_TX_DMA_IRQn          DMA1_Stream4_IRQn
  // #define FLASH_SPI_TX_DMA_IRQHandler    DMA1_Stream4_IRQHandler
  // #define FLASH_SPI_TX_DMA_FLAG_TC       DMA_IT_TCIF4
  // #define FLASH_SPI_TX_DMA_STATUS_REG    HISR
  // #define FLASH_SPI_RX_DMA_CHANNEL       DMA_Channel_0
  // #define FLASH_SPI_RX_DMA_STREAM        DMA1_Stream3
  // #define FLASH_SPI_RX_DMA_IRQn          DMA1_Stream3_IRQn
  // #define FLASH_SPI_RX_DMA_IRQHandler    DMA1_Stream3_IRQHandler
  // #define FLASH_SPI_RX_DMA_STATUS_REG    LISR
  // #define FLASH_SPI_RX_DMA_FLAG_TC       DMA_IT_TCIF3
#endif

#define ADC_VREF_PREC2 1024 // fake

// Touch
#if defined(HARDWARE_TOUCH)
  #define TOUCH_I2C_BUS                   I2C_Bus_1
  #define TOUCH_INT_GPIO                  GPIO_PIN(GPIOI, 11)  // PH.02
#if defined(PCBX12S)
  // #define TOUCH_RST_GPIO                  GPIO_PIN(GPIOF, 7)  // PF.7
#else
  #define TOUCH_RST_GPIO                  GPIO_PIN(GPIOI, 8)  // PF.10
#endif
  #define TOUCH_INT_EXTI_Line             LL_EXTI_LINE_2
  #define TOUCH_INT_EXTI_Port             LL_SYSCFG_EXTI_PORTH
  #define TOUCH_INT_EXTI_SysCfgLine       LL_SYSCFG_EXTI_LINE2
  // TOUCH_INT_EXTI IRQ
#if !defined(USE_EXTI2_IRQ)
  #define USE_EXTI2_IRQ
  #define EXTI2_IRQ_Priority  9
#endif

#if defined(PCBX12S)
  #define TOUCH_PANEL_INVERTED
#endif
#endif // HARDWARE_TOUCH

// First I2C Bus
#if defined(RADIO_TX16S) || defined(RADIO_F16) || defined(PCBX12S) || defined(RADIO_T15) || defined(RADIO_V16)
  #define I2C_B1                      I2C1
  #define I2C_B1_SCL_GPIO             GPIO_PIN(GPIOB, 8)  // PB.08
  #define I2C_B1_SDA_GPIO             GPIO_PIN(GPIOB, 9)  // PB.09
  #define I2C_B1_GPIO_AF              LL_GPIO_AF_4   // I2C1
  #define I2C_B1_CLK_RATE             400000
#else
  #define I2C_B1                      I2C2
  #define I2C_B1_SCL_GPIO             GPIO_PIN(GPIOH, 4)  // PH.07
  #define I2C_B1_SDA_GPIO             GPIO_PIN(GPIOH, 5)  // PH.08
  #define I2C_B1_GPIO_AF              LL_GPIO_AF_4   // I2C2
  #define I2C_B1_CLK_RATE             400000
#endif

// Second I2C Bus
#if !defined(AUX_SERIAL) && defined(IMU_LSM6DS33)
  #define I2C_B2                      I2C2
  #define I2C_B2_SCL_GPIO             GPIO_PIN(GPIOB, 10)  // PB.10
  #define I2C_B2_SDA_GPIO             GPIO_PIN(GPIOB, 11)  // PB.11
  #define I2C_B2_GPIO_AF              LL_GPIO_AF_4    // I2C2
  #define I2C_B2_CLK_RATE             400000
  #if defined(RADIO_TX16S) || defined(RADIO_F16) || defined(RADIO_V16)
    #define I2C_B2_PWR_GPIO           GPIO_PIN(GPIOA, 15)  // PA.15
  #endif
#endif


// Millisecond timer
#define MS_TIMER                        TIM14
#define MS_TIMER_IRQn                   TIM8_TRG_COM_TIM14_IRQn
#define MS_TIMER_IRQHandler             TIM8_TRG_COM_TIM14_IRQHandler

// Mixer scheduler timer
#define MIXER_SCHEDULER_TIMER                TIM13
#define MIXER_SCHEDULER_TIMER_FREQ           (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define MIXER_SCHEDULER_TIMER_IRQn           TIM8_UP_TIM13_IRQn
#define MIXER_SCHEDULER_TIMER_IRQHandler     TIM8_UP_TIM13_IRQHandler

// SDRAM
#define SDRAM_BANK2

#define LCD_W                          480
#define LCD_H                          320
#define LCD_PHYS_H                     LCD_H
#define LCD_PHYS_W                     LCD_W
#define LCD_DEPTH                      16

