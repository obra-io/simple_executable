#ifndef __APP_H
#define __APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <alesi.h>
#include <alesi_action.h>

enum app_signals
{
    APP_SIGNAL__NONE = ALESI_APP_SIGNAL_START,

    APP_SIGNAL__DIN1,
    APP_SIGNAL__DIN2,
    APP_SIGNAL__DIN3,
    APP_SIGNAL__DIN4,
    APP_SIGNAL__DIN5,
    APP_SIGNAL__DIN6,
    APP_SIGNAL__DIN7,
    APP_SIGNAL__DIN8,
    APP_SIGNAL__PB0,
    APP_SIGNAL__DOUT1,
    APP_SIGNAL__DOUT2,
    APP_SIGNAL__DOUT3,
    APP_SIGNAL__DOUT4,
    APP_SIGNAL__DOUT5,
    APP_SIGNAL__DOUT6,

    NUM_APP_SIGNAL
};

AlesiStateHandler_t hsm_test_init(void);

extern AlesiCrossbarDesc_t const app_crossbar_descs[];
extern size_t const app_crossbar_descs_cnt;

#ifdef __cplusplus
}
#endif

#endif /* __APP_H */
