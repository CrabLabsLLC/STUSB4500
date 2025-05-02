/**
 * @file stusb4500_registers.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef STUSB4500_REGISTERS_H
#define STUSB4500_REGISTERS_H

#include <stdint.h>

/** @defgroup STUSB4500_Registers Register Addresses
 *  @brief STUSB4500 register offsets
 *  @{ */

/* Device identification and revision */
#define STUSB4500_REG_BCD_TYPEC_REV_LOW         0x06  /**< [R] Type-C revision (LSB) */
#define STUSB4500_REG_BCD_TYPEC_REV_HIGH        0x07  /**< [R] Type-C revision (MSB) */
#define STUSB4500_REG_BCD_USBPD_REV_LOW         0x08  /**< [R] USB-PD revision (LSB) */
#define STUSB4500_REG_BCD_USBPD_REV_HIGH        0x09  /**< [R] USB-PD revision (MSB) */
#define STUSB4500_REG_DEVICE_CAPAB_HIGH         0x0A  /**< [R] Device capabilities (high byte) */

/* Alert and status */
#define STUSB4500_REG_ALERT_STATUS_1            0x0B  /**< [R] Alert status register */
#define STUSB4500_REG_ALERT_STATUS_1_MASK       0x0C  /**< [R/W] Alert mask register */
#define STUSB4500_REG_PORT_STATUS_0             0x0D  /**< [R] Port status transition */
#define STUSB4500_REG_PORT_STATUS_1             0x0E  /**< [R] Port status */

/* Type-C monitoring */
#define STUSB4500_REG_TYPEC_MONITORING_STATUS_0 0x0F  /**< [R] Type-C monitoring status (low) */
#define STUSB4500_REG_TYPEC_MONITORING_STATUS_1 0x10  /**< [R] Type-C monitoring status (high) */

/* CC and power faults */
#define STUSB4500_REG_CC_STATUS                 0x11  /**< [R] CC line status */
#define STUSB4500_REG_CC_HW_FAULT_STATUS_0      0x12  /**< [R] CC hardware fault status (low) */
#define STUSB4500_REG_CC_HW_FAULT_STATUS_1      0x13  /**< [R] CC hardware fault status (high) */

/* PD and Type-C state machines */
#define STUSB4500_REG_PD_TYPEC_STATUS           0x14  /**< [R] PD-TypeC protocol status */
#define STUSB4500_REG_TYPEC_STATUS              0x15  /**< [R] Type-C FSM state */
#define STUSB4500_REG_PRT_STATUS                0x16  /**< [R] Protocol layer status */

/* PD commands and monitoring */
#define STUSB4500_REG_PD_COMMAND_CTRL           0x1A  /**< [R/W] PD command/control */
#define STUSB4500_REG_MONITORING_CTRL_0         0x20  /**< [R/W] Monitoring control (low) */
#define STUSB4500_REG_MONITORING_CTRL_2         0x22  /**< [R/W] Monitoring control (high) */

/* Reset and VBUS control */
#define STUSB4500_REG_RESET_CTRL                0x23  /**< [R/W] Software reset control */
#define STUSB4500_REG_VBUS_DISCHARGE_TIME_CTRL  0x25  /**< [R/W] VBUS discharge timing */
#define STUSB4500_REG_VBUS_DISCHARGE_CTRL       0x26  /**< [R/W] VBUS discharge enable */
#define STUSB4500_REG_VBUS_CTRL                 0x27  /**< [R/W] VBUS sink enable */

/* Policy engine and GPIO */
#define STUSB4500_REG_PE_FSM                    0x29  /**< [R] Policy engine FSM state */
#define STUSB4500_REG_GPIO_SW_GPIO              0x2D  /**< [R/W] Software-controlled GPIO */

/* Device identifier */
#define STUSB4500_REG_DEVICE_ID                 0x2F  /**< [R] Device identifier */

