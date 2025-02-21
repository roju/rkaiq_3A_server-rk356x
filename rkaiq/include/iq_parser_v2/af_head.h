/*
 * af_head.h
 *
 *  Copyright (c) 2021 Rockchip Corporation
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

#ifndef __CALIBDBV2_AF_HEADER_H__
#define __CALIBDBV2_AF_HEADER_H__

#include "rk_aiq_comm.h"

RKAIQ_BEGIN_DECLARE

#define CALIBDBV2_MAX_ISO_LEVEL                    13
#define CALIBDBV2_ZOOM_FOCUS_POSITION_NUM          32
#define CALIBDBV2_ZOOM_FOCUS_ZOOM_MOVE_TBL_SIZE    32
#define CALIBDBV2_AF_CORRECT_SEARCHTBL_MAX         100
#define CALIBDBV2_MAX_MEAS_CONFIG_NUM              32

typedef enum CalibDbV2_Af_SearchDir_s {
    CalibDbV2_AF_POSITIVE_SEARCH     = 0,
    CalibDbV2_AF_NEGATIVE_SEARCH     = 1,
    CalibDbV2_AF_ADAPTIVE_SEARCH     = 2
} CalibDbV2_Af_SearchDir_t;

typedef enum CalibDbV2_Af_SS_s {
    CalibDbV2_AFSS_INVALID         = 0,
    CalibDbV2_AFSS_FULLRANGE       = 1,    /**< scan the full focus range to find the point of best focus */
    CalibDbV2_AFSS_HILLCLIMBING    = 2,    /**< use hillclimbing search */
    CalibDbV2_AFSS_ADAPTIVE_RANGE  = 3,    /**< similar to full range search, but with multiple subsequent scans
                                                with decreasing range and step size will be performed. */
    CalibDbV2_AFSS_MUTIWINDOW      = 4,    /**< search by muti-window statistics */
    CalibDbV2_AFSS_MAX
} CalibDbV2_Af_SS_t;

typedef enum CalibDbV2_AF_MODE_s
{
    CalibDbV2_AFMODE_NOT_SET = -1,
    CalibDbV2_AFMODE_AUTO,
    CalibDbV2_AFMODE_MACRO,
    CalibDbV2_AFMODE_INFINITY,
    CalibDbV2_AFMODE_FIXED,
    CalibDbV2_AFMODE_EDOF,
    CalibDbV2_AFMODE_CONT_VIDEO,
    CalibDbV2_AFMODE_CONT_PICTURE,
    CalibDbV2_AFMODE_ZOOM_ONESHOT,
} CalibDbV2_AF_MODE_t;

typedef enum CalibDbV2_PDAF_DATA_DIR_s {
    CalibDbV2_PDAF_DIR_INVAL = 0,
    CalibDbV2_PDAF_DIR_LEFT  = 1,
    CalibDbV2_PDAF_DIR_RIGHT = 2,
    CalibDbV2_PDAF_DIR_TOP   = 3,
    CalibDbV2_PDAF_DIR_DOWN  = 4
} CalibDbV2_PDAF_DATA_DIR_t;

typedef enum {
    CalibDbV2_PDAF_SENSOR_TYPE1,
    CalibDbV2_PDAF_SENSOR_TYPE2,
    CalibDbV2_PDAF_SENSOR_TYPE3
} CalibDbV2_PDAF_SENSOR_TYPE_t;

typedef struct CalibDbV2_Af_ContrastZoom_s {
    // M4_ARRAY_DESC("QuickFoundThersZoomIdx", "u16", M4_SIZE(1,32), M4_RANGE(0,65535), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          QuickFoundThersZoomIdx[32];
    // M4_NUMBER_DESC("QuickFoundThersZoomIdx_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     QuickFoundThersZoomIdx_len;
    // M4_ARRAY_DESC("QuickFoundThers", "f32", M4_SIZE(1,32), M4_RANGE(0,1), "0.2", M4_DIGIT(3), M4_DYNAMIC(0))
    float                   QuickFoundThers[32];
    // M4_NUMBER_DESC("QuickFoundThers_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     QuickFoundThers_len;
    // M4_ARRAY_DESC("SearchStepZoomIdx", "u16", M4_SIZE(1,32), M4_RANGE(0,65535), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          SearchStepZoomIdx[32];
    // M4_NUMBER_DESC("SearchStepZoomIdx_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     SearchStepZoomIdx_len;
    // M4_ARRAY_DESC("SearchStep", "u16", M4_SIZE(1,32), M4_RANGE(0,65535), "16", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          SearchStep[32];
    // M4_NUMBER_DESC("SearchStep_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     SearchStep_len;
    // M4_ARRAY_DESC("StopStepZoomIdx", "u16", M4_SIZE(1,32), M4_RANGE(0,65535), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          StopStepZoomIdx[32];
    // M4_NUMBER_DESC("StopStepZoomIdx_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     StopStepZoomIdx_len;
    // M4_ARRAY_DESC("StopStep", "u16", M4_SIZE(1,32), M4_RANGE(0,65535), "4", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          StopStep[32];
    // M4_NUMBER_DESC("StopStep_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     StopStep_len;
    // M4_NUMBER_DESC("SkipHighPassZoomIdx", "u16", M4_RANGE(0, 65535), "10000", M4_DIGIT(0))
    unsigned short          SkipHighPassZoomIdx;
    // M4_NUMBER_DESC("SkipHighPassGain", "f32", M4_RANGE(0, 1000), "1000", M4_DIGIT(3))
    float                   SkipHighPassGain;
    // M4_NUMBER_DESC("SwitchDirZoomIdx", "u16", M4_RANGE(0, 65535), "0", M4_DIGIT(0))
    unsigned short          SwitchDirZoomIdx;

    // M4_NUMBER_DESC("Spotlight HighlightRatio", "f32", M4_RANGE(0, 1), "0.014", M4_DIGIT(3))
    float                   SpotlightHighlightRatio;
    // M4_ARRAY_DESC("Spotlight LumaRatio", "f32", M4_SIZE(1,3), M4_RANGE(0,1), "[0.3, 0.5, 0.8]", M4_DIGIT(3), M4_DYNAMIC(0))
    float                   SpotlightLumaRatio[3];
    // M4_ARRAY_DESC("Spotlight BlkCnt", "f32", M4_SIZE(1,3), M4_RANGE(0,1), "[0.2, 0.5, 0.25]", M4_DIGIT(3), M4_DYNAMIC(0))
    float                   SpotlightBlkCnt[3];
} CalibDbV2_Af_ContrastZoom_t;

