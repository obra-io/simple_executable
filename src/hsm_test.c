#include "app.h"

ALESI_DECLARE_STATE(on);
ALESI_DECLARE_STATE(held);

static uint16_t pb_cnt;
static AlesiHandle_t pb_cnt_h;

AlesiStateHandler_t hsm_test_init(AlesiStateControl_t * const me,
        uint8_t const id)
{
    ALESI_ENSURE_SIGNAL(alesi_subscribe_key(ALESI_SIG_KEY "pb1"));;
    ALESI_ENSURE_SIGNAL(alesi_subscribe_key(ALESI_SIG_KEY "in1"));

    pb_cnt_h = alesi_new_topic(ALESI_APP_KEY "pb_cnt", sizeof(pb_cnt), ALESI_NO_SIGNAL);

    ALESI_ENSURE_H(pb_cnt_h);

    return state__on;
};

static AlesiStatus_t state__on(AlesiStateControl_t * const control,
        AlesiEvent_t const event_h)
{
    AlesiStatus_t status = ALESI_STATE_IGNORED;

    switch (event_h)
    {
        case SIGNAL__PB1:
            pb_cnt++;

            alesi_printf("PB1 Down %d\n", pb_cnt);

            alesi_publish_bytes(pb_cnt_h, (uint8_t *) &pb_cnt, sizeof(pb_cnt));

            ALESI_TRANSITION_STATE(state__held);
        break;

        case SIGNAL__DIN1:
            alesi_printf("DIN1 Active\n");

            status = ALESI_STATE_HANDLED;
        break;

        default:
            /* root state */
        break;
    }

    return status;
}

static AlesiStatus_t state__held(AlesiStateControl_t * const control,
        AlesiEvent_t const event_h)
{
    AlesiStatus_t status = ALESI_STATE_IGNORED;

    switch (event_h)
    {
        case SIGNAL__PB1:
            alesi_printf("PB1 Up\n");

            ALESI_TRANSITION_STATE(state__on);
        break;

        default:
            ALESI_SUPER_STATE(state__on);
        break;
    }

    return status;
};
