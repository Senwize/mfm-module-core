#if !defined(_TWI_H_)
#define _TWI_H_

#include <stdint.h>
#include "ev_events.h"

#define TWI_BUFFER_LENGTH 32

#ifndef TWI_CMD_COUNT
#warning "TWI_CMD_COUNT must be defined manually to use memory efficiently"
#define TWI_CMD_COUNT 2
#endif

typedef struct
{
  uint8_t cmd;
  void (*handler)(uint8_t *data, uint8_t len);
} twi_cmd_t;

extern twi_cmd_t twi_cmds[];

#ifdef __cplusplus
extern "C"
{
#endif

  void twi_init(uint8_t addr);
  void twi_ack(void);
  void twi_nack(void);
  uint8_t twi_available(void);

#ifdef __cplusplus
}
#endif

#endif // _TWI_H_