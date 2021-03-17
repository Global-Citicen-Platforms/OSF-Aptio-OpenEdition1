/** @file

Copyright (c) 2018, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985 - 2021, American Megatrends International LLC. *
//*                                                                     *
//*      All rights reserved.                                           *
//*                                                                     *
//*      This program and the accompanying materials are licensed and   *
//*      made available under the terms and conditions of the BSD       *
//*      License that accompanies this distribution.  The full text of  *
//*      the license may be found at:                                   *
//*      http://opensource.org/licenses/bsd-license.php.                *
//*                                                                     *
//*      THIS PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN        *
//*      "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF        *
//*      ANY KIND, EITHER EXPRESS OR IMPLIED.                           *
//*                                                                     *
//***********************************************************************

#include <PiPei.h>
#include <Library/DebugLib.h>

#include <Library/GpioLib.h>
#include <GpioPinsSklH.h>
#include <Library/PcdLib.h>

#include <Register/PchRegsPcr.h>
#include <Library/PchPcrLib.h>
#include <Register/PchRegsSpi.h>

GPIO_INIT_CONFIG mGpioTableTiogaPass[] = 
{
// Group A
	//ME{GPIO_SKL_H_GPP_A0,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A0_RCIN_N_ESPI_ALERT1_N [PU_FM_RCIN_N]
	{GPIO_SKL_H_GPP_A1,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A1_LAD0_ESPI_IO0 [LPC_LAD_IO0]
	{GPIO_SKL_H_GPP_A2,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A2_LAD1_ESPI_IO1 [LPC_LAD_IO1]
	{GPIO_SKL_H_GPP_A3,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A3_LAD2_ESPI_IO2 [LPC_LAD_IO2]
	{GPIO_SKL_H_GPP_A4,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A4_LAD3_ESPI_IO3 [LPC_LAD_IO2]
	{GPIO_SKL_H_GPP_A5,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A5_LFRAME_N_ESPI_CS0_N [LPC_LFRAME_N_CS0_N]
	{GPIO_SKL_H_GPP_A6,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A6_SERIRQ_ESPI_CS1_N [IRQ_LPC_SERIRQ_N]
	{GPIO_SKL_H_GPP_A7,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A7_PIRQA_N_ESPI_ALERT0_N [IRQ_PIRQA_SPI_TPM_N]
	{GPIO_SKL_H_GPP_A8,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A8_CLKRUN_N [PU_LPC_CLKRUN_N]
	{GPIO_SKL_H_GPP_A9,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A9_CLKOUT_LPC0_ESPI_CLK [CLK_24M_BMC_LPC]
	{GPIO_SKL_H_GPP_A10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A10_CLKOUT_LPC1 [NOT USED]
	{GPIO_SKL_H_GPP_A11, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A11_PME_N [PU_LPC_PME_N]
	{GPIO_SKL_H_GPP_A12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,  GpioTermNone}},//GPP_A12_BMBUSY_N_SXEXITHLDOFF_N [PU_IRQ_PCH_SCI_WHEA_N]
	{GPIO_SKL_H_GPP_A13, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A13_SUSWARN_N_SUSPWRDNACK [FM_MB_SLOT_ID0]
	{GPIO_SKL_H_GPP_A14, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A14_ESPI_RESET_N [FM_MB_SLOT_ID1]
	{GPIO_SKL_H_GPP_A15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A15_SUSACK_N [FM_MB_SLOT_ID2]
	{GPIO_SKL_H_GPP_A16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A16_CLKOUT_LPC2 [FM_UART_PRES_N]
	{GPIO_SKL_H_GPP_A17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A17 [FM_CPU_BMC_INIT]
	{GPIO_SKL_H_GPP_A18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_A18 [RST_PCH_SYSRST_BTN_OUT_N]
	//ME{GPIO_SKL_H_GPP_A19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_A19 [FM_ME_RECOVER_N]
	{GPIO_SKL_H_GPP_A20, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A20 [NOT USED]
	{GPIO_SKL_H_GPP_A21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A21 [FM_OCP_MEZZA_PRES_N]
	{GPIO_SKL_H_GPP_A22, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A22 [FM_TPM_PRES_N]
	{GPIO_SKL_H_GPP_A23, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_A23 [FM_BMC_READY_N]
// Group B
	{GPIO_SKL_H_GPP_B0,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B0_CORE_VID0 [VID_PCH_CORE_PVNN_AUX_VID_0]
	{GPIO_SKL_H_GPP_B1,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B1_CORE_VID1 [VID_PCH_CORE_PVNN_AUX_VID_1]
	{GPIO_SKL_H_GPP_B2,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B2 [PU_IRQ_VRALERT_N]
	{GPIO_SKL_H_GPP_B3,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B3_CPU_GP2 [FM_QAT_EN_N]
	{GPIO_SKL_H_GPP_B4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B4_CPU_GP3 [IRQ_PVDDQ_ABC_VRHOT_LVT3_N]
	{GPIO_SKL_H_GPP_B5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B5_SRCCLKREQ0_N [IRQ_PVDDQ_DEF_VRHOT_LVT3_N]
	{GPIO_SKL_H_GPP_B6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_B6_SRCCLKREQ1_N [IRQ_PVDDQ_GHJ_VRHOT_LVT3_N]
	{GPIO_SKL_H_GPP_B7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_B7_SRCCLKREQ2_N [IRQ_PVDDQ_KLM_VRHOT_LVT3_N]
	{GPIO_SKL_H_GPP_B8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B8_SRCCLKREQ3_N [FP_NMI_BTN_N]
	{GPIO_SKL_H_GPP_B9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B9_SRCCLKREQ4_N [FM_PWR_BTN_N]
	{GPIO_SKL_H_GPP_B10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B10_SRCCLKREQ5_N [RST_SYSTEM_BTN_N]
	{GPIO_SKL_H_GPP_B11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutLow,     GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B11 [FM_PMBUS_ALERT_BUF_EN_N]
	{GPIO_SKL_H_GPP_B12, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B12_GLB_RST_WARN_N [FM_GLOBAL_RST_WARN_N]
	{GPIO_SKL_H_GPP_B13, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B13_PLTRST_N [RST_PLTRST_N]
	{GPIO_SKL_H_GPP_B14, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_B14_SPKR [FM_BIOS_TOP_SWAP_SPKR]
	{GPIO_SKL_H_GPP_B15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B15 [FM_UART_ALERT_N]
	{GPIO_SKL_H_GPP_B16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B16 [IRQ_PCH_NIC_ALERT_N]
	{GPIO_SKL_H_GPP_B17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B17 [FM_PCH_PWRBTN_OUT_N]
	{GPIO_SKL_H_GPP_B18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B18 [FM_UV_ADR_TRIGGER_EN]
	{GPIO_SKL_H_GPP_B19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutHigh,    GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B19 [FM_BIOS_PREFRB2_GOOD]
	{GPIO_SKL_H_GPP_B20, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow ,    GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_B20 [FM_BIOS_POST_CMPLT_N]
	{GPIO_SKL_H_GPP_B21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B21 [FM_FAST_PROCHOT_EN_N]
	{GPIO_SKL_H_GPP_B22, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B22 [FM_USB_P0_EN_BOOT_BIOS_STRAP_N]
	{GPIO_SKL_H_GPP_B23, { GpioPadModeNative2, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_B23_MEIE_SML1ALRT_N_PHOT_N [FM_PCH_BMC_THERMTRIP_EXI_STRAP_N]
// Group C
	{GPIO_SKL_H_GPP_C0,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C0_SMBCLK [SMB_HOST_STBY_LVC3_SCL_R1]
	{GPIO_SKL_H_GPP_C1,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C1_SMBDATA [SMB_HOST_STBY_LVC3_SDA_R1]
	{GPIO_SKL_H_GPP_C2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C2_SMBALERT_N [PU_PCH_TLS_ENABLE_STRAP]
	//ME{GPIO_SKL_H_GPP_C3,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C3_SML0CLK_IE [SMB_SMLINK0_STBY_LVC3_SCL_R1]
	//ME{GPIO_SKL_H_GPP_C4,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C4_SML0DATA_IE [SMB_SMLINK0_STBY_LVC3_SDA_R1]
	{GPIO_SKL_H_GPP_C5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutHigh, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C5_SML0ALERT_IE_N [IRQ_SML0_ALERT_N]
	//ME{GPIO_SKL_H_GPP_C6,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C6_SML1CLK_IE [SMB_PMBUS_BMC_STBY_LVC3_SCL_R1]
	//ME{GPIO_SKL_H_GPP_C7,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C7_SML1DATA_IE [SMB_PMBUS_BMC_STBY_LVC3_SDA_R1]
	{GPIO_SKL_H_GPP_C8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C8 [FM_PASSWORD_CLEAR_N]
	{GPIO_SKL_H_GPP_C9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C9 [FM_CPU1_RC_EN]
	{GPIO_SKL_H_GPP_C10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutHigh,    GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_C10 [FM_PCH_SATA_RAID_KEY]
	{GPIO_SKL_H_GPP_C11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C11 [FM_BOARD_REV_ID2]
	{GPIO_SKL_H_GPP_C12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C12 [FM_BOARD_REV_ID0]
	{GPIO_SKL_H_GPP_C13, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_C13 [FM_BOARD_REV_ID1]
	{GPIO_SKL_H_GPP_C14, { GpioPadModeGpio,    GpioHostOwnAcpi, GpioDirIn,    GpioOutDefault, GpioIntLevel | GpioIntSci,GpioResetNormal,  GpioTermNone}},//GPP_C14 [IRQ_BMC_PCH_SCI_LPC_N]
	{GPIO_SKL_H_GPP_C15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C15 [FM_SLT_CFG0]
	{GPIO_SKL_H_GPP_C16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C16 [FM_SLT_CFG1]
	{GPIO_SKL_H_GPP_C17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C17 [FM_SLT_CFG2_R]
	{GPIO_SKL_H_GPP_C18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C18 [FM_PMBUS_ALERT_BUF_EN_N]
	{GPIO_SKL_H_GPP_C19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C19 [FM_BB_BMC_MP_GPIO]
	//ME{GPIO_SKL_H_GPP_C20, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutHigh,    GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C20 [FM_THROTTLE_N]
	{GPIO_SKL_H_GPP_C21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_C21 [FM_BIOS_POST_CMPLT_N]
	{GPIO_SKL_H_GPP_C22, { GpioPadModeGpio,    GpioHostOwnAcpi, GpioDirInInv,    GpioOutDefault, GpioIntLevel | GpioIntSmi,GpioResetNormal,  GpioTermNone}},//GPP_C22 [IRQ_BMC_PCH_SMI_LPC_N]
	{GPIO_SKL_H_GPP_C23, { GpioPadModeGpio,    GpioHostOwnAcpi, GpioDirIn,    GpioOutDefault, GpioIntLevel | GpioIntSmi,GpioResetDeep,    GpioTermNone}},//GPP_C23 [FM_CPU_CATERR_DLY_LVT3_R_N]
// Group D
	{GPIO_SKL_H_GPP_D0,  { GpioPadModeGpio,    GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntEdge | GpioIntNmi,GpioResetNormal,  GpioTermNone}},//GPP_D0 [IRQ_BMC_PCH_NMI_STBY_R_N]
	{GPIO_SKL_H_GPP_D1,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow,    GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D1 [FM_PWR_LED_N]
	{GPIO_SKL_H_GPP_D2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_D2 [IRQ_HSC_FAULT_N]
	{GPIO_SKL_H_GPP_D3,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,  GpioTermNone}},//GPP_D3 [IRQ_MEZZ_LAN_ALERT_N]
	{GPIO_SKL_H_GPP_D4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutHigh,    GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_D4 [FM_PCH_PLD_DATA_R]
	{GPIO_SKL_H_GPP_D5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D5 [FM_BMC_ENABLE_N]
	{GPIO_SKL_H_GPP_D6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D6 [FM_CPLD_BMC_PWRDN_N]
	{GPIO_SKL_H_GPP_D7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D7 [FM_BMC_CPLD_GPO]
	{GPIO_SKL_H_GPP_D8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D8 [FM_BMC_FAULT_LED_N]
	{GPIO_SKL_H_GPP_D9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D9_SSATA_DEVSLP3 [IRQ_FORCE_NM_THROTTLE_N]
	{GPIO_SKL_H_GPP_D10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D10_SSATA_DEVSLP4 [H_CPU0_FAST_WAKE_LVT3_N]
	{GPIO_SKL_H_GPP_D11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D11_SSATA_DEVSLP5 [IRQ_LOM_ALERT_N]
	{GPIO_SKL_H_GPP_D12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D12_SSATA_SDATAOUT1 [FM_TPM_PRES_RST_N]
	{GPIO_SKL_H_GPP_D13, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D13_SML0BCLK_IE [SMB_SLOTX24_STBY_LVC3_SCL_R1]
	{GPIO_SKL_H_GPP_D14, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D14_SML0BDATA_IE [SMB_SLOTX24_STBY_LVC3_SDA_R1]
	{GPIO_SKL_H_GPP_D15, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D15_SSATA_SDATAOUT0 [SGPIO_PCH_SSATA_DOUT0]
	{GPIO_SKL_H_GPP_D16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D16_SML0BALERT_IE_N [IRQ_OOB_MGMT_RISER_ALERT_N]
	{GPIO_SKL_H_GPP_D17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D17 [FM_XRC_PRESENT_N]
	{GPIO_SKL_H_GPP_D18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_D18 [FM_XRC_READY_N]
	{GPIO_SKL_H_GPP_D19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_D19 [FM_ADR_MODE_SEL_R]
	{GPIO_SKL_H_GPP_D20, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D20 [FM_BMC_HEARTBEAT_N]
	{GPIO_SKL_H_GPP_D21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D21_IE_UART_RX [NOT USED]
	{GPIO_SKL_H_GPP_D22, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D22_IE_UART_TX [NOT USED]
	{GPIO_SKL_H_GPP_D23, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_D23 [FM_CPU0_THERMTRIP_LATCH_LVT3_N]
// Group E	
    {GPIO_SKL_H_GPP_E0,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E0_SATAXPCIE0_SATAGP0 [FM_CPU0_RC_ERROR_N]
	{GPIO_SKL_H_GPP_E1,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E1_SATAXPCIE1_SATAGP1 [FM_CPU1_RC_ERROR_N]
	{GPIO_SKL_H_GPP_E2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E2_SATAXPCIE2_SATAGP2 [FM_POST_CARD_PRES_BMC_N]
	{GPIO_SKL_H_GPP_E3,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E3_CPU_GP0 [FM_CPLD_ADR_TRIGGER_N]
	{GPIO_SKL_H_GPP_E4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E4_SATA_DEVSLP0 [FM_CPU_ERR2_LVT3_N]
	{GPIO_SKL_H_GPP_E5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E5_SATA_DEVSLP1 [FM_CPU_MSMI_LVT3_N]
	{GPIO_SKL_H_GPP_E6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E6_SATA_DEVSLP2 [IRQ_BMC_PCH_NMI_STBY_N]
	{GPIO_SKL_H_GPP_E7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E7_CPU_GP1 [FM_ADR_SMI_GPIO_N]
	{GPIO_SKL_H_GPP_E8,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E8_SATA_LED_N [LED_PCH_SATA_HDD_N]
	{GPIO_SKL_H_GPP_E9,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E9_USB2_OC0_N [FM_OC0_USB_N]
	{GPIO_SKL_H_GPP_E10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E10_USB2_OC1_N [IRQ_BMC_PCH_SCI_LPC_N]
	{GPIO_SKL_H_GPP_E11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E11_USB2_OC2_N [IRQ_BMC_PCH_SMI_LPC_N]
	{GPIO_SKL_H_GPP_E12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_E12_USB2_OC3_N [IRQ_UV_DETECT_N
// Group F
    {GPIO_SKL_H_GPP_F0,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F0_SATAXPCIE3_SATAGP3 [IRQ_OC_DETECT_N]
	{GPIO_SKL_H_GPP_F1,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F1_SATAXPCIE4_SATAGP4 [FM_HSC_TIMER_EXP_N]
	{GPIO_SKL_H_GPP_F2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F2_SATAXPCIE5_SATAGP5 [FM_MP_PS_FAIL_N]
	{GPIO_SKL_H_GPP_F3,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F3_SATAXPCIE6_SATAGP6 [FM_MP_PS_REDUNDANT_LOST_N]
	{GPIO_SKL_H_GPP_F4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F4_SATAXPCIE7_SATAGP7 [FM_BMC_READY_N]
	{GPIO_SKL_H_GPP_F5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F5_SATA_DEVSLP3 [FM_BIOS_USB_RECOVERY]
	{GPIO_SKL_H_GPP_F6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_F6_SATA_DEVSLP4 [JTAG_PCH_PLD_TCK]
	{GPIO_SKL_H_GPP_F7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_F7_SATA_DEVSLP5 [JTAG_PCH_PLD_TDI]
	{GPIO_SKL_H_GPP_F8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutLow,     GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_F8_SATA_DEVSLP6 [JTAG_PCH_PLD_TMS]
	{GPIO_SKL_H_GPP_F9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_F9_SATA_DEVSLP7 [JTAG_PCH_PLD_TDO]
	{GPIO_SKL_H_GPP_F10, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F10_SATA_SCLOCK [SGPIO_PCH_SATA_CLOCK]
	{GPIO_SKL_H_GPP_F11, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F11_SATA_SLOAD [SGPIO_PCH_SATA_LOAD
	{GPIO_SKL_H_GPP_F12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F12_SATA_SDATAOUT1 [IRQ_SML1_PMBUS_ALERT_R1_N]
	{GPIO_SKL_H_GPP_F13, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F13_SATA_SDATAOUT0 [SGPIO_PCH_SATA_DOUT0]
	{GPIO_SKL_H_GPP_F14, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F14_SSATA_LED_N [LED_PCH_SSATA_HDD_N
	{GPIO_SKL_H_GPP_F15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F15_USB2_OC4_N [FM_FORCE_ADR_N]
	{GPIO_SKL_H_GPP_F16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F16_USB2_OC5_N [FM_IE_DISABLE_N]
	{GPIO_SKL_H_GPP_F17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F17_USB2_OC6_N [FM_BIOS_TOP_SWAP]
	{GPIO_SKL_H_GPP_F18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F18_USB2_OC7_N [FM_MEM_THERM_EVENT_PCH_N]
	{GPIO_SKL_H_GPP_F19, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F19_LAN_SMBCLK [SMB_LAN_STBY_LVC3_SCL_R2]
	{GPIO_SKL_H_GPP_F20, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F20_LAN_SMBDATA [SMB_LAN_STBY_LVC3_SDA_R2]
	{GPIO_SKL_H_GPP_F21, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F21_LAN_SMBALRT_N [IRQ_PCH_NIC_ALERT_N]
	{GPIO_SKL_H_GPP_F22, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F22_SSATA_SCLOCK [SGPIO_PCH_SSATA_CLOCK]
	{GPIO_SKL_H_GPP_F23, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_F23_SSATA_SLOAD [SGPIO_PCH_SSATA_LOAD]
// Group G
    {GPIO_SKL_H_GPP_G0,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G0_FANTACH0_FANTACH0IE [NOT USED]
	{GPIO_SKL_H_GPP_G1,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G1_FANTACH1_FANTACH1IE [NOT USED]
	{GPIO_SKL_H_GPP_G2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G2_FANTACH2_FANTACH2IE [NOT USED]
	{GPIO_SKL_H_GPP_G3,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G3_FANTACH3_FANTACH3IE [NOT USED]
	{GPIO_SKL_H_GPP_G4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G4_FANTACH4_FANTACH4IE [NOT USED]
	{GPIO_SKL_H_GPP_G5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G5_FANTACH5_FANTACH5IE [NOT USED]
	{GPIO_SKL_H_GPP_G6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G6_FANTACH6_FANTACH6IE [FM_CPU1_THERMTRIP_LATCH_LVT3_N]
	{GPIO_SKL_H_GPP_G7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G7_FANTACH7_FANTACH7IE [NOT USED]
	{GPIO_SKL_H_GPP_G8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G8_FANPWM0_FANPWM0IE [NOT USED]
	{GPIO_SKL_H_GPP_G9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G9_FANPWM1_FANPWM1IE [NOT USED]
	{GPIO_SKL_H_GPP_G10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G10_FANPWM2_FANPWM2IE [NOT USED]
	{GPIO_SKL_H_GPP_G11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G11_FANPWM3_FANPWM3IE [NOT USED]
	{GPIO_SKL_H_GPP_G12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_G12 [FM_BOARD_SKU_ID0]
	{GPIO_SKL_H_GPP_G13, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_G13 [FM_BOARD_SKU_ID1]
	{GPIO_SKL_H_GPP_G14, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_G14 [FM_BOARD_SKU_ID2]
	{GPIO_SKL_H_GPP_G15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_G15 [FM_BOARD_SKU_ID3]
	{GPIO_SKL_H_GPP_G16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_G16 [FM_BOARD_SKU_ID4]
	{GPIO_SKL_H_GPP_G17, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G17_ADR_COMPLETE [FM_ADR_COMPLETE]
	{GPIO_SKL_H_GPP_G18, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G18_NMI_N [FM_NMI_EVENT_N]
	{GPIO_SKL_H_GPP_G19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G19_SMI_N [FM_BIOS_SMI_ACTIVE_N]
	{GPIO_SKL_H_GPP_G20, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G20_SSATA_DEVSLP0 [IRQ_FORCE_NM_THROTTLE_N]
	{GPIO_SKL_H_GPP_G21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G21_SSATA_DEVSLP1 [FM_SOL_UART_CH_SEL
	{GPIO_SKL_H_GPP_G22, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G22_SSATA_DEVSLP2 [FM_CPU0_RC_EN
	{GPIO_SKL_H_GPP_G23, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_G23_SSATAXPCIE0_SSATAGP0 [FM_UARTSW_MSB_N
// Group H
	{GPIO_SKL_H_GPP_H0,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H0_SRCCLKREQ6_N [FM_UARTSW_LSB_N]
	{GPIO_SKL_H_GPP_H1,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H1_SRCCLKREQ7_N [FM_BACKUP_BIOS_SEL_N]
	{GPIO_SKL_H_GPP_H2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H2_SRCCLKREQ8_N [NOT USED]
	{GPIO_SKL_H_GPP_H3,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H3_SRCCLKREQ9_N [NOT USED]
	{GPIO_SKL_H_GPP_H4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H4_SRCCLKREQ10_N [NOT USED]
	{GPIO_SKL_H_GPP_H5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H5_SRCCLKREQ11_N [NOT USED]
	{GPIO_SKL_H_GPP_H6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H6_SRCCLKREQ12_N [NOT USED]
	{GPIO_SKL_H_GPP_H7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H7_SRCCLKREQ13_N [NOT USED]
	{GPIO_SKL_H_GPP_H8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H8_SRCCLKREQ14_N [NOT USED]
	{GPIO_SKL_H_GPP_H9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H9_SRCCLKREQ15_N [NOT USED]
	{GPIO_SKL_H_GPP_H10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H10_SML2CLK_IE [SMB_VR_STBY_LVC3_SCL_R1]
	{GPIO_SKL_H_GPP_H11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H11_SML2DATA_IE [SMB_VR_STBY_LVC3_SDA_R1]
	{GPIO_SKL_H_GPP_H12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H12_SML2ALERT_N_IE_N [FM_FLASH_ATTACH_CFG_STRAP]
	{GPIO_SKL_H_GPP_H13, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H13_SML3CLK_IE [NOT USED]
	{GPIO_SKL_H_GPP_H14, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H14_SML3DATA_IE [NOT USED]
	{GPIO_SKL_H_GPP_H15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_H15_SML3ALERT_N_IE_N [PU_ADR_TIMER_HOLD_OFF_N]
	{GPIO_SKL_H_GPP_H16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H16_SML4CLK_IE [SMB_LAN_STBY_LVC3_SCL_R1]
	{GPIO_SKL_H_GPP_H17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H17_SML4DATA_IE [SMB_LAN_STBY_LVC3_SDA_R1]
	{GPIO_SKL_H_GPP_H18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_H18_SML4ALERT_N_IE_N [FM_OC_DETECT_EN_N]
	{GPIO_SKL_H_GPP_H19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetNormal,GpioTermNone}},//GPP_H19_SSATAXPCIE1_SSATAGP1 [FP_PWR_ID_LED_N]
	{GPIO_SKL_H_GPP_H20, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_H20_SSATAXPCIE2_SSATAGP2 [FM_BMC_NMI_N]
	{GPIO_SKL_H_GPP_H21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_H21_SSATAXPCIE3_SSATAGP3 [FM_BIOS_SMI_ACTIVE_N]
	{GPIO_SKL_H_GPP_H22, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_H22_SSATAXPCIE4_SSATAGP4 [FM_PCH_BMC_THERMTRIP_N]
	{GPIO_SKL_H_GPP_H23, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,GpioTermNone}},//GPP_H23_SSATAXPCIE5_SSATAGP5 [FM_SSATA_PCIE_M2_SEL]
// Group I
    {GPIO_SKL_H_GPP_I0,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I0_LAN_TDO [JTAG_PCH_GBE_TDO]
	{GPIO_SKL_H_GPP_I1,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I1_LAN_TCK [JTAG_PCH_GBE_CLK]
	{GPIO_SKL_H_GPP_I2,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I2_LAN_TMS [JTAG_PCH_GBE_TMS]
	{GPIO_SKL_H_GPP_I3,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I3_LAN_TDI [JTAG_PCH_GBE_TDI]
	{GPIO_SKL_H_GPP_I4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I4_DO_RESET_IN_N [IRQ_DIMM_SAVE_LVT3_N]
	{GPIO_SKL_H_GPP_I5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I5_DO_RESET_OUT_N [IRQ_BOARD_BMC_ALERT_N]
	{GPIO_SKL_H_GPP_I6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I6_RESET_DONE [FM_CPU1_RC_ERROR_N]
	{GPIO_SKL_H_GPP_I7,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I7_LAN_TRST_N [JTAG_PCH_GBE_TRST_N]
	{GPIO_SKL_H_GPP_I8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I8_PCI_DIS_N [PU_10GBE_LOM_PCI_DISABLE_N]
	{GPIO_SKL_H_GPP_I9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I9_LAN_DIS_N [FM_10GBE_LOM_DISABLE_N]
	{GPIO_SKL_H_GPP_I10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_I10 [FM_BIOS_MRC_DEBUG_MSG_DIS_N]
// Group GPD
    {GPIO_SKL_H_GPD0,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPD0 [XDP_PCH_PWR_DEBUG_N]
	{GPIO_SKL_H_GPD1,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD1_ACPRESENT [FM_CPU1_SKTOCC_LVT3_N]
	{GPIO_SKL_H_GPD2,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD2_GBE_WAKE_N [RST_BMC_SRST_R_N]
	{GPIO_SKL_H_GPD3,    { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD3_PWRBTN_N [FM_PCH_PWRBTN_N]
	{GPIO_SKL_H_GPD4,    { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD4_SLP_S3_N [FM_SLPS3_N]
	{GPIO_SKL_H_GPD5,    { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD5_SLP_S4_N [FM_SLPS4_N]
	{GPIO_SKL_H_GPD6,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD6_SLP_A_N [FM_CPU0_SKTOCC_LVT3_N]
	{GPIO_SKL_H_GPD7,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD7 [FM_BATTERY_SENSE_EN_N]
	{GPIO_SKL_H_GPD8,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD8_SUSCLK [NOT USED]
	{GPIO_SKL_H_GPD9,    { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD9 [FM_BMC_CPLD_MP_RST_N]
	{GPIO_SKL_H_GPD10,   { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD10_SLP_S5_N [FM_CPU0_RC_ERROR_N]
	{GPIO_SKL_H_GPD11,   { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutHigh,    GpioIntDis,GpioResetPwrGood,  GpioTermNone}},//GPD11_GBEPHY [FM_GBE_LOM_DISABLE_N]
// Group J
    {GPIO_SKL_H_GPP_J0,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J0_LAN_LED_P0_0 [LED_GBE_P0_0]
	{GPIO_SKL_H_GPP_J1,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J1_LAN_LED_P0_1 [LED_GBE_P0_1]
	{GPIO_SKL_H_GPP_J2,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J2_LAN_LED_P1_0 [LED_GBE_P1_0]
	{GPIO_SKL_H_GPP_J3,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J3_LAN_LED_P1_1 [LED_GBE_P1_1]
	{GPIO_SKL_H_GPP_J4,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J4_LAN_LED_P2_0 [LED_GBE_P2_0]
	{GPIO_SKL_H_GPP_J5,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J5_LAN_LED_P2_1 [LED_GBE_P2_1]
	{GPIO_SKL_H_GPP_J6,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J6_LAN_LED_P3_0 [LED_GBE_P3_0]
	{GPIO_SKL_H_GPP_J7,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J7_LAN_LED_P3_1 [LED_GBE_P3_1]
	{GPIO_SKL_H_GPP_J8,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J8_LAN_I2C_SCL_MDC_P0 [SMB_PCH_MEZZ_LOM0_SCL]
	{GPIO_SKL_H_GPP_J9,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J9_LAN_I2C_SDA_MDIO_P0 [SMB_PCH_MEZZ_LOM0_SDA]
	{GPIO_SKL_H_GPP_J10, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J10_LAN_I2C_SCL_MDC_P1 [SMB_PCH_MEZZ_LOM1_SCL]
	{GPIO_SKL_H_GPP_J11, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J_11_SMB_GBE1_LVC3_R_SDA [SMB_PCH_MEZZ_LOM1_SDA]
	{GPIO_SKL_H_GPP_J12, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J12_LAN_I2C_SCL_MDC_P2 [SMB_PCH_MEZZ_LOM2_SCL]
	{GPIO_SKL_H_GPP_J13, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J13_LAN_I2C_SDA_MDIO_P2 [SMB_PCH_MEZZ_LOM2_SDA]
	{GPIO_SKL_H_GPP_J14, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,   GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J14_LAN_I2C_SCL_MDC_P3 [SMB_PCH_MEZZ_LOM3_SCL]
	{GPIO_SKL_H_GPP_J15, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J15_LAN_I2C_SDA_MDIO_P3 [SMB_PCH_MEZZ_LOM3_SDA]
	{GPIO_SKL_H_GPP_J16, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J16_LAN_SDP_P0_0 [FM_GBE0_LVC3_MOD_ABS]
	{GPIO_SKL_H_GPP_J17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J17_LAN_SDP_P0_1 [TP_PCH_GPP_J17]
	{GPIO_SKL_H_GPP_J18, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J18_LAN_SDP_P1_0 [FM_GBE1_LVC3_MOD_ABS]
	{GPIO_SKL_H_GPP_J19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J19_LAN_SDP_P1_1 [TP_PCH_GPP_J19]
	{GPIO_SKL_H_GPP_J20, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J20_LAN_SDP_P2_0 [FM_GBE2_LVC3_MOD_ABS]
	{GPIO_SKL_H_GPP_J21, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J21_LAN_SDP_P2_1 [TP_PCH_GPP_J21]
	{GPIO_SKL_H_GPP_J22, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J22_LAN_SDP_P3_0 [FM_GBE3_LVC3_MOD_ABS]
	{GPIO_SKL_H_GPP_J23, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_J23_LAN_SDP_P3_1 [TP_PCH_GPP_J23]
// Group K
    {GPIO_SKL_H_GPP_K0,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K0_LAN_NCSI_CLK_IN [CLK_50M_CKMNG_PCH_10GBE]
	{GPIO_SKL_H_GPP_K1,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K1_LAN_NCSI_TXD0 [RMII_BMC_PCH_SPRNGVLLE_TXD0]
	{GPIO_SKL_H_GPP_K2,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K2_LAN_NCSI_TXD1 [RMII_BMC_PCH_SPRNGVLLE_TXD1]
	{GPIO_SKL_H_GPP_K3,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K3_LAN_NCSI_TX_EN [RMII_BMC_PCH_SPRNGVLLE_TXEN]
	{GPIO_SKL_H_GPP_K4,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K4_LAN_NCSI_CRS_DV [RMII_BMC_PCH_SPRNGVLLE_CRSDV_R1]
	{GPIO_SKL_H_GPP_K5,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K5_LAN_NCSI_RXD0 [RMII_SPRNGVLLE_BMC_PCH_RXD0_R1]
	{GPIO_SKL_H_GPP_K6,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K6_LAN_NCSI_RXD1 [RMII_SPRNGVLLE_BMC_PCH_RXD1_R1]
	{GPIO_SKL_H_GPP_K7,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K7 [RMII_BMC_PCH_SPRNGVLLE_RXER_R]
	{GPIO_SKL_H_GPP_K8,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K8_LAN_NCSI_ARB_IN [RMII_PCH_SPRNGVLLE_ARB_IN]
	{GPIO_SKL_H_GPP_K9,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K9_LAN_NCSI_ARB_OUT [RMII_PCH_SPRNGVLLE_ARB_OUT_R]
	{GPIO_SKL_H_GPP_K10, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_K10_PE_RST_N [RST_PCIE_PCH_PERST_N]
// Group L
    //{GPIO_SKL_H_GPP_L0,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L0
	//{GPIO_SKL_H_GPP_L1,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirOut,   GpioOutHigh,    GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L1
	{GPIO_SKL_H_GPP_L2,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L2_TESTCH0_D0 [FM_PRSNT_2_1_N]
	{GPIO_SKL_H_GPP_L3,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L3_TESTCH0_D1 [FM_PRSNT_2_2_N]
	{GPIO_SKL_H_GPP_L4,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L4_TESTCH0_D2 [FM_PRSNT_2_3_N]
	{GPIO_SKL_H_GPP_L5,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L5_TESTCH0_D3 [FM_PRSNT_2_4_N]
	{GPIO_SKL_H_GPP_L6,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L6_TESTCH0_D4 [FM_PRSNT_2_5_N]
	{GPIO_SKL_H_GPP_L7,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L7_TESTCH0_D5 [FM_PRSNT_2_6_N]
	{GPIO_SKL_H_GPP_L8,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L8_TESTCH0_D6 [FM_OCP_MEZZB_PRES_N]
	{GPIO_SKL_H_GPP_L9,  { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L9_TESTCH0_D7 [FM_OCP_MEZZC_PRES_N]
	{GPIO_SKL_H_GPP_L10, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L10_TESTCH0_CLK [TP_PCH_GPP_L10]
	{GPIO_SKL_H_GPP_L11, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L11_TESTCH1_D0 [TP_PCH_GPP_L11]
	{GPIO_SKL_H_GPP_L12, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L12_TESTCH1_D1 [H_CPU0_MEMABC_MEMHOT_PCH_N]
	{GPIO_SKL_H_GPP_L13, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L13_TESTCH1_D2 [H_CPU0_MEMDEF_MEMHOT_PCH_N]
	{GPIO_SKL_H_GPP_L14, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L14_TESTCH1_D3 [H_CPU1_MEMGHJ_MEMHOT_PCH_N
	{GPIO_SKL_H_GPP_L15, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L15_TESTCH1_D4 [H_CPU1_MEMKLM_MEMHOT_PCH_N]
	{GPIO_SKL_H_GPP_L16, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L16_TESTCH1_D5 [FM_CPU0_PROCHOT_PCH_N]
	{GPIO_SKL_H_GPP_L17, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L17_TESTCH1_D6 [FM_CPU1_PROCHOT_PCH_N
	{GPIO_SKL_H_GPP_L18, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L18_TESTCH1_D7 [FM_CPU_ERR0_PCH_N]
	{GPIO_SKL_H_GPP_L19, { GpioPadModeGpio,    GpioHostOwnGpio, GpioDirIn,    GpioOutDefault, GpioIntDis,GpioResetDeep,  GpioTermNone}},//GPP_L19_TESTCH1_CLK [FM_CPU_ERR1_PCH_N]
};

UINTN mGpioTableSizeTiogaPass = sizeof(mGpioTableTiogaPass);