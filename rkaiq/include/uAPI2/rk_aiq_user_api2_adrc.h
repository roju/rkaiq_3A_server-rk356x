/*
 *  Copyright (c) 2019 Rockchip Corporation
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

#ifndef _RK_AIQ_USER_API2_ADRC_H_
#define _RK_AIQ_USER_API2_ADRC_H_

#include "adrc/rk_aiq_uapi_adrc_int.h"
#include "adrc_uapi_compact.h"

#ifndef RK_AIQ_SYS_CTX_T
#define RK_AIQ_SYS_CTX_T
typedef struct rk_aiq_sys_ctx_s rk_aiq_sys_ctx_t;
#endif

RKAIQ_BEGIN_DECLARE

XCamReturn rk_aiq_user_api2_adrc_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, drc_attrib_t attr);
XCamReturn rk_aiq_user_api2_adrc_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, drc_attrib_t* attr);

XCamReturn rk_aiq_user_api2_adrc_v10_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx,
                                               const drcAttrV10_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v10_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, drcAttrV10_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v11_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx,
                                               const drcAttrV11_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v11_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, drcAttrV11_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v12_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx,
                                               const drcAttrV12_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v12_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, drcAttrV12_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v12_lite_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx,
                                                    const drcAttrV12Lite_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v12_lite_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx,
                                                    drcAttrV12Lite_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v20_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx,
                                               const drcAttrV20_t* attr);
XCamReturn rk_aiq_user_api2_adrc_v20_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, drcAttrV20_t* attr);

RKAIQ_END_DECLARE

#endif
