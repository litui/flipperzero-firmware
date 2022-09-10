#pragma once

#include "scenes/dtmf_dolphin_scene.h"

#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/scene_manager.h>
#include <gui/modules/submenu.h>
#include <gui/modules/button_panel.h>
#include <gui/modules/variable_item_list.h>
#include <notification/notification_messages.h>
#include <input/input.h>

#include "views/dtmf_dolphin_dialer.h"
#include "views/dtmf_dolphin_bluebox.h"

#define TAG "DTMFDolphin"

#define FURI_HAL_SPEAKER_TIMER TIM16
#define FURI_HAL_SPEAKER_CHANNEL LL_TIM_CHANNEL_CH1
#define DMA_INSTANCE DMA1, LL_DMA_CHANNEL_1

typedef enum {
    DTMFDolphinEventVolumeUp = 0,
    DTMFDolphinEventVolumeDown,
    DTMFDolphinBlueboxOkCB,
    DTMFDolphinEventStartDialer,
    DTMFDolphinEventStartBluebox,
    DTMFDolphinEventStartRedbox,
} DTMFDolphinEvent;

typedef struct DTMFDolphinApp {
    size_t max_samples;
    size_t sample_count;
    uint8_t *sample_buffer;
    float volume;

    FuriMessageQueue* queue;

    ViewDispatcher* view_dispatcher;
    SceneManager* scene_manager;
    VariableItemList* main_menu_list;
    DTMFDolphinDialer* dtmf_dolphin_dialer;
    DTMFDolphinBluebox* dtmf_dolphin_bluebox;

    Gui* gui;
    // ButtonPanel* dialer_button_panel;
    // ButtonPanel* bluebox_button_panel;
    // ButtonPanel* redbox_button_panel;
    NotificationApp* notification;
} DTMFDolphinApp;

typedef enum {
    DTMFDolphinViewMainMenu,
    DTMFDolphinViewDialer,
    DTMFDolphinViewBluebox,
    DTMFDolphinViewRedbox,
} DTMFDolphinView;
