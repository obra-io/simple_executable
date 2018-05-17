#include "app.h"

int main(void)
{
    AlesiStatus_t status;

    status = alesi_config_crossbar(app_crossbar_descs,
            app_crossbar_descs_cnt);

    if (status == ALESI_OK)
    {
        status = alesi_config_bridge(app_bridge_descs, app_bridge_descs_cnt);
    }

    if (status == ALESI_OK)
    {
        status = alesi_config_j1939(app_j1939_descs, app_j1939_descs_cnt);
    }

    if (status == ALESI_OK)
    {
        status = alesi_init();
    }

    if (status == ALESI_OK)
    {
        status = alesi_new_hsm("hsm_test", hsm_test_init, 5U, 0U);
    }

    if (status == ALESI_OK)
    {
       alesi_start();
    }

    /* Will only get here if Alesi fails to start */
    while(1);

    return 0;
}