typedef struct CalibDbV2_Af_Contrast_s {
    // M4_BOOL_DESC("enable", "1")
    bool enable;
    // M4_ENUM_DESC("SearchStrategy", "CalibDbV2_Af_SS_t", "CalibDbV2_AFSS_ADAPTIVE_RANGE")
    CalibDbV2_Af_SS_t         Afss;                       /**< enumeration type for search strategy */
    // M4_ENUM_DESC("FullDir", "CalibDbV2_Af_SearchDir_t", "CalibDbV2_AF_ADAPTIVE_SEARCH")
    CalibDbV2_Af_SearchDir_t  FullDir;
    // M4_ARRAY_DESC("FullRangeTbl", "s16", M4_SIZE(1,3), M4_RANGE(-1023,1023), "[0,1,64]", M4_DIGIT(0), M4_DYNAMIC(0))
    short                   FullRangeTbl[3];
    // M4_ENUM_DESC("AdaptiveDir", "CalibDbV2_Af_SearchDir_t", "CalibDbV2_AF_ADAPTIVE_SEARCH")
    CalibDbV2_Af_SearchDir_t  AdaptiveDir;
    // M4_ARRAY_DESC("AdaptRangeTbl", "u16", M4_SIZE(1,65), M4_RANGE(0,1023), "[0,8,16,24,32,40,48,56,64]", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          AdaptRangeTbl[65];            /**< adaptive range search table*/
    // M4_NUMBER_DESC("AdaptRangeTbl_len", "s32", M4_RANGE(1,65), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     AdaptRangeTbl_len;
    // M4_ARRAY_DESC("FineSearchStep", "u16", M4_SIZE(1,65), M4_RANGE(0,1023), "[4,4,4,4,4,4,4,4,4]", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          FineSearchStep[65];
    // M4_NUMBER_DESC("FineSearchStep_len", "s32", M4_RANGE(1,65), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     FineSearchStep_len;
    // M4_NUMBER_DESC("SkipCurveFitGain", "f32", M4_RANGE(0, 1000), "0", M4_DIGIT(3))
    float                   SkipCurveFitGain;
    // M4_ARRAY_DESC("TrigThers", "f32", M4_SIZE(1,32), M4_RANGE(0,1), "0.075", M4_DIGIT(3), M4_DYNAMIC(0))
    float                   TrigThers[32];                    /**< AF trigger threshold */
    // M4_NUMBER_DESC("TrigThers_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     TrigThers_len;
    // M4_ARRAY_DESC("TrigThersFv", "f32", M4_SIZE(1,32), M4_RANGE(0,100000000000), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    float                   TrigThersFv[32];                    /**< AF trigger threshold */
    // M4_NUMBER_DESC("TrigThersFv_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int                     TrigThersFv_len;
    // M4_NUMBER_DESC("LumaTrigThers", "f32", M4_RANGE(0,1), "1", M4_DIGIT(3),M4_HIDE(0))
    float                   LumaTrigThers;
    // M4_NUMBER_DESC("ExpTrigThers", "f32", M4_RANGE(0,1), "1", M4_DIGIT(3),M4_HIDE(0))
    float                   ExpTrigThers;
    // M4_NUMBER_DESC("ChangedFrames", "u16", M4_RANGE(0,1000), "10", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          ChangedFrames;

    // M4_NUMBER_DESC("StableThers", "f32", M4_RANGE(0,1), "0.02", M4_DIGIT(3),M4_HIDE(0))
    float                   StableThers;                  /**< AF stable threshold */
    // M4_NUMBER_DESC("StableFrames", "u16", M4_RANGE(0,65535), "3", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          StableFrames;                 /**< AF stable  status must hold frames */
    // M4_NUMBER_DESC("StableTime", "u16", M4_RANGE(0,65535), "200", M4_DIGIT(3),M4_HIDE(0))
    unsigned short          StableTime;                   /**< AF stable status must hold time */

    // M4_NUMBER_DESC("SceneDiffEnable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned char           SceneDiffEnable;
    // M4_NUMBER_DESC("SceneDiffThers", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   SceneDiffThers;
    // M4_NUMBER_DESC("SceneDiffBlkThers", "u16", M4_RANGE(0,225), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          SceneDiffBlkThers;
    // M4_NUMBER_DESC("CenterSceneDiffThers", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   CenterSceneDiffThers;

    // M4_NUMBER_DESC("ValidMaxMinRatio", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   ValidMaxMinRatio;
    // M4_NUMBER_DESC("ValidValueThers", "f32", M4_RANGE(0,1000000), "0", M4_DIGIT(0),M4_HIDE(0))
    float                   ValidValueThers;

    // M4_NUMBER_DESC("OutFocusValue", "f32", M4_RANGE(0,1000000), "50", M4_DIGIT(3),M4_HIDE(0))
    float                   OutFocusValue;                /**< out of focus vlaue*/
    // M4_NUMBER_DESC("OutFocusPos", "u16", M4_RANGE(0,65), "32", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          OutFocusPos;                  /**< out of focus position*/

    // M4_NUMBER_DESC("LowLumaValue", "f32", M4_RANGE(0,4095), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   LowLumaValue;                /**< low luma thr vlaue*/
    // M4_NUMBER_DESC("LowLumaPos", "u16", M4_RANGE(0,1023), "64", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          LowLumaPos;                  /**< low luma focus position*/

    // M4_NUMBER_DESC("WeightEnable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned char           WeightEnable;
    // M4_ARRAY_DESC("Weight", "u16", M4_SIZE(15,15), M4_RANGE(0,65535), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short          Weight[225];                  /**< weight */

    // M4_NUMBER_DESC("SearchPauseLumaEnable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned char           SearchPauseLumaEnable;
    // M4_NUMBER_DESC("SearchPauseLumaThers", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   SearchPauseLumaThers;
    // M4_NUMBER_DESC("StableFrames", "u16", M4_RANGE(0,65535), "0", M4_DIGIT(3),M4_HIDE(0))
    unsigned short          SearchLumaStableFrames;
    // M4_NUMBER_DESC("SearchLumaStableThers", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   SearchLumaStableThers;

    // M4_NUMBER_DESC("Stage1QuickFoundThers", "f32", M4_RANGE(0,1), "0.01", M4_DIGIT(3),M4_HIDE(0))
    float                   Stage1QuickFoundThers;
    // M4_NUMBER_DESC("Stage2QuickFoundThers", "f32", M4_RANGE(0,1), "0.2", M4_DIGIT(3),M4_HIDE(0))
    float                   Stage2QuickFoundThers;

    // M4_NUMBER_DESC("FlatValue", "f32", M4_RANGE(0,65535), "0", M4_DIGIT(3),M4_HIDE(0))
    float                   FlatValue;

    // M4_NUMBER_DESC("PointLightLumaTh", "u16", M4_RANGE(0,65535), "4095", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          PointLightLumaTh;                 /**< point light luma threshold */
    // M4_NUMBER_DESC("PointLightCntTh", "u16", M4_RANGE(0,65535), "225", M4_DIGIT(0),M4_HIDE(0))
    unsigned short          PointLightCntTh;                  /**< point light count threshold */

    // M4_STRUCT_DESC("ZoomConfig", "normal_ui_style")
    CalibDbV2_Af_ContrastZoom_t ZoomCfg;
} CalibDbV2_Af_Contrast_t;

typedef struct CalibDbV2_Af_Laser_s {
    // M4_BOOL_DESC("enable", "0")
    bool enable;
    // M4_ARRAY_DESC("vcmDot", "f32", M4_SIZE(1,7), M4_RANGE(0,64), "[0, 16, 32, 40, 48, 56, 64]", M4_DIGIT(0), M4_DYNAMIC(0))
    float vcmDot[7];
    // M4_ARRAY_DESC("distanceDot", "f32", M4_SIZE(1,7), M4_RANGE(0,65535), "[0.2, 0.24, 0.34, 0.4, 0.66, 1, 3]", M4_DIGIT(4), M4_DYNAMIC(0))
    float distanceDot[7];
} CalibDbV2_Af_Laser_t;

typedef struct CalibDbV2_Af_Pdaf_fineSearch_s {
    // M4_NUMBER_DESC("confidence", "f32", M4_RANGE(0,1), "0.5", M4_DIGIT(3),M4_HIDE(0))
    float confidence;
    // M4_NUMBER_DESC("range", "s32", M4_RANGE(0,1023), "0", M4_DIGIT(0))
    int range;
    // M4_NUMBER_DESC("stepPos", "s32", M4_RANGE(1,1023), "1", M4_DIGIT(0))
    int stepPos;
} CalibDbV2_Af_Pdaf_fineSearch_t;

typedef struct CalibDbV2_Af_PdafIsoPara_s {
    // M4_NUMBER_DESC("iso", "u32", M4_RANGE(0, 1000000), "50", M4_DIGIT(0))
    int iso;
    // M4_NUMBER_DESC("pdConfdRatio0", "f32", M4_RANGE(0,1), "1", M4_DIGIT(3),M4_HIDE(0))
    float pdConfdRatio0;
    // M4_NUMBER_DESC("pdConfdRatio1", "f32", M4_RANGE(0,1), "1", M4_DIGIT(3),M4_HIDE(0))
    float pdConfdRatio1;
    // M4_NUMBER_DESC("pdConfdRatio2", "f32", M4_RANGE(0,1), "1", M4_DIGIT(3),M4_HIDE(0))
    float pdConfdRatio2;
    // M4_NUMBER_DESC("pdConfdRatio3", "f32", M4_RANGE(0,1), "1", M4_DIGIT(3),M4_HIDE(0))
    float pdConfdRatio3;
    // M4_NUMBER_DESC("pdConfdRhresh", "f32", M4_RANGE(0,1), "0.4", M4_DIGIT(3),M4_HIDE(0))
    float pdConfdThresh;
    // M4_NUMBER_DESC("convergedInfPdThresh", "u16", M4_RANGE(0,1023), "12", M4_DIGIT(0),M4_HIDE(0))
    unsigned short convergedInfPdThresh;
    // M4_NUMBER_DESC("convergedMacPdThresh", "u16", M4_RANGE(0,1023), "12", M4_DIGIT(0),M4_HIDE(0))
    unsigned short convergedMacPdThresh;
    // M4_NUMBER_DESC("defocusInfPdThresh", "u16", M4_RANGE(0,1023), "12", M4_DIGIT(0),M4_HIDE(0))
    unsigned short defocusInfPdThresh;
    // M4_NUMBER_DESC("defocusMacPdThresh", "u16", M4_RANGE(0,1023), "12", M4_DIGIT(0),M4_HIDE(0))
    unsigned short defocusMacPdThresh;
    // M4_NUMBER_DESC("stablePdRatio", "f32", M4_RANGE(0,255), "0.125", M4_DIGIT(3),M4_HIDE(0))
    float stablePdRatio;
    // M4_NUMBER_DESC("stablePdOffset", "u16", M4_RANGE(0,1023), "8", M4_DIGIT(3),M4_HIDE(0))
    unsigned short stablePdOffset;
    // M4_NUMBER_DESC("stableCntRatio", "f32", M4_RANGE(0,1023), "1.5", M4_DIGIT(3),M4_HIDE(0))
    float stableCntRatio;
    // M4_NUMBER_DESC("noconfCntThresh", "u16", M4_RANGE(0,255), "4", M4_DIGIT(0),M4_HIDE(0))
    unsigned short noconfCntThresh;
    // M4_NUMBER_DESC("roiBlkCntW", "u8", M4_RANGE(1, 10), "3", M4_DIGIT(0))
    unsigned char roiBlkCntW;
    // M4_NUMBER_DESC("roiBlkCntH", "u8", M4_RANGE(1, 10), "3", M4_DIGIT(0))
    unsigned char roiBlkCntH;
    // M4_STRUCT_LIST_DESC("fineSearchTbl", M4_SIZE(1,10), "normal_ui_style")
    CalibDbV2_Af_Pdaf_fineSearch_t fineSearchTbl[10];
    // M4_NUMBER_DESC("fineSearchTbl_len", "s32", M4_RANGE(1,10), "1", M4_DIGIT(0), M4_HIDE(0))
    int fineSearchTbl_len;
} CalibDbV2_Af_PdafIsoPara_t;

