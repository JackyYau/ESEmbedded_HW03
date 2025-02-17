HW03
===
This is the hw03 sample. Please follow the steps below.

# Build the Sample Program

1. Fork this repo to your own github account.

2. Clone the repo that you just forked.

3. Under the hw03 dir, use:

	* `make` to build.

	* `make clean` to clean the ouput files.

4. Extract `gnu-mcu-eclipse-qemu.zip` into hw03 dir. Under the path of hw03, start emulation with `make qemu`.

	See [Lecture 02 ─ Emulation with QEMU] for more details.

5. The sample is a minimal program for ARM Cortex-M4 devices, which enters `while(1);` after reset. Use gdb to get more details.

	See [ESEmbedded_HW02_Example] for knowing how to do the observation and how to use markdown for taking notes.

# Build Your Own Program

1. Edit main.c.

2. Make and run like the steps above.

3. Please avoid using hardware dependent C Standard library functions like `printf`, `malloc`, etc.

# HW03 Requirements

1. How do C functions pass and return parameters? Please describe the related standard used by the Application Binary Interface (ABI) for the ARM architecture.

2. Modify main.c to observe what you found.

3. You have to state how you designed the observation (code), and how you performed it.

	Just like how you did in HW02.

3. If there are any official data that define the rules, you can also use them as references.

4. Push your repo to your github. (Use .gitignore to exclude the output files like object files or executable files and the qemu bin folder)

[Lecture 02 ─ Emulation with QEMU]: http://www.nc.es.ncku.edu.tw/course/embedded/02/#Emulation-with-QEMU
[ESEmbedded_HW02_Example]: https://github.com/vwxyzjimmy/ESEmbedded_HW02_Example

--------------------

- [] **If you volunteer to give the presentation next week, check this.**

--------------------

**★★★ Please take your note here ★★★**
The ARM calling convention mandates using a full-descending stack.[1]

This calling convention causes a "typical" ARM subroutine to

    In the prologue, push r4 to r11 to the stack, and push the return address in r14, to the stack. (This can be done with a single STM instruction).
    copy any passed arguments (in r0 to r3) to the local scratch registers (r4 to r11).
    allocate other local variables to the remaining local scratch registers (r4 to r11).
    do calculations and call other subroutines as necessary using BL, assuming r0 to r3, r12 and r14 will not be preserved.
    put the result in r0
    In the epilogue, pull r4 to r11 from the stack, and pull the return address to the program counter r15. (This can be done with a single LDM instruction).
