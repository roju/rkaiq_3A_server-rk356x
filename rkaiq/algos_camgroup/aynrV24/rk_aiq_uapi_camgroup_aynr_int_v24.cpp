#include "aynrV24/rk_aiq_uapi_camgroup_aynr_int_v24.h"

#include "rk_aiq_types_camgroup_aynr_prvt_v24.h"

#if 1
#define CAMGROUP_AYNRV24_CHROMA_SF_STRENGTH_SLOPE_FACTOR (5.0)

XCamReturn rk_aiq_uapi_camgroup_aynrV24_SetAttrib(RkAiqAlgoContext* ctx,
                                                  const rk_aiq_ynr_attrib_v24_t* attr,
                                                  bool /* need_sync */) {
    LOGD_ANR("%s:%d\n", __FUNCTION__, __LINE__);

    CamGroup_AynrV24_Contex_t* pGroupCtx = (CamGroup_AynrV24_Contex_t*)ctx;
    Aynr_Context_V24_t* pCtx             = pGroupCtx->aynr_contex_v24;

    pCtx->eMode = attr->eMode;
    if (pCtx->eMode == AYNRV24_OP_MODE_AUTO) {
        pCtx->stAuto = attr->stAuto;
    } else if (pCtx->eMode == AYNRV24_OP_MODE_MANUAL) {
        pCtx->stManual.stSelect = attr->stManual.stSelect;
    } else if (pCtx->eMode == AYNRV24_OP_MODE_REG_MANUAL) {
        pCtx->stManual.stFix = attr->stManual.stFix;
    }
    pCtx->isReCalculate |= 1;

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn rk_aiq_uapi_camgroup_aynrV24_GetAttrib(const RkAiqAlgoContext* ctx,
                                                  rk_aiq_ynr_attrib_v24_t* attr) {
    LOGD_ANR("%s:%d\n", __FUNCTION__, __LINE__);

    CamGroup_AynrV24_Contex_t* pGroupCtx = (CamGroup_AynrV24_Contex_t*)ctx;
    Aynr_Context_V24_t* pCtx             = pGroupCtx->aynr_contex_v24;

    attr->eMode = pCtx->eMode;
    memcpy(&attr->stAuto, &pCtx->stAuto, sizeof(attr->stAuto));
    memcpy(&attr->stManual, &pCtx->stManual, sizeof(attr->stManual));

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn rk_aiq_uapi_camgroup_aynrV24_SetLumaSFStrength(
    const RkAiqAlgoContext* ctx, const rk_aiq_ynr_strength_v24_t* pStrength) {
    LOGD_ANR("%s:%d\n", __FUNCTION__, __LINE__);
    CamGroup_AynrV24_Contex_t* pGroupCtx = (CamGroup_AynrV24_Contex_t*)ctx;
    Aynr_Context_V24_t* pCtx             = pGroupCtx->aynr_contex_v24;

    float fStrength = 1.0f;
    float fPercent  = 0.5f;
    float fslope    = CAMGROUP_AYNRV24_CHROMA_SF_STRENGTH_SLOPE_FACTOR;

    fPercent = pStrength->percent;

    if (fPercent <= 0.5) {
        fStrength = fPercent / 0.5;
    } else {
        if (fPercent >= 0.999999) fPercent = 0.999999;
        fStrength = 0.5 * fslope / (1.0 - fPercent) - fslope + 1;
    }

    pCtx->stStrength         = *pStrength;
    pCtx->stStrength.percent = fStrength;
    pCtx->isReCalculate |= 1;

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn rk_aiq_uapi_camgroup_aynrV24_GetLumaSFStrength(const RkAiqAlgoContext* ctx,
                                                          rk_aiq_ynr_strength_v24_t* pStrength) {
    LOGD_ANR("%s:%d\n", __FUNCTION__, __LINE__);
    CamGroup_AynrV24_Contex_t* pGroupCtx = (CamGroup_AynrV24_Contex_t*)ctx;
    Aynr_Context_V24_t* pCtx             = pGroupCtx->aynr_contex_v24;

    float fStrength = 1.0f;
    float fPercent  = 0.5f;
    float fslope    = CAMGROUP_AYNRV24_CHROMA_SF_STRENGTH_SLOPE_FACTOR;

    fStrength = pCtx->stStrength.percent;

    if (fStrength <= 1) {
        fPercent = fStrength * 0.5;
    } else {
        float tmp = 1.0;
        tmp       = 1 - 0.5 * fslope / (fStrength + fslope - 1);
        if (abs(tmp - 0.999999) < 0.000001) {
            tmp = 1.0;
        }
        fPercent = tmp;
    }

    *pStrength         = pCtx->stStrength;
    pStrength->percent = fPercent;

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn rk_aiq_uapi_camgroup_aynrV24_GetInfo(const RkAiqAlgoContext* ctx,
                                                rk_aiq_ynr_info_v24_t* pInfo) {
    CamGroup_AynrV24_Contex_t* pGroupCtx = (CamGroup_AynrV24_Contex_t*)ctx;
    Aynr_Context_V24_t* pCtx             = pGroupCtx->aynr_contex_v24;

    pInfo->iso = pCtx->stExpInfo.arIso[pCtx->stExpInfo.hdr_mode];

    pInfo->expo_info = pCtx->stExpInfo;
    return XCAM_RETURN_NO_ERROR;
}

#endif
