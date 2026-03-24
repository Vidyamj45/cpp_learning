📘 Namespace in C++ 

🔹 **What is Namespace?**

👉 A namespace is used to avoid name conflicts by grouping identifiers (variables, functions, classes).



🔹 Syntax

namespace A {
  int x = 10;

}

👉 Access using:

A::x;



🔹 Why Needed?

👉 Same name can exist in different namespaces

namespace A { int x = 10; }

namespace B { int x = 20; }

A::x;  // 10

B::x;  // 20





🔹 using namespace

using namespace std;

👉 Avoid writing std:: again and again



🔹 Types

1\. Nested Namespace

namespace A {

   namespace B {

      int x = 5;
   }

}

A::B::x;


2\. Anonymous Namespace

namespace {

&#x20;   int x = 10;

}
👉 Scope limited to that file



🔹 Standard Namespace
👉 std contains:

cout

cin

vector

sort

**Example:**

std::cout << "Hello";



**🔴 Disadvantage of using namespace (Global Scope)**

❌ Problem: Name Conflict

#include <iostream>
#include <algorithm>
using namespace std;
int count = 5;

int main() {
 int arr[] = {1,2,2,3};
   int c = count(arr, arr+4, 2);  // ❌ ERROR

}

💥 Issue:
count → your variable
count() → function from <algorithm>
👉 Compiler gets confused (ambiguity)





**✅ Correct Way**

#include <iostream>
#include <algorithm>
int count = 5;

int main(){
   int arr[] = {1,2,2,3};
   int c = std::count(arr, arr+4, 2);  // ✅ clear
}


🔥 Interview Summary (Must Remember)
Namespace → avoids name conflict
Access using ::
using namespace → avoid in global scope

Causes:
ambiguity
name conflicts
hidden bugs

