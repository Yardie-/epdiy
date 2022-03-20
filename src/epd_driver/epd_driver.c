#include "epd_driver.h"
#include "epd_temperature.h"
#include "esp_assert.h"
#include "esp_heap_caps.h"
#include "esp_log.h"
#include "esp_types.h"
void epd_clear() {
    epd_clear_area(epd_full_screen());
}

enum EpdDrawError epd_draw_image(EpdRect area, const uint8_t *data, const EpdWaveform *waveform) {
    int temperature = epd_ambient_temperature();
	assert(waveform != NULL);
    EpdRect no_crop = {
        .x = 0,
        .y = 0,
        .width = 0,
        .height = 0,
    };
    return epd_draw_base(area, data, no_crop, EPD_MODE_DEFAULT, temperature, NULL, waveform);
}
