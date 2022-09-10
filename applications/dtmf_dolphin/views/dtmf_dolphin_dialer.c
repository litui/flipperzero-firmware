#include "dtmf_dolphin_dialer.h"

#include <gui/elements.h>

typedef struct DTMFDolphinDialer {
    View* view;
    DTMFDolphinDialerOkCallback callback;
    void* context;
} DTMFDolphinDialer;

typedef struct {
    uint8_t index;
} DTMFDolphinDialerModel;

static bool dtmf_dolphin_dialer_process_left(DTMFDolphinDialer* dtmf_dolphin_dialer);
static bool dtmf_dolphin_dialer_process_right(DTMFDolphinDialer* dtmf_dolphin_dialer);
static bool dtmf_dolphin_dialer_process_ok(DTMFDolphinDialer* dtmf_dolphin_dialer, InputEvent* event);

static void dtmf_dolphin_dialer_draw_callback(Canvas* canvas, void* _model) {
    DTMFDolphinDialerModel* model = _model;
    UNUSED(model);
    canvas_set_font(canvas, FontPrimary);
    elements_multiline_text(canvas, 2, 10, "Dialer");
    elements_multiline_text(canvas, 78, 10, "Detail");
    canvas_draw_line(canvas, 76, 0, 76, 64);
    // elements_multiline_text_aligned(canvas, 64, 2, AlignCenter, AlignTop, "Dialer Mode");
    canvas_set_font(canvas, FontSecondary);

    // canvas_draw_frame(canvas, 38, 12, 52, 52);
    // canvas_draw_circle(canvas, 45, 18, 5);
    canvas_draw_rframe(canvas, 2, 13, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 7, 19, AlignCenter, AlignCenter, "1");
    canvas_draw_rframe(canvas, 15, 13, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 20, 19, AlignCenter, AlignCenter, "2");
    canvas_draw_rframe(canvas, 28, 13, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 33, 19, AlignCenter, AlignCenter, "3");
    canvas_draw_rframe(canvas, 41, 13, 33, 11, 2);
    canvas_draw_str_aligned(canvas, 57, 19, AlignCenter, AlignCenter, "A");

    canvas_draw_rframe(canvas, 2, 26, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 7, 32, AlignCenter, AlignCenter, "4");
    canvas_draw_rframe(canvas, 15, 26, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 20, 32, AlignCenter, AlignCenter, "5");
    canvas_draw_rframe(canvas, 28, 26, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 33, 32, AlignCenter, AlignCenter, "6");
    canvas_draw_rframe(canvas, 41, 26, 33, 11, 2);
    canvas_draw_str_aligned(canvas, 57, 32, AlignCenter, AlignCenter, "B");

    canvas_draw_rframe(canvas, 2, 39, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 7, 45, AlignCenter, AlignCenter, "7");
    canvas_draw_rframe(canvas, 15, 39, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 20, 45, AlignCenter, AlignCenter, "8");
    canvas_draw_rframe(canvas, 28, 39, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 33, 45, AlignCenter, AlignCenter, "9");
    canvas_draw_rframe(canvas, 41, 39, 33, 11, 2);
    canvas_draw_str_aligned(canvas, 57, 45, AlignCenter, AlignCenter, "C");

    canvas_draw_rframe(canvas, 2, 52, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 7, 58, AlignCenter, AlignCenter, "*");
    canvas_draw_rframe(canvas, 15, 52, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 20, 58, AlignCenter, AlignCenter, "0");
    canvas_draw_rframe(canvas, 28, 52, 11, 11, 2);
    canvas_draw_str_aligned(canvas, 33, 58, AlignCenter, AlignCenter, "#");
    canvas_draw_rframe(canvas, 41, 52, 33, 11, 2);
    canvas_draw_str_aligned(canvas, 57, 58, AlignCenter, AlignCenter, "D");

    // elements_multiline_text_aligned(
    //     canvas, 64, 16, AlignCenter, AlignTop, "Press < or > to select");
    // elements_multiline_text_aligned(
    //     canvas, 64, 32, AlignCenter, AlignTop, dtmf_dolphin_get_tone_name(model->index, DTMF_DOLPHIN_TONE_BLOCK_BLUEBOX));
}

