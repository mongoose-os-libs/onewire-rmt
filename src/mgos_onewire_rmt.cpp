#include "OnewireRmt.h"
#include "mgos_onewire_rmt.h"

OnewireRmt* mgos_onewire_rmt_create(int pin,int rmt_rx,int rmt_tx)
{
    return new OnewireRmt(pin,rmt_rx,rmt_tx);
}

void mgos_onewire_rmt_close(OnewireRmt *ow)
{
    delete ow;
}

bool mgos_onewire_rmt_reset(OnewireRmt *ow)
{
    return ow->reset();
}

uint8_t mgos_onewire_rmt_crc8(const uint8_t *rom, int len)
{
    return OnewireRmt::crc8(rom, len);
}

void mgos_onewire_rmt_target_setup(OnewireRmt *ow, const uint8_t family_code)
{
    ow->target_search(family_code);
}

bool mgos_onewire_rmt_next(OnewireRmt *ow, uint8_t *rom, int mode)
{
    return ow->search(rom, mode);
}

void mgos_onewire_rmt_select(OnewireRmt *ow, const uint8_t *rom)
{
    ow->select(rom);
}

void mgos_onewire_rmt_skip(OnewireRmt *ow)
{
    ow->skip();
}

void mgos_onewire_rmt_search_clean(OnewireRmt *ow)
{
    ow->reset_search();
}

bool mgos_onewire_rmt_read_bit(OnewireRmt *ow)
{
    return ow->read_bit();
}

uint8_t mgos_onewire_rmt_read(OnewireRmt *ow)
{
    return ow->read();
}

void mgos_onewire_rmt_read_bytes(OnewireRmt *ow, uint8_t *buf, int len)
{
    ow->read_bytes(buf, len);
}

void mgos_onewire_rmt_write_bit(OnewireRmt *ow, int bit)
{
    ow->write_bit(bit);
}

void mgos_onewire_rmt_write(OnewireRmt *ow, const uint8_t data)
{
    ow->write(data);
}

void mgos_onewire_rmt_write_bytes(OnewireRmt *ow, const uint8_t *buf, int len)
{
    ow->write_bytes(buf, len);
}


