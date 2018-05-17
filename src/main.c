#include "app.h"

int main(void)
{
    ALESI_ENSURE_OK(alesi_config_crossbar(app_crossbar_descs, app_crossbar_descs_cnt));

    ALESI_ENSURE_OK(alesi_config_bridge(app_bridge_descs, app_bridge_descs_cnt));

    ALESI_ENSURE_OK(alesi_config_j1939(app_j1939_descs, app_j1939_descs_cnt));

    ALESI_ENSURE_OK(alesi_init());

    ALESI_ENSURE_OK(alesi_new_hsm("hsm_test", hsm_test_init, 5U, 0U));

    alesi_start();

    /* Will only get here if Alesi fails to start */
    while(1);

    return 0;
}
