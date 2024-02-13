#include "types.h"
#include "defs.h"
#include "x86.h"
#include "fs.h"
#include "buf.h"
#include "param.h"

extern char end[]; // first address after kernel loaded from ELF file

static inline void
welcome(void) {
  struct buf *b1 = bread(1, 0);
  cprintf("After preparing fs.img, we have rebooted %d times\n", b1->data[0]);
  b1->data[0] = b1->data[0] + 1;
  bwrite(b1);
}

// Bootstrap processor starts running C code here.
// Allocate a real stack and switch to it, first
// doing some setup required for memory allocator to work.
int
main(void)
{
  mpinit();        // detect other processors
  lapicinit();     // interrupt controller
  picinit();       // disable pic
  ioapicinit();    // another interrupt controller
  uartinit();      // serial port
  ideinit();       // disk 
  tvinit();        // trap vectors
  binit();         // buffer cache
  idtinit();       // load idt register
  sti();           // enable interrupts
  welcome();       // print welcome message
  for(;;)
    wfi();
}
