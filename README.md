# stack-struct
## Explain
* The program uses stack tables to convert decimal to binary, octal, and hexadecimal.
* InitStack: constructs an empty stack, the initial size STACK_INIT_SIZE is set to 11 or other number, and the basic data type (ElemType) saved is set to int. 
* DestroyStack: destroys the given stack and reclaims the space 
* IsEmpty: allocated to the stack to determine whether a given stack is an empty GetTop: to get the stack top element, which is still in the stack. 
* Push: presses the given element into the stack. 
* Pop: takes out the top element of the stack.
* GetTop: get stack top element
* TraverseStack: Traversing stack table
* transfer: functions that realize decimal to binary, octal, and hexadecimal functions
## template
* First step : Enter the destination binary in the console window (2、8 or 16), carriage return
* Second step : Enter any decimal number of int type, carriage return.
* Last step : If you also want to perform a decimal conversion, after each successful decimal to target conversion results are displayed, enter       the character'yb 'and repeat steps I and II above.If you no longer need to perform another decimal conversion, please enter the character'n'.
* Decimal to binary : 1258
* Decimal to octal : 457
* Decimal to hexadecimal : 2019
* The result will be as follows:
```
请输入目标进制：2
请输入该10进制数：1258
当前栈中的情况：010011101010
出栈：010011101010
栈销毁成功！
是否继续，y/n:
y
请输入目标进制：8
请输入该10进制数：457
当前栈中的情况：0711
出栈：0711
栈销毁成功！
是否继续，y/n:
y
请输入目标进制：16
请输入该10进制数：2019
当前栈中的情况：0x7E3
出栈：0x7E3
栈销毁成功！
是否继续，y/n:
n
```
## Build Status
[![Build Status](https://dev.azure.com/2923616405/Edipyc-GitHub-Builds/_apis/build/status/pengyoucongcode.stack-struct?branchName=master)](https://dev.azure.com/2923616405/Edipyc-GitHub-Builds/_build/latest?definitionId=5&branchName=master)