typedef struct CalibDbV2_Af_PdafCalibInf_s {
    // M4_NUMBER_DESC("pdGainMapW", "u16", M4_RANGE(1,1000), "32", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdGainMapW;
    // M4_NUMBER_DESC("pdGainMapH", "u16", M4_RANGE(1,1000), "32", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdGainMapH;
    // M4_NUMBER_DESC("pdDccMapW", "u16", M4_RANGE(1,1000), "32", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdDccMapW;
    // M4_NUMBER_DESC("pdDccMapH", "u16", M4_RANGE(1,1000), "32", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdDccMapH;
} CalibDbV2_Af_PdafCalibInf_t;

typedef struct CalibDbV2_Af_PdafResolution_s {
    // M4_ENUM_DESC("pdType", "CalibDbV2_PDAF_SENSOR_TYPE_t", "CalibDbV2_PDAF_SENSOR_TYPE2")
    CalibDbV2_PDAF_SENSOR_TYPE_t pdType;
    // M4_NUMBER_DESC("imageWidth", "u16", M4_RANGE(0, 65535), "508", M4_DIGIT(0))
    unsigned short imageWidth;
    // M4_NUMBER_DESC("imageHeight", "u16", M4_RANGE(0, 65535), "760", M4_DIGIT(0))
    unsigned short imageHeight;
    // M4_NUMBER_DESC("pdOutWidth", "u16", M4_RANGE(0, 65535), "508", M4_DIGIT(0))
    unsigned short pdOutWidth;
    // M4_NUMBER_DESC("pdOutHeight", "u16", M4_RANGE(0, 65535), "760", M4_DIGIT(0))
    unsigned short pdOutHeight;
    // M4_NUMBER_DESC("pdCropX", "u16", M4_RANGE(0, 65535), "508", M4_DIGIT(0))
    unsigned short pdCropX;
    // M4_NUMBER_DESC("pdCropY", "u16", M4_RANGE(0, 65535), "760", M4_DIGIT(0))
    unsigned short pdCropY;
    // M4_NUMBER_DESC("pdBaseWidth", "u16", M4_RANGE(0, 65535), "508", M4_DIGIT(0))
    unsigned short pdBaseWidth;
    // M4_NUMBER_DESC("pdBaseHeight", "u16", M4_RANGE(0, 65535), "760", M4_DIGIT(0))
    unsigned short pdBaseHeight;
} CalibDbV2_Af_PdafResolution_t;

typedef struct CalibDbV2_Af_Pdaf_s {
    // M4_BOOL_DESC("enable", "0")
    bool enable;
    // M4_NUMBER_DESC("pdVsCdDebug", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdVsCdDebug;
    // M4_NUMBER_DESC("pdDumpDebug", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdDumpDebug;
    // M4_NUMBER_DESC("pdDumpMaxFrm", "u16", M4_RANGE(1,10000), "300", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdDumpMaxFrm;
    // M4_NUMBER_DESC("pdDataBit", "u16", M4_RANGE(1,16), "10", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdDataBit;
    // M4_NUMBER_DESC("pdBlkLevel", "u16", M4_RANGE(1,1023), "64", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdBlkLevel;
    // M4_NUMBER_DESC("pdSearchRadius", "u16", M4_RANGE(0,32), "3", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdSearchRadius;
    // M4_NUMBER_DESC("pdMirrorInCalib", "u8", M4_RANGE(0, 3), "1", M4_DIGIT(0))
    unsigned char pdMirrorInCalib;
    // M4_NUMBER_DESC("pdChangeLeftRight", "u8", M4_RANGE(0, 1), "1", M4_DIGIT(0))
    unsigned char pdChangeLeftRight;
    // M4_NUMBER_DESC("pdVsImgoutMirror", "u8", M4_RANGE(0, 3), "0", M4_DIGIT(0))
    unsigned char pdVsImgoutMirror;
    // M4_NUMBER_DESC("pdLRInDiffLine", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdLRInDiffLine;
    // M4_NUMBER_DESC("pdWidth", "u16", M4_RANGE(0, 65535), "508", M4_DIGIT(0))
    unsigned short pdWidth;
    // M4_NUMBER_DESC("pdHeight", "u16", M4_RANGE(0, 65535), "760", M4_DIGIT(0))
    unsigned short pdHeight;
    // M4_NUMBER_DESC("pdMaxWidth", "u16", M4_RANGE(0, 65535), "508", M4_DIGIT(0))
    unsigned short pdMaxWidth;
    // M4_NUMBER_DESC("pdMaxHeight", "u16", M4_RANGE(0, 65535), "760", M4_DIGIT(0))
    unsigned short pdMaxHeight;
    // M4_NUMBER_DESC("pdVerBinning", "u8", M4_RANGE(0, 255), "0", M4_DIGIT(0))
    unsigned char pdVerBinning;
    // M4_NUMBER_DESC("pdFrmInValid", "u8", M4_RANGE(0, 4), "1", M4_DIGIT(0))
    unsigned char pdFrmInValid;
    // M4_NUMBER_DESC("pdDgainValid", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdDgainValid;
    // M4_NUMBER_DESC("pdGainMapNormEn", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdGainMapNormEn;
    // M4_NUMBER_DESC("pdConfdMode", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdConfdMode;
    // M4_NUMBER_DESC("pdNoiseSn", "f32", M4_RANGE(0,100), "0.207", M4_DIGIT(3),M4_HIDE(0))
    float pdNoiseSn;
    // M4_ARRAY_DESC("pdNoiseRn", "f32", M4_SIZE(1,2), M4_RANGE(0,100), "[0.14, 2.8]", M4_DIGIT(3), M4_DYNAMIC(0))
    float pdNoiseRn[2];
    // M4_NUMBER_DESC("pdNoisePn", "f32", M4_RANGE(0,100), "0.25", M4_DIGIT(3),M4_HIDE(0))
    float pdNoisePn;
    // M4_NUMBER_DESC("pdSatValRatio", "f32", M4_RANGE(0,1), "0.92", M4_DIGIT(3),M4_HIDE(0))
    float pdSatValRatio;
    // M4_NUMBER_DESC("pdSatCntRatio", "f32", M4_RANGE(0,1), "0.06", M4_DIGIT(3),M4_HIDE(0))
    float pdSatCntRatio;
    // M4_NUMBER_DESC("pdDiscardRegionEn", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char pdDiscardRegionEn;
    // M4_NUMBER_DESC("pdLessTextureRatio", "f32", M4_RANGE(0,5), "0.25", M4_DIGIT(3),M4_HIDE(0))
    float pdLessTextureRatio;
    // M4_NUMBER_DESC("pdTargetOffset", "s16", M4_RANGE(-4096,4096), "0", M4_DIGIT(0),M4_HIDE(0))
    short pdTargetOffset;
    // M4_STRUCT_DESC("pdCalibInf", "normal_ui_style")
    CalibDbV2_Af_PdafCalibInf_t pdCalibInf;
    // M4_NUMBER_DESC("pdConfdMwinFactor", "u16", M4_RANGE(0,225), "3", M4_DIGIT(0),M4_HIDE(0))
    unsigned short pdConfdMwinFactor;
    // M4_NUMBER_DESC("pdCenterMinFv", "u32", M4_RANGE(0,100000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned int pdCenterMinFv;
    // M4_NUMBER_DESC("pdCenterMinRatio", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3),M4_HIDE(0))
    float pdCenterMinRatio;
    // M4_NUMBER_DESC("pdHighlightRatio", "f32", M4_RANGE(0,1), "0.1", M4_DIGIT(3),M4_HIDE(0))
    float pdHighlightRatio;
    // M4_ARRAY_DESC("pdStepRatio", "f32", M4_SIZE(1,7), M4_RANGE(0,1), "[1.0, 1.0, 1.0, 0.9, 0.8, 0.7, 0.7]", M4_DIGIT(3), M4_DYNAMIC(0))
    float pdStepRatio[7];
    // M4_ARRAY_DESC("pdStepDefocus", "u16", M4_SIZE(1,7), M4_RANGE(0,1023), "[32, 64, 96, 128, 160, 192, 224]", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned short pdStepDefocus[7];
    // M4_STRUCT_LIST_DESC("pdIsoPara", M4_SIZE(1,13), "normal_ui_style")
    CalibDbV2_Af_PdafIsoPara_t pdIsoPara[CALIBDBV2_MAX_ISO_LEVEL];
    // M4_NUMBER_DESC("pdIsoPara_len", "s32", M4_RANGE(1,16), "1", M4_DIGIT(0), M4_HIDE(0))
    int pdIsoPara_len;
    // M4_STRUCT_LIST_DESC("pdResoInf", M4_SIZE(1,16), "normal_ui_style")
    CalibDbV2_Af_PdafResolution_t pdResoInf[16];
    // M4_NUMBER_DESC("pdResoInf_len", "s32", M4_RANGE(1,16), "1", M4_DIGIT(0), M4_HIDE(0))
    int pdResoInf_len;
} CalibDbV2_Af_Pdaf_t;

