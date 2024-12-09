/*
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

#ifndef _RK_AIQ_USER_API_AYUVMEV1_H_
#define _RK_AIQ_USER_API_AYUVMEV1_H_

#include "ayuvmeV1/rk_aiq_uapi_ayuvme_int_v1.h"

typedef struct rk_aiq_sys_ctx_s rk_aiq_sys_ctx_t;

RKAIQ_BEGIN_DECLARE

XCamReturn
rk_aiq_user_api_ayuvmeV1_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, const rk_aiq_yuvme_attrib_v1_t* attr);

XCamReturn
rk_aiq_user_api_ayuvmeV1_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_yuvme_attrib_v1_t* attr);

XCamReturn
rk_aiq_user_api_ayuvmeV1_SetStrength(const rk_aiq_sys_ctx_t* sys_ctx, const rk_aiq_yuvme_strength_v1_t* pStrength);

XCamReturn
rk_aiq_user_api_ayuvmeV1_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_yuvme_strength_v1_t* pStrength);

XCamReturn
rk_aiq_user_api_ayuvmeV1_GetInfo(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_yuvme_info_v1_t* pInfo);

RKAIQ_END_DECLARE

#endif
