/*
 * Copyright (c) 2024 Rockchip Eletronics Co., Ltd.
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
 */


#ifndef _RK_AIQ_USER_API_ABAYERTNRV30_H_
#define _RK_AIQ_USER_API_ABAYERTNRV30_H_

#include "abayertnrV30/rk_aiq_uapi_abayertnr_int_v30.h"

typedef struct rk_aiq_sys_ctx_s rk_aiq_sys_ctx_t;

RKAIQ_BEGIN_DECLARE

XCamReturn
rk_aiq_user_api_abayertnrV30_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, const rk_aiq_bayertnr_attrib_v30_t* attr);

XCamReturn
rk_aiq_user_api_abayertnrV30_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_bayertnr_attrib_v30_t* attr);

XCamReturn rk_aiq_user_api_abayertnrV30_SetStrength(
    const rk_aiq_sys_ctx_t* sys_ctx, const rk_aiq_bayertnr_strength_v30_t* pStrength);

XCamReturn
rk_aiq_user_api_abayertnrV30_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_bayertnr_strength_v30_t *pStrength);


XCamReturn
rk_aiq_user_api_abayertnrV30_GetInfo(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_bayertnr_info_v30_t *pInfo);




RKAIQ_END_DECLARE

#endif