typedef struct CalibDbV2_Af_VcmCfg_s {
    // M4_NUMBER_DESC("max logical pos", "u32", M4_RANGE(0,4095), "64", M4_DIGIT(0))
    unsigned int max_logical_pos;
    // M4_NUMBER_DESC("start current", "s32", M4_RANGE(-1, 2048), "-1", M4_DIGIT(0))
    int start_current;
    // M4_NUMBER_DESC("rated current", "s32", M4_RANGE(-1, 2048), "-1", M4_DIGIT(0))
    int rated_current;
    // M4_NUMBER_DESC("step mode", "s32", M4_RANGE(-1, 1000), "-1", M4_DIGIT(0))
    int step_mode;
    // M4_NUMBER_DESC("extra delay", "s32", M4_RANGE(-10000,10000), "0", M4_DIGIT(0))
    int extra_delay;
    // M4_NUMBER_DESC("posture diff", "f32", M4_RANGE(0,1), "0", M4_DIGIT(3))
    float posture_diff;
} CalibDbV2_Af_VcmCfg_t;

typedef struct CalibDbV2_Af_MeasIsoCfg_s {
    // M4_NUMBER_DESC("iso", "u32", M4_RANGE(0, 1000000), "0", M4_DIGIT(0))
    int iso;
    // M4_NUMBER_DESC("afmThres", "u16", M4_RANGE(0, 255), "4", M4_DIGIT(0))
    unsigned short afmThres;
    // M4_ARRAY_MARK_DESC("Gamma_curve", "u16", M4_SIZE(1,17),  M4_RANGE(0, 1023), "[0,45,108,179,245,344,409,459,500,567,622,676,759,833,896,962,1023]", M4_DIGIT(0), M4_DYNAMIC(0), "curve_table")
    unsigned short gammaY[17];
    // M4_ARRAY_DESC("gaussWeight", "u8", M4_SIZE(1,3), M4_RANGE(0,128), "[32,16,8]", M4_DIGIT(0), M4_DYNAMIC(0))
    unsigned char gaussWeight[3];
} CalibDbV2_Af_MeasIsoCfg_t;

typedef struct CalibDbV2_Af_DefCode_s {
    // M4_NUMBER_DESC("code", "u8", M4_RANGE(0, 64), "32", M4_DIGIT(0))
    unsigned char code;
} CalibDbV2_Af_DefCode_t;

typedef struct CalibDbV2_Af_ZoomFocusTbl_s {
    // M4_NUMBER_DESC("widemod deviate", "u32", M4_RANGE(0, 1000), "0", M4_DIGIT(0))
    int widemod_deviate;
    // M4_NUMBER_DESC("telemod deviate", "u32", M4_RANGE(0, 1000), "0", M4_DIGIT(0))
    int telemod_deviate;
    // M4_NUMBER_DESC("focus backward value", "u32", M4_RANGE(0, 1000), "0", M4_DIGIT(0))
    int focus_backval;
    // M4_ARRAY_DESC("zoom move dot", "u32", M4_SIZE(1,32), M4_RANGE(0,1000000), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    int zoom_move_dot[32];
    // M4_NUMBER_DESC("zoom move step len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int zoom_move_dot_len;
    // M4_ARRAY_DESC("zoom move step", "u32", M4_SIZE(1,32), M4_RANGE(0,1000000), "16", M4_DIGIT(0), M4_DYNAMIC(0))
    int zoom_move_step[32];
    // M4_NUMBER_DESC("zoom move step len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int zoom_move_step_len;
    // M4_ARRAY_DESC("zoom search table", "s32", M4_SIZE(1,32), M4_RANGE(-32768,32767), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    int ZoomSearchTbl[32];
    // M4_NUMBER_DESC("zoom search table number", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int ZoomSearchTbl_len;
    // M4_NUMBER_DESC("zoom search reference curve", "u32", M4_RANGE(0, 32), "0", M4_DIGIT(0))
    int ZoomSearchRefCurveIdx;
    // M4_NUMBER_DESC("zoom search margin", "u32", M4_RANGE(0, 100000), "50", M4_DIGIT(0))
    int FocusSearchMargin;
    // M4_ARRAY_DESC("zoom search plus range", "u32", M4_SIZE(1,32), M4_RANGE(0,32767), "0", M4_DIGIT(0), M4_DYNAMIC(0))
    int FocusSearchPlusRange[32];
    // M4_NUMBER_DESC("FocusSearchPlusRange_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int FocusSearchPlusRange_len;
    // M4_NUMBER_DESC("focus stage1 step", "u32", M4_RANGE(0, 100), "0", M4_DIGIT(0))
    int FocusStage1Step;
    // M4_NUMBER_DESC("quickFndRate", "f32", M4_RANGE(0,1), "0.2", M4_DIGIT(3),M4_HIDE(0))
    float QuickFndRate;
    // M4_NUMBER_DESC("quickFndMinFv", "f32", M4_RANGE(0,2147483647), "1000", M4_DIGIT(0),M4_HIDE(0))
    float QuickFndMinFv;
    // M4_NUMBER_DESC("search zoom range", "u32", M4_RANGE(0, 100000), "100", M4_DIGIT(0))
    int searchZoomRange;
    // M4_NUMBER_DESC("search focus range", "u32", M4_RANGE(0, 100000), "100", M4_DIGIT(0))
    int searchFocusRange;
    // M4_NUMBER_DESC("search emax", "f32", M4_RANGE(0,100000), "100", M4_DIGIT(3),M4_HIDE(0))
    float searchEmax;
    // M4_NUMBER_DESC("search eavg", "f32", M4_RANGE(0,100000), "100", M4_DIGIT(3),M4_HIDE(0))
    float searchEavg;

    // M4_NUMBER_DESC("IsZoomFocusRec", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char IsZoomFocusRec;
    // M4_STRING_DESC("ZoomInfoDir", M4_SIZE(1,1), M4_RANGE(0, 64), "/data/", M4_DYNAMIC(0))
    char ZoomInfoDir[64];
    // M4_NUMBER_DESC("zoom init Index", "u32", M4_RANGE(0, 100000), "0", M4_DIGIT(0))
    int ZoomInitIndex;
    // M4_STRING_DESC("ZoomCurveFile", M4_SIZE(1,1), M4_RANGE(0, 64), "/data/zoomcurve.bin", M4_DYNAMIC(0))
    char ZoomCurveFile[64];
} CalibDbV2_Af_ZoomFocusTbl_t;

typedef struct CalibDb_Af_LdgParam_s {
    // M4_NUMBER_DESC("enable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char enable;
    // M4_NUMBER_DESC("ldg xl", "u32", M4_RANGE(0, 255), "10", M4_DIGIT(0))
    int ldg_xl;
    // M4_NUMBER_DESC("ldg yl", "u32", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    int ldg_yl;
    // M4_NUMBER_DESC("ldg kl", "u32", M4_RANGE(0, 2147483647), "1286", M4_DIGIT(0))
    int ldg_kl;
    // M4_NUMBER_DESC("ldg xh", "u32", M4_RANGE(0, 255), "118", M4_DIGIT(0))
    int ldg_xh;
    // M4_NUMBER_DESC("ldg yh", "u32", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    int ldg_yh;
    // M4_NUMBER_DESC("ldg kh", "u32", M4_RANGE(0, 2147483647), "1340", M4_DIGIT(0))
    int ldg_kh;
} CalibDbV2_Af_LdgParam_t;

typedef struct CalibDb_Af_HighLightParam_s {
    // M4_NUMBER_DESC("ther0", "u32", M4_RANGE(0, 255), "245", M4_DIGIT(0))
    int ther0;
    // M4_NUMBER_DESC("ther1", "u32", M4_RANGE(0, 255), "200", M4_DIGIT(0))
    int ther1;
} CalibDbV2_Af_HighLightParam_t;

