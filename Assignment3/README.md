# Parenthesis Matching Using Stack in C++

## Overview
This C++ program checks if expressions with parentheses are balanced using a stack.

## How It Works
The program reads an expression, uses a stack to manage opening and closing parentheses, 
and outputs whether the expression is 
"Balanced" or "Not Balanced."

## Setup and Execution
**Compile and Run with Script:**
1. Make the script executable:
   ```
   chmod +x run.sh
   ```
2. Execute the script:
   ```
   ./run.sh
   ```

**Manual Compilation and Execution:**
```
g++ -std=c++17 -Wall -Wextra -o balance balance.cpp
./balance
```

## Testing
Input different expressions to test balance status. Example:
- Input: `(())` → Output: `Balanced`
- Input: `(()` → Output: `Not Balanced`

## Maintainer
- Kaya Unal
