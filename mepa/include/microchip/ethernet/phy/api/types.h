// Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
// SPDX-License-Identifier: MIT

#ifndef _MICROCHIP_ETHERNET_PHY_API_TYPES_H_
#define _MICROCHIP_ETHERNET_PHY_API_TYPES_H_

#include <microchip/ethernet/common.h>
#include <microchip/ethernet/hdr_start.h>  // ALL INCLUDE ABOVE THIS LINE

typedef mesa_aneg_t mepa_aneg_t;
typedef mesa_bool_t mepa_bool_t;
typedef mesa_chip_no_t mepa_chip_no_t;
typedef mesa_fiber_port_speed_t mepa_fiber_port_speed_t;
typedef mesa_phy_mdi_t mepa_mdi_t;
typedef mesa_phy_media_interface_t mepa_media_interface_t;
typedef mesa_port_interface_t mepa_port_interface_t;
typedef mesa_port_no_t mepa_port_no_t;
typedef mesa_port_speed_t mepa_port_speed_t;
typedef mesa_rc mepa_rc;
typedef mesa_sd10g_media_type_t mepa_sd10g_media_type_t;
typedef mesa_phy_power_mode_t mepa_power_mode_t;
typedef mesa_phy_status_1g_t mepa_aneg_status_t;
typedef mesa_phy_rgmii_conf_t mepa_rgmii_conf_t;
typedef mesa_phy_tbi_conf_t mepa_tbi_conf_t;
typedef mesa_phy_forced_reset_t mepa_forced_reset_t;
typedef mesa_phy_pkt_mode_t mepa_pkt_mode_t;
typedef mesa_phy_reset_conf_t mepa_reset_conf_t;
typedef mesa_phy_event_t mepa_event_t;
typedef mesa_phy_veriphy_status_t mepa_cable_diag_status_t;
typedef mesa_port_admin_state_t mepa_port_admin_state_t;

/** \brief Cable diagnostics status */
#define MEPA_CABLE_DIAG_STATUS_OK        MESA_VERIPHY_STATUS_OK
#define MEPA_CABLE_DIAG_STATUS_OPEN      MESA_VERIPHY_STATUS_OPEN
#define MEPA_CABLE_DIAG_STATUS_SHORT     MESA_VERIPHY_STATUS_SHORT
#define MEPA_CABLE_DIAG_STATUS_ABNORM    MESA_VERIPHY_STATUS_ABNORM
#define MEPA_CABLE_DIAG_STATUS_SHORT_A   MESA_VERIPHY_STATUS_SHORT_A
#define MEPA_CABLE_DIAG_STATUS_SHORT_B   MESA_VERIPHY_STATUS_SHORT_B
#define MEPA_CABLE_DIAG_STATUS_SHORT_C   MESA_VERIPHY_STATUS_SHORT_C
#define MEPA_CABLE_DIAG_STATUS_SHORT_D   MESA_VERIPHY_STATUS_SHORT_D
#define MEPA_CABLE_DIAG_STATUS_COUPL_A   MESA_VERIPHY_STATUS_COUPL_A
#define MEPA_CABLE_DIAG_STATUS_COUPL_B   MESA_VERIPHY_STATUS_COUPL_B
#define MEPA_CABLE_DIAG_STATUS_COUPL_C   MESA_VERIPHY_STATUS_COUPL_C
#define MEPA_CABLE_DIAG_STATUS_COUPL_D   MESA_VERIPHY_STATUS_COUPL_D
#define MEPA_CABLE_DIAG_STATUS_UNKNOWN   MESA_VERIPHY_STATUS_UNKNOWN
#define MEPA_CABLE_DIAG_STATUS_RUNNING   MESA_VERIPHY_STATUS_RUNNING

/** \brief PHY auto negotiation advertisement */
typedef struct {
    mepa_bool_t speed_10m_hdx;    /**< 10Mbps, half duplex */
    mepa_bool_t speed_10m_fdx;    /**< 10Mbps, full duplex */
    mepa_bool_t speed_100m_hdx;   /**< 100Mbps, half duplex */
    mepa_bool_t speed_100m_fdx;   /**< 100Mbps, full duplex */
    mepa_bool_t speed_1g_fdx;     /**< 1000Mpbs, full duplex */
    mepa_bool_t speed_1g_hdx;     /**< 1000Mpbs, full duplex */
    mepa_bool_t tx_remote_fault;  /**< Local Application fault indication for Link Partner */
    mepa_bool_t speed_2g5_fdx;    /**< 2500Mpbs, full duplex */
    mepa_bool_t speed_5g_fdx;     /**< 5GE, full duplex */
    mepa_bool_t speed_10g_fdx;    /**< 10GE, full duplex */
    mepa_bool_t no_restart_aneg;  /**< Do not restart aneg */
} mepa_aneg_adv_t;

/** \brief Cable diagnostics result */
typedef struct {
    mesa_bool_t               link;      /**< Link status */
    mepa_cable_diag_status_t  status[4]; /**< Status, pair A-D (0-3) */
    uint8_t                   length[4]; /**< Length (meters), pair A-D (0-3) */
} mepa_cable_diag_result_t;

typedef struct {
    mepa_media_interface_t media_intf;
} mepa_reset_param_t;

/* mepa_rc error codes */
#define MEPA_RC_OK                              MESA_RC_OK
#define MEPA_RC_ERROR                           MESA_RC_ERROR
#define MEPA_RC_INV_STATE                       MESA_RC_INV_STATE
#define MEPA_RC_INCOMPLETE                      MESA_RC_INCOMPLETE
#define MEPA_RC_NOT_IMPLEMENTED                 MESA_RC_NOT_IMPLEMENTED
#define MEPA_RC_ERR_PARM                        MESA_RC_ERR_PARM
#define MEPA_RC_ERR_NO_RES                      MESA_RC_ERR_NO_RES
#define MEPA_RC_ERR_KR_CONF_NOT_SUPPORTED       MESA_RC_ERR_KR_CONF_NOT_SUPPORTED
#define MEPA_RC_ERR_KR_CONF_INVALID_PARAMETER   MESA_RC_ERR_KR_CONF_INVALID_PARAMETER

typedef enum {
    MEPA_TRACE_LVL_RACKET  = 1,
    MEPA_TRACE_LVL_NOISE   = 2,
    MEPA_TRACE_LVL_DEBUG   = 4,
    MEPA_TRACE_LVL_INFO    = 6,
    MEPA_TRACE_LVL_WARNING = 8,
    MEPA_TRACE_LVL_ERROR   = 9,
    MEPA_TRACE_LVL_NONE    = 10,
} mepa_trace_level_t;

#include <microchip/ethernet/hdr_end.h>  // ALL INCLUDE ABOVE THIS LINE
#endif // _MICROCHIP_ETHERNET_PHY_API_TYPES_H_