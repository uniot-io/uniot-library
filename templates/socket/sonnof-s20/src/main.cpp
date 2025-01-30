#include <AppKit.h>
#include <Uniot.h>

#define PIN_LED 13
#define PIN_RELAY 12
#define PIN_BUTTON 0

using namespace uniot;

void setup() {
  Uniot.begin();

  auto &MainAppKit = AppKit::getInstance();

  MainAppKit.configureNetworkController({.pinBtn = PIN_BUTTON, .pinLed = PIN_LED, .maxRebootCount = 255});

  PrimitiveExpeditor::getRegisterManager().setDigitalOutput(PIN_RELAY, PIN_LED);

  Uniot.getEventBus().registerKit(MainAppKit);
  Uniot.getScheduler().push(MainAppKit);

  MainAppKit.attach();
}

void loop() {
  Uniot.loop();
}
