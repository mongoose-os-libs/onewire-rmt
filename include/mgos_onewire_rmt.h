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

/*
 * Create a OnewireRmt object instance. Return value: an object with the methods
 * described below.
 */
OnewireRmt* mgos_onewire_rmt_create(int pin, int rmt_rx, int rmt_tx);

/*
 * Destroy an `ow` instance.
 */
void mgos_onewire_rmt_close(OnewireRmt *ow);

/*
 * Performs a 1-Wire reset cycle. Returns 1 if a device responds
 * with a presence pulse.  Returns 0 if there is no device or the
 * bus is shorted or otherwise held low for more than 250uS
 */
bool mgos_onewire_rmt_reset(OnewireRmt *ow);

/*
 * Computes a Dallas Semiconductor 8 bit CRC, these are used in the
 * ROM and scratchpad registers.
 */
uint8_t mgos_onewire_rmt_crc8(const uint8_t *rom, int len);

/*
 * Setup the search to find the device type 'family_code' (family code) on the next call
 * to `mgos_onewire_rmt_next()` if it is present.
 *
 * If no devices of the desired family are currently on the bus, then
 * device of some another type will be found by `search()`.
 */
void mgos_onewire_rmt_target_setup(OnewireRmt *ow, const uint8_t family_code);

/*
 * Looks for the next device.
 * Returns 1 if a new address has been returned in the provided 8-byte array `buf`.
 * A zero might mean that the bus is shorted, there are no devices,
 * or you have already retrieved all of them.
 * It might be a good idea to check the CRC to make sure you didn't get garbage.
 * The order is deterministic. You will always get the same devices in the same order.
 * Parameter mode is not used.
 */
bool mgos_onewire_rmt_next(OnewireRmt *ow, uint8_t *rom, int mode);

/*
 * Select a device based on its address `rom`, which is a 8-byte array.
 * After a reset, this is needed to choose which device you will use, and then
 * all communication will be with that device, until another reset.
 */
void mgos_onewire_rmt_select(OnewireRmt *ow, const uint8_t *rom);

/*
 * Issues a 1-Wire rom skip command, to address all on bus.
 */
void mgos_onewire_rmt_skip(OnewireRmt *ow);

/*
 * Reset a search. Next use of `mgos_onewire_rmt_next(....)` will begin
 * at the first device.
 */
void mgos_onewire_rmt_search_clean(OnewireRmt *ow);

/*
 * Reads a single bit from the onewire bus.
 * The returned value is either 0 or 1.
 */
bool mgos_onewire_rmt_read_bit(OnewireRmt *ow);

/*
 * Reads a byte from the onewire bus.
 */
uint8_t mgos_onewire_rmt_read(OnewireRmt *ow);

/*
 * Reads multiple bytes from the onewire bus and write them to `buf`. The given
 * buffer should be at least `len` bytes long.
 */
void mgos_onewire_rmt_read_bytes(OnewireRmt *ow, uint8_t *buf, int len);

/*
 * Writes a single bit to the onewire bus. Given `bit` should be either 0 or 1.
 */
void mgos_onewire_rmt_write_bit(OnewireRmt *ow, int bit);

/*
 * Writes a byte to the onewire bus.
 */
void mgos_onewire_rmt_write(OnewireRmt *ow, const uint8_t data);

/*
 * Writes `len` bytes from the buffer `buf`.
 */
void mgos_onewire_rmt_write_bytes(OnewireRmt *ow, const uint8_t *buf, int len);

#ifdef __cplusplus
}
#endif
