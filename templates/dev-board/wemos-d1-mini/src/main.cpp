#include <AppKit.h>
#include <Uniot.h>

#define PIN_LED 2

using namespace uniot;

void setup() {
  Uniot.begin();

  auto &MainAppKit = AppKit::getInstance();

  MainAppKit.configureNetworkController({.pinLed = PIN_LED, .maxRebootCount = 255});

  PrimitiveExpeditor::getRegisterManager().setDigitalOutput(PIN_LED);

  Uniot.getEventBus().registerKit(MainAppKit);
  Uniot.getScheduler().push(MainAppKit);

  MainAppKit.attach();
}

void loop() {
  Uniot.loop();
}