/* RX message reception registers */
#define STUSB4500_REG_RX_HEADER_LOW             0x31  /**< [R] RX header (LSB) */
#define STUSB4500_REG_RX_HEADER_HIGH            0x32  /**< [R] RX header (MSB) */
#define STUSB4500_REG_RX_DATA_OBJ1_0            0x33  /**< [R] RX Data Object #1 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ1_1            0x34  /**< [R] RX Data Object #1 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ1_2            0x35  /**< [R] RX Data Object #1 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ1_3            0x36  /**< [R] RX Data Object #1 [31:24] */
#define STUSB4500_REG_RX_DATA_OBJ2_0            0x37  /**< [R] RX Data Object #2 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ2_1            0x38  /**< [R] RX Data Object #2 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ2_2            0x39  /**< [R] RX Data Object #2 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ2_3            0x3A  /**< [R] RX Data Object #2 [31:24] */
#define STUSB4500_REG_RX_DATA_OBJ3_0            0x3B  /**< [R] RX Data Object #3 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ3_1            0x3C  /**< [R] RX Data Object #3 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ3_2            0x3D  /**< [R] RX Data Object #3 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ3_3            0x3E  /**< [R] RX Data Object #3 [31:24] */
#define STUSB4500_REG_RX_DATA_OBJ4_0            0x3F  /**< [R] RX Data Object #4 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ4_1            0x40  /**< [R] RX Data Object #4 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ4_2            0x41  /**< [R] RX Data Object #4 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ4_3            0x42  /**< [R] RX Data Object #4 [31:24] */
#define STUSB4500_REG_RX_DATA_OBJ5_0            0x43  /**< [R] RX Data Object #5 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ5_1            0x44  /**< [R] RX Data Object #5 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ5_2            0x45  /**< [R] RX Data Object #5 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ5_3            0x46  /**< [R] RX Data Object #5 [31:24] */
#define STUSB4500_REG_RX_DATA_OBJ6_0            0x47  /**< [R] RX Data Object #6 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ6_1            0x48  /**< [R] RX Data Object #6 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ6_2            0x49  /**< [R] RX Data Object #6 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ6_3            0x4A  /**< [R] RX Data Object #6 [31:24] */
#define STUSB4500_REG_RX_DATA_OBJ7_0            0x4B  /**< [R] RX Data Object #7 [7:0] */
#define STUSB4500_REG_RX_DATA_OBJ7_1            0x4C  /**< [R] RX Data Object #7 [15:8] */
#define STUSB4500_REG_RX_DATA_OBJ7_2            0x4D  /**< [R] RX Data Object #7 [23:16] */
#define STUSB4500_REG_RX_DATA_OBJ7_3            0x4E  /**< [R] RX Data Object #7 [31:24] */

/* TX message transmission registers */
#define STUSB4500_REG_TX_HEADER_LOW             0x51  /**< [R/W] TX header (LSB) */
#define STUSB4500_REG_TX_HEADER_HIGH            0x52  /**< [R/W] TX header (MSB) */

/* Sink PDO configuration */
#define STUSB4500_REG_DPM_PDO_NUMB              0x70  /**< [R/W] Number of active Sink PDOs */
#define STUSB4500_REG_DPM_SNK_PDO1_0            0x85  /**< [R/W] Sink PDO1 [7:0] */
#define STUSB4500_REG_DPM_SNK_PDO1_1            0x86  /**< [R/W] Sink PDO1 [15:8] */
#define STUSB4500_REG_DPM_SNK_PDO1_2            0x87  /**< [R/W] Sink PDO1 [23:16] */
#define STUSB4500_REG_DPM_SNK_PDO1_3            0x88  /**< [R/W] Sink PDO1 [31:24] */
#define STUSB4500_REG_DPM_SNK_PDO2_0            0x89  /**< [R/W] Sink PDO2 [7:0] */
#define STUSB4500_REG_DPM_SNK_PDO2_1            0x8A  /**< [R/W] Sink PDO2 [15:8] */
#define STUSB4500_REG_DPM_SNK_PDO2_2            0x8B  /**< [R/W] Sink PDO2 [23:16] */
#define STUSB4500_REG_DPM_SNK_PDO2_3            0x8C  /**< [R/W] Sink PDO2 [31:24] */
#define STUSB4500_REG_DPM_SNK_PDO3_0            0x8D  /**< [R/W] Sink PDO3 [7:0] */
#define STUSB4500_REG_DPM_SNK_PDO3_1            0x8E  /**< [R/W] Sink PDO3 [15:8] */
#define STUSB4500_REG_DPM_SNK_PDO3_2            0x8F  /**< [R/W] Sink PDO3 [23:16] */
#define STUSB4500_REG_DPM_SNK_PDO3_3            0x90  /**< [R/W] Sink PDO3 [31:24] */

