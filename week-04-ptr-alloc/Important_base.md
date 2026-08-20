# Stack vs Heap

<p>Before starting exploring memory allocation in the
C programming language I find it important for myself to 
dive deeply in how exactly memory <b>works</b>.</p>

## The Stack

> What is stack?

<p>Call stack is a part of a virtual memory, used to automatically delete and manage data 
for a called function. It is managed directly by the CPU via specific registers.</p>

<p><i>Call stack and stack structure are not the same.</i></p>

> How does it work?

<p>Every function call creates an isolated <b>stack frame</b> on top of the stack. 
That frame contains: input arguments, return address, previous <code>EBP</code> (base pointer) and non-static variables.
It uses <code>EBP</code> and <code>ESP</code> registers. Base pointer shows the bottom of the current frame 
and a stack pointer shows the top of a stack.</p>

> Why is it so fast?

<p>To allocate or delete a big part of data from the stack processor simply "moves" stack pointer by simple subtraction / addition. <br>

<code>SUB ESP, 64</code> - subtracts 64 bytes from a register, moves it down. Creates space. <br>
<code>ADD ESP, 64</code> - adds 64 bytes to a register, moves it up. Clears space (data is not deleted from addresses). <br>

Both operations are O(1). Data is stored tightly and sequentially which allows it to stay in the CPU's fast L1/L2 cache.
</p>

> Where is it?

<p>Stack starts from the <b>highest</b> addresses and "grows" <b>downwards</b> to the <b>lower</b> addresses.</p>

> How big is it?

<p>The size of the stack is <b>fixed</b> and limited by the OS. Linux OS usually gives 8 MB.</p>

> What could possibly go wrong?

<p><b>Stack Overflow:</b> As has been mentioned above, stack is limited, so creating an endless recursion or 
a gigantic array (ex. <code>int arr[1000000000]</code>) will result in an overflow (no memory left).</p>
<p><b>Dangling Pointer:</b> If we try to access (via pointer) a local variable of a function, it may result in an undefined
behaviour since the frame is considered "deleted" and may be overwritten by new data.</p>

## The Heap

> What is heap?

<p>Heap is an unstructured pool of virtual memory, 
which should be operated manually to allocate custom size blocks of the data. </p>

> How does it work?

<p>In C memory on heap is operated by standard library <code>stdlib.h</code>, 
alocator, part of the <code>glibc</code>.
When allocation function is called, the library allocates data block from that pool.</p> 

> How big is data block?

<p>When you try to allocate 16 bytes of data, the block is larger than that: <br>
<b>Header:</b> Block size and flags. <br>
<b>Payload:</b> Data itself. <br>
<b>Padding:</b> Additional space for CPU architecture. <br>
Thanks to the header, <code>free()</code> function exactly knows how big is data block. 
</p>

> How fast is it?

<p>Slower than the stack, as the alocator must find a free block of the needed size 
(algorithms Best-fit, First-fit), update the lists of free blocks and divide the memory.</p>

> Where is it?

<p>The heap starts right after <code>Text</code> and <code>BSS/Data</code> segments and grows <b>upwards</b>
to the <b>higher</b> addreses.</p>

> What could possibly go wrong?

<p><b>Memory Leak:</b> Memory allocating without further freeing. Potential data leak and run out of free memory.</p>
<p><b>Use-After-Free:</b> After the block has been freed, trying to access the pointer may lead to undefined behaviour.</p>
<p><b>Double Free:</b> Trying to call free() twice for the same address (breaks the allocator metadata).</p>
<p><b>Heap Fragmentation:</b> The appearance of a large number of small "holes" between the occupied blocks, 
which is why it is not possible to allocate one large solid piece.</p>

##  Stack vs Heap

| Characteristics  | Stack                  | Heap                        |
|:----------------:|------------------------|-----------------------------|
|   Operated by    | Auto (CPU / Compiler)  | Manually (malloc / free)    |
|     Lifetime     | Limited by scope {}    | Until free()                |
|       Size       | Fixed by OS            | Limited by RAM and Swap     |
| Growth direction | $\downarrow$ downwards | $\uparrow$ upwards          |
|      Speed       | The fastest O(1)       | Slower (need to find space) |
|    CPU Cache     | Localized tight        | May be fragmented           |

<b>THE END</b>