typedef struct CalibDbV2_AF_Tuning_Para_s {
    // M4_ENUM_DESC("mode", "CalibDbV2_AF_MODE_t", "CalibDbV2_AFMODE_CONT_PICTURE")
    CalibDbV2_AF_MODE_t af_mode;
    // M4_NUMBER_DESC("win_h_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_offs;
    // M4_NUMBER_DESC("win_v_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_offs;
    // M4_NUMBER_DESC("win_h_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_size;
    // M4_NUMBER_DESC("win_v_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_size;
    // M4_NUMBER_DESC("win_h_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_offs;
    // M4_NUMBER_DESC("win_v_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_offs;
    // M4_NUMBER_DESC("win_h_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_size;
    // M4_NUMBER_DESC("win_v_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_size;
    // M4_STRUCT_DESC("fixed mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t fixed_mode;
    // M4_STRUCT_DESC("macro mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t macro_mode;
    // M4_STRUCT_DESC("infinity mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t infinity_mode;
    // M4_STRUCT_DESC("ldg param", "normal_ui_style")
    CalibDbV2_Af_LdgParam_t ldg_param;
    // M4_STRUCT_DESC("high light", "normal_ui_style")
    CalibDbV2_Af_HighLightParam_t highlight;
    // M4_STRUCT_DESC("contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t contrast_af;
    // M4_STRUCT_DESC("video contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t video_contrast_af;
    // M4_STRUCT_DESC("laser af", "normal_ui_style")
    CalibDbV2_Af_Laser_t laser_af;
    // M4_STRUCT_DESC("vcmcfg", "normal_ui_style")
    CalibDbV2_Af_VcmCfg_t vcmcfg;
    // M4_STRUCT_DESC("zoomfocus_tbl", "normal_ui_style")
    CalibDbV2_Af_ZoomFocusTbl_t zoomfocus_tbl;
    // M4_STRUCT_LIST_DESC("meas iso config", M4_SIZE(1,13), "normal_ui_style")
    CalibDbV2_Af_MeasIsoCfg_t measiso_cfg[CALIBDBV2_MAX_ISO_LEVEL];
} CalibDbV2_AF_Tuning_Para_t;

typedef struct {
    // M4_STRUCT_DESC("TuningPara", "normal_ui_style")
    CalibDbV2_AF_Tuning_Para_t TuningPara;
} CalibDbV2_AF_t;

typedef struct CalibDbV2_AfV30_MeasCfg_s {
    // M4_NUMBER_DESC("table index", "u32", M4_RANGE(0, 1000000), "0", M4_DIGIT(0))
    unsigned int tbl_idx;
    // M4_NUMBER_DESC("afmThres", "u16", M4_RANGE(0, 255), "4", M4_DIGIT(0))
    unsigned short afmThres;
    // M4_ARRAY_MARK_DESC("Gamma Curve", "u16", M4_SIZE(1,17),  M4_RANGE(0, 1023), "[0,45,108,179,245,344,409,459,500,567,622,676,759,833,896,962,1023]", M4_DIGIT(0), M4_DYNAMIC(0), "curve_table")
    unsigned short gammaY[17];
    // M4_NUMBER_DESC("v1fv reliable", "f32", M4_RANGE(0, 1), "0.2", M4_DIGIT(3))
    float v1fv_reliable;
    // M4_NUMBER_DESC("v2fv reliable", "f32", M4_RANGE(0, 1), "0.2", M4_DIGIT(3))
    float v2fv_reliable;
    // M4_NUMBER_DESC("v1 fir sel", "u8", M4_RANGE(0, 1), "1", M4_DIGIT(0))
    unsigned char v1_fir_sel;
    // M4_ARRAY_DESC("v1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.04, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v1_band[2];
    // M4_ARRAY_DESC("vertical first iir filter", "s16", M4_SIZE(1,9), M4_RANGE(-2047,2047), "[0, 483, 0, 0, 27, 0, 0, 28, 0]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_iir_coe[9];
    // M4_ARRAY_DESC("vertical first fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-1212, 0, 1212]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_fir_coe[3];
    // M4_ARRAY_DESC("v2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.04, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v2_band[2];
    // M4_ARRAY_DESC("vertical second iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[483, 27, 28]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_iir_coe[3];
    // M4_ARRAY_DESC("vertical second fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-1212, 0, 1212]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_fir_coe[3];
    // M4_ARRAY_DESC("h1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.04, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h1_band[2];
    // M4_ARRAY_DESC("horizontal first iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 553, -271, 471, 0, -471]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal first iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[97, 875, -400, 199, 0, -199]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir2_coe[6];
    // M4_ARRAY_DESC("h2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.04, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h2_band[2];
    // M4_ARRAY_DESC("horizontal second iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 553, -271, 471, 0, -471]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal second iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[97, 875, -400, 199, 0, -199]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir2_coe[6];
    // M4_NUMBER_DESC("ldg enable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char ldg_en;
    // M4_NUMBER_DESC("vertical minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_l;
    // M4_NUMBER_DESC("vertical gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ve_ldg_gain_l;
    // M4_NUMBER_DESC("vertical slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_l;
    // M4_NUMBER_DESC("vertical maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_h;
    // M4_NUMBER_DESC("vertical gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ve_ldg_gain_h;
    // M4_NUMBER_DESC("vertical slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_h;
    // M4_NUMBER_DESC("horizontal minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_l;
    // M4_NUMBER_DESC("horizontal gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ho_ldg_gain_l;
    // M4_NUMBER_DESC("horizontal slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_l;
    // M4_NUMBER_DESC("horizontal maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_h;
    // M4_NUMBER_DESC("horizontal gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ho_ldg_gain_h;
    // M4_NUMBER_DESC("horizontal slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_h;
    // M4_NUMBER_DESC("vertical fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short v_fv_thresh;
    // M4_NUMBER_DESC("horizontal fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short h_fv_thresh;
    // M4_NUMBER_DESC("highlight thresh", "u16", M4_RANGE(0, 4095), "912", M4_DIGIT(0))
    unsigned short highlit_thresh;
    // M4_NUMBER_DESC("vertical fv ratio", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v_fv_ratio;
} CalibDbV2_AfV30_MeasCfg_t;

typedef struct CalibDbV2_AfV30_ZoomMeas_s {
    // M4_NUMBER_DESC("zoom index", "u32", M4_RANGE(0,100000), "0", M4_DIGIT(0), M4_HIDE(0))
    int zoom_idx;
    // M4_ARRAY_DESC("iso", "f32", M4_SIZE(1,13), M4_RANGE(50, 10000000), "[50, 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200, 102400, 204800]", M4_DIGIT(0), M4_HIDE(0))
    float iso[CALIBDBV2_MAX_ISO_LEVEL];
    // M4_ARRAY_DESC("meas table index", "u32", M4_SIZE(1,13), M4_RANGE(0,100), "0", M4_DIGIT(0))
    int idx[CALIBDBV2_MAX_ISO_LEVEL];
    // M4_ARRAY_DESC("spotlight scene meas table index", "u32", M4_SIZE(1,13), M4_RANGE(0,100), "0", M4_DIGIT(0))
    int spotlt_scene_idx[CALIBDBV2_MAX_ISO_LEVEL];
} CalibDbV2_AfV30_ZoomMeas_t;

typedef struct CalibDbV2_AFV30_Tuning_Para_s {
    // M4_ENUM_DESC("mode", "CalibDbV2_AF_MODE_t", "CalibDbV2_AFMODE_CONT_PICTURE")
    CalibDbV2_AF_MODE_t af_mode;
    // M4_NUMBER_DESC("win_h_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_offs;
    // M4_NUMBER_DESC("win_v_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_offs;
    // M4_NUMBER_DESC("win_h_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_size;
    // M4_NUMBER_DESC("win_v_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_size;
    // M4_NUMBER_DESC("win_h_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_offs;
    // M4_NUMBER_DESC("win_v_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_offs;
    // M4_NUMBER_DESC("win_h_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_size;
    // M4_NUMBER_DESC("win_v_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_size;
    // M4_STRUCT_DESC("fixed mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t fixed_mode;
    // M4_STRUCT_DESC("macro mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t macro_mode;
    // M4_STRUCT_DESC("infinity mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t infinity_mode;
    // M4_STRUCT_DESC("contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t contrast_af;
    // M4_STRUCT_DESC("video contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t video_contrast_af;
    // M4_STRUCT_DESC("laser af", "normal_ui_style")
    CalibDbV2_Af_Laser_t laser_af;
    // M4_STRUCT_DESC("pdaf", "normal_ui_style")
    CalibDbV2_Af_Pdaf_t pdaf;
    // M4_STRUCT_DESC("vcmcfg", "normal_ui_style")
    CalibDbV2_Af_VcmCfg_t vcmcfg;
    // M4_STRUCT_DESC("zoomfocus_tbl", "normal_ui_style")
    CalibDbV2_Af_ZoomFocusTbl_t zoomfocus_tbl;
    // M4_STRUCT_LIST_DESC("zoom_meas", M4_SIZE(1,8), "normal_ui_style")
    CalibDbV2_AfV30_ZoomMeas_t zoom_meas[8];
    // M4_NUMBER_DESC("zoom_meas_len", "s32", M4_RANGE(1,8), "1", M4_DIGIT(0), M4_HIDE(0))
    int zoom_meas_len;
    // M4_STRUCT_LIST_DESC("meas config table", M4_SIZE(1,32), "normal_ui_style")
    CalibDbV2_AfV30_MeasCfg_t meascfg_tbl[CALIBDBV2_MAX_MEAS_CONFIG_NUM];
    // M4_NUMBER_DESC("meascfg_tbl_len", "s32", M4_RANGE(1,13), "1", M4_DIGIT(0), M4_HIDE(0))
    int meascfg_tbl_len;
} CalibDbV2_AFV30_Tuning_Para_t;

typedef struct {
    // M4_STRUCT_DESC("TuningPara", "normal_ui_style")
    CalibDbV2_AFV30_Tuning_Para_t TuningPara;
} CalibDbV2_AFV30_t;