/* RDO status registers */
#define STUSB4500_REG_RDO_REG_STATUS_0          0x91  /**< [R] RDO status [7:0] */
#define STUSB4500_REG_RDO_REG_STATUS_1          0x92  /**< [R] RDO status [15:8] */
#define STUSB4500_REG_RDO_REG_STATUS_2          0x93  /**< [R] RDO status [23:16] */
#define STUSB4500_REG_RDO_REG_STATUS_3          0x94  /**< [R] RDO status [31:24] */

/** @} */

/** @defgroup STUSB4500_Bitfields Register Bitfields
 *  @brief Shift and mask macros for each register field
 *  @{ */

/* BCD and Device Capability Fields */
/** Type-C revision (LSB) */
#define STUSB4500_BCD_TYPEC_REV_LOW_SHIFT       0
#define STUSB4500_BCD_TYPEC_REV_LOW_MASK        (0xFFU << STUSB4500_BCD_TYPEC_REV_LOW_SHIFT)
/** Type-C revision (MSB) */
#define STUSB4500_BCD_TYPEC_REV_HIGH_SHIFT      0
#define STUSB4500_BCD_TYPEC_REV_HIGH_MASK       (0xFFU << STUSB4500_BCD_TYPEC_REV_HIGH_SHIFT)
/** USB-PD revision (LSB) */
#define STUSB4500_BCD_USBPD_REV_LOW_SHIFT       0
#define STUSB4500_BCD_USBPD_REV_LOW_MASK        (0xFFU << STUSB4500_BCD_USBPD_REV_LOW_SHIFT)
/** USB-PD revision (MSB) */
#define STUSB4500_BCD_USBPD_REV_HIGH_SHIFT      0
#define STUSB4500_BCD_USBPD_REV_HIGH_MASK       (0xFFU << STUSB4500_BCD_USBPD_REV_HIGH_SHIFT)
/** Device capabilities (high byte) */
#define STUSB4500_DEVICE_CAPAB_HIGH_SHIFT       0
#define STUSB4500_DEVICE_CAPAB_HIGH_MASK        (0xFFU << STUSB4500_DEVICE_CAPAB_HIGH_SHIFT)

/* ALERT_STATUS_1 Bitfields @ 0x0B */
/** Port status alert */
#define STUSB4500_PORT_STATUS_AL_SHIFT          6
#define STUSB4500_PORT_STATUS_AL_MASK           (0x1U << STUSB4500_PORT_STATUS_AL_SHIFT)
/** Type-C monitoring alert */
#define STUSB4500_TYPEC_MON_STATUS_AL_SHIFT     5
#define STUSB4500_TYPEC_MON_STATUS_AL_MASK      (0x1U << STUSB4500_TYPEC_MON_STATUS_AL_SHIFT)
/** CC hardware fault alert */
#define STUSB4500_CC_HW_FAULT_AL_SHIFT          4
#define STUSB4500_CC_HW_FAULT_AL_MASK           (0x1U << STUSB4500_CC_HW_FAULT_AL_SHIFT)
/** Protocol layer alert */
#define STUSB4500_PRT_STATUS_AL_SHIFT           1
#define STUSB4500_PRT_STATUS_AL_MASK            (0x1U << STUSB4500_PRT_STATUS_AL_SHIFT)

/* ALERT_STATUS_1_MASK Bitfields @ 0x0C */
/** Port status mask */
#define STUSB4500_PORT_STATUS_AL_M_SHIFT        6
#define STUSB4500_PORT_STATUS_AL_M_MASK         (0x1U << STUSB4500_PORT_STATUS_AL_M_SHIFT)
/** Type-C monitoring mask */
#define STUSB4500_TYPEC_MON_STATUS_M_SHIFT      5
#define STUSB4500_TYPEC_MON_STATUS_M_MASK       (0x1U << STUSB4500_TYPEC_MON_STATUS_M_SHIFT)
/** CC fault mask */
#define STUSB4500_CC_FAULT_AL_M_SHIFT           4
#define STUSB4500_CC_FAULT_AL_M_MASK            (0x1U << STUSB4500_CC_FAULT_AL_M_SHIFT)
/** Protocol layer mask */
#define STUSB4500_PRT_STATUS_AL_M_SHIFT         1
#define STUSB4500_PRT_STATUS_AL_M_MASK          (0x1U << STUSB4500_PRT_STATUS_AL_M_SHIFT)

