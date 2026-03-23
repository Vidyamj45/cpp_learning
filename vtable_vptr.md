**Example Code (2 virtual functions)**

class Base {

public:

&#x20;   virtual void f1() { cout << "Base f1\\n"; }

&#x20;   virtual void f2() { cout << "Base f2\\n"; }

};



class Derived : public Base {

public:

&#x20;   void f1() { cout << "Derived f1\\n"; } // override

&#x20;   // f2 not overridden

};





🔹 vtable (created at **compile time**)



Base vtable

\[0] → Base::f1

\[1] → Base::f2



Derived vtable

\[0] → Derived::f1   (overridden)

\[1] → Base::f2      (inherited)





🔹 vptr (created at **runtime**)



When you do:



Derived obj;



Memory:



obj:

+--------+

| vptr   |

+--------+

| data   |









👉 Each object has its own vptr



🔹 How vptr attaches to vtable



During object creation:

Base constructor runs

vptr → Base vtable



Derived constructor runs

vptr → Derived vtable   ✅ (final)

👉 Same vptr is updated





🔹 Function Call Flow

Base\* ptr = \&obj;

ptr->f1();

ptr->f2();

Internally:

ptr → obj → vptr → vtable → function

Calls:

f1 → index 0 → Derived::f1

f2 → index 1 → Base::f2

🔹 Summary Flow (VERY IMPORTANT)

1\. Compile time:

&#x20;  - vtable created for each class



2\. Runtime (object creation):

&#x20;  - memory allocated (includes vptr)

&#x20;  - Base constructor → vptr = Base vtable

&#x20;  - Derived constructor → vptr = Derived vtable (final)



3\. Function call:

&#x20;  - use vptr → go to vtable → call function using index

🔥 One-line memory



👉 vtable = function list (per class)

👉 vptr = pointer to that list (per object)

👉 constructor = connects vptr to correct vtable







**####################################**

**VIRTUAL DESTRUCTOR**

**####################################**

**class Base {**

**public:**

&#x20;   **virtual \~Base() {**

&#x20;       **cout << "Base Destructor\\n";**

&#x20;   **}**

**};**



**class Derived : public Base {**

**public:**

&#x20;   **\~Derived() {**

&#x20;       **cout << "Derived Destructor\\n";**

&#x20;   **}**

**};**





delete obj;

&#x20;  ↓

(via vptr → Derived destructor)

&#x20;  ↓

Derived Destructor executes

&#x20;  ↓

Compiler-added Base destructor call

&#x20;  ↓

Base Destructor executes

