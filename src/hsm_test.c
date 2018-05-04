#include "app.h"

static AlesiStatus_t state__on(AlesiStateControl_t * const control, AlesiEvent_t const event_h);
static AlesiStatus_t state__pressed(AlesiStateControl_t * const control, AlesiEvent_t const event_h);

static AlesiStatus_t state__pressed(AlesiStateControl_t * const control, AlesiEvent_t const event_h)
{
    AlesiStatus_t status = ALESI_STATE_IGNORED;
    uint8_t out[1] = {0xAA};

    switch (event_h)
    {
        case SYSTEM_SIGNAL__HSM_INIT:
            status = ALESI_STATE_HANDLED;
        break;

        case APP_SIGNAL__PB0:
            alesi_publish_bits(alesi_h_from_key(":bsp:dout"), out, 6, true);

            ALESI_TRANSITION_STATE(state__on);
        break;

        default:
            ALESI_RETURN_SUPER(state__on);
        break;
    }

    return status;
}

static AlesiStatus_t state__on(AlesiStateControl_t * const control, AlesiEvent_t const event_h)
{
    AlesiStatus_t status = ALESI_STATE_IGNORED;
    static uint16_t jj;
    static uint16_t ii;
    static uint8_t buf[2] = {'0', '9'};
    uint8_t out[1] = {0xAA};

    switch (event_h)
    {
        case SYSTEM_SIGNAL__HSM_INIT:
            status = ALESI_STATE_HANDLED;
        break;

        case SYSTEM_SIGNAL__TICK_10MS:
            jj++;

            status = ALESI_STATE_HANDLED;
        break;

        case SYSTEM_SIGNAL__TICK_100MS:
            ii++;

            status = ALESI_STATE_HANDLED;
        break;

        case APP_SIGNAL__PB0:
            if (++buf[0] > '9')
            {
                buf[0] = '0';
            }

            if (--buf[1] < '0')
            {
                buf[1] = '9';
            }

            alesi_publish_bytes(alesi_h_from_key(":bsp:display"), buf, 2);

            alesi_publish_bits(alesi_h_from_key(":bsp:dout"), out, 6, false);

            ALESI_TRANSITION_STATE(state__pressed);
        break;
    }

    return status;
}

AlesiStateHandler_t hsm_test_init(void)
{
    alesi_subscribe(":signal:tick10");
    alesi_subscribe(":signal:tick100");
    alesi_subscribe(":signal:pb0");

    return state__on;
}