static bool dtmf_dolphin_dialer_input_callback(InputEvent* event, void* context) {
    furi_assert(context);
    DTMFDolphinDialer* dtmf_dolphin_dialer = context;
    bool consumed = false;

    if(event->type == InputTypeShort) {
        if(event->key == InputKeyRight) {
            consumed = dtmf_dolphin_dialer_process_right(dtmf_dolphin_dialer);
        } else if(event->key == InputKeyLeft) {
            consumed = dtmf_dolphin_dialer_process_left(dtmf_dolphin_dialer);
        }
    } else if(event->key == InputKeyOk) {
        consumed = dtmf_dolphin_dialer_process_ok(dtmf_dolphin_dialer, event);
    }

    return consumed;
}

static bool dtmf_dolphin_dialer_process_left(DTMFDolphinDialer* dtmf_dolphin_dialer) {
    with_view_model(
        dtmf_dolphin_dialer->view, (DTMFDolphinDialerModel * model) {
            if(model->index) {
                model->index--;
            }
            return true;
        });
    return true;
}

static bool dtmf_dolphin_dialer_process_right(DTMFDolphinDialer* dtmf_dolphin_dialer) {
    with_view_model(
        dtmf_dolphin_dialer->view, (DTMFDolphinDialerModel * model) {
            if(model->index < DTMF_DOLPHIN_BLUEBOX_TONE_COUNT) {
                model->index++;
            }
            return true;
        });
    return true;
}

static bool dtmf_dolphin_dialer_process_ok(DTMFDolphinDialer* dtmf_dolphin_dialer, InputEvent* event) {
    bool consumed = false;

    with_view_model(
        dtmf_dolphin_dialer->view, (DTMFDolphinDialerModel* model) {
            if(event->type == InputTypePress) {
                if(model->index < DTMF_DOLPHIN_BLUEBOX_TONE_COUNT) {
                    // TODO: Do the thing
                } else {
                    // TODO: Do the thing
                }
                consumed = true;
            } else if(event->type == InputTypeRelease) {
                if(model->index < DTMF_DOLPHIN_BLUEBOX_TONE_COUNT) {
                    // gpio_item_set_pin(Model->pin_idx, false);
                } else {
                    // gpio_item_set_all_pins(false);
                }
                consumed = true;
            }
            dtmf_dolphin_dialer->callback(event->type, dtmf_dolphin_dialer->context);
            return true;
        });

    return consumed;
}

DTMFDolphinDialer* dtmf_dolphin_dialer_alloc() {
    DTMFDolphinDialer* dtmf_dolphin_dialer = malloc(sizeof(DTMFDolphinDialer));

    dtmf_dolphin_dialer->view = view_alloc();
    view_allocate_model(dtmf_dolphin_dialer->view, ViewModelTypeLocking, sizeof(DTMFDolphinDialerModel));
    view_set_context(dtmf_dolphin_dialer->view, dtmf_dolphin_dialer);
    view_set_draw_callback(dtmf_dolphin_dialer->view, dtmf_dolphin_dialer_draw_callback);
    view_set_input_callback(dtmf_dolphin_dialer->view, dtmf_dolphin_dialer_input_callback);

    return dtmf_dolphin_dialer;
}

void dtmf_dolphin_dialer_free(DTMFDolphinDialer* dtmf_dolphin_dialer) {
    furi_assert(dtmf_dolphin_dialer);
    view_free(dtmf_dolphin_dialer->view);
    free(dtmf_dolphin_dialer);
}

View* dtmf_dolphin_dialer_get_view(DTMFDolphinDialer* dtmf_dolphin_dialer) {
    furi_assert(dtmf_dolphin_dialer);
    return dtmf_dolphin_dialer->view;
}

void dtmf_dolphin_dialer_set_ok_callback(DTMFDolphinDialer* dtmf_dolphin_dialer, DTMFDolphinDialerOkCallback callback, void* context) {
    furi_assert(dtmf_dolphin_dialer);
    furi_assert(callback);
    with_view_model(
        dtmf_dolphin_dialer->view, (DTMFDolphinDialerModel * model) {
            UNUSED(model);
            dtmf_dolphin_dialer->callback = callback;
            dtmf_dolphin_dialer->context = context;
            return false;
        });
}
