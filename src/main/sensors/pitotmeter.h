/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

typedef enum {
    PITOT_DEFAULT = 0,
    PITOT_NONE = 1,
    PITOT_MS4525 = 2,
    PITOT_FAKE = 3,
} pitotSensor_e;

#define PITOT_MAX  PITOT_FAKE
#define PITOT_SAMPLE_COUNT_MAX   48

typedef struct pitotmeterConfig_s {
    uint8_t use_median_filtering;            // Use 3-point median filtering
    float pitot_noise_lpf;                   // additional LPF to reduce pitot noise
    float pitot_scale;                       // scale value
} pitotmeterConfig_t;

extern int32_t AirSpeed;

#ifdef PITOT
void usePitotmeterConfig(pitotmeterConfig_t *pitotmeterConfigToUse);
bool isPitotCalibrationComplete(void);
void pitotSetCalibrationCycles(uint16_t calibrationCyclesRequired);
uint32_t pitotUpdate(void);
bool isPitotReady(void);
int32_t pitotCalculateAirSpeed(void);
#endif
