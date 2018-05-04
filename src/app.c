#include "app.h"

AlesiCrossbarPoint_t const crossbar_points_din[] =
{
    {
        .signal_name = "in1",
        .signal = APP_SIGNAL__DIN1,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 0U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in2",
        .signal = APP_SIGNAL__DIN2,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 1U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in3",
        .signal = APP_SIGNAL__DIN3,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 2U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in4",
        .signal = APP_SIGNAL__DIN4,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 3U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in5",
        .signal = APP_SIGNAL__DIN5,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 4U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in6",
        .signal = APP_SIGNAL__DIN6,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 5U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in7",
        .signal = APP_SIGNAL__DIN7,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 6U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in8",
        .signal = APP_SIGNAL__DIN8,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 7U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "pb0",
        .signal = APP_SIGNAL__PB0,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 8U,
        .invert = false,
        .level_trigger = false
    }

};

AlesiCrossbarPoint_t const crossbar_points_dout[] =
{
    {
        .signal_name = "out1",
        .signal = APP_SIGNAL__DOUT1,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 0U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out2",
        .signal = APP_SIGNAL__DOUT2,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 1U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out3",
        .signal = APP_SIGNAL__DOUT3,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 2U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out4",
        .signal = APP_SIGNAL__DOUT4,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 3U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out5",
        .signal = APP_SIGNAL__DOUT5,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 4U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out6",
        .signal = APP_SIGNAL__DOUT6,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 5U,
        .invert = false,
        .level_trigger = true
    }
};

AlesiCrossbarDesc_t const app_crossbar_descs[] =
{
    {
        .key = ":bsp:din",
        .points = crossbar_points_din,
        .num_points = ALESI_COUNT_OF(crossbar_points_din)
    },
    {
        .key = ":bsp:dout",
        .points = crossbar_points_dout,
        .num_points = ALESI_COUNT_OF(crossbar_points_dout)
    }
};

size_t const app_crossbar_descs_cnt = ALESI_COUNT_OF(app_crossbar_descs);
