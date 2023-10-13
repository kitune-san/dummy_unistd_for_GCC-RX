# dummy_unistd_for_GCC-RX
Dummy unistd function for GCC-RX + newlib

I want to remove these warning messages.

```
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-closer.o): in function `_close_r':
(.text._close_r+0x10): warning: _close is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-fstatr.o): in function `_fstat_r':
(.text._fstat_r+0x12): warning: _fstat is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-signalr.o): in function `_getpid_r':
(.text._getpid_r+0x1): warning: _getpid is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-isattyr.o): in function `_isatty_r':
(.text._isatty_r+0x10): warning: _isatty is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-signalr.o): in function `_kill_r':
(.text._kill_r+0x12): warning: _kill is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-lseekr.o): in function `_lseek_r':
(.text._lseek_r+0x14): warning: _lseek is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-readr.o): in function `_read_r':
(.text._read_r+0x14): warning: _read is not implemented and will always fail
c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/bin/ld.exe: c:/programdata/gcc for renesas rx 8.3.0.202202-gnurx-elf/rx-elf/rx-elf/bin/../lib/gcc/rx-elf/8.3.0.202202-GNURX/../../../../rx-elf/lib/rxv3\libc.a(lib_a-writer.o): in function `_write_r':
(.text._write_r+0x14): warning: _write is not implemented and will always fail
```

## Usage
Copy dummy_unistd.{c,h} to e2studio project directory.
