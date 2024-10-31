// Library

class Context {
public:
  long virtual millis() = 0;
};

class State {
public:
  State(Context *ctx) : ctx(ctx) {}
  
  State *loop() {
    long currentTime = ctx->millis();
    return nullptr;
  }
protected:
  Context *ctx;
};

// Specific repo

#include <Arduino.h>

struct RocketContext : public Context {
  Sensors sensors;
  Servo servo;

  long millis() override {
    return ::millis();
  }
};

struct RTOSContext : public Context {
  long millis() override {
    // something something gettimeofday
  }
}


class PreLaunch : public State<RocketContext> {
  State<RocketContext> *loop() {
    ctx->sensors;
  }
};
