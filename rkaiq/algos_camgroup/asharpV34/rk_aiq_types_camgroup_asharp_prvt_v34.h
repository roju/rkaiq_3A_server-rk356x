/*
* rk_aiq_types_camgroup_asharp_algo_prvt_v34.h

* for rockchip v2.0.0
*
*  Copyright (c) 2024 Rockchip Corporation
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
/* for rockchip v2.0.0*/

#ifndef __RK_AIQ_CAMGROUP_ASHARPV34_ALGO_PRVT_H__
#define __RK_AIQ_CAMGROUP_ASHARPV34_ALGO_PRVT_H__

#include "asharpV34/rk_aiq_types_asharp_algo_prvt_v34.h"

typedef enum CalibDbV2_CamGroup_AsharpV34_Method_e {
    CalibDbV2_CAMGROUP_ASHARPV34_METHOD_MIN = 0,
    CalibDbV2_CAMGROUP_ASHARPV34_METHOD_MEAN, /*config each camera with same para, para is got by
                                                 mean stas of all cameras*/
    CalibDbV2_CAMGROUP_ASHARPV34_METHOD_MAX,  /*config each camera with diff para, each para is got
                                                 by stats of tha camera*/
} CalibDbV2_CamGroup_AsharpV34_Method_t;

typedef struct CalibDbV2_CamGroup_AsharpV34_s {
    CalibDbV2_CamGroup_AsharpV34_Method_t groupMethod;
    // add more para for surround view
} CalibDbV2_CamGroup_AsharpV34_t;

typedef struct CamGroup_AsharpV34_Contex_s {
    Asharp_Context_V34_t* asharp_contex_v34;
    CalibDbV2_CamGroup_AsharpV34_t group_CalibV2;
    int camera_Num;

} CamGroup_AsharpV34_Contex_t;

#endif
