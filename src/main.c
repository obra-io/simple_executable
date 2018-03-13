#include <alesi.h>

int main(void)
{
    AlesiStatus_t status;

    status = alesi_init();

    if (status == ALESI_OK)
    {
       alesi_start();
    }

    /* Will only get here if Alesi fails to start */
    while(1);

    return 0;
}