typedef enum CalibDbV2_AF_DNSCL_MODE_s {
    CalibDbV2_AF_DNSCL_0 = 0,
    CalibDbV2_AF_DNSCL_1 = 1,
    CalibDbV2_AF_DNSCL_2 = 2,
    CalibDbV2_AF_DNSCL_4 = 3,
    CalibDbV2_AF_DNSCL_8 = 4
} CalibDbV2_AF_DNSCL_MODE_t;

typedef struct CalibDbV2_AfV31_MeasCfg_s {
    // M4_NUMBER_DESC("table index", "u32", M4_RANGE(0, 1000000), "0", M4_DIGIT(0))
    unsigned int tbl_idx;
    // M4_BOOL_DESC("from awb", "0")
    bool from_awb;
    // M4_BOOL_DESC("from ynr", "0")
    bool from_ynr;
    // M4_NUMBER_DESC("afmThres", "u16", M4_RANGE(0, 255), "4", M4_DIGIT(0))
    unsigned short afmThres;
    // M4_ARRAY_MARK_DESC("Gamma Curve", "u16", M4_SIZE(1,17),  M4_RANGE(0, 1023), "[0,45,108,179,245,344,409,459,500,567,622,676,759,833,896,962,1023]", M4_DIGIT(0), M4_DYNAMIC(0), "curve_table")
    unsigned short gammaY[17];
    // M4_ARRAY_DESC("gaus coe", "s16", M4_SIZE(3,3), M4_RANGE(-128, 127), "[0,64,0,0,64,0,0,0,0]", M4_DIGIT(0), M4_DYNAMIC(0))
    short gaus_coe[9];
    // M4_ENUM_DESC("downscale mode", "CalibDbV2_AF_DNSCL_MODE_t", "CalibDbV2_AF_DNSCL_1")
    CalibDbV2_AF_DNSCL_MODE_t dnscl_mode;
    // M4_NUMBER_DESC("v1fv reliable", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v1fv_reliable;
    // M4_NUMBER_DESC("v2fv reliable", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v2fv_reliable;
    // M4_NUMBER_DESC("v1 fir sel", "u8", M4_RANGE(0, 1), "1", M4_DIGIT(0))
    unsigned char v1_fir_sel;
    // M4_ARRAY_DESC("v1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.042,0.140]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v1_band[2];
    // M4_ARRAY_DESC("vertical first iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-255,255), "[-265, 686, 512]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_iir_coe[3];
    // M4_ARRAY_DESC("vertical first fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-124, 0, 124]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_fir_coe[3];
    // M4_ARRAY_DESC("v2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.055, 0.125]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v2_band[2];
    // M4_ARRAY_DESC("vertical second iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-325, 724, 512]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_iir_coe[3];
    // M4_ARRAY_DESC("vertical second fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-94, 0, 94]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_fir_coe[3];
    // M4_ARRAY_DESC("h1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.042, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h1_band[2];
    // M4_ARRAY_DESC("horizontal first iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 557, -276, 460, 0, -460]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal first iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[100, 870, -399, 191, 0, -191]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir2_coe[6];
    // M4_ARRAY_DESC("h2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.055, 0.125]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h2_band[2];
    // M4_ARRAY_DESC("horizontal second iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[415, 648, -344, 403, 0, -403]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal second iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[96, 854, -409, 156, 0, -156]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir2_coe[6];
    // M4_NUMBER_DESC("ldg enable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char ldg_en;
    // M4_NUMBER_DESC("vertical minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_l;
    // M4_NUMBER_DESC("vertical gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ve_ldg_gain_l;
    // M4_NUMBER_DESC("vertical slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_l;
    // M4_NUMBER_DESC("vertical maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_h;
    // M4_NUMBER_DESC("vertical gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ve_ldg_gain_h;
    // M4_NUMBER_DESC("vertical slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_h;
    // M4_NUMBER_DESC("horizontal minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_l;
    // M4_NUMBER_DESC("horizontal gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ho_ldg_gain_l;
    // M4_NUMBER_DESC("horizontal slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_l;
    // M4_NUMBER_DESC("horizontal maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_h;
    // M4_NUMBER_DESC("horizontal gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ho_ldg_gain_h;
    // M4_NUMBER_DESC("horizontal slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_h;
    // M4_NUMBER_DESC("vertical fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short v_fv_thresh;
    // M4_NUMBER_DESC("horizontal fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short h_fv_thresh;
    // M4_NUMBER_DESC("highlight thresh", "u16", M4_RANGE(0, 1023), "912", M4_DIGIT(0))
    unsigned short highlit_thresh;
    // M4_NUMBER_DESC("vertical fv ratio", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v_fv_ratio;
} CalibDbV2_AfV31_MeasCfg_t;

typedef struct CalibDbV2_AFV31_Tuning_Para_s {
    // M4_ENUM_DESC("mode", "CalibDbV2_AF_MODE_t", "CalibDbV2_AFMODE_CONT_PICTURE")
    CalibDbV2_AF_MODE_t af_mode;
    // M4_NUMBER_DESC("win_h_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_offs;
    // M4_NUMBER_DESC("win_v_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_offs;
    // M4_NUMBER_DESC("win_h_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_size;
    // M4_NUMBER_DESC("win_v_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_size;
    // M4_NUMBER_DESC("win_h_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_offs;
    // M4_NUMBER_DESC("win_v_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_offs;
    // M4_NUMBER_DESC("win_h_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_size;
    // M4_NUMBER_DESC("win_v_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_size;
    // M4_STRUCT_DESC("fixed mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t fixed_mode;
    // M4_STRUCT_DESC("macro mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t macro_mode;
    // M4_STRUCT_DESC("infinity mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t infinity_mode;
    // M4_STRUCT_DESC("contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t contrast_af;
    // M4_STRUCT_DESC("video contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t video_contrast_af;
    // M4_STRUCT_DESC("laser af", "normal_ui_style")
    CalibDbV2_Af_Laser_t laser_af;
    // M4_STRUCT_DESC("vcmcfg", "normal_ui_style")
    CalibDbV2_Af_VcmCfg_t vcmcfg;
    // M4_STRUCT_DESC("zoomfocus_tbl", "normal_ui_style")
    CalibDbV2_Af_ZoomFocusTbl_t zoomfocus_tbl;
    // M4_STRUCT_LIST_DESC("zoom_meas", M4_SIZE(1,8), "normal_ui_style")
    CalibDbV2_AfV30_ZoomMeas_t zoom_meas[8];
    // M4_NUMBER_DESC("zoom_meas_len", "s32", M4_RANGE(1,8), "1", M4_DIGIT(0), M4_HIDE(0))
    int zoom_meas_len;
    // M4_STRUCT_LIST_DESC("meas config table", M4_SIZE(1,32), "normal_ui_style")
    CalibDbV2_AfV31_MeasCfg_t meascfg_tbl[CALIBDBV2_MAX_MEAS_CONFIG_NUM];
    // M4_NUMBER_DESC("meascfg_tbl_len", "s32", M4_RANGE(1,13), "1", M4_DIGIT(0), M4_HIDE(0))
    int meascfg_tbl_len;
} CalibDbV2_AFV31_Tuning_Para_t;

typedef struct {
    // M4_STRUCT_DESC("TuningPara", "normal_ui_style")
    CalibDbV2_AFV31_Tuning_Para_t TuningPara;
} CalibDbV2_AFV31_t;