/* PORT_STATUS_0 Bitfields @ 0x0D */
/** Attach transition flag */
#define STUSB4500_ATTACH_TRANS_SHIFT            0
#define STUSB4500_ATTACH_TRANS_MASK             (0x1U << STUSB4500_ATTACH_TRANS_SHIFT)

/* PORT_STATUS_1 Bitfields @ 0x0E */
/** Attached device type [7:5] */
#define STUSB4500_ATTACHED_DEVICE_SHIFT         5
#define STUSB4500_ATTACHED_DEVICE_MASK          (0x7U << STUSB4500_ATTACHED_DEVICE_SHIFT)
/** Power mode flag */
#define STUSB4500_POWER_MODE_SHIFT              3
#define STUSB4500_POWER_MODE_MASK               (0x1U << STUSB4500_POWER_MODE_SHIFT)
/** Data role flag */
#define STUSB4500_DATA_MODE_SHIFT               2
#define STUSB4500_DATA_MODE_MASK                (0x1U << STUSB4500_DATA_MODE_SHIFT)
/** Attach state flag */
#define STUSB4500_ATTACH_STATE_SHIFT            0
#define STUSB4500_ATTACH_STATE_MASK             (0x1U << STUSB4500_ATTACH_STATE_SHIFT)

/* TYPEC_MONITORING_STATUS_0 Bitfields @ 0x0F */
/** VBUS overvoltage flag */
#define STUSB4500_VBUS_HIGH_SHIFT               5
#define STUSB4500_VBUS_HIGH_MASK                (0x1U << STUSB4500_VBUS_HIGH_SHIFT)
/** VBUS undervoltage flag */
#define STUSB4500_VBUS_LOW_SHIFT                4
#define STUSB4500_VBUS_LOW_MASK                 (0x1U << STUSB4500_VBUS_LOW_SHIFT)
/** VBUS ready transition */
#define STUSB4500_VBUS_READY_TRANS_SHIFT        3
#define STUSB4500_VBUS_READY_TRANS_MASK         (0x1U << STUSB4500_VBUS_READY_TRANS_SHIFT)
/** VSAFE0V transition */
#define STUSB4500_VBUS_VSAFE0V_TRANS_SHIFT      2
#define STUSB4500_VBUS_VSAFE0V_TRANS_MASK       (0x1U << STUSB4500_VBUS_VSAFE0V_TRANS_SHIFT)
/** VBUS valid transition */
#define STUSB4500_VBUS_VALID_SNK_TRANS_SHIFT    1
#define STUSB4500_VBUS_VALID_SNK_TRANS_MASK     (0x1U << STUSB4500_VBUS_VALID_SNK_TRANS_SHIFT)

/* TYPEC_MONITORING_STATUS_1 Bitfields @ 0x10 */
/** VBUS ready state */
#define STUSB4500_VBUS_READY_SHIFT              3
#define STUSB4500_VBUS_READY_MASK               (0x1U << STUSB4500_VBUS_READY_SHIFT)
/** VSAFE0V state */
#define STUSB4500_VBUS_VSAFE0V_SHIFT            2
#define STUSB4500_VBUS_VSAFE0V_MASK             (0x1U << STUSB4500_VBUS_VSAFE0V_SHIFT)
/** VBUS valid state */
#define STUSB4500_VBUS_VALID_SNK_SHIFT          1
#define STUSB4500_VBUS_VALID_SNK_MASK           (0x1U << STUSB4500_VBUS_VALID_SNK_SHIFT)

/* CC_STATUS Bitfields @ 0x11 */
/** Looking for connection */
#define STUSB4500_LOOKING_CONNECTION_SHIFT      5
#define STUSB4500_LOOKING_CONNECTION_MASK       (0x1U << STUSB4500_LOOKING_CONNECTION_SHIFT)
/** Connection result */
#define STUSB4500_CONNECT_RESULT_SHIFT          4
#define STUSB4500_CONNECT_RESULT_MASK           (0x1U << STUSB4500_CONNECT_RESULT_SHIFT)
/** CC2 state [3:2] */
#define STUSB4500_CC2_STATE_SHIFT               2
#define STUSB4500_CC2_STATE_MASK                (0x3U << STUSB4500_CC2_STATE_SHIFT)
/** CC1 state [1:0] */
#define STUSB4500_CC1_STATE_SHIFT               0
#define STUSB4500_CC1_STATE_MASK                (0x3U << STUSB4500_CC1_STATE_SHIFT)

