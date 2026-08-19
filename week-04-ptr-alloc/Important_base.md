# Stack vs Heap

<p>Before starting exploring memory allocation in the
C programming language I find it important for myself to 
dive deeply in how exactly memory <b>works</b>.</p>

## The Stack

> What is stack?

<p>Call stack is a part of a virtual memory, used to automatically delete and manage data 
for a called function. It is managed directly by the CPU via specific registers.</p>

> How does it work?

<p>Every function call creates an isolated <b>stack frame</b> on top of the stack. 
That frame contains: input arguments, return address, previous <code>EBP</code> (base pointer) and non-static variables.
It uses <code>EBP</code> and <code>ESP</code> registers. Base pointer shows the bottom of the frame of the current frame 
and a stack pointer shows the top of a stack.</p>

> Why is it so fast?

<p>To allocate or delete a big part of data from the stack processor simply "moves" stack pointer by simple subtraction / addition. <br>

<code>SUB ESP, 64</code> - subtracts 64 bytes from a register, moves it down. Creates space. <br>
<code>ADD ESP, 64</code> - adds 64 bytes to a register, moves it up. Clears space (data is not deleted from addresses). <br>

Both operations are O(1). Data is stored tightly and sequentially which allows it to stay in the CPU's fast L1/L2 cache.
</p>

> Where is it?

<p>Stack starts from the <b>highest</b> addresses and "grows" downwards to the <b>lower</b> addresses.</p>

> How big is it?

<p>The size of the stack is <b>fixed</b> and limited by the OS. Linux OS usually gives 8 MB.</p>

> What could possibly go wrong?

<p><b>Stack Overflow:</b> As has been mentioned above, stack is limited, so creating an endless recursion or 
a gigantic array (ex. <code>int arr[1000000000]</code>) will result in an overflow (no memory left).</p>
<p><b>Dangling Pointer:</b> If we try to access (via pointer) a local variable of a function, it may result in an undefined
behaviour since the frame is considered "deleted" and may be overwritten by new data.</p>

## The Heap

> What is heap?



<b>THE END</b>