#include <lcm/lcm-cpp.hpp>
#include "example/example_t.hpp"

int init()
{
  // Initialize LCM
  lcm::LCM lcm;

  if (!lcm.good())
    return 1;

  // Construct example message
  example::example_t example_msg;

  example_msg.timestamp = time(NULL);
  example_msg.position[0] = 1;
  example_msg.position[1] = 2;
  example_msg.position[2] = 3;
  example_msg.orientation[0] = 1;
  example_msg.orientation[1] = 0;
  example_msg.orientation[2] = 0;
  example_msg.orientation[3] = 0;
  example_msg.num_ranges = 15;
  example_msg.ranges.resize((unsigned long) example_msg.num_ranges);

  for (int i = 0; i < example_msg.num_ranges; i++) {
    example_msg.ranges[i] = (short) i;
  }

  example_msg.name = "Sample message";
  example_msg.enabled = true;

  // Publish message
  lcm.publish("EXAMPLE_MESSAGES", &example_msg);

  return 0;
}
