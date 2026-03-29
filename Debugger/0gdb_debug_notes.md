**GDB Debugging (VS Code) - Quick Guide**



STEP 1: Compile with debug info g++ -g Test.cpp -o test.exe



STEP 2: Start debugging Press F5



STEP 3: Set breakpoint Click left side of line (red dot)



STEP 4: Debug controls



F5 -> Start / Continue execution F10 -> Step Over (next line, no

function entry) F11 -> Step Into (enter function) Shift + F11 -> Step

Out (exit function) Shift + F5 -> Stop debugging



STEP 5: Observe values - Hover mouse on variables - Check Variables

panel



STEP 6: Debug flow 1. Set breakpoint 2. Press F5 3. Check variable

values 4. Use F10/F11 to move step by step 5. Identify issue





Locals = current function’s local scope

Call stack = all active function calls

Watch = anything you choose to monitor across all functions





**###########################################################**

**\*Simple structure example\*** 





\#include <iostream>

using namespace std;



struct Data {

&#x20;   int a;

&#x20;   int b;

&#x20;   int c;

};



int main() {

&#x20;   Data d;



&#x20;   d.a = 10;

&#x20;   d.b = 20;

&#x20;   d.c = 30;    // Add breakpoint here



&#x20;   cout << d.a << " " << d.b << " " << d.c << endl;



&#x20;   return 0;

}



**\*Add to Watch\***

d

d.a

d.b

d.c



\&d

\&d.a

\&d.b

\&d.c

sizeof(d)



**Addresses (example)**

\&d     = 0x1000

\&d.a   = 0x1000

\&d.b   = 0x1004

\&d.c   = 0x1008





✅ Struct is contiguous

All members are stored one after another

