#include PLATFORM_HEADER
#include "app_process.h"
#include "stack/include/ember.h"
#include "hal/hal.h"
#include "em_chip.h"
#include "app_log.h"
#include "sl_app_common.h"
#include "app_framework_common.h"
#include "sl_simple_led_instances.h"
#include "app_process.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_eusart.h"

#define IPC_RX_MAX_SIZE  30
#define IPC_TX_MAX_SIZE  255

extern volatile uint8_t ipcRxBuffer[IPC_RX_MAX_SIZE];
extern volatile uint8_t ipcTxBuffer[IPC_TX_MAX_SIZE];

extern volatile uint32_t ipcRxPos;
extern volatile uint32_t ipcTxLen;
extern volatile bool ipcDataReady;

typedef enum {     /* IPC message identification byte */
  IPC_CHANGE,          // (C -> EXT) notify change of information
  IPC_LIST,            // (C -> EXT) send list of connected sensors and associated information
  IPC_REQUEST,         // (C <- EXT) request sensor change state
  IPC_ACK,             // (C <->EXT) response to IPC_CHANGE; request IPC_LIST
  IPC_ERR,
} ipc_message_pid_t;
void startIPC(void);
void ipcReplyHandler(void);
bool ipcRequestHandler(EmberNodeId id, sensor_state_t state);
void ipcInitThread(void);
void ipcRtosTask(void *p_arg);