typedef struct CalibDbV2_AfV32_MeasCfg_s {
    // M4_NUMBER_DESC("table index", "u32", M4_RANGE(0, 1000000), "0", M4_DIGIT(0))
    unsigned int tbl_idx;
    // M4_BOOL_DESC("from awb", "0")
    bool from_awb;
    // M4_BOOL_DESC("from ynr", "0")
    bool from_ynr;
    // M4_BOOL_DESC("from bnr", "0")
    bool from_bnr;
    // M4_BOOL_DESC("bls en", "0")
    bool bls_en;
    // M4_BOOL_DESC("avg ds en", "0")
    bool avg_ds_en;
    // M4_BOOL_DESC("v1 max mode", "0")
    bool v1_maxmode;
    // M4_BOOL_DESC("v2 max mode", "0")
    bool v2_maxmode;
    // M4_BOOL_DESC("h1 max mode", "0")
    bool h1_maxmode;
    // M4_BOOL_DESC("h2 max mode", "0")
    bool h2_maxmode;
    // M4_BOOL_DESC("hiir left border mode", "0")
    bool hiir_left_border_mode;
    // M4_NUMBER_DESC("bnr in shift", "u8", M4_RANGE(0, 15), "0", M4_DIGIT(0))
    unsigned char bnr_in_shift;
    // M4_NUMBER_DESC("bls offset", "s16", M4_RANGE(-256, 255), "0", M4_DIGIT(0))
    short bls_offset;
    // M4_NUMBER_DESC("avg ds mode", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char avg_ds_mode;
    // M4_NUMBER_DESC("afmThres", "u16", M4_RANGE(0, 255), "4", M4_DIGIT(0))
    unsigned short afmThres;
    // M4_ARRAY_MARK_DESC("Gamma Curve", "u16", M4_SIZE(1,17),  M4_RANGE(0, 1023), "[0,45,108,179,245,344,409,459,500,567,622,676,759,833,896,962,1023]", M4_DIGIT(0), M4_DYNAMIC(0), "curve_table")
    unsigned short gammaY[17];
    // M4_ARRAY_DESC("gaus coe", "s16", M4_SIZE(3,3), M4_RANGE(-128, 127), "[0,64,0,0,64,0,0,0,0]", M4_DIGIT(0), M4_DYNAMIC(0))
    short gaus_coe[9];
    // M4_ENUM_DESC("downscale mode", "CalibDbV2_AF_DNSCL_MODE_t", "CalibDbV2_AF_DNSCL_1")
    CalibDbV2_AF_DNSCL_MODE_t dnscl_mode;
    // M4_NUMBER_DESC("v1fv reliable", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v1fv_reliable;
    // M4_NUMBER_DESC("v2fv reliable", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v2fv_reliable;
    // M4_NUMBER_DESC("v1 fir sel", "u8", M4_RANGE(0, 1), "1", M4_DIGIT(0))
    unsigned char v1_fir_sel;
    // M4_ARRAY_DESC("v1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.042,0.140]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v1_band[2];
    // M4_ARRAY_DESC("vertical first iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-255,255), "[-265, 686, 512]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_iir_coe[3];
    // M4_ARRAY_DESC("vertical first fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-124, 0, 124]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_fir_coe[3];
    // M4_ARRAY_DESC("v2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.055, 0.125]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v2_band[2];
    // M4_ARRAY_DESC("vertical second iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-325, 724, 512]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_iir_coe[3];
    // M4_ARRAY_DESC("vertical second fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-94, 0, 94]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_fir_coe[3];
    // M4_ARRAY_DESC("h1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.042, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h1_band[2];
    // M4_ARRAY_DESC("horizontal first iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 557, -276, 460, 0, -460]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal first iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 870, -399, 37, 0, -37]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir2_coe[6];
    // M4_ARRAY_DESC("h2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.055, 0.125]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h2_band[2];
    // M4_ARRAY_DESC("horizontal second iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 648, -344, 327, 0, -327]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal second iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 854, -409, 29, 0, -29]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir2_coe[6];
    // M4_NUMBER_DESC("ldg enable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char ldg_en;
    // M4_NUMBER_DESC("vertical minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_l;
    // M4_NUMBER_DESC("vertical gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ve_ldg_gain_l;
    // M4_NUMBER_DESC("vertical slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_l;
    // M4_NUMBER_DESC("vertical maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_h;
    // M4_NUMBER_DESC("vertical gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ve_ldg_gain_h;
    // M4_NUMBER_DESC("vertical slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_h;
    // M4_NUMBER_DESC("horizontal minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_l;
    // M4_NUMBER_DESC("horizontal gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ho_ldg_gain_l;
    // M4_NUMBER_DESC("horizontal slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_l;
    // M4_NUMBER_DESC("horizontal maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_h;
    // M4_NUMBER_DESC("horizontal gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ho_ldg_gain_h;
    // M4_NUMBER_DESC("horizontal slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_h;
    // M4_NUMBER_DESC("horizontal dilate num", "u8", M4_RANGE(0, 7), "0", M4_DIGIT(0))
    unsigned char hldg_dilate_num;
    // M4_NUMBER_DESC("vertical fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short v_fv_thresh;
    // M4_NUMBER_DESC("vertical fv limit", "u16", M4_RANGE(0, 1023), "1023", M4_DIGIT(0))
    unsigned short v_fv_limit;
    // M4_NUMBER_DESC("vertical fv slope", "u16", M4_RANGE(0, 511), "256", M4_DIGIT(0))
    unsigned short v_fv_slope;
    // M4_NUMBER_DESC("horizontal fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short h_fv_thresh;
    // M4_NUMBER_DESC("horizontal fv limit", "u16", M4_RANGE(0, 1023), "1023", M4_DIGIT(0))
    unsigned short h_fv_limit;
    // M4_NUMBER_DESC("horizontal fv slope", "u16", M4_RANGE(0, 511), "256", M4_DIGIT(0))
    unsigned short h_fv_slope;
    // M4_NUMBER_DESC("highlight thresh", "u16", M4_RANGE(0, 1023), "912", M4_DIGIT(0))
    unsigned short highlit_thresh;
    // M4_NUMBER_DESC("vertical fv ratio", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v_fv_ratio;
} CalibDbV2_AfV32_MeasCfg_t;

typedef struct CalibDbV2_AFV32_Tuning_Para_s {
    // M4_ENUM_DESC("mode", "CalibDbV2_AF_MODE_t", "CalibDbV2_AFMODE_CONT_PICTURE")
    CalibDbV2_AF_MODE_t af_mode;
    // M4_NUMBER_DESC("win_h_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_offs;
    // M4_NUMBER_DESC("win_v_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_offs;
    // M4_NUMBER_DESC("win_h_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_size;
    // M4_NUMBER_DESC("win_v_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_size;
    // M4_NUMBER_DESC("win_h_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_offs;
    // M4_NUMBER_DESC("win_v_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_offs;
    // M4_NUMBER_DESC("win_h_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_size;
    // M4_NUMBER_DESC("win_v_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_size;
    // M4_STRUCT_DESC("fixed mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t fixed_mode;
    // M4_STRUCT_DESC("macro mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t macro_mode;
    // M4_STRUCT_DESC("infinity mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t infinity_mode;
    // M4_STRUCT_DESC("contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t contrast_af;
    // M4_STRUCT_DESC("video contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t video_contrast_af;
    // M4_STRUCT_DESC("laser af", "normal_ui_style")
    CalibDbV2_Af_Laser_t laser_af;
    // M4_STRUCT_DESC("vcmcfg", "normal_ui_style")
    CalibDbV2_Af_VcmCfg_t vcmcfg;
    // M4_STRUCT_DESC("zoomfocus_tbl", "normal_ui_style")
    CalibDbV2_Af_ZoomFocusTbl_t zoomfocus_tbl;
    // M4_STRUCT_LIST_DESC("zoom_meas", M4_SIZE(1,8), "normal_ui_style")
    CalibDbV2_AfV30_ZoomMeas_t zoom_meas[8];
    // M4_NUMBER_DESC("zoom_meas_len", "s32", M4_RANGE(1,8), "1", M4_DIGIT(0), M4_HIDE(0))
    int zoom_meas_len;
    // M4_STRUCT_LIST_DESC("meas config table", M4_SIZE(1,32), "normal_ui_style")
    CalibDbV2_AfV32_MeasCfg_t meascfg_tbl[CALIBDBV2_MAX_MEAS_CONFIG_NUM];
    // M4_NUMBER_DESC("meascfg_tbl_len", "s32", M4_RANGE(1,13), "1", M4_DIGIT(0), M4_HIDE(0))
    int meascfg_tbl_len;
} CalibDbV2_AFV32_Tuning_Para_t;

typedef struct {
    // M4_STRUCT_DESC("TuningPara", "normal_ui_style")
    CalibDbV2_AFV32_Tuning_Para_t TuningPara;
} CalibDbV2_AFV32_t;

typedef enum CalibDbV2_AF_INPUT_SEL_e {
    AFSEL_DPCCOUT_0  = 0,    // channel 0
    AFSEL_DPCCOUT_1  = 1,    // channel 1
    AFSEL_DPCCOUT_2  = 2,    // channel 2
    AFSEL_DEBAYER_IN = 3,    // debayer in
    AFSEL_BNR_IN     = 4,    // bnr in
    AFSEL_YNR_IN     = 5,    // ynr in
    AFSEL_VICAP_IN   = 6,    // vicap in
    AFSEL_MAX
} CalibDbV2_AF_INPUT_SEL_t;

