#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stm32wbxx_ll_tim.h>
#include <stm32wbxx_ll_dma.h>

#define FURI_HAL_SPEAKER_TIMER TIM16
#define FURI_HAL_SPEAKER_CHANNEL LL_TIM_CHANNEL_CH1
#define DMA_INSTANCE DMA1, LL_DMA_CHANNEL_1

#ifdef __cplusplus
extern "C" {
#endif

void dtmf_dolphin_speaker_init();

void dtmf_dolphin_speaker_start();

void dtmf_dolphin_speaker_stop();

void dtmf_dolphin_dma_init(uint32_t address, size_t size);

void dtmf_dolphin_dma_start();

void dtmf_dolphin_dma_stop();

#ifdef __cplusplus
}
#endif