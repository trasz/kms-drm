/*
 * Copyright 2012-16 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef _DCE_DCE_TRANSFORM_H_
#define _DCE_DCE_TRANSFORM_H_


#include "transform.h"

#define TO_DCE_TRANSFORM(transform)\
	container_of(transform, struct dce_transform, base)

#define LB_TOTAL_NUMBER_OF_ENTRIES 1712
#define LB_BITS_PER_ENTRY 144

#define XFM_COMMON_REG_LIST_DCE_BASE(id) \
	SRI(LB_DATA_FORMAT, LB, id), \
	SRI(GAMUT_REMAP_CONTROL, DCP, id), \
	SRI(GAMUT_REMAP_C11_C12, DCP, id), \
	SRI(GAMUT_REMAP_C13_C14, DCP, id), \
	SRI(GAMUT_REMAP_C21_C22, DCP, id), \
	SRI(GAMUT_REMAP_C23_C24, DCP, id), \
	SRI(GAMUT_REMAP_C31_C32, DCP, id), \
	SRI(GAMUT_REMAP_C33_C34, DCP, id), \
	SRI(DENORM_CONTROL, DCP, id), \
	SRI(DCP_SPATIAL_DITHER_CNTL, DCP, id), \
	SRI(OUT_ROUND_CONTROL, DCP, id), \
	SRI(OUT_CLAMP_CONTROL_R_CR, DCP, id), \
	SRI(OUT_CLAMP_CONTROL_G_Y, DCP, id), \
	SRI(OUT_CLAMP_CONTROL_B_CB, DCP, id), \
	SRI(SCL_MODE, SCL, id), \
	SRI(SCL_TAP_CONTROL, SCL, id), \
	SRI(SCL_CONTROL, SCL, id), \
	SRI(SCL_BYPASS_CONTROL, SCL, id), \
	SRI(EXT_OVERSCAN_LEFT_RIGHT, SCL, id), \
	SRI(EXT_OVERSCAN_TOP_BOTTOM, SCL, id), \
	SRI(SCL_VERT_FILTER_CONTROL, SCL, id), \
	SRI(SCL_HORZ_FILTER_CONTROL, SCL, id), \
	SRI(SCL_COEF_RAM_SELECT, SCL, id), \
	SRI(SCL_COEF_RAM_TAP_DATA, SCL, id), \
	SRI(VIEWPORT_START, SCL, id), \
	SRI(VIEWPORT_SIZE, SCL, id), \
	SRI(SCL_HORZ_FILTER_SCALE_RATIO, SCL, id), \
	SRI(SCL_VERT_FILTER_SCALE_RATIO, SCL, id), \
	SRI(SCL_HORZ_FILTER_INIT, SCL, id), \
	SRI(SCL_VERT_FILTER_INIT, SCL, id), \
	SRI(SCL_AUTOMATIC_MODE_CONTROL, SCL, id), \
	SRI(LB_MEMORY_CTRL, LB, id), \
	SRI(SCL_UPDATE, SCL, id), \
	SRI(SCL_F_SHARP_CONTROL, SCL, id)

#define XFM_COMMON_REG_LIST_DCE100(id) \
	XFM_COMMON_REG_LIST_DCE_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, CRTC, id), \
	SRI(DCFE_MEM_PWR_STATUS, CRTC, id)

#define XFM_COMMON_REG_LIST_DCE110(id) \
	XFM_COMMON_REG_LIST_DCE_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, DCFE, id), \
	SRI(DCFE_MEM_PWR_STATUS, DCFE, id)

#define XFM_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define XFM_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh) \
	XFM_SF(OUT_CLAMP_CONTROL_B_CB, OUT_CLAMP_MIN_B_CB, mask_sh), \
	XFM_SF(OUT_CLAMP_CONTROL_B_CB, OUT_CLAMP_MAX_B_CB, mask_sh), \
	XFM_SF(OUT_CLAMP_CONTROL_G_Y, OUT_CLAMP_MIN_G_Y, mask_sh), \
	XFM_SF(OUT_CLAMP_CONTROL_G_Y, OUT_CLAMP_MAX_G_Y, mask_sh), \
	XFM_SF(OUT_CLAMP_CONTROL_R_CR, OUT_CLAMP_MIN_R_CR, mask_sh), \
	XFM_SF(OUT_CLAMP_CONTROL_R_CR, OUT_CLAMP_MAX_R_CR, mask_sh), \
	XFM_SF(OUT_ROUND_CONTROL, OUT_ROUND_TRUNC_MODE, mask_sh), \
	XFM_SF(DCP_SPATIAL_DITHER_CNTL, DCP_SPATIAL_DITHER_EN, mask_sh), \
	XFM_SF(DCP_SPATIAL_DITHER_CNTL, DCP_SPATIAL_DITHER_MODE, mask_sh), \
	XFM_SF(DCP_SPATIAL_DITHER_CNTL, DCP_SPATIAL_DITHER_DEPTH, mask_sh), \
	XFM_SF(DCP_SPATIAL_DITHER_CNTL, DCP_FRAME_RANDOM_ENABLE, mask_sh), \
	XFM_SF(DCP_SPATIAL_DITHER_CNTL, DCP_RGB_RANDOM_ENABLE, mask_sh), \
	XFM_SF(DCP_SPATIAL_DITHER_CNTL, DCP_HIGHPASS_RANDOM_ENABLE, mask_sh), \
	XFM_SF(DENORM_CONTROL, DENORM_MODE, mask_sh), \
	XFM_SF(LB_DATA_FORMAT, PIXEL_DEPTH, mask_sh), \
	XFM_SF(LB_DATA_FORMAT, PIXEL_EXPAN_MODE, mask_sh), \
	XFM_SF(GAMUT_REMAP_C11_C12, GAMUT_REMAP_C11, mask_sh), \
	XFM_SF(GAMUT_REMAP_C11_C12, GAMUT_REMAP_C12, mask_sh), \
	XFM_SF(GAMUT_REMAP_C13_C14, GAMUT_REMAP_C13, mask_sh), \
	XFM_SF(GAMUT_REMAP_C13_C14, GAMUT_REMAP_C14, mask_sh), \
	XFM_SF(GAMUT_REMAP_C21_C22, GAMUT_REMAP_C21, mask_sh), \
	XFM_SF(GAMUT_REMAP_C21_C22, GAMUT_REMAP_C22, mask_sh), \
	XFM_SF(GAMUT_REMAP_C23_C24, GAMUT_REMAP_C23, mask_sh), \
	XFM_SF(GAMUT_REMAP_C23_C24, GAMUT_REMAP_C24, mask_sh), \
	XFM_SF(GAMUT_REMAP_C31_C32, GAMUT_REMAP_C31, mask_sh), \
	XFM_SF(GAMUT_REMAP_C31_C32, GAMUT_REMAP_C32, mask_sh), \
	XFM_SF(GAMUT_REMAP_C33_C34, GAMUT_REMAP_C33, mask_sh), \
	XFM_SF(GAMUT_REMAP_C33_C34, GAMUT_REMAP_C34, mask_sh), \
	XFM_SF(GAMUT_REMAP_CONTROL, GRPH_GAMUT_REMAP_MODE, mask_sh), \
	XFM_SF(SCL_MODE, SCL_MODE, mask_sh), \
	XFM_SF(SCL_TAP_CONTROL, SCL_H_NUM_OF_TAPS, mask_sh), \
	XFM_SF(SCL_TAP_CONTROL, SCL_V_NUM_OF_TAPS, mask_sh), \
	XFM_SF(SCL_CONTROL, SCL_BOUNDARY_MODE, mask_sh), \
	XFM_SF(SCL_BYPASS_CONTROL, SCL_BYPASS_MODE, mask_sh), \
	XFM_SF(EXT_OVERSCAN_LEFT_RIGHT, EXT_OVERSCAN_LEFT, mask_sh), \
	XFM_SF(EXT_OVERSCAN_LEFT_RIGHT, EXT_OVERSCAN_RIGHT, mask_sh), \
	XFM_SF(EXT_OVERSCAN_TOP_BOTTOM, EXT_OVERSCAN_TOP, mask_sh), \
	XFM_SF(EXT_OVERSCAN_TOP_BOTTOM, EXT_OVERSCAN_BOTTOM, mask_sh), \
	XFM_SF(SCL_COEF_RAM_SELECT, SCL_C_RAM_FILTER_TYPE, mask_sh), \
	XFM_SF(SCL_COEF_RAM_SELECT, SCL_C_RAM_PHASE, mask_sh), \
	XFM_SF(SCL_COEF_RAM_SELECT, SCL_C_RAM_TAP_PAIR_IDX, mask_sh), \
	XFM_SF(SCL_COEF_RAM_TAP_DATA, SCL_C_RAM_EVEN_TAP_COEF_EN, mask_sh), \
	XFM_SF(SCL_COEF_RAM_TAP_DATA, SCL_C_RAM_EVEN_TAP_COEF, mask_sh), \
	XFM_SF(SCL_COEF_RAM_TAP_DATA, SCL_C_RAM_ODD_TAP_COEF_EN, mask_sh), \
	XFM_SF(SCL_COEF_RAM_TAP_DATA, SCL_C_RAM_ODD_TAP_COEF, mask_sh), \
	XFM_SF(VIEWPORT_START, VIEWPORT_X_START, mask_sh), \
	XFM_SF(VIEWPORT_START, VIEWPORT_Y_START, mask_sh), \
	XFM_SF(VIEWPORT_SIZE, VIEWPORT_HEIGHT, mask_sh), \
	XFM_SF(VIEWPORT_SIZE, VIEWPORT_WIDTH, mask_sh), \
	XFM_SF(SCL_HORZ_FILTER_SCALE_RATIO, SCL_H_SCALE_RATIO, mask_sh), \
	XFM_SF(SCL_VERT_FILTER_SCALE_RATIO, SCL_V_SCALE_RATIO, mask_sh), \
	XFM_SF(SCL_HORZ_FILTER_INIT, SCL_H_INIT_INT, mask_sh), \
	XFM_SF(SCL_HORZ_FILTER_INIT, SCL_H_INIT_FRAC, mask_sh), \
	XFM_SF(SCL_VERT_FILTER_INIT, SCL_V_INIT_INT, mask_sh), \
	XFM_SF(SCL_VERT_FILTER_INIT, SCL_V_INIT_FRAC, mask_sh), \
	XFM_SF(LB_MEMORY_CTRL, LB_MEMORY_CONFIG, mask_sh), \
	XFM_SF(LB_MEMORY_CTRL, LB_MEMORY_SIZE, mask_sh), \
	XFM_SF(SCL_VERT_FILTER_CONTROL, SCL_V_2TAP_HARDCODE_COEF_EN, mask_sh), \
	XFM_SF(SCL_HORZ_FILTER_CONTROL, SCL_H_2TAP_HARDCODE_COEF_EN, mask_sh), \
	XFM_SF(SCL_UPDATE, SCL_COEF_UPDATE_COMPLETE, mask_sh), \
	XFM_SF(LB_DATA_FORMAT, ALPHA_EN, mask_sh)

#define XFM_COMMON_MASK_SH_LIST_DCE110(mask_sh) \
	XFM_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh), \
	XFM_SF(DCFE_MEM_PWR_CTRL, SCL_COEFF_MEM_PWR_DIS, mask_sh), \
	XFM_SF(DCFE_MEM_PWR_STATUS, SCL_COEFF_MEM_PWR_STATE, mask_sh), \
	XFM_SF(SCL_MODE, SCL_PSCL_EN, mask_sh)

#define XFM_REG_FIELD_LIST(type) \
	type OUT_CLAMP_MIN_B_CB; \
	type OUT_CLAMP_MAX_B_CB; \
	type OUT_CLAMP_MIN_G_Y; \
	type OUT_CLAMP_MAX_G_Y; \
	type OUT_CLAMP_MIN_R_CR; \
	type OUT_CLAMP_MAX_R_CR; \
	type OUT_ROUND_TRUNC_MODE; \
	type DCP_SPATIAL_DITHER_EN; \
	type DCP_SPATIAL_DITHER_MODE; \
	type DCP_SPATIAL_DITHER_DEPTH; \
	type DCP_FRAME_RANDOM_ENABLE; \
	type DCP_RGB_RANDOM_ENABLE; \
	type DCP_HIGHPASS_RANDOM_ENABLE; \
	type DENORM_MODE; \
	type PIXEL_DEPTH; \
	type PIXEL_EXPAN_MODE; \
	type GAMUT_REMAP_C11; \
	type GAMUT_REMAP_C12; \
	type GAMUT_REMAP_C13; \
	type GAMUT_REMAP_C14; \
	type GAMUT_REMAP_C21; \
	type GAMUT_REMAP_C22; \
	type GAMUT_REMAP_C23; \
	type GAMUT_REMAP_C24; \
	type GAMUT_REMAP_C31; \
	type GAMUT_REMAP_C32; \
	type GAMUT_REMAP_C33; \
	type GAMUT_REMAP_C34; \
	type GRPH_GAMUT_REMAP_MODE; \
	type SCL_MODE; \
	type SCL_BYPASS_MODE; \
	type SCL_PSCL_EN; \
	type SCL_H_NUM_OF_TAPS; \
	type SCL_V_NUM_OF_TAPS; \
	type SCL_BOUNDARY_MODE; \
	type EXT_OVERSCAN_LEFT; \
	type EXT_OVERSCAN_RIGHT; \
	type EXT_OVERSCAN_TOP; \
	type EXT_OVERSCAN_BOTTOM; \
	type SCL_COEFF_MEM_PWR_DIS; \
	type SCL_COEFF_MEM_PWR_STATE; \
	type SCL_C_RAM_FILTER_TYPE; \
	type SCL_C_RAM_PHASE; \
	type SCL_C_RAM_TAP_PAIR_IDX; \
	type SCL_C_RAM_EVEN_TAP_COEF_EN; \
	type SCL_C_RAM_EVEN_TAP_COEF; \
	type SCL_C_RAM_ODD_TAP_COEF_EN; \
	type SCL_C_RAM_ODD_TAP_COEF; \
	type VIEWPORT_X_START; \
	type VIEWPORT_Y_START; \
	type VIEWPORT_HEIGHT; \
	type VIEWPORT_WIDTH; \
	type SCL_H_SCALE_RATIO; \
	type SCL_V_SCALE_RATIO; \
	type SCL_H_INIT_INT; \
	type SCL_H_INIT_FRAC; \
	type SCL_V_INIT_INT; \
	type SCL_V_INIT_FRAC; \
	type LB_MEMORY_CONFIG; \
	type LB_MEMORY_SIZE; \
	type SCL_V_2TAP_HARDCODE_COEF_EN; \
	type SCL_H_2TAP_HARDCODE_COEF_EN; \
	type SCL_COEF_UPDATE_COMPLETE; \
	type ALPHA_EN

struct dce_transform_shift {
	XFM_REG_FIELD_LIST(uint8_t);
};

struct dce_transform_mask {
	XFM_REG_FIELD_LIST(uint32_t);
};

struct dce_transform_registers {
	uint32_t LB_DATA_FORMAT;
	uint32_t GAMUT_REMAP_CONTROL;
	uint32_t GAMUT_REMAP_C11_C12;
	uint32_t GAMUT_REMAP_C13_C14;
	uint32_t GAMUT_REMAP_C21_C22;
	uint32_t GAMUT_REMAP_C23_C24;
	uint32_t GAMUT_REMAP_C31_C32;
	uint32_t GAMUT_REMAP_C33_C34;
	uint32_t DENORM_CONTROL;
	uint32_t DCP_SPATIAL_DITHER_CNTL;
	uint32_t OUT_ROUND_CONTROL;
	uint32_t OUT_CLAMP_CONTROL_R_CR;
	uint32_t OUT_CLAMP_CONTROL_G_Y;
	uint32_t OUT_CLAMP_CONTROL_B_CB;
	uint32_t SCL_MODE;
	uint32_t SCL_TAP_CONTROL;
	uint32_t SCL_CONTROL;
	uint32_t SCL_BYPASS_CONTROL;
	uint32_t EXT_OVERSCAN_LEFT_RIGHT;
	uint32_t EXT_OVERSCAN_TOP_BOTTOM;
	uint32_t SCL_VERT_FILTER_CONTROL;
	uint32_t SCL_HORZ_FILTER_CONTROL;
	uint32_t DCFE_MEM_PWR_CTRL;
	uint32_t DCFE_MEM_PWR_STATUS;
	uint32_t SCL_COEF_RAM_SELECT;
	uint32_t SCL_COEF_RAM_TAP_DATA;
	uint32_t VIEWPORT_START;
	uint32_t VIEWPORT_SIZE;
	uint32_t SCL_HORZ_FILTER_SCALE_RATIO;
	uint32_t SCL_VERT_FILTER_SCALE_RATIO;
	uint32_t SCL_HORZ_FILTER_INIT;
	uint32_t SCL_VERT_FILTER_INIT;
	uint32_t SCL_AUTOMATIC_MODE_CONTROL;
	uint32_t LB_MEMORY_CTRL;
	uint32_t SCL_UPDATE;
	uint32_t SCL_F_SHARP_CONTROL;
};

struct init_int_and_frac {
	uint32_t integer;
	uint32_t fraction;
};

struct scl_ratios_inits {
	uint32_t h_int_scale_ratio;
	uint32_t v_int_scale_ratio;
	struct init_int_and_frac h_init;
	struct init_int_and_frac v_init;
};

enum ram_filter_type {
	FILTER_TYPE_RGB_Y_VERTICAL	= 0, /* 0 - RGB/Y Vertical filter */
	FILTER_TYPE_CBCR_VERTICAL	= 1, /* 1 - CbCr  Vertical filter */
	FILTER_TYPE_RGB_Y_HORIZONTAL	= 2, /* 1 - RGB/Y Horizontal filter */
	FILTER_TYPE_CBCR_HORIZONTAL	= 3, /* 3 - CbCr  Horizontal filter */
	FILTER_TYPE_ALPHA_VERTICAL	= 4, /* 4 - Alpha Vertical filter. */
	FILTER_TYPE_ALPHA_HORIZONTAL	= 5, /* 5 - Alpha Horizontal filter. */
};

struct dce_transform {
	struct transform base;
	const struct dce_transform_registers *regs;
	const struct dce_transform_shift *xfm_shift;
	const struct dce_transform_mask *xfm_mask;

	const uint16_t *filter_v;
	const uint16_t *filter_h;
	const uint16_t *filter_v_c;
	const uint16_t *filter_h_c;
	int lb_pixel_depth_supported;
	int lb_memory_size;
	int lb_bits_per_entry;
	bool prescaler_on;
};

bool dce_transform_construct(struct dce_transform *xfm110,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dce_transform_registers *regs,
	const struct dce_transform_shift *xfm_shift,
	const struct dce_transform_mask *xfm_mask);

bool dce_transform_get_optimal_number_of_taps(
	struct transform *xfm,
	struct scaler_data *scl_data,
	const struct scaling_taps *in_taps);


#endif /* _DCE_DCE_TRANSFORM_H_ */
