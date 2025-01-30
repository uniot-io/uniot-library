#include <AppKit.h>
#include <Uniot.h>

#define PIN_LDR A0
#define PIN_RED D8
#define PIN_GREEN D6
#define PIN_BLUE D7
#define PIN_BUTTON D2

#define BTN_PIN_LEVEL LOW
#define LED_PIN_LEVEL HIGH

using namespace uniot;

void setup() {
  Uniot.begin();

  auto &MainAppKit = AppKit::getInstance();

  MainAppKit.configureNetworkController({
    .pinBtn = PIN_BUTTON,
    .activeLevelBtn = BTN_PIN_LEVEL,
    .pinLed = PIN_RED,
    .activeLevelLed = LED_PIN_LEVEL,
    .maxRebootCount = 255
  });

  PrimitiveExpeditor::getRegisterManager().setDigitalOutput(PIN_RED, PIN_GREEN, PIN_BLUE);
  PrimitiveExpeditor::getRegisterManager().setDigitalInput(PIN_RED, PIN_GREEN, PIN_BLUE);
  PrimitiveExpeditor::getRegisterManager().setAnalogOutput(PIN_RED, PIN_GREEN, PIN_BLUE);
  PrimitiveExpeditor::getRegisterManager().setAnalogInput(PIN_LDR);

  Uniot.getEventBus().registerKit(MainAppKit);
  Uniot.getScheduler().push(MainAppKit);

  MainAppKit.attach();
}

void loop() {
  Uniot.loop();
}
