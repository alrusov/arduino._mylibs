#if !defined _MYLIBS
#define _MYLIBS

#if defined DEBUG

#define debugPort Serial
#define DEBUG_PORT_BAUDRATE 115200

#include <stdarg.h>

void debugInit() {
  debugPort.begin(DEBUG_PORT_BAUDRATE);
  while(!debugPort);
}

void debugPrintf(char *format, ...) {
  char buf[80];
  va_list ap;
  va_start(ap, format);
  vsnprintf(buf, sizeof(buf), format, ap);
  va_end(ap);

  debugPort.print(buf);
}

#else

#define debugInit() ;
#define debugPrintf(...) ;

#endif

//-----------------------------------------------------------------------------------------------------------------------------------------//

typedef uint8_t byte_t;

//-----------------------------------------------------------------------------------------------------------------------------------------//

#define turnOver16(a) (uint16_t(a[1]) | uint16_t(a[0]) << 8)
#define turnOver24(a) (uint32_t(a[2]) | uint32_t(a[1]) << 8 | uint32_t(a[0]) << 16)
#define turnOver32(a) (uint32_t(a[3]) | uint32_t(a[2]) << 8 | uint32_t(a[1]) << 16 | uint32_t(a[0]) << 24)

uint16_t swap16(uint16_t v) {
  return (v << 8) | (v >> 8);
}

//-----------------------------------------------------------------------------------------------------------------------------------------//

#endif
