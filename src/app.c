#include "app.h"

//------------------------------------------------------------------------------
// Crossbar
//------------------------------------------------------------------------------
AlesiPointDesc_t const point_descs_din[] =
{
    {
        .signal_name = "in1",
        .signal = SIGNAL__DIN1,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 0U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in2",
        .signal = SIGNAL__DIN2,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 1U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in3",
        .signal = SIGNAL__DIN3,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 2U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in4",
        .signal = SIGNAL__DIN4,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 3U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in5",
        .signal = SIGNAL__DIN5,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 4U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in6",
        .signal = SIGNAL__DIN6,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 5U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in7",
        .signal = SIGNAL__DIN7,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 6U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "in8",
        .signal = SIGNAL__DIN8,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 7U,
        .invert = false,
        .level_trigger = false
    },
    {
        .signal_name = "pb1",
        .signal = SIGNAL__PB1,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 8U,
        .invert = false,
        .level_trigger = true
    }
};

AlesiPointDesc_t const point_descs_dout[] =
{
    {
        .signal_name = "out1",
        .signal = SIGNAL__DOUT1,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 0U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out2",
        .signal = SIGNAL__DOUT2,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 1U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out3",
        .signal = SIGNAL__DOUT3,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 2U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out4",
        .signal = SIGNAL__DOUT4,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 3U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out5",
        .signal = SIGNAL__DOUT5,
        .cmp_val = 0x1,
        .cmp_len = 1U,
        .cmp_offset = 4U,
        .invert = false,
        .level_trigger = true
    },
    {
        .signal_name = "out6",
        .signal = SIGNAL__DOUT6,
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
        .key = ":pg:auxio1",
        .point_descs = point_descs_din,
        .num_points = ALESI_COUNT_OF(point_descs_din)
    },
    {
        .key = ":bsp:dout",
        .point_descs = point_descs_dout,
        .num_points = ALESI_COUNT_OF(point_descs_dout)
    }
};

size_t const app_crossbar_descs_cnt = ALESI_COUNT_OF(app_crossbar_descs);

//------------------------------------------------------------------------------
// Bridge
//------------------------------------------------------------------------------

void translator__din_to_auxio(uint8_t * const dst, uint8_t const * const src)
{
    if ((dst != NULL) && (src != NULL))
    {
        memcpy(dst, src, 8U);
    }
}

void translator__auxio_to_dout(uint8_t * const dst, uint8_t const * const src)
{
    if ((dst != NULL) && (src != NULL))
    {
        memcpy(dst, src, 8U);
    }
}

AlesiBridgeDesc_t const app_bridge_descs[] =
{
    {
        .src_key = ALESI_BSP_KEY "din",
        .dst_key = ALESI_PG_KEY "auxio1",
        .mode = ALESI_BRIDGE_MODE__TRANSLATE,
        .translator = translator__din_to_auxio
    },
    {
        .src_key = ALESI_PG_KEY "auxio2",
        .dst_key = ALESI_BSP_KEY "dout",
        .mode = ALESI_BRIDGE_MODE__TRANSLATE,
        .translator = translator__auxio_to_dout
    }
};

size_t const app_bridge_descs_cnt = ALESI_COUNT_OF(app_bridge_descs);

//------------------------------------------------------------------------------
// J1939
//------------------------------------------------------------------------------
AlesiJ1939Desc_t const app_j1939_descs[] =
{
    {
        .pg_key = "auxio1",
        .pgn = 65241U,
        .size = 8U,
        .rate = 100U
    },
    {
        .pg_key = "auxio2",
        .pgn = 65242U,
        .size = 8U,
        .rate = 100U
    }
};

size_t const app_j1939_descs_cnt = ALESI_COUNT_OF(app_j1939_descs);
