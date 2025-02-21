/*
 * Copyright (c) 2019-2022 Rockchip Eletronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef ___RK_AIQ_CALIB_DB_V2_TYPES_ISP32_H__
#define ___RK_AIQ_CALIB_DB_V2_TYPES_ISP32_H__

#include "ablc_head_V32.h"
#include "adegamma_head.h"
#include "adehaze_head.h"
#include "adpcc_head.h"
#include "adrc_head.h"
#include "aec_head.h"
#include "af_head.h"
#include "agamma_head.h"
#include "agic_head.h"
#include "aie_head.h"
#include "alsc_head.h"
#include "amerge_head.h"
#include "atmo_head.h"
#include "awb_head.h"
#include "bayer2dnr_head_v23.h"
#include "bayertnr_head_v23.h"
#include "cac_head.h"
#include "ccm_head.h"
#include "cgc_head.h"
#include "cnr_head_v30.h"
#include "cproc_head.h"
#include "cpsl_head.h"
#include "csm_head.h"
#include "debayer_head.h"
#include "fec_head.h"
#include "gain_head_v2.h"
#include "ldch_head.h"
#include "lut3d_head.h"
#include "sharp_head_v33.h"
#include "thumbnails_head.h"
#include "ynr_head_v22.h"
#include "rkpostisp_head_v1.h"

#if defined(ISP_HW_V32)
#ifdef USE_NEWSTRUCT
#include "isp/rk_aiq_isp_dm21.h"
#include "algos/rk_aiq_api_types_dm.h"
#include "isp/rk_aiq_isp_btnr32.h"
#include "algos/rk_aiq_api_types_btnr32.h"
#include "isp/rk_aiq_isp_gamma21.h"
#include "algos/rk_aiq_api_types_gamma.h"
#include "isp/rk_aiq_isp_ynr32.h"
#include "algos/rk_aiq_api_types_ynr.h"
#include "isp/rk_aiq_isp_sharp32.h"
#include "algos/rk_aiq_api_types_sharp.h"
#include "isp/rk_aiq_isp_cnr32.h"
#include "algos/rk_aiq_api_types_cnr.h"
#include "isp/rk_aiq_isp_drc32.h"
#include "algos/rk_aiq_api_types_drc.h"
#include "isp/rk_aiq_isp_dehaze22.h"
#include "algos/rk_aiq_api_types_dehaze.h"
#include "isp/rk_aiq_isp_dpcc20.h"
#include "algos/rk_aiq_api_types_dpcc20.h"
#endif
#endif

RKAIQ_BEGIN_DECLARE

typedef struct CalibDbV2_ColorAsGrey_Param_s {
    // M4_BOOL_DESC("enable", "0")
    bool enable;
    // M4_NUMBER_DESC("skip_frame", "s8", M4_RANGE(0,255), "10", M4_DIGIT(0))
    int8_t skip_frame;
} CalibDbV2_ColorAsGrey_Param_t;

typedef struct CalibDbV2_ColorAsGrey_s {
    // M4_STRUCT_DESC("param", "normal_ui_style")
    CalibDbV2_ColorAsGrey_Param_t param;
} CalibDbV2_ColorAsGrey_t;

typedef struct CalibDbV2_LUMA_DETECT_s {
    unsigned char luma_detect_en;
    int fixed_times;
    float mutation_threshold;
    float mutation_threshold_level2;
} CalibDbV2_LUMA_DETECT_t;

typedef struct CamCalibDbV2ContextIsp32_s {
    // M4_STRUCT_DESC("AEC", "normal_ui_style")
    CalibDb_Aec_ParaV2_t ae_calib;
    // M4_STRUCT_DESC("wb_v32", "normal_ui_style")
    CalibDbV2_Wb_Para_V32_t wb_v32;
    // M4_STRUCT_DESC("ablcV32_calib", "normal_ui_style")
    CalibDbV2_Blc_V32_t ablcV32_calib;
    // M4_STRUCT_DESC("ccm_calib", "normal_ui_style")
    CalibDbV2_Ccm_Para_V32_t ccm_calib_v2;
    // M4_STRUCT_DESC("lut3d_calib", "normal_ui_style")
    CalibDbV2_Lut3D_Para_V2_t lut3d_calib;
    // M4_STRUCT_DESC("degamma", "curve_ui_type_A")
    CalibDbV2_Adegmma_t adegamma_calib;
#if defined(ISP_HW_V32)
    // M4_STRUCT_DESC("agic_calib_v21", "normal_ui_style")
    CalibDbV2_Gic_V21_t agic_calib_v21;
#endif

#if defined(ISP_HW_V32)
    #ifdef USE_NEWSTRUCT
    // M4_STRUCT_DESC("demosaic", "normal_ui_style")
    dm_api_attrib_t demosaic;
    #else
    // M4_STRUCT_DESC("debayer_calib", "normal_ui_style")
    CalibDbV2_Debayer_v2_t debayer_v2;
    #endif
#endif

#if defined(ISP_HW_V32_LITE)
    // M4_STRUCT_DESC("debayer_calib", "normal_ui_style")
    CalibDbV2_Debayer_v2_lite_t debayer_v2_lite;
#endif

    // M4_STRUCT_DESC("Amerge_calib", "normal_ui_style")
    CalibDbV2_merge_v12_t amerge_calib_v12;
#if defined(ISP_HW_V32)
    #ifdef USE_NEWSTRUCT
    // M4_STRUCT_DESC("drc", "normal_ui_style")
    drc_api_attrib_t drc;
    #else
    // M4_STRUCT_DESC("Adrc_calib", "normal_ui_style")
    CalibDbV2_drc_V12_t adrc_calib_v12;
    #endif
#elif defined(ISP_HW_V32_LITE)
    // M4_STRUCT_DESC("adrc_calib_v12_lite", "normal_ui_style")
    CalibDbV2_drc_v12_lite_t adrc_calib_v12_lite;
#endif
    #ifdef USE_NEWSTRUCT
    // M4_STRUCT_DESC("gamma", "normal_ui_style")
    gamma_api_attrib_t gamma;
    // M4_STRUCT_DESC("dehaze", "normal_ui_style")
    dehaze_api_attrib_t dehaze;
    #else
    // M4_STRUCT_DESC("agamma_calib", "normal_ui_style")
    CalibDbV2_gamma_v11_t agamma_calib_v11;
    // M4_STRUCT_DESC("adehaze_calib", "normal_ui_style")
    CalibDbV2_dehaze_v12_t adehaze_calib_v12;
    #endif
#ifdef USE_NEWSTRUCT
    // M4_STRUCT_DESC("dpcc", "normal_ui_style")
    dpcc_api_attrib_t dpcc;
#else
    // M4_STRUCT_DESC("adpcc_calib", "normal_ui_style")
    CalibDbV2_Dpcc_t adpcc_calib;
#endif
    // M4_STRUCT_DESC("aldch", "normal_ui_style")
    CalibDbV2_LDCH_t aldch;
    // M4_STRUCT_DESC("cpsl", "normal_ui_style")
    CalibDbV2_Cpsl_t cpsl;
    // M4_STRUCT_DESC("cproc_calib", "normal_ui_style")
    CalibDbV2_Cproc_t cproc;
    // M4_STRUCT_DESC("aie_calib", "normal_ui_style")
    CalibDbV2_IE_t ie;
    // M4_STRUCT_DESC("colorAsGrey", "normal_ui_style")
    CalibDbV2_ColorAsGrey_t colorAsGrey;
    // M4_STRUCT_DESC("lsc_v2", "normal_ui_style")
    CalibDbV2_LSC_t lsc_v2;
#if defined(ISP_HW_V32)
    // M4_STRUCT_DESC("bayer2dnr_v23", "normal_ui_style")
    CalibDbV2_Bayer2dnrV23_t bayer2dnr_v23;
#ifdef USE_NEWSTRUCT
    // M4_STRUCT_DESC("bayertnr", "normal_ui_style")
    btnr_api_attrib_t bayertnr;
#else
    // M4_STRUCT_DESC("bayertnr_v23", "normal_ui_style")
    CalibDbV2_BayerTnrV23_t bayertnr_v23;
#endif
#else
    // M4_STRUCT_DESC("bayertnr_v23_lite", "normal_ui_style")
    CalibDbV2_BayerTnrV23Lite_t bayertnr_v23;
#endif
#ifdef USE_NEWSTRUCT
    // M4_STRUCT_DESC("ynr", "normal_ui_style")
    cnr_api_attrib_t cnr;
    // M4_STRUCT_DESC("ynr", "normal_ui_style")
    ynr_api_attrib_t ynr;
    // M4_STRUCT_DESC("sharp", "normal_ui_style")
    sharp_api_attrib_t sharp;
#else
    // M4_STRUCT_DESC("ynr_v22", "normal_ui_style")
    CalibDbV2_YnrV22_t ynr_v22;
    // M4_STRUCT_DESC("cnr_v30", "normal_ui_style")
    CalibDbV2_CNRV30_t cnr_v30;
#if defined(ISP_HW_V32)
    // M4_STRUCT_DESC("sharp_v33", "normal_ui_style")
    CalibDbV2_SharpV33_t sharp_v33;
#else
    // M4_STRUCT_DESC("sharp_v33_lite", "normal_ui_style")
    CalibDbV2_SharpV33Lite_t sharp_v33;
#endif
#endif
    // M4_STRUCT_DESC("ainr_v1", "normal_ui_style")
    CalibDbV2_PostIspV1_t ainr_v1;
#if defined(ISP_HW_V32)
    // M4_STRUCT_DESC("cac_v11", "normal_ui_style")
    CalibDbV2_Cac_V11_t cac_v11;
#endif
    // M4_STRUCT_DESC("af_calib", "normal_ui_style")
#if defined(ISP_HW_V32)
    CalibDbV2_AFV31_t af_v31;
#endif
#if defined(ISP_HW_V32_LITE)
    CalibDbV2_AFV32_t af_v32;
#endif
    // M4_STRUCT_DESC("gain_v2", "normal_ui_style")
    CalibDbV2_GainV2_t gain_v2;
    // M4_STRUCT_DESC("csm", "normal_ui_style")
    CalibDbV2_csm_t csm;
    // M4_STRUCT_DESC("cgc", "normal_ui_style")
    CalibDbV2_cgc_t cgc;
} CamCalibDbV2ContextIsp32_t;

RKAIQ_END_DECLARE

#endif
