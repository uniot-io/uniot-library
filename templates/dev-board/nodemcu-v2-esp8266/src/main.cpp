#include <AppKit.h>
#include <Uniot.h>

#define PIN_LED 2
#define PIN_BUTTON 0

#define LED_PIN_LEVEL LOW

using namespace uniot;

void setup() {
  Uniot.begin();

  auto &MainAppKit = AppKit::getInstance();

  MainAppKit.configureNetworkController({
    .pinBtn = PIN_BUTTON,
    .pinLed = PIN_LED,
    .activeLevelLed = LED_PIN_LEVEL,
    .maxRebootCount = 255
  });

  PrimitiveExpeditor::getRegisterManager().setDigitalOutput(PIN_LED);

  Uniot.getEventBus().registerKit(MainAppKit);
  Uniot.getScheduler().push(MainAppKit);

  MainAppKit.attach();
}

void loop() {
  Uniot.loop();
}
