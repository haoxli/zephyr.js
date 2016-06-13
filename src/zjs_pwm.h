// Copyright (c) 2016, Intel Corporation.

#include "jerry-api.h"

jerry_object_t *zjs_pwm_init();

bool zjs_pwm_open(const jerry_object_t *function_obj_p,
                  const jerry_value_t *this_p,
                  jerry_value_t *ret_val_p,
                  const jerry_value_t args_p[],
                  const jerry_length_t args_cnt);

bool zjs_pwm_pin_set_period(const jerry_object_t *function_obj_p,
                            const jerry_value_t *this_p,
                            jerry_value_t *ret_val_p,
                            const jerry_value_t args_p[],
                            const jerry_length_t args_cnt);

bool zjs_pwm_pin_set_period_us(const jerry_object_t *function_obj_p,
                               const jerry_value_t *this_p,
                               jerry_value_t *ret_val_p,
                               const jerry_value_t args_p[],
                               const jerry_length_t args_cnt);

bool zjs_pwm_pin_set_pulse_width(const jerry_object_t *function_obj_p,
                                const jerry_value_t *this_p,
                                jerry_value_t *ret_val_p,
                                const jerry_value_t args_p[],
                                const jerry_length_t args_cnt);

bool zjs_pwm_pin_set_pulse_width_us(const jerry_object_t *function_obj_p,
                                    const jerry_value_t *this_p,
                                    jerry_value_t *ret_val_p,
                                    const jerry_value_t args_p[],
                                    const jerry_length_t args_cnt);