#ifndef __APP_H
#define __APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <alesi.h>
#include <alesi_action.h>

enum signal
{
    SIGNAL__NONE = ALESI_APP_SIGNAL_START,
    SIGNAL__DIN1,
    SIGNAL__DIN2,
    SIGNAL__DIN3,
    SIGNAL__DIN4,
    SIGNAL__DIN5,
    SIGNAL__DIN6,
    SIGNAL__DIN7,
    SIGNAL__DIN8,
    SIGNAL__PB0,
    SIGNAL__DOUT1,
    SIGNAL__DOUT2,
    SIGNAL__DOUT3,
    SIGNAL__DOUT4,
    SIGNAL__DOUT5,
    SIGNAL__DOUT6,

    NUM_SIGNAL
};

AlesiStateHandler_t hsm_test_init(void);

extern AlesiCrossbarDesc_t const app_crossbar_descs[];
extern size_t const app_crossbar_descs_cnt;

#ifdef __cplusplus
}
#endif

#endif /* __APP_H */
