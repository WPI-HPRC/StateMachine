#pragma once

template <typename SensorData> struct Ctx {
  SensorData sensorData;
};

#define USE_SENSOR_DATA(SensorData)                                            \
  using State = BaseState<SensorData>;                                         \
  using Transition = BaseTransition<SensorData>;                               \
  using Context = Ctx<SensorData>;                                             \
  using DebouncerCommand = BaseDebouncerCommand<SensorData>;