typedef struct CalibDbV2_AfV33_MeasCfg_s {
    // M4_NUMBER_DESC("table index", "u32", M4_RANGE(0, 1000000), "0", M4_DIGIT(0))
    unsigned int tbl_idx;
    // M4_ENUM_DESC("input sel", "CalibDbV2_AF_INPUT_SEL_t", "AFSEL_DPCCOUT_0")
    CalibDbV2_AF_INPUT_SEL_t input_sel;
    // M4_NUMBER_DESC("bnr in shift", "u8", M4_RANGE(0, 15), "0", M4_DIGIT(0))
    unsigned char bnr_in_shift;
    // M4_ENUM_DESC("downscale mode", "CalibDbV2_AF_DNSCL_MODE_t", "CalibDbV2_AF_DNSCL_1")
    CalibDbV2_AF_DNSCL_MODE_t dnscl_mode;
    // M4_BOOL_DESC("bls en", "0")
    bool bls_en;
    // M4_NUMBER_DESC("bls offset", "s16", M4_RANGE(-256, 255), "0", M4_DIGIT(0))
    short bls_offset;
    // M4_BOOL_DESC("v1 max mode", "0")
    bool v1_maxmode;
    // M4_BOOL_DESC("v2 max mode", "0")
    bool v2_maxmode;
    // M4_BOOL_DESC("h1 max mode", "0")
    bool h1_maxmode;
    // M4_BOOL_DESC("h2 max mode", "0")
    bool h2_maxmode;
    // M4_BOOL_DESC("hiir left border mode", "0")
    bool hiir_left_border_mode;
    // M4_ARRAY_MARK_DESC("Gamma Curve", "u16", M4_SIZE(1,17),  M4_RANGE(0, 1023), "[0,45,108,179,245,344,409,459,500,567,622,676,759,833,896,962,1023]", M4_DIGIT(0), M4_DYNAMIC(0), "curve_table")
    unsigned short gammaY[17];
    // M4_ARRAY_DESC("gaus coe", "s16", M4_SIZE(3,3), M4_RANGE(-128, 127), "[0,64,0,0,64,0,0,0,0]", M4_DIGIT(0), M4_DYNAMIC(0))
    short gaus_coe[9];
    // M4_ARRAY_DESC("v1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.042,0.140]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v1_band[2];
    // M4_ARRAY_DESC("vertical first iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-255,255), "[-265, 686, 512]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_iir_coe[3];
    // M4_ARRAY_DESC("vertical first fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-124, 0, 124]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v1_fir_coe[3];
    // M4_ARRAY_DESC("v2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.055, 0.125]", M4_DIGIT(3), M4_DYNAMIC(0))
    float v2_band[2];
    // M4_ARRAY_DESC("vertical second iir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-325, 724, 512]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_iir_coe[3];
    // M4_ARRAY_DESC("vertical second fir filter", "s16", M4_SIZE(1,3), M4_RANGE(-2047,2047), "[-94, 0, 94]", M4_DIGIT(0), M4_DYNAMIC(0))
    short v2_fir_coe[3];
    // M4_ARRAY_DESC("h1 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.042, 0.14]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h1_band[2];
    // M4_ARRAY_DESC("horizontal first iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 557, -276, 460, 0, -460]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal first iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 870, -399, 37, 0, -37]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h1_iir2_coe[6];
    // M4_ARRAY_DESC("h2 band", "f32", M4_SIZE(1,2), M4_RANGE(0, 1), "[0.055, 0.125]", M4_DIGIT(3), M4_DYNAMIC(0))
    float h2_band[2];
    // M4_ARRAY_DESC("horizontal second iir1 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 648, -344, 327, 0, -327]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir1_coe[6];
    // M4_ARRAY_DESC("horizontal second iir2 filter", "s16", M4_SIZE(1,6), M4_RANGE(-2047,2047), "[512, 854, -409, 29, 0, -29]", M4_DIGIT(0), M4_DYNAMIC(0))
    short h2_iir2_coe[6];
    // M4_NUMBER_DESC("ldg enable", "u8", M4_RANGE(0, 1), "0", M4_DIGIT(0))
    unsigned char ldg_en;
    // M4_NUMBER_DESC("vertical minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_l;
    // M4_NUMBER_DESC("vertical gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ve_ldg_gain_l;
    // M4_NUMBER_DESC("vertical slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_l;
    // M4_NUMBER_DESC("vertical maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ve_ldg_lumth_h;
    // M4_NUMBER_DESC("vertical gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ve_ldg_gain_h;
    // M4_NUMBER_DESC("vertical slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ve_ldg_gslp_h;
    // M4_NUMBER_DESC("horizontal minluma thresh", "u8", M4_RANGE(0, 255), "64", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_l;
    // M4_NUMBER_DESC("horizontal gain for minluma", "u8", M4_RANGE(0, 255), "28", M4_DIGIT(0))
    unsigned char ho_ldg_gain_l;
    // M4_NUMBER_DESC("horizontal slope low", "u16", M4_RANGE(0, 8191), "1286", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_l;
    // M4_NUMBER_DESC("horizontal maxluma thresh", "u8", M4_RANGE(0, 255), "185", M4_DIGIT(0))
    unsigned char ho_ldg_lumth_h;
    // M4_NUMBER_DESC("horizontal gain for maxluma", "u8", M4_RANGE(0, 255), "8", M4_DIGIT(0))
    unsigned char ho_ldg_gain_h;
    // M4_NUMBER_DESC("horizontal slope high", "u16", M4_RANGE(0, 8191), "1400", M4_DIGIT(0))
    unsigned short ho_ldg_gslp_h;
    // M4_NUMBER_DESC("horizontal dilate num", "u8", M4_RANGE(0, 7), "0", M4_DIGIT(0))
    unsigned char hldg_dilate_num;
    // M4_NUMBER_DESC("vertical fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short v_fv_thresh;
    // M4_NUMBER_DESC("vertical fv limit", "u16", M4_RANGE(0, 1023), "1023", M4_DIGIT(0))
    unsigned short v_fv_limit;
    // M4_NUMBER_DESC("vertical fv slope", "u16", M4_RANGE(0, 511), "256", M4_DIGIT(0))
    unsigned short v_fv_slope;
    // M4_NUMBER_DESC("horizontal fv thresh", "u16", M4_RANGE(0, 4095), "4", M4_DIGIT(0))
    unsigned short h_fv_thresh;
    // M4_NUMBER_DESC("horizontal fv limit", "u16", M4_RANGE(0, 1023), "1023", M4_DIGIT(0))
    unsigned short h_fv_limit;
    // M4_NUMBER_DESC("horizontal fv slope", "u16", M4_RANGE(0, 511), "256", M4_DIGIT(0))
    unsigned short h_fv_slope;
    // M4_NUMBER_DESC("highlight thresh", "u16", M4_RANGE(0, 1023), "912", M4_DIGIT(0))
    unsigned short highlit_thresh;
    // M4_NUMBER_DESC("v1fv reliable", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v1fv_reliable;
    // M4_NUMBER_DESC("v2fv reliable", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v2fv_reliable;
    // M4_NUMBER_DESC("vertical fv ratio", "f32", M4_RANGE(0, 1), "0.5", M4_DIGIT(3))
    float v_fv_ratio;
} CalibDbV2_AfV33_MeasCfg_t;

typedef struct CalibDbV2_AFV33_Tuning_Para_s {
    // M4_ENUM_DESC("mode", "CalibDbV2_AF_MODE_t", "CalibDbV2_AFMODE_CONT_PICTURE")
    CalibDbV2_AF_MODE_t af_mode;
    // M4_NUMBER_DESC("win_h_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_offs;
    // M4_NUMBER_DESC("win_v_offs", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_offs;
    // M4_NUMBER_DESC("win_h_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_h_size;
    // M4_NUMBER_DESC("win_v_size", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short win_v_size;
    // M4_NUMBER_DESC("win_h_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_offs;
    // M4_NUMBER_DESC("win_v_offs in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_offs;
    // M4_NUMBER_DESC("win_h_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_h_size;
    // M4_NUMBER_DESC("win_v_size in video", "u16", M4_RANGE(0,2000), "0", M4_DIGIT(0),M4_HIDE(0))
    unsigned short video_win_v_size;
    // M4_STRUCT_DESC("fixed mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t fixed_mode;
    // M4_STRUCT_DESC("macro mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t macro_mode;
    // M4_STRUCT_DESC("infinity mode", "normal_ui_style")
    CalibDbV2_Af_DefCode_t infinity_mode;
    // M4_STRUCT_DESC("contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t contrast_af;
    // M4_STRUCT_DESC("video contrast af", "normal_ui_style")
    CalibDbV2_Af_Contrast_t video_contrast_af;
    // M4_STRUCT_DESC("laser af", "normal_ui_style")
    CalibDbV2_Af_Laser_t laser_af;
    // M4_STRUCT_DESC("pdaf", "normal_ui_style")
    CalibDbV2_Af_Pdaf_t pdaf;
    // M4_STRUCT_DESC("vcmcfg", "normal_ui_style")
    CalibDbV2_Af_VcmCfg_t vcmcfg;
    // M4_STRUCT_DESC("zoomfocus_tbl", "normal_ui_style")
    CalibDbV2_Af_ZoomFocusTbl_t zoomfocus_tbl;
    // M4_STRUCT_LIST_DESC("zoom_meas", M4_SIZE(1,8), "normal_ui_style")
    CalibDbV2_AfV30_ZoomMeas_t zoom_meas[8];
    // M4_NUMBER_DESC("zoom_meas_len", "s32", M4_RANGE(1,8), "1", M4_DIGIT(0), M4_HIDE(0))
    int zoom_meas_len;
    // M4_STRUCT_LIST_DESC("meas config table", M4_SIZE(1,32), "normal_ui_style")
    CalibDbV2_AfV33_MeasCfg_t meascfg_tbl[CALIBDBV2_MAX_MEAS_CONFIG_NUM];
    // M4_NUMBER_DESC("meascfg_tbl_len", "s32", M4_RANGE(1,32), "1", M4_DIGIT(0), M4_HIDE(0))
    int meascfg_tbl_len;
} CalibDbV2_AFV33_Tuning_Para_t;

typedef struct {
    // M4_STRUCT_DESC("TuningPara", "normal_ui_style")
    CalibDbV2_AFV33_Tuning_Para_t TuningPara;
} CalibDbV2_AFV33_t;

RKAIQ_END_DECLARE

#endif
