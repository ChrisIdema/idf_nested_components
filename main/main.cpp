#include "component1.h"
#include "component2.h"

extern "C" {

void app_main() {

  component1_test();
  component2_test();
  
  while(1) {
  
  }
}

}  // extern "C"