/* CC_HW_FAULT_STATUS_0 Bitfields @ 0x12 */
/** OVP transition */
#define STUSB4500_VPU_OVP_TRANS_SHIFT           5
#define STUSB4500_VPU_OVP_TRANS_MASK            (0x1U << STUSB4500_VPU_OVP_TRANS_SHIFT)
/** VPU valid transition */
#define STUSB4500_VPU_VALID_TRANS_SHIFT         4
#define STUSB4500_VPU_VALID_TRANS_MASK          (0x1U << STUSB4500_VPU_VALID_TRANS_SHIFT)

/* CC_HW_FAULT_STATUS_1 Bitfields @ 0x13 */
/** OVP fault */
#define STUSB4500_VPU_OVP_FAULT_SHIFT           7
#define STUSB4500_VPU_OVP_FAULT_MASK            (0x1U << STUSB4500_VPU_OVP_FAULT_SHIFT)
/** VPU valid */
#define STUSB4500_VPU_VALID_SHIFT               6
#define STUSB4500_VPU_VALID_MASK                (0x1U << STUSB4500_VPU_VALID_SHIFT)
/** VBUS discharge fault */
#define STUSB4500_VBUS_DISCH_FAULT_SHIFT        4
#define STUSB4500_VBUS_DISCH_FAULT_MASK         (0x1U << STUSB4500_VBUS_DISCH_FAULT_SHIFT)

/* PD_TYPEC_STATUS Bitfields @ 0x14 */
/** PD handshake check [3:0] */
#define STUSB4500_PD_HANDCHECK_SHIFT            0
#define STUSB4500_PD_HANDCHECK_MASK             (0xFU << STUSB4500_PD_HANDCHECK_SHIFT)

/* TYPEC_STATUS Bitfields @ 0x15 */
/** Cable orientation */
#define STUSB4500_REVERSE_SHIFT                 7
#define STUSB4500_REVERSE_MASK                  (0x1U << STUSB4500_REVERSE_SHIFT)
/** FSM state [4:0] */
#define STUSB4500_FSM_STATE_SHIFT               0
#define STUSB4500_FSM_STATE_MASK                (0x1FU << STUSB4500_FSM_STATE_SHIFT)

/* PRT_STATUS Bitfields @ 0x16 */
/** PRL message received */
#define STUSB4500_PRL_MSG_RCVD_SHIFT            2
#define STUSB4500_PRL_MSG_RCVD_MASK             (0x1U << STUSB4500_PRL_MSG_RCVD_SHIFT)
/** PRL hardware reset received */
#define STUSB4500_PRL_HW_RST_RCVD_SHIFT         0
#define STUSB4500_PRL_HW_RST_RCVD_MASK          (0x1U << STUSB4500_PRL_HW_RST_RCVD_SHIFT)

/* PD_COMMAND_CTRL Bitfields @ 0x1A */
/** Send PD command [5:0] */
#define STUSB4500_SEND_CMD_SHIFT                0
#define STUSB4500_SEND_CMD_MASK                 (0x3FU << STUSB4500_SEND_CMD_SHIFT)

/* MONITORING_CTRL_0 Bitfields @ 0x20 */
/** Sink disconnect threshold */
#define STUSB4500_SNK_DISC_TH_SHIFT             3
#define STUSB4500_SNK_DISC_TH_MASK              (0x1U << STUSB4500_SNK_DISC_TH_SHIFT)

/* MONITORING_CTRL_2 Bitfields @ 0x22 */
/** Overvoltage level [7:4] */
#define STUSB4500_VSHIFT_HIGH_SHIFT             4
#define STUSB4500_VSHIFT_HIGH_MASK              (0xFU << STUSB4500_VSHIFT_HIGH_SHIFT)
/** Undervoltage level [3:0] */
#define STUSB4500_VSHIFT_LOW_SHIFT              0
#define STUSB4500_VSHIFT_LOW_MASK               (0xFU << STUSB4500_VSHIFT_LOW_SHIFT)

/* RESET_CTRL Bitfields @ 0x23 */
/** Software reset enable */
#define STUSB4500_SW_RESET_SHIFT                0
#define STUSB4500_SW_RESET_MASK                 (0x1U << STUSB4500_SW_RESET_SHIFT)

