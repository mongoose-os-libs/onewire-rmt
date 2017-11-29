#pragma once
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
#include "OnewireRmt.h"
#else
typedef struct OnewireRmtTag OnewireRmt;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    OnewireRmt* mgos_onewire_rmt_create(int pin,int rmt_rx,int rmt_tx);
    void mgos_onewire_rmt_close(OnewireRmt *ow);

    bool mgos_onewire_rmt_reset(OnewireRmt *ow);
    uint8_t mgos_onewire_rmt_crc8(const uint8_t *rom, int len);
    void mgos_onewire_rmt_target_setup(OnewireRmt *ow, const uint8_t family_code);

    bool mgos_onewire_rmt_next(OnewireRmt *ow, uint8_t *rom, int mode);
    void mgos_onewire_rmt_select(OnewireRmt *ow, const uint8_t *rom);
    void mgos_onewire_rmt_skip(OnewireRmt *ow);
    void mgos_onewire_rmt_search_clean(OnewireRmt *ow);

    bool mgos_onewire_rmt_read_bit(OnewireRmt *ow);
    uint8_t mgos_onewire_rmt_read(OnewireRmt *ow);
    void mgos_onewire_rmt_read_bytes(OnewireRmt *ow, uint8_t *buf, int len);

    void mgos_onewire_rmt_write_bit(OnewireRmt *ow, int bit);
    void mgos_onewire_rmt_write(OnewireRmt *ow, const uint8_t data);
    void mgos_onewire_rmt_write_bytes(OnewireRmt *ow, const uint8_t *buf, int len);

#ifdef __cplusplus
}
#endif
