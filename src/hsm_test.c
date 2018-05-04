#include "app.h"

static AlesiStatus_t state__on(AlesiStateControl_t * const control, AlesiEvent_t const event_h);
static AlesiStatus_t state__pressed1(AlesiStateControl_t * const control, AlesiEvent_t const event_h);
static AlesiStatus_t state__pressed2(AlesiStateControl_t * const control, AlesiEvent_t const event_h);

static AlesiStatus_t state__pressed2(AlesiStateControl_t * const control, AlesiEvent_t const event_h)
{
    AlesiStatus_t status = ALESI_STATE_IGNORED;

    switch (event_h)
    {
        case SYSTEM_SIGNAL__HSM_INIT:
            status = ALESI_STATE_HANDLED;
        break;

        case APP_SIGNAL__PB0:
            alesi_publish_bits(alesi_h_from_key(":bsp:dout"), 0x0F, 6, ALESI_PUB_TYPE__OVERWRITE);

            alesi_print_fstr("PB0 #2\n");

            ALESI_TRANSITION_STATE(state__pressed1);
        break;

        default:
            ALESI_RETURN_SUPER(state__on);
        break;
    }

    return status;
}

static AlesiStatus_t state__pressed1(AlesiStateControl_t * const control, AlesiEvent_t const event_h)
{
    AlesiStatus_t status = ALESI_STATE_IGNORED;

    switch (event_h)
    {
        case SYSTEM_SIGNAL__HSM_INIT:
            status = ALESI_STATE_HANDLED;
        break;

        case APP_SIGNAL__PB0:
            alesi_publish_bits(alesi_h_from_key(":bsp:dout"), 0xAA, 6, ALESI_PUB_TYPE__SET);

            alesi_print_fstr("PB0 #1\n");

            ALESI_TRANSITION_STATE(state__pressed2);
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
            alesi_publish_bytes(alesi_h_from_key(":bsp:display"), buf, 2);

            alesi_print_fstr("Initial PB0\n");

            ALESI_TRANSITION_STATE(state__pressed1);
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