/* VBUS_DISCHARGE_TIME_CTRL Bitfields @ 0x25 */
/** Time to 0V [7:4] */
#define STUSB4500_DISCH_TIME_TO0V_SHIFT         4
#define STUSB4500_DISCH_TIME_TO0V_MASK          (0xFU << STUSB4500_DISCH_TIME_TO0V_SHIFT)
/** Transition time [3:0] */
#define STUSB4500_DISCH_TIME_TRANS_SHIFT        0
#define STUSB4500_DISCH_TIME_TRANS_MASK         (0xFU << STUSB4500_DISCH_TIME_TRANS_SHIFT)

/* VBUS_DISCHARGE_CTRL Bitfields @ 0x26 */
/** Discharge enable */
#define STUSB4500_DISCH_EN_SHIFT                7
#define STUSB4500_DISCH_EN_MASK                 (0x1U << STUSB4500_DISCH_EN_SHIFT)

/* VBUS_CTRL Bitfields @ 0x27 */
/** Sink VBUS enable */
#define STUSB4500_SINK_VBUS_EN_SHIFT            1
#define STUSB4500_SINK_VBUS_EN_MASK             (0x1U << STUSB4500_SINK_VBUS_EN_SHIFT)

/* PE_FSM Bitfields @ 0x29 */
/** Policy engine FSM state [7:0] */
#define STUSB4500_PE_FSM_SHIFT                  0
#define STUSB4500_PE_FSM_MASK                   (0xFFU << STUSB4500_PE_FSM_SHIFT)

/* GPIO_SW_GPIO Bitfields @ 0x2D */
/** Software GPIO state */
#define STUSB4500_GPIO_SHIFT                    0
#define STUSB4500_GPIO_MASK                     (0x1U << STUSB4500_GPIO_SHIFT)

/* DEVICE_ID Bitfields @ 0x2F */
/** Device ID [7:0] */
#define STUSB4500_ID_SHIFT                      0
#define STUSB4500_ID_MASK                       (0xFFU << STUSB4500_ID_SHIFT)

/* RX_HEADER Bitfields */
/** RX header low byte */
#define STUSB4500_RX_HDR_LOW_SHIFT              0
#define STUSB4500_RX_HDR_LOW_MASK               (0xFFU << STUSB4500_RX_HDR_LOW_SHIFT)
/** RX header high byte */
#define STUSB4500_RX_HDR_HIGH_SHIFT             0
#define STUSB4500_RX_HDR_HIGH_MASK              (0xFFU << STUSB4500_RX_HDR_HIGH_SHIFT)

/* RX_DATA_OBJ Bitfields */
/** RX data object byte [7:0] */
#define STUSB4500_RX_OBJ_BYTE_SHIFT             0
#define STUSB4500_RX_OBJ_BYTE_MASK              (0xFFU << STUSB4500_RX_OBJ_BYTE_SHIFT)

/* TX_HEADER Bitfields */
/** TX header low byte */
#define STUSB4500_TX_HDR_LOW_SHIFT              0
#define STUSB4500_TX_HDR_LOW_MASK               (0xFFU << STUSB4500_TX_HDR_LOW_SHIFT)
/** TX header high byte */
#define STUSB4500_TX_HDR_HIGH_SHIFT             0
#define STUSB4500_TX_HDR_HIGH_MASK              (0xFFU << STUSB4500_TX_HDR_HIGH_SHIFT)

/* DPM_PDO_NUMB Bitfields @ 0x70 */
/** Number of Sink PDOs [2:0] */
#define STUSB4500_PDO_NUM_SHIFT                 0
#define STUSB4500_PDO_NUM_MASK                  (0x7U << STUSB4500_PDO_NUM_SHIFT)

/* DPM_SNK_PDO Bitfields */
/** PDO byte [7:0] */
#define STUSB4500_PDO_BYTE_SHIFT                0
#define STUSB4500_PDO_BYTE_MASK                 (0xFFU << STUSB4500_PDO_BYTE_SHIFT)

/* RDO_REG_STATUS Bitfields */
/** RDO status byte [7:0] */
#define STUSB4500_RDO_BYTE_SHIFT                0
#define STUSB4500_RDO_BYTE_MASK                 (0xFFU << STUSB4500_RDO_BYTE_SHIFT)

/** @} */
#endif /* STUSB4500_REGISTERS_H */